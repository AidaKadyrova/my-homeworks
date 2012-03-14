#include <stdio.h>
#include <string.h>
#include "hash.h"

/*int hash(char s[])
{
	int result = 0;
	int length = strlen(s);
	for (int i = 0; i < length; i++)
		result = (result + s[i]) % 100;
	return result;
}*/
int main()
{
	Hash *hash = createHash();
	FILE *file1 = fopen("input1.txt","r");
	int const dim = 256;
	int const sizeHash = 100;
	char s[dim];
	bool h[sizeHash];
	while (!feof(file1))
	{
		
		fgets(s, 256, file1);
		int length = strlen(s);
		add(hash, s, length );
	}
	fclose(file1);
	FILE *file2 = fopen("input2.txt","r");
	FILE *file3 = fopen("output.txt","w");
	while (!feof(file2))
	{
		fgets(s, sizeHash, file2);
		int length = strlen(s);
		if (findWord(hash, s, length))
		fprintf(file3,"%s", s);
	}
	fclose(file2);
	fclose(file3);
	return 0;
}