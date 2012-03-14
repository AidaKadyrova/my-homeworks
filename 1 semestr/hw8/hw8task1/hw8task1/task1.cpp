#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int &a, int &b)
{
	b = b + a;
	a = b - a;
	b = b - a;
}
int main()
{
	srand(time(0));
	int const dimension = 10;
	int mass[dimension];
	for (int i = 0; i < dimension; i++)
	{
		mass[i] = rand() % 100;
		printf("%d ", mass[i]);
	}
	printf("\n");
	for (int i = 0; i < dimension - 1; i++)
		for (int j = i + 1; j < dimension; j++)
			if (mass[j] < mass[i])
				swap(mass[j], mass[i]);
	for (int i = 0; i < dimension; i++)
		printf("%d ", mass[i]);
	printf("\n");
	return 0;
}