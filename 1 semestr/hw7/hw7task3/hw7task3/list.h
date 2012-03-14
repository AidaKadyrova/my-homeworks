#pragma once

typedef struct List* plst;

struct List;

void push(plst &head, int a);
void popNext(plst &head);
void goToBegin(plst &head1);
int previous(plst &head1);
void popPrev(plst &head1);
int front(List *plst);
int priority(char symbol);
int sign(char symbol);
int counting(char sign,int a,int b);
void makeOperation(plst &head1,plst &head2);