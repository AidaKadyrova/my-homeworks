#include <stdio.h>
#include <string.h>
#include "list.h"
#include "hash.h"

int main()
{
	Hash *hash = createHash();
	int const wordLength = 25;
	char word[wordLength];
		int a =  0;
	scanf("%d", &a);
    FILE *file = fopen("test.txt", "r");
	while (!feof(file))
	{
		char c = fgetc(file);
		if (letter(c))
		{   
			ungetc(c, file);
			fscanf(file, "%s ", word);
			add(hash, word);
		}
	}
	print(hash);
	delete hash;
	fclose(file);
	scanf("%d", &a);
    return 0;
}
