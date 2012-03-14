#pragma once

struct ListElement;
struct List;

typedef ListElement *Position;

List *createList();
Position first(List *list);
Position next(Position pos, List *list);
void add(List *list, int value);
void printEl(List *list);
void read(FILE *file, List *list);
void deleteList(List *list);
int retrieve(Position pos, List *list);
int lengthOfList(List* list);