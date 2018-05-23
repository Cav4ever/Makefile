#include "algorithms.h"

int binary_search(int list[], int item, int len)
{
	int low = 0;
	int high = len -1;
	int mid = 0;
	int guess = 0;
	while(low <= high)
	{
		mid = (low + high) / 2;
		guess = list[mid];
		if(guess == item)
		{
			return mid;
		}
		else if(guess < item)
			low = mid + 1;
		else
			high = mid -1;		
	}
	return -1;
}

void selectionSort(int arr[], int len)
{
	int i = 0, j = 0, temp = 0;
	for(i; i < len - 1; i++)
	{
		for(j = i + 1; j < len; j++)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void bubbleSort(int arr[], int len)
{
	int i = 0, j = 0, temp = 0;
	for(i; i < len - 1; i++)
	{
		for(j = 0; j < len - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void quickSort(int arr[], int low, int high)
{
	int pivotKey = 0;
	if(low < high)
	{
		pivotKey = partition(arr, low, high);
		quickSort(arr, low, pivotKey - 1);
		quickSort(arr, pivotKey + 1, high);
	}
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[low];
	while(low < high)
	{
		while(low < high && arr[high] >= pivot)
			high--;
		swap(&arr[low], &arr[high]);
		
		while(low < high && arr[low] <= pivot)
			low++;
		swap(&arr[low], &arr[high]);
	}
	return low;
}