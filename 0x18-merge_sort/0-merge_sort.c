#include "sort.h"

/**
 * merge - merges a split array
 * @array: array to merge into
 * @arr2: array to merge from
 * @start: start index
 * @mid: mid index
 * @end: end index
 *
 */
void merge(int *array, int *arr2, int start, int mid, int end)
{
	int i, j, k;
	int num1 = mid - start + 1;
	int num2 = end - mid;

	for (i = 0; i < num1; i++)
		arr2[i] = array[start + i];
	for (j = i; j - i < num2; j++)
		arr2[j] = array[mid + 1 + (j - i)];
	printf("Merging...\n");
	printf("[left]: ");
	print_array(arr2, num1);
	printf("[right]: ");
	print_array(arr2 + i, num2);
	j = i, i = 0, k = start;
	while (i < num1 && j - num1 < num2)
	{
		if (arr2[i] <= arr2[j])
		{
			array[k] = arr2[i];
			i++;
		}
		else
		{
			array[k] = arr2[j];
			j++;
		}
		k++;
	}
	while (i < num1)
	{
		array[k] = arr2[i];
		i++, k++;
	}
	while (j - i < num2)
	{
		array[k] = arr2[j];
		j++, k++;
	}
	printf("[Done]: ");
	print_array(array + start, end - start + 1);
}
/**
 * split_merge - split array, sort to arr2, and merge to array
 * @array: array to sort
 * @arr2: secondary array
 * @start: start index
 * @end: end index
 *
 * Return: void
 */
void split_merge(int *array, int *arr2, size_t start, size_t end)
{
	int mid;

	/*printf("Test\n");*/
	if (start < end)
	{
		mid = (start + (end - start - 1) / 2);

		split_merge(array, arr2, start, mid);
		split_merge(array, arr2, mid + 1, end);

		merge(array, arr2, start, mid, end);
	}
}
/**
 * merge_sort - sorts an array using merge sort algo
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *arr2;

	if (size < 2)
		return;
	arr2 = malloc(sizeof(int) * size);
	split_merge(array, arr2, 0, size);
	free(arr2);
}
