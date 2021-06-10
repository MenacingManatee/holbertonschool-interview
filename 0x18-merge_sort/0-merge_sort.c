#include "sort.h"

int *arr_copy(int *array, size_t n1, size_t n2);
void free_arr(int *array);
/**
 * merge - merges a split array
 * @array: array to merge into
 * @arr2: array to merge from
 * @start: start index
 * @mid: mid index
 * @end: end index
 *
 */
void merge(int *array, int start, int mid, int end)
{
	int i, j, k;
	int num1 = mid - start + 1;
	int num2 = end - mid;
	int *L, *R;

	L = arr_copy(array, start, num1);
	R = arr_copy(array, mid + 1, num2);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(L, num1);
	printf("[right]: ");
	print_array(R, num2);

	i = 0;
	j = 0;
	k = start;

	while (i < num1 && j < num2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < num1)
	{
		array[k] = L[i];
		i++;
		k++;
	}
	while (j < num2)
	{
		array[k] = R[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	print_array(array + start, k - start);
	free_arr(L);
	free_arr(R);
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
void split_merge(int *array, size_t start, size_t end)
{
	int mid;

	if (start < end)
	{
		mid = ((end - 1) + start) / 2;

		split_merge(array, start, mid);
		split_merge(array, mid + 1, end);

		merge(array, start, mid, end);
	}
}
/**
 * arr_copy - copies an array
 * @array: array to copy
 * @n1: start index
 * @n2: end index
 *
 * Return: new array
 */
int *arr_copy(int *array, size_t n1, size_t n2)
{
	int *ret = malloc(sizeof(int) * n2);
	size_t i, j;

	for (i = 0, j = n1; i < n2; i++, j++)
		ret[i] = array[j];
	return (ret);
}
/**
 * free_arr - frees an array
 * @array: array to free
 *
 */
void free_arr(int *array)
{
	free(array);
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
	split_merge(array, 0, size);
}
