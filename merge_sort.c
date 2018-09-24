#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high)
{
	int n1 = mid - low + 1;
	int n2 = high - mid;
	int left[n1], right[n2];
	int q = 0, i, w = 0;

	for (i = 0; i < n1; i++)
	{
		left[i] = arr[low + i];
	}

	for (i = 0; i < n2; i++)
	{
		right[i] = arr[mid + i + 1];
		//	printf("%d ",right[i]);
	}

	int e = 0, r = 0, l = low;

	while (e < n1 && r < n2)
	{
		if (left[e] <= right[r])
		{
			arr[l] = left[e];
			e++;
			l++;
		}
		else
		{
			arr[l] = right[r];
			r++;
			l++;
		}
	}

	while (e < n1)
	{
		arr[l] = left[e];
		e++;
		l++;
	}
	while (r < n2)
	{
		arr[l] = right[r];
		l++;
		r++;
	}
}

void sort(int arr[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;

		sort(arr, low, mid);
		sort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

int main()
{
	int arr[5] = {1, 5, 4, 3, 7};
	int size = 5;
	int i;
	printf("before\n");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	sort(arr, 0, size - 1);

	printf("\nafter\n");

	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
