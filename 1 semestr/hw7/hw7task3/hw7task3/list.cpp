#include <stdio.h>
#include <string.h>
#include "list.h"

typedef struct List* plst;

struct List
	{
		int value;
		plst next;
		plst prev;
	};

void push(plst &head, int a)
{
	plst newList = new List;
	newList->value = a;
	newList->next = head;
	newList->prev = NULL;
	if(newList->next != NULL)
		newList->next->prev = newList;
	head = newList;
}

void popNext(plst &head)
{
	if (head)
	{	
		List *old = head;
		head = head->next;
		delete(old);
	}	
}

void popPrev(plst &head1)
{
	if (head1)
	{
		List *old = head1;
		head1 = head1->prev;
		delete(old);
	}	
}

int previous(plst &head1)
{
	if (head1->prev)
		return 1;
	else 
		return 0;
}

void goToBegin(plst &head1)
{
	
	while(head1->next)
	head1 = head1->next;
}
int front(List *plst)
{
	if (plst)
		return plst->value;
	else return -1;
}

int priority(char symbol)
{
	if ((symbol == ')') || (symbol == '('))
		return 1;
	if ((symbol == '+') || (symbol == '-'))
		return 2;
	if ((symbol == '*') || (symbol == '/'))
		return 3;
	
	else return 0;
}

int sign(char symbol)
{
	if ((symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/'))
		return 1;
	
	else return 0;
}


int counting(char sign,int a,int b)
{
	int result = 0;
	if (sign == '+')
		result = (b + a);
	if (sign == '-')
		result = (b - a);
	if (sign == '*')
		result = (b * a);
	if (sign == '/')
		result = (b / a);
	return result;
}

void makeOperation(plst &head1,plst &head2)
{
	int a = front(head2);
	popNext(head2);
	int b = front(head2);
	popNext(head2);
	push(head2, counting(front(head1), a, b));
	popPrev(head1);
}