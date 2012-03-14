#pragma once

struct Node;

void create(Node* &node, Node* parent, int x);
void add(Node* &node, int x);//добавл€ем эл-т в мн-во
void remove(Node* &node, int x);//удал€ем эл-т из мн-ва
Node* find(Node* node, int x);
void printUp(Node* node);//печать в возраст пор€дке
void printDown(Node* node);//печать в убывающем пор€дке
void exit(Node* &node);//удал€ем дерево