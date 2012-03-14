#include <stdio.h>
#include "list.h"

int main()
{
	printf("0 - vyhod\n1 - proverka ravenstva mnogochlenov p i q\n2 - vychislenye znachenya mnogochlena v tochke x0\n3 - vychislenye summy mnogochlenov r = p + q\n");
	int command = 5;
	
	while (command != 0)
	{
		printf("vvedyte comandu\n");
		scanf("%d", &command);
		if (command == 0)
			printf("vyhod\n");
		else if (command == 1)
		{
			plist p = NULL;
			plist q = NULL;
			printf("dlya p:\n");
			read(p);
			printf("dlya q:\n");
			read(q);
			equals(p,q);
		}
		else if (command == 2)
		{
			plist p = NULL;
			read(p);
			int x0 = 0;
			printf("vvedyte x0\n");
			scanf("%d", &x0);
			value(p, x0);
			
		}
		else if (command == 3)
		{
			plist p = NULL;
			plist q = NULL;
			plist r = NULL;
			printf("dlya p:\n");
			read(p);
			printf("dlya q:\n");
			read(q);
			add(p,q,r);
		}
		else
			printf("nevernaya comanda,vvedute druguyu comandu\n");
	}
	return 0;
}