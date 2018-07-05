#include <stdio.h>
#include "algorithms.h"
#include "other.h"

/*Test for quick_sort*/
int main()
{
	int list[] = {3, 1, 24, 35, 2, 7, 21, 0, 5};
	int len = sizeof(list)/sizeof(list[0]);
	
	printf("Before Sort:\n");
	showArray(list, len);
	
	merge_sort(list, len);
	printf("After Sort:\n");
	showArray(list, len);
	
	return 0;
}


int m=0; // 散列表表长，全局变量

/*
int main()  
{  
    int arr[HASHSIZE]={12,67,56,16,25,37,22,29,15,47,48,34};  
    int i,p,key,result;  
    HashTable H;  
  
    key=39;  
  
    InitHashTable(&H);  
    for(i=0;i<m;i++)  
         InsertHash(&H,arr[i]);  
      
    result=SearchHash(H,key,&p);  
    if (result)  
        printf("查找 %d 的地址为：%d \n",key,p);  
    else  
        printf("查找 %d 失败。\n",key);  
  
    for(i=0;i<m;i++)  
    {  
        key=arr[i];  
        SearchHash(H,key,&p);  
        printf("查找 %d 的地址为：%d \n",key,p);  
    }  
  
    return 0;  
}  */
