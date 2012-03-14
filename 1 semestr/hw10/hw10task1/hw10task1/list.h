#pragma once

typedef struct List *plist;

struct List;

void push(plist &head, int fact, int deg);
void pop(plist &head);
void read(plist &head);
int deg(int a, int n);
void equals(plist &p,plist &q);
void value(plist &p, int a);
void add(plist &p,plist &q,plist &r);
