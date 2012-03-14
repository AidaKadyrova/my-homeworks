#include <stdio.h>
#include "exp.h"

bool digit (char c)
{
	return (c >= '0' && c <= '9');
}

bool isNumber(char num[],int &i)
{
	int state = 0;
	while(1)
	{
		switch (state)
		{
		case 0:
			if (digit(num[i]))
				state = 1;
			else if ((num[i] == '-') && digit(num[i + 1]))
			{
				i++;
				state = 1;
			}
			else state = -1;
		break;		
		case 1:
			i++;
			if (digit(num[i]))
				state = 1;
			else
				state = 2;
			break;
		case 2:
			if (num[i] == '.')
			{	
				i++;
				if (digit(num[i])) 
					state = 3;
				else state = -1;
			}
			else 
				state = 4;
			break;

		case 3:
			i++;
			if (digit(num[i]))
				state = 3;
			else
				state = 4;
			break;
		case 4:
			if (num[i] == 'E') 
				state = 5;
			else 
				if (num[i] == ' ' || num[i] == 0)
					state = 7;
				else state = -1;
			break;
		case 5:
			i++;
			if (num[i] == '+' || num[i] == '-' || digit(num[i]))
				state = 6;
			else 
				state = -1;
			break;
		case 6:
			i++;
			if (digit(num[i]))
				state = 6;
			else	
				if (num[i] == ' ' || num[i] == 0)
					state = 7;
			break;
		case 7:
			return 1;
			break;
		case -1:
			return 0;
			break;
		}
	}
}

bool isExpression(char str[],int i)
{
	int state = 0;
	while (1)
	{
		switch(state)
		{
		case 0:
			if (digit(str[i]) || (str[i] == '-') && digit(str[i + 1]))
				state = 1;
			else return 0;
			break;
		case 1:
			if (isNumber(str, i) && (str[i] == ' ' || str[i] == 0))
				state = 2;
			else
				return 0;
			break;
		case 2:
			if (str[i] == 0)
				return 1;
			else
				if ((str[i + 1] == '+' || str [i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/') && str[i + 2] == ' ')
				{
					i += 3;
					if (isExpression(str, i))
						return 1;
				}
			else
				return 0;
			break;
		}
	}
}
