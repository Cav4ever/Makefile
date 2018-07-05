void quick_sort(int[], int, int);
int Qsort(int[], int, int);

/*HsahTable*/
#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 /* 定义散列表长为数组的长度 */  
#define NULLKEY -32768
#define OK 1

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */

typedef struct
{  
   int *elem; /* 数据元素存储基址，动态分配数组 */  
   int count; /*  当前数据元素个数 */  
}HashTable;

/* 初始化散列表 */  
Status InitHashTable(HashTable*);
/* 散列函数 */  
int Hash(int);
/* 插入关键字进散列表 */  
void InsertHash(HashTable*, int);
/* 散列表查找关键字 */  
Status SearchHash(HashTable, int, int* );

void insert_sort(int [], int);
void select_sort(int [], int);
void bubble_sort(int [], int);
void shell_sort(int [], int);
void merge_sort(int [], int);
void mergeSort(int [], int, int, int []);
void mergeArray(int [], int, int, int, int[]);