#pragma once

struct Hash;

Hash *createHash();

int hash1(char word[]);
bool findWord(Hash *hash, char word[]);
void add(Hash *hash, char word[]);
void print(Hash *hash);
bool letter(char c);