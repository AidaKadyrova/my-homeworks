#include <stdio.h>
#include "hash.h"

#include <string.h>

int const hashLength = 1000;

struct Hash
{
	List *h[hashLength];
};

Hash *createHash()
{
	Hash *result = new Hash;
	for (int i = 0; i < hashLength; i++)
	    result->h[i] = NULL;
	return result;
}

bool letter(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return 1;
	else return 0;
}

int hash1(char word[],int length)
{
	int result = 0;
	for (int i = 0; i < length; ++i)
		if (letter(word[i]))
			result = (result + word[i]) % hashLength;
	return result;
}

bool findWord(Hash *hash, char word[], int length)
{
	if (strcmp(hash->h[hash1(word)]->string, word) == 0)
		return 1;
	else if (hash->h[hash1(word)]->next != NULL)
		return strcmp(hash->h[hash1(word)]->next->string, word) == 0;
}

void add(Hash *hash, char word[], int length)
{
	int const hashValue = hash1(word);
	if (hash->h[hashValue] == NULL)
	{
		hash->h[hashValue] = new List();
		strcpy(hash->h[hashValue]->string, word);
		hash->h[hashValue]->next = NULL;	
		return;
	}
	else
	{
	List *temp = hash->h[hashValue];
	bool same = findWord(hash, word, length);
		if (!same)
		{
			List *list = new List();
			strcpy(list->string, word);
			list->next = NULL;
			temp->next = list;
		}
	}
}

