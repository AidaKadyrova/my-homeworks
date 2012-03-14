#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int n = 0;
	printf("vvedyte nechetnoe chislo n\n");
	scanf("%d", &n);
	srand(time(0));
	int mas[30][30];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mas[i][j] = rand() % 10;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d  ", mas[i][j]);
		printf("\n\n");
	}
	printf("vyvod po spiraly\n\n");
	int r = 0;
	int count = 0;
	int center = n / 2;
	while (center > r)
		{
			r++;
			for (int j = center - r + 1; j < center + r; j++)
				printf("%d ", mas[center - r + 1][j]);			//move right
			for (int j = center - r + 1; j < center + r; j++)
				printf("%d ", mas[j][center + r]);				//move down
			for (int j = center + r; j > center - r; j--)
				printf("%d ", mas[center + r][j]);				//move left
			for (int j = center + r; j >center - r; j--)
				printf("%d ", mas[j][center - r]);				//move up
		}
	r++;
	for (int j = center - r + 1; j < center + r; j++)
		printf("%d ", mas[center - r + 1][j]);					//move right once again
	printf("\n");
	return 0;
}