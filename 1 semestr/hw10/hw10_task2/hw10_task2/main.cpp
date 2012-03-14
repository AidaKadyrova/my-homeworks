#include <stdio.h>
#include <string.h>

//digit+ (. digit+)? (E(+ | -)? digi+)?

int main()
{
	char num[20];
	scanf("%s",num);
	int state = 0;
	int i = 0;
	while(1)
	{
		switch (state)
		{
		case 0:
			if (num[i] >= '0' && num[i] <= '9')
				state = 1;
			else state = -1;
		break;		
		case 1:
			i++;
			if (num[i] >= '0' && num[i] <= '9')
				state = 1;
			else
				state = 2;
			break;
		case 2:
			if (num[i] == '.')
			{	
				i++;
				if (num[i] >= '0' && num[i] <= '9')
					state = 3;
				else state = -1;
			}
			else 
				state = 4;
			break;

		case 3:
			i++;
			if (num[i] >= '0' && num[i] <= '9')
				state = 3;
			else
				state = 4;
			break;
		case 4:
			if (num[i] == 'E') //&& num[i+1] >= '0' && num[i+1] <= '9')
				state = 5;
			else 
				if (num[i] == 0)
					state = 7;
				else state = -1;
			break;
		case 5:
			i++;
			if (num[i] == '+' || num[i] == '-' || (num[i] >= '0' && num[i] <= '9'))
				state = 6;
			else 
				state = -1;
			break;
		case 6:
			i++;
			if (num[i] >= '0' && num[i] <= '9')
				state = 6;
			else	
				if (num[i] == 0)
					state = -1;
				else
					state = 7;
			break;
		case 7:
			printf("da\n");
			return 0;
			break;
		case -1:
			printf("net\n");
			return 0;
			break;
	
		}
	}
}