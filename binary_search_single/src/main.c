#include <stdio.h>
#include "algorithms.h"

int main()
{
	int list[] = {1, 3, 5, 7, 9};
	int len = sizeof(list) / sizeof(list[0]);
	printf("%d\n", binary_search(list, 3, len));
	printf("%d\n", binary_search(list, 0, len));
	return 0;
}