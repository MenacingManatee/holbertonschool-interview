#include "sort.h"
#include <stdio.h>


void sift_down(int *array, int start, int end, size_t size);
void heapify(int *array, size_t size, int i);
/**
  * heap_sort - heap sort algorithm
  * @array: array to sort
  * @size: size of array
  */
void heap_sort(int *array, size_t size)
{
	int i, tmp;

	heapify(array, size, ((size - 2) / 2) - 1);
	for (i = size -1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		if (i >= 1)
		  sift_down(array, 0, i, size);
	}
}
/**
 *
 */
void heapify(int *array, size_t size, int i)
{
	int max = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int tmp;

	if (l >= (int)size || r >= (int)size)
		return;
	if (array[l] > array[max])
		max = l;
	if (array[r] > array[max])
		max = r;
	if (max != i)
	{
		tmp = array[i];
		array[i] = array[max];
		array[max] = tmp;
		print_array(array, size);
	}
	if (max != i)
		heapify(array, size, ((size - 2) / 2) - 1);
	else if (i > 0)
		heapify(array, size, i - 1);

}
/**
 *
 */
void sift_down(int *array, int start, int end, size_t size)
{
	int max = start;
	int l = start * 2 + 1;
	int r = start * 2 + 2;
	int tmp;

	if (r > end && l > end)
		return;
	if (l < end && array[l] > array[max])
		max = l;
	if (r < end && array[r] > array[max])
		max = r;
	if (max != start)
	{
		tmp = array[start];
		array[start] = array[max];
		array[max] = tmp;
		print_array(array, size);
	}
	if (max != start)
	{
		sift_down(array, max, end, size);
	}
}
