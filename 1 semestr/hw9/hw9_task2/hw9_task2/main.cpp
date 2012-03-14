#include <stdio.h>
#include "hash.h"

int main()
{
	int const dim = 100;
	char str1[dim];
	char str2[dim];
	printf("Input 1st string\n");
	gets(str1);
	printf("Input 2nd string\n");
	gets(str2);
	find(str1, str2);
	return 0;
}