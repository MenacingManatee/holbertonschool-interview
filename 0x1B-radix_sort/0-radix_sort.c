#include "sort.h"

/**
 * get_max - Get largest int in arr
 * @arr: Int array to search
 * @size: Size of the array
 *
 * Return: Largest number in array
 */
int get_max(int *arr, size_t size)
{
	int max = arr[0], i;

	for (i = 0; i < (int)size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return (max);
}
/**
 * lsd_sort - sorts an array using lsd sort algo
 * @array: array to sort
 * @size: size of array
 * @mod: number to divide by before finding least significant digit
 *
 * Return: Void
 */
void lsd_sort(int *array, size_t size, int mod)
{
	int *res;
	int i, count[10] = { 0 };

	res = malloc(size * sizeof(int));
	if (res == NULL)
		return;
	for (i = 0; i < (int)size; i++)
		count[(array[i] / mod) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		res[count[(array[i] / mod) % 10] - 1] = array[i];
		/*printf("%d - %d\n", count[(array[i] / mod) % 10] - 1, array[i]);*/
		count[(array[i] / mod) % 10]--;
	}
	for (i = 0; i < (int)size; i++)
	array[i] = res[i];
	print_array(array, size);
}
/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix algo
 *
 * @array: array to sort
 * @size: size of array
 *
 * Return: Void
 */
void radix_sort(int *array, size_t size)
{
	int max, mod;

	if (array == NULL || size < 2)
		return;
	max = get_max(array, size);
	for (mod = 1; max / mod > 0; mod *= 10)
	{
		lsd_sort(array, size, mod);
	}
}
