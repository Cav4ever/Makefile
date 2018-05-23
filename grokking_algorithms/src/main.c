#include <stdio.h>
#include "algorithms.h"
#include "other.h"

int main()
{
	int list[] = {23, 24,6, 3, 35, 13, 9, 21, 1, 0};
	int len = sizeof(list)/sizeof(list[0]);
	printf("Before Sort:\n");
	showArray(list, len);
	quickSort(list, 0, len - 1);
	printf("After Sort:\n");
	showArray(list, len);
	return 0;
}
/* Test for binary_search
int main()
{
	int list[] = {1, 3, 5, 7, 9};
	int len = sizeof(list) / sizeof(list[0]);
	printf("%d\n", binary_search(list, 3, len));
	printf("%d\n", binary_search(list, 0, len));
	return 0;
}
*/