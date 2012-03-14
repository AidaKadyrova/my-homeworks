#include <stdio.h>
#include "list.h"

List* merge(List* newList1, List* newList2)
{
	Position head1 = first(newList1);
	Position head2 = first(newList2);
	List* newList = createList();
	while (head1 != NULL && head2 != NULL)
	{
		if (retrieve(head1, newList1) <= retrieve(head2, newList2))
		{
			add(newList, retrieve(head1, newList1));
			head1 = next(head1, newList1);
		}
		else
		{
			add(newList, retrieve(head2, newList2));
			head2 = next(head2, newList2);
		}
	}
	if (head2 == NULL)
		while (head1 != NULL)
		{
			add(newList, retrieve(head1, newList1));
			head1 = next(head1, newList1);
		}
	if (head1 == NULL)
		while (head2 != NULL)
		{
			add(newList, retrieve(head2, newList2));
			head2 = next(head2, newList2);
		}
	deleteList(newList1);
	deleteList(newList2);
	List* newNewList = createList();
	head1 = first(newList);
	while (head1 != NULL)
	{
		add(newNewList, retrieve(head1, newList));
		head1 = next(head1, newList);
	}
	deleteList(newList);
	return newNewList;
}

List* mergeSort(List* list)
{
	List* newList1 = createList();
	List* newList2 = createList();
	int length = lengthOfList(list);
	if (length != 1)
	{
		Position temp = first(list);
		for (int i = 1; i <= length/2; ++i)
		{
			add(newList1, retrieve(temp, list));
			temp = next(temp, list);
		}
		for (int i = length/2 + 1; i <= length; ++i)
		{
			add(newList2, retrieve(temp, list));
			temp = next(temp, list);
		}
		list = merge(mergeSort(newList1), mergeSort(newList2));
	}
	return list;
}

int main()
{
	List* procedure = createList();
	FILE *file = fopen("input.txt","r");
	read(file, procedure);
	fclose(file);
    printEl(mergeSort(procedure));
	printf("\n");
	return 0;
}