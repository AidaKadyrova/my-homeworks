#include <stdio.h>

int main()
{
	FILE *file;
	file = fopen("input.txt", "r");
	int const dim = 80;
	int mass[dim][dim];
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			mass[i][j] = 0;
	int cities = 0;
	int roads = 0;
	fscanf(file, "%d %d", &cities, &roads);
	while (!feof(file))
	{
		int city1 = 0;
		int city2 = 0;
		int distance = 0;
		fscanf(file, "%d %d %d", &city1, &city2, &distance);
		mass[city1][city2] = distance;
		mass[city2][city1] = distance;
	}
	bool check[dim];
	for (int i = 0; i < dim; i++)
		check[i] = false;
	int max = 10000;
	int dist[dim];
	dist[1] = 0;
	for (int i = 2; i < dim; i++)
		dist[i] = max;
	int start = 1;
	int count = 0;
	int next = 0;
	while (count < cities)
	{
		int minDist = max;
		for (int  i = 2; i <= cities; i++)
		{
			if (mass[start][i])
			{
				if (dist[start] + mass[start][i] < dist[i] && !check[i])
					dist[i] = dist[start] + mass[start][i];
				if (mass[start][i] < minDist && !check[i])
				{
					minDist = mass[start][i];
					next = i;
				}
			}
		}
		check[start] = true;
		start = next;
		count++;
	}
	count = 1;
	printf("next city   distance\n\n");
	while (count < cities)
	{
		int min = max;
		int city = 0;
		for (int i = 2; i <= cities; i++)
			if (dist[i] && dist[i] < min)
			{
				min = dist[i];
				city = i;
			}
		dist[city] = 0;
		printf("    %d\t\t%d \n", city, min);
		count++;
	}			
}		