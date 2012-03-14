#include <stdio.h>
#include "list.h"

typedef struct List *plist;

struct List
{
	int degree;
	int factor;
	plist next; 
};

void push(plist &head, int fact, int deg)
{
	plist newList = new List;
	newList->factor = fact;
	newList->degree = deg;
	newList->next = head;
	head = newList;
}

void pop(plist &head)
{
	if (head)
	{	
		List *old = head;
		head = head->next;
		delete(old);
	}	
}

void read(plist &head)
{
	int fact = 0;
	int deg = 1;
	while (deg != 0)
			{
				printf("vvedyte koefficient i stepen,nachinaya so starshego chlena\n");
				scanf("%d%d", &fact, &deg);
				push(head, fact, deg);
			}
}
int deg(int a, int n)
{
	int res = 1;
	while (n)
	{
		if (n % 2 == 1)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}

void equals(plist &p,plist &q)
{
	while(p && q)
		if (p->factor == q->factor)
		{
			pop(p);
			pop(q);
		}
		else
			break;
	if (p || q)
		printf("mnogochleny ne ravny\n\n");
	else 
		printf("mnogochleny ravny\n\n");
}

void value(plist &p, int a)
{
	int result = 0;
	while (p)
	{
		result += p->factor * deg(a, p->degree);
		pop(p);
	}
	printf("p(x0) = %d\n\n", result);
}

void add(plist &p,plist &q,plist &r)
{
	while (p && q)
	{
		push(r,p->factor + q->factor,p->degree);
		pop(p);
		pop(q);
	}
	if (p)
		while (p)
		{
			push(r,p->factor,p->degree);
			pop(p);
		}
	if (q)
	while (q)
	{
		push(r,q->factor,q->degree);
		pop(q);
	}
	printf("r = p + q\nr = ");
	while(r->next)
	{
		printf("%dx^%d + ", r->factor, r->degree);
		pop(r);
	}
	printf("%dx^%d\n\n", r->factor, r->degree);
	pop(r);
}

