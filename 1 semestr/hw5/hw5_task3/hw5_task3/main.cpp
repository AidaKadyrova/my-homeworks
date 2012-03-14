#include <stdio.h>
#include <string.h>

typedef struct Tree* tr;


struct Tree
{
	char value;
	tr left;
	tr right;
};

void order(tr &root, char x[])
{
	int i = 0;
		if (x[i] == '(')
		{ 
			i++;
			tr head = new Tree;
			head->left = NULL;
			head->right = NULL;
			//root->value = x[i];
			i++;
			while(x[i] != ')')
			{
			tr temp = new Tree;
			temp->value = x[i];
			temp->left = NULL;
			temp->right = NULL;
			if (head->left == NULL) 
				head->value = temp->value;
			else head->right = temp;
			i++;
			}


		}
}

/*int printList(tr root) 
{
	printf("List: ");
	if (!root) 
		printf("Empty\n"); 
	while (root)
	{
		printf("%d ", root->value);
		root = root->left;
	}
	printf("\n");
	return 0;
}*/



int main()
{
	tr root = NULL;
	char s[80];
	scanf("%s", s);
	order(root, s);
//	int l = strlen(s);
	//for (int i = 0; i < l; i++)
//	{
	//	order(s[i]);
//	}
//	printList(root);
	return 0;
}