#include <stdio.h>

int main()
{
	int n = 6;
	int a = 0;
	int count[100];for (int i = 0; i <100; i++)
	for (int i = 0; i < 100; 
		count[i] = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		count[a]++;
	}
	for (int i = 0; i <100, i++)
		printf("%d", count[i]);
	int max = 0;
	for (int i = 99; i > 0 ; i--)
		if (count[i] > 1 && max < i)
		{
			max = i;
			break;
		}
	printf("%d", max);
	return 0;
}