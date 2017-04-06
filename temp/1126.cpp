#include<stdio.h>
#include<string.h>
int n,count,tot[26],gen[10010][10];
char name[100];
void run()
{
	int i,j,max;
	printf("     %s\n",name);
	for(i=0;i<count;i++)
	{
		memset(tot,0,sizeof(tot));
		max=1;
		for(j=0;j<n;j++)
		{
			tot[gen[i][j]]++;
			if(tot[gen[i][j]]>=tot[max])
				max=gen[i][j];
		}
		for(j=0;j<n;j++)
			if(gen[i][j]!=max)break;
		if(j==n)continue;
		printf("%4d ",i+1);
		for(j=0;j<n;j++)
		{
			if(gen[i][j]!=max)
				printf("        *");
			else if(j!=n-1) 
				printf("         ");
		}
		putchar('\n');
	}
}
void cutname()
{
	int i,flag=0;
	n=0;
	for(i=0;name[i]!='\0';i++)
	{
		if(name[i]!=' '&&!flag)
			flag=1;
		if(name[i]==' '&&flag)
		{
			n++;flag=0;
		}
	}
	if(flag)n++;
}
void init(char *str)
{
	int i,j=0;
	for(i=0;str[i]!='\0';i++)
		if(str[i]!=' ')
			gen[count][j++]=str[i]-'A';
	count++;
}
void main()
{
	int flag;
	char str[80];
	printf("Program 7 by team X\n");
	while(1)
	{
		flag=0;
		if(gets(name)==0)break;
		while(name[0]=='\0')
			if(gets(name)==0)
			{
				flag=1;break;
			}
		if(flag)break;
		cutname();
		count=0;
		while(gets(str))
			init(str);
		run();
	}
	printf("End of program 7 by team X\n");
}