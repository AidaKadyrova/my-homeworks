#include <stdio.h>
#include "list.h"

int main()
{
	printf("vvedyte col-vo elementov: \n");
	int count = 0;
	scanf("%d", &count);
	printf("kakoy dolzhen ostat'sya\n", count);
	int i = 0;
	scanf("%d", &i);
	plst head = NULL;
	int k = runCount(head, i, count);
	delList(head);
	return 0;
}