#include <stdio.h>
#include "other.h"

void showArray(int arr[], int len)
{
	int i = 0;
	for(i; i < len; i++)
		printf("%d\n", arr[i]);
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}