#include <stdio.h>
#include <stdlib.h>
#include "algorithms.h"
#include "other.h"

extern int m;

void quick_sort(int arr[], int low, int high)
{
	int pivotKey = 0;
	if(low < high)
	{
		pivotKey = Qsort(arr, low, high);
		quick_sort(arr, low, pivotKey - 1);
		quick_sort(arr, pivotKey + 1, high);
	}
}

int Qsort(int arr[], int low, int high)
{
	int pivot = arr[low];
	while(low < high)
	{
		while(low < high && pivot <= arr[high])
			high--;
		swap(&arr[low], &arr[high]);
		
		while(low < high && pivot >= arr[low])
			low++;
		swap(&arr[low], &arr[high]);
	}
	return low;
}

/* 初始化散列表 */  
Status InitHashTable(HashTable *H)  
{  
    int i;  
    m=HASHSIZE;  
    H->count=m;  
    H->elem=(int *)malloc(m*sizeof(int));  
    for(i=0;i<m;i++)  
        H->elem[i]=NULLKEY;   
    return OK;  
}  
  
/* 散列函数 */  
int Hash(int key)  
{  
    return key % m; /* 除留余数法 */  
}  
  
/* 插入关键字进散列表 */  
void InsertHash(HashTable *H,int key)  
{  
    int addr = Hash(key); /* 求散列地址 */  
    while (H->elem[addr] != NULLKEY) /* 如果不为空，则冲突 */  
    {  
        addr = (addr+1) % m; /* 开放定址法的线性探测 */  
    }  
    H->elem[addr] = key; /* 直到有空位后插入关键字 */  
}  
  
/* 散列表查找关键字 */  
Status SearchHash(HashTable H,int key,int *addr)  
{  
    *addr = Hash(key);  /* 求散列地址 */  
    while(H.elem[*addr] != key) /* 如果不为空，则冲突 */  
    {  
        *addr = (*addr+1) % m; /* 开放定址法的线性探测 */  
        if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) /* 如果循环回到原点 */  
            return UNSUCCESS;   /* 则说明关键字不存在 */  
    }  
    return SUCCESS;  
}  

void insert_sort(int a[], int len)
{
	int i = 0, j = 0, temp = 0;
	for(i = 1; i < len; i++ )
	{
		for(j = i; j > 0 && a[j] < a[j - 1]; j--)
		{
			temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
		}
	}
}

void bubble_sort(int a[], int len)
{
	int i = 0, j = 0, temp = 0;
	for(i = 0; i < len - 1; i++ )
	{
		for(j = 0; j < len - i - 1; j++)
		{
			if(a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void select_sort(int a[], int len)
{
	int i = 0, j = 0, min = 0, temp = 0;
	for(i = 0; i < len - 1; i++ )
	{
		min = i;
		for(j = i + 1; j < len; j++)
		{
			if(a[j] < a[min])
			{
				min = j;
			}
		}
		if(i != min)
		{
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
}

void shell_sort(int a[], int len)
{
	int i = 0, j = 0, temp = 0;
	int h = 1;
	while(h < len / 3)
	{
		h = 3 * h + 1;
	}
	while(h >= 1)
	{
		for(i = h; i < len; i++)
		{
			for(j = i; j >= h && a[j] < a[j - h]; j -= h)
			{
				temp = a[j];
				a[j] = a[j - h];
				a[j - h] = temp;
			}
		}
		h = h/3;
	}
}

void merge_sort(int a[], int n)
{
	int *p = (int *) malloc(n * sizeof(int));
	if(NULL == p)
	{
		return;
	}
	mergeSort(a, 0, n - 1, p);
	free(p);
	return;
}

void mergeSort(int a[], int first, int last, int temp[])
{
	if(first < last)
	{
		int mid = (first + last) / 2;
		mergeSort(a, first, mid, temp);
		mergeSort(a, mid + 1, last, temp);
		mergeArray(a, first, mid, last, temp);
	}
	return;
}

void mergeArray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1, k = 0;
	while(i <= mid && j <= last)
	{
		if(a[i] < a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}
	while(i <= mid)
	{
		temp[k++] = a[i++];
	}
	while(j <= last)
	{
		temp[k++] = a[j++];
	}
	for(i = 0; i < k ; i++)
	{
		a[first + i] = temp[i];
	}
	return ;
}