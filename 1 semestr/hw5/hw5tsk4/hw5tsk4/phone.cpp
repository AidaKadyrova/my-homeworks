#include <stdio.h>
#include "phone.h"
#include <string.h>

struct Phone 
{
	char *name;
	int number;
	Phone *next;
};

void createContact(Phone *ph, char name[], int number )
{
		ph->name = strdup(name);
		ph->number = number;
		ph->next = NULL;
}
void addContact(char name[], int number, Phone *&list)
{
	if (list == NULL)
	{
		list = new Phone;
		createContact(list, name, number);
	}
	else
	{
		Phone *t = list;
		while (t->next)
			t = t->next;
		Phone *p = new Phone;
		t->next = p;
		createContact(p, name, number);
	}
}

void searchByName(char name[], Phone *list)
{
	Phone *p = list;
	while(p)
	{
		if (strcmp(p->name, name) == 0)
		{
			printf("%d\n", p->number);
			return;
		}
		else
			p = p->next;
    }
    printf("No contact!\n");
}

void searchByNumber(int number, Phone *list)
{
    Phone *p = list;
    while(p)
	{
		if (p->number == number)
		{
			printf("%s\n", p->name);
			return;
		}
		else
			p = p->next;
	}
	printf("No contact!\n");
}
	
void save(Phone *list)
{
	FILE *file = fopen("spravochnik.txt", "w");
	Phone *p = list;
	while(p)
	{
		fprintf(file, "%s %d\n", p->name, p->number);
		p = p->next;
	}
	fclose(file);
}

void exit(Phone *list)
{
    if (list->next)
    exit(list->next);
	delete list;
}

void open(Phone *&list)
{
	int const size = 30;
	FILE *file = fopen("spravochnik.txt", "r");
	if (!file)
		return;
	while(!feof(file))
	{
		int number = 0;
		char name[size];
		fscanf(file, "%s %d\n", name, &number);
		addContact(name, number, list);
	}
	fclose(file);
}

