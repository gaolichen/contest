#include<stdio.h>
#include<string.h>
int sk[10000],pop,cw[3000][26],cn[26],n,m;
char word[3000][21],str[50][21];
void init()
{
	int i,j;
	memset(cw,0,sizeof(int)*26*n);
	for(i=0;i<n;i++)
		for(j=0;word[i][j]!='\0';j++)
			cw[i][word[i][j]-'A']++;
}
int found(int *cn)
{
	int i;
	for(i=0;i<26;i++)
		if(cn[i])return 0;
	return 1;
}
void print()
{
	int i;
	for(i=0;i<m;i++)
		printf("%s ",str[i]);
	putchar('=');
	for(i=0;i<pop;i++)
		printf(" %s",word[sk[i]]);
	putchar('\n');
}
int check(int *cn,int  k)
{
	int i;
	for(i=0;i<26;i++)
		if(cn[i]<cw[k][i])return 0;
	for(i=0;i<m;i++)
		if(strcmp(word[k],str[i])==0)
			return 0;
	return 1;
}
void run()
{
	int i,j;
	memset(cn,0,sizeof(cn));
	for(i=0;i<m;i++)
		for(j=0;str[i][j]!='\0';j++)
			cn[str[i][j]-'A']++;
	pop=i=0;
	while(pop>=0)
	{
		if(found(cn))
		{
			print();
			pop--;
			if(pop>=0)
			{
				i=sk[pop]+1;
				for(j=0;j<26;j++)
					cn[j]+=cw[i-1][j];
			}
		}
		else if(i==n)
		{
			pop--;
			if(pop>=0)
			{
				i=sk[pop]+1;
				for(j=0;j<26;j++)
					cn[j]+=cw[i-1][j];
			}
		}
		else if(check(cn,i))
		{
			sk[pop++]=i;
			for(j=0;j<26;j++)
				cn[j]-=cw[i][j];
		}
		else i++;
	}
}
void main()
{
	char ch;
	n=0;
	gets(word[n]);
	while(word[n][0]!='#')
	{
		n++;
		gets(word[n]);
	}
	init();
	while(1)
	{
		m=0;
		while(1)
		{
			scanf("%s%c",str[m++],&ch);
			if(ch=='\n')
			break;
		}
		if(str[m-1][0]=='#')break;
		run();
	}
}