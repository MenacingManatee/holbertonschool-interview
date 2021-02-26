#include "slide_line.h"
#include <stdio.h>

void merge_nums(int *line, size_t size, int direction);
/**
 * slide_line - slides and merges an array of integers
 * @line: array of integers containing size elements
 * @size: Size of array line
 * @direction: direction to slide
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL)
		return (0);
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	merge_nums(line, size, direction);
	return (1);
}

/**
 * merge_nums - Merges the numbers in an array
 * @line: array of integers
 * @size: Size of the array
 * @direction: direction to slide
 *
 * Return: void
 */
void merge_nums(int *line, size_t size, int direction)
{
	int i, j, catch;

	if (direction == SLIDE_LEFT)
	{
		for (i = j = catch = 1; i < (int)size; i++, j = i)
		{
			while (j >= 1 && line[j - 1] == 0 && line[j] != 0)
			{
				line[j - 1] += line[j];
				line[j] = 0;
				j--;
			}
			if (line[j] == line[j - 1] && line[j] != 0 && j >= catch)
			{
				line[j - 1] += line[j];
				line[j] = 0;
				catch++;
			}
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		for (i = j = catch = size - 2; i >= 0; i--, j = i)
		{
			while (j <= (int)size - 2 && line[j + 1] == 0 && line[j] != 0)
			{
				line[j + 1] += line[j];
				line[j] = 0;
				j++;
			}
			if (line[j] == line[j + 1] && line[j] != 0 && j <= catch)
			{
				line[j + 1] += line[j];
				line[j] = 0;
				catch--;
			}
		}
	}
}
