#include <stdio.h>
#include "list.h"

struct ListElement
{
	int value;
	ListElement *next;
};

struct List
{
	ListElement *head;
};

List *createList()
{
	List *result = new List;
	result->head = NULL;
	return result;
}	

Position first(List *List)
{
	return List->head;
}

Position next(Position pos, List *List)
{
	if (List->head != NULL)
	{
		ListElement* temp = List->head;
		while (temp != pos && temp != NULL)
			temp = temp->next;
		if (temp != NULL)
			return temp->next;
		else 
			return NULL;
	}
	else
		return NULL;
}

void add(List* list, int value)
{
	ListElement *newElement = new ListElement;
	if (list->head == NULL)
	{
	    newElement->next = NULL;
	    newElement->value = value;
	    list->head = newElement;
	}
	else
	{
		newElement->next = list->head;
		newElement->value = value;
        list->head = newElement;
    }	
}

void deleteList(List *list)
{
	ListElement *temp = list->head;
	while (temp != NULL)
	{
		list->head = list->head->next;
		delete temp;
		temp = list->head;
	}
	delete list;
}

int retrieve(Position pos, List *list)
{
	return pos->value;
}

void printEl(List *list)
{
	ListElement *constHead = list->head;
	while (constHead != NULL)
	{
		printf("%d ", constHead->value);
		constHead = constHead->next;
	}
}

void read(FILE *file, List *list)
{
	file = fopen("test.txt", "r");
	int number = 0;
	while (!feof(file))
	{
		fscanf(file, "%d", &number);
		add(list, number);
	}
	fclose(file);
}

int lengthOfList(List* list)
{
	int length = 0;
	Position head = first(list);
	while (head != NULL)
	{
		head = head->next;
		length++;
	}
	return length;
}
