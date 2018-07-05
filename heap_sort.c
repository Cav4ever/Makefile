#include <stdio.h>

void heap_sort(int [], int);
void heap_adjust(int [], int, int);
void showArray(int [], int);
void swap(int *, int *);

int main()
{
	int a[] = {3, 1, 2, 32, 37, 24, 23, 6};
	int len = sizeof(a) / sizeof(a[0]);
	printf("Before sort:\n");
	showArray(a, len);
	heap_sort(a, len);
	printf("After sort:\n");
	showArray(a, len);
	return 0;
}

void heap_sort(int a[], int len)
{
	int i = len / 2 - 1;
	for(i; i >= 0; i--)
	{
		heap_adjust(a, i, len);
	}
	for(i = len - 1; i > 0; i--)
	{
		swap(&a[0], &a[i]);
		heap_adjust(a, 0, i);
	}
}

void heap_adjust(int a[], int i, int len)
{
	int j = 2 * i + 1;
	int temp = a[i];
	for (j; j < len ; j = 2 * j + 1)
	{
		if(j < len - 1 && a[j] < a[j + 1])
		{
			j++;
		}
		if(temp >= a[j])
		{
			break;
		}
		a[i] =a[j];
		i = j;
	}
	a[i] = temp;
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void showArray(int a[], int len )
{
	int i = 0;
	for(i; i < len; i++)
	{
		printf("%d\n", a[i]);
	}
}
