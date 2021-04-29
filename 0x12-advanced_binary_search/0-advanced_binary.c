#include "search_algos.h"

/**
 * print_array - prints an array in expected format
 * @array: array to print
 * @size: size of array
 *
 */
void print_array(int *array, size_t size)
{
	int i;

	printf("Searching in array: ");
	for (i = 0; i < (int)size; i++)
	{
		printf("%d", array[i]);
		if (i == (int)size - 1)
			printf("\n");
		else
			printf(", ");
	}
}
/**
 * advanced_binary - searches for a value in a sorted array of integers.
 * @array: pointer to the first element of the array to search in
 * @size: Num of elements in array
 * @value: value to search for
 *
 * Return: Index where value is found, or -1 on failure
 */
int advanced_binary(int *array, size_t size, int value)
{
	int num = size / 2;
	int odd = size % 2 == 0 ? 0 : 1;
	int tmp = -1;

	if (array == NULL || size <= 0)
		return (-1);
	print_array(array, size);
	if (array[num] == value)
	{
		if (size > 3)
		{
			tmp = advanced_binary(array, size / 2, value);
		}
		else if (size <= 3)
		{
			if (array[0] == value)
				return (0);
		}
		return ((tmp == -1 ? num : tmp));
	}
	else if (array[num] > value)
	{
		if (1) /* Betty */
			return (advanced_binary(array, size / 2, value));
	}
	else
	{
		num = advanced_binary(array + (size / 2) + odd, size / 2, value);
		return (num == -1 ? -1 : num + (int)size / 2 + odd);
	}
}
