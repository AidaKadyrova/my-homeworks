#include <cstdio>
#include "node.h"

int main()
{
	printf("0 - exit \n1 - add value  to sorted list\n2 - remove value from list\n3 - print list\n\n");
	pnode root = NULL;
	int cmd = 1;
	int value = 0;
	while (cmd != 0)
	{
		printf("vvedyte comandy\n");
		scanf("%d", &cmd);
		if (cmd == 0)
		{ 
			printf("exit\n");
			cleanOut(root);
			break;
		}
		else if (cmd == 1) 
		{   printf("vvedyte value ");
			scanf("%d", &value);
			addItem(root, value);
		}
		else if (cmd == 2) 
		{	
			printf("vvedyte chislo, kotoroe neobhodimo udalit  ");
			scanf("%d", &value);
			removeItem(root, value);
		}
		else if (cmd == 3)
			printList(root);
		else if (cmd > 3)
			printf("ne pravilnaya comanda\n");
	}
	return 0;
}
