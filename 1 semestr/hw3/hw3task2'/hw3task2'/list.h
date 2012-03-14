#pragma once

struct List;

typedef struct List *plst;

plst createList();
plst createListCount(int count);//
void printList(plst head);//
void del(plst elem);//
void delList(plst l);//
int doCount(plst head, int k, int count);//
int runCount(plst head, int i, int count);//