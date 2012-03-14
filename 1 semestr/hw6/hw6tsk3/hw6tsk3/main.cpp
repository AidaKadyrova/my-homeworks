#include <stdio.h>

int length(int a) // считает кол-во разрядов числа
{
	int count = 0;
	while (a != 0)
	{
		count++;
		a = a / 10;
	}
	return count;
}

void gap(int deg[],int &k)
{
	while (deg[k] == 0)
		k++;
	for (int j = 0; j < length(deg[k]); j++)
		printf(" ");
	k++;
}

int main()
{
	int const dim = 80;
	int inputMass[dim]; //массив коэффициентов
	int maxDeg = 0;
	printf("vvedyte max stepen\n");
	scanf("%d", &maxDeg);
	printf("\nvvedyte coefficienty\n");
	for (int i = 0; i <= maxDeg; i++) //считываем коэффициенты
	{
		scanf("%d", &inputMass[i]);   
	}
	int deg[dim];
	for (int i = 0; i < dim; i++)
		deg[i] = 0;
	int index = length(inputMass[0]) + 2; 
	deg[index] = maxDeg; // заполняем массив степеней
	for (int i = 1; i < maxDeg; i++) 
	{
		if (inputMass[i] != 0)
		{
			if (inputMass[i] == 1 || inputMass[i] == -1 )
			{
				index = index + length(inputMass[i]) + 2;
				deg[index] = maxDeg - i;
			}
			else
			{
				index = index + length(inputMass[i]) + 3;
				deg[index] = maxDeg - i;
			}
		}
	}
	printf("\n");
	for (int i = 0; i < index + 1; i++) //выводим массив степеней
		if (deg[i] != 0 && deg[i] != 1)
			printf("%d", deg[i]);
		else
			printf(" ");
	printf("\n");
	if (inputMass[0] != 0) //выводим коэффициент при старшей степени
	{
		if (inputMass[0] == 1)
			printf(" x");
		else if (inputMass[0] == -1)
			printf("-x");
		else if (inputMass[0] < 0)
			printf("%dx", inputMass[0]);
		else 
			printf(" %dx", inputMass[0]);
	}
	int k = 0;
	for (int i = 1; i < maxDeg; i++) // все остальные, кроме последнего
	{
		
		if (inputMass[i] != 0)
		{
			gap(deg,k);
			if (inputMass[i] == 1)
				printf("+x");
			else if (inputMass[i] == -1)
				printf("-x");
			else 
			{
				if (inputMass[i] < 0)
					printf("%dx", inputMass[i]);
				else
					printf("+%dx", inputMass[i]);
			}		
		}
	}
	gap(deg,k);
	if (inputMass[maxDeg] < 0) //выводим коэффициент при 0 степени
		printf("%d", inputMass[maxDeg]);
	else if (inputMass[maxDeg] != 0)
		printf("+%d", inputMass[maxDeg]);
	printf("\n");
	return 0;
}	
	