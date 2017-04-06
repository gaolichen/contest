#include<stdio.h>
void main()
{
	int i,t,j;
	char buf[80];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%s",buf);
		printf("String #%d\n",i+1);
		for(j=0;buf[j]!='\0';j++)
		{
			if(buf[j]=='Z')
				putchar('A');
			else putchar(buf[j]+1);
		}
		putchar('\n');
		putchar('\n');
	}
}