#include <stdio.h>
#include "node.h"
#include <locale.h>

void operations()
{
	printf("�������� ��������:\n 1 - �������� �������� � ���������\n");
	printf(" 2 - ������� �������� �� ���������\n");
	printf(" 3 - ���������, ����������� �� �������� ���������\n");
	printf(" 4 - ���������� ������� �������� ��������� � ������������ �������\n");
	printf(" 5 - ���������� ������� �������� ��������� � ��������� �������\n");
	printf(" 0 - ����� �� ���������\n" );
}

int main()
{	
	setlocale(LC_ALL, "Rus");
	Node* root = NULL;
	int operation = 0;
	int el = 0;
	operations();
	while (true)
	{
	    printf("�������� ��������: ");
	    scanf("%d", &operation);
		switch (operation)
		{
		    case 1:
	        {
	            printf("������� ��������\n");
	            scanf("%d", &el);
	            add(root, el);
			    break;
	        }
		    case 2:
	        {
		        printf("������� ��������\n");
	            scanf("%d", &el);
			    remove(root, el);
			    break;
	        }
		    case 3:
	        {
		        printf("������� ��������\n");
	            scanf("%d", &el);
		        if (find(root, el) != NULL)
			        printf("������� ����������� ���������\n");
				else
			        printf("������� �� ����������� ���������\n");
			    break;
	        }
		    case 4:
		    {
		        printUp(root);
				break;
		    }
		    case 5:
		    {
			    printDown(root);
			    break;
			}
		    case 0:
		    {
			    exit(root);
			    return 0;
				break;
		    }
		}
	}
}