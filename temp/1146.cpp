#include<stdio.h>
#include<string.h>
char pic[10][11][23][12],str[20];
int n,s;
void init()
{
	int i,j,size;
	memset(pic,' ',sizeof(pic));
	for(size=1;size<=10;size++)
	{
		for(i=1;i<=size;i++)
			for(j=0;j<10;j++)
			{
			if(j==5||j==6)continue;
			pic[j][size][i][size+1]='|';
			}
		for(i=size+2;i<2*size+2;i++)
		for(j=0;j<10;j++)
		{
			if(j==2)continue;
			pic[j][size][i][size+1]='|';
		}
		for(i=1;i<=size;i++)
		for(j=0;j<10;j++)
		{
			if(j==1||j==4)continue;
			pic[j][size][0][i]='-';
		}
		for(i=1;i<=size;i++)
			for(j=0;j<10;j++)
			{
				if(j==1||j==4||j==7)
					continue;
				pic[j][size][2*size+2][i]='-';
			}
		for(i=1;i<=size;i++)
			for(j=0;j<10;j++)
			{
				if(j==1||j==7||j==0)
					continue;
				pic[j][size][size+1][i]='-';
			}
		for(i=1;i<=size;i++)
			for(j=0;j<10;j++)
			{
				if(j==1||j==2||j==3||j==7)
					continue;
				pic[j][size][i][0]='|';
			}
		for(i=size+2;i<2*size+2;i++)
			for(j=0;j<10;j++)
			{
				if(j==1||j==3||j==4||j==5||j==7||j==9)
					continue;
				pic[j][size][i][0]='|';
			}
	}
}
void run()
{
	int i,j,num[10],tot=0,k;
	for(i=0;str[i]!='\0';i++)
		num[i]=str[i]-'0';
	tot=i;
	for(i=0;i<2*s+3;i++)
	{
		for(j=0;j<tot;j++)
		{
			if(j)
				putchar(' ');
			for(k=0;k<s+2;k++)
			putchar(pic[num[j]][s][i][k]);
		}
		putchar('\n');
	}
}
void main()
{
	int i;
	init();
	n=0;
	scanf("%d%s",&s,str);
	for(i=0;str[i]!='\0';i++)
		n=10*n+str[i]-'0';
	while(s||n)
	{
		run();
		putchar('\n');
		scanf("%d%s",&s,str);
		n=0;
		for(i=0;str[i]!='\0';i++)
			n=10*n+str[i]-'0';
	}
}