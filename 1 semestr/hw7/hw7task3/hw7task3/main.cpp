#include <stdio.h>
#include <string.h>
#include "list.h"

int main()
{
	char infix[20];
	gets(infix);
	int length = strlen(infix); 
	plst head = NULL;	// временный стек
	plst head1 = NULL;	// основной стек
	plst head2 = NULL;	// расчетный стек
	for (int i = 0; i < length; i++)
	{
		if (!priority(infix[i]))   
			push(head1, infix[i]); 
		else                       
		{
			if ((head == NULL) || (priority(infix[i]) > priority(front(head))) || infix[i] == '(')
				push(head, infix[i]); 
			else
			{ 
				while (head != NULL && priority(infix[i]) <= priority(front(head)))
				{
					if (front(head) != '(')
						push(head1, front(head));
						popNext(head);
				}
				if (infix[i] != ')')
				push(head,infix[i]);
			}
		}
	}
	while (head != NULL)
	{
		push(head1, front(head));
		popNext(head);
	}
	goToBegin(head1);
	
    while (previous(head1))
	{	
		if (!sign(front(head1)))
		{
			push(head2, front(head1)-'0');
			popPrev(head1);
		}
		else 
			makeOperation(head1,head2);	
	}		
	makeOperation(head1,head2);
	printf("result = ");
	printf("%d\n",front(head2));
	return 0;
}