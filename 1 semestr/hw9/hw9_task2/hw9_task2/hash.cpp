#include <stdio.h>
#include "hash.h"
#include <string.h>

int const dim = 1000;

int hash(char s[], int lenght)
{
	int hash = 0;
	int d = 1;
	for ( int i = lenght - 1; i >= 0; i--)
	{
		hash += s[i] * d;
		d *= 13;
	}
	return (hash % dim);

}
void find(char s1[], char s2[])
{
	int h2 = hash(s2, strlen(s2));
	int i = 0;
	int count = 0;
	int h1 = hash(s1, strlen(s2));
	int m = strlen(s1);
	int n = strlen(s2);
	while (i <= m - n)
	{
		if (h1 == h2)
			count++;
		int diff = s1[i];
		for (int j = 0; j < n - 1; j++)
			diff *= 13;
		diff = diff % dim;
		h1 = ((((h1 - diff + dim) * 13) % dim + s1[i + n]) % dim);
		i++;
	}
	printf("%d\n", count);
}