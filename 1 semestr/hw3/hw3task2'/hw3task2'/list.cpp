#include "list.h"
#include <stdio.h>

typedef struct List *plst;

struct List
{
	int value;
	plst next;
};

plst createList()
{
	plst tmp = new List;
	tmp->value = 0;
	tmp->next =	NULL;
	return tmp;
}

plst createListCount(int count)
{
	plst head = createList();
	plst tmp = head;
	for (int i = 0; i < count; i++)
	{
		tmp->next = createList();
		tmp = tmp->next;
		tmp->value = i + 1;
	}
	tmp->next = head->next;
	return head;
}

void delList(plst l)
{
	plst tmp = l;
	while (tmp && tmp != tmp->next)
	{
		plst t = tmp->next;
		delete tmp;
		tmp = t;
	}
	if (tmp)
		delete tmp;
}

void printList(plst head)
{ 
	plst tmp = head;
	while(tmp = tmp->next)
		printf("%d ", tmp->value);
}	

void del(plst el)
{
	int num = el->next->value;
	plst tmp = el->next->next;
	delete el->next;
	el->value = num;
	el->next = tmp;
}

int doCount(plst head, int k, int count)
{
	int j = count;
	plst tmp = head->next;
	while (j > 1)
	{
		for (int i = 0; i < k; i++)
			tmp = tmp->next;
		del(tmp);
		j--;
	}; 

	head->next = tmp;
	return tmp->value;
}
int runCount(plst head, int i, int count)
{
	int k = 1;
	plst h = head;
	while(true)
	{
		delList(h);
		h = NULL;
		h = createListCount(count);
		int j = doCount(h, k, count);

		if (j == i)
		{
			printf("nyzhno udalyat' kazhdy %d element\n", k);
			break;
		}
		k++;
	}
	return k;
}

