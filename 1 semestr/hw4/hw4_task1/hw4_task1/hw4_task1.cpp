#include <stdio.h>
#include <string.h>

int main()
{
	printf("vvedyte stroki\n");
	char s[80];
	scanf("%s", s); 
	char s1[80];
	scanf("%s",s1);
	if(strlen(s) != strlen(s1))
		printf("ne vozmozhno, dlina razlichna\n");
	else
	{
		int lenth = strlen(s);
		int count[256];
		for (int i = 0; i < 256; i++)
			count[i] = 0;
		for (int i = 0; i < lenth; i++)
		{
			count[s[i]]++;
			count[s1[i]]--;
		}
		bool flag = true;
		for (int i = 0; i < 256; i++)
			if  (count[i] != 0)
			{
			    printf("ne vozmozhno\n");
				flag = false;
				break;
			}
		if (flag) 
			printf("mozhno\n");
	}
	return 0;
}
