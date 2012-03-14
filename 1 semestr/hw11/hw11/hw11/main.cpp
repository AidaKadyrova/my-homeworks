#include <stdio.h>
#include "exp.h"

int main()
{
	char str[80];
	gets(str);
	int i = 0;
	if (isExpression(str, i))
		printf("da\n");
	else printf("net\n");
	return 0;
}