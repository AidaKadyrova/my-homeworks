#pragma once

struct List
{
	char string[256];
	List *next;
};

struct Hash;

Hash *createHash();

int hash1(char word[]);
bool findWord(Hash *hash, char word[], int length);
void add(Hash *hash, char word[], int length);
bool letter(char c);