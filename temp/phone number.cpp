#include<stdio.h>
#include<string.h>
#define N 50000
#define MAX 21000000
int pre[26]={2,2,2,3,3,3,4,4,1,1,5,5,6,6,0,7,0,
		7,7,8,8,8,9,9,9,0};
int s;
char num[20],word[N][50];
int fit(int i,int j)
{
	int k;
	k=0;
	while(pre[word[i][k]-'a']==num[j]-'0')
	{
		k++;j++;
	}
	if(word[i][k]=='\0'){s=j;return 1;}
	else return 0;
}
void main()
{
	int i,j,k,min,pop,pho[50],sk[50],n;
	char buf[80];
	for(i=0;i<=9;i++)
	{
		printf("%d ",i);
	   for(j=0;j<26;j++)
		   if(pre[j]==i)
			   printf("%c",'a'+j);
		   printf("\n");
	}
	gets(num);
	while(num[0]!='-')
	{
		scanf("%d",&n);
		gets(buf);
		for(i=0;i<n;i++)
		{gets(word[i]);}
		min=MAX;
		pop=i=0;j=0;
		while(pop>=0)
		{
			if(num[j]=='\0')
			{
				if(pop<min)
				{
					min=pop;
					for(k=0;k<pop;k++)
					pho[k]=sk[k];
				}
				pop--;
				i=sk[pop]+1;
				j-=strlen(word[i-1]);
			}
			else if(i==n||pop>=min)
			{
				pop--;
				if(pop>=0)
				{
				i=sk[pop]+1;
				j-=strlen(word[i-1]);
				}
			}
			else if(fit(i,j))
			{
				sk[pop]=i;
				pop++;
				j+=strlen(word[i]);
				i=0;
			}
			else i++;
		}
		if(min!=MAX)
		{
			for(i=0;i<min;i++)
			{
				j=pho[i];
			for(k=0;word[j][k]!='\0';k++)
				printf("%c",word[j][k]);
			if(i!=min-1)printf(" ");
			}
			printf("\n");
		}
		else printf("No solution.\n");
		gets(num);
	}
}