#include <stdio.h>

int variant(int n, int var[])
{
	int k = var[n];
	while (k > 3)
	{
		k = variant(var[n], var);
	}
	return k;
}
int main()
{
	const int stud = 100;
	int var[stud];
	int num = 0;
	int amount = 0;
	int k = 0;
	FILE *file = fopen("input.txt","r");
	fscanf(file, "%d", &amount);
	for (int i = 0; i < amount; i++)
		var[i] = 0;
	while (!feof(file))
	{
		fscanf(file, "%d%d", &num, &k);
		var[num] = k;
	}
	for (int i = 1; i <= amount; i++)
		if (var[i] != 0)
			printf("%d %d\n", i, variant(i, var));
		else
			printf("%d studenta nado otchislit'\n", i);
	fclose(file);
	
	return 0;
}