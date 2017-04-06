#include<stdio.h>
#include<string.h>
char pic[50][50],let[5][50][50];
int w,h;
int check(char *sk)
{
	int i,j,k,t;
	char pp[50][50];
	memset(pp,'.',sizeof(pp));
	for(i=0;i<5;i++)
	{
		t=sk[i]-'A';
		for(j=0;j<h;j++)
			for(k=0;k<w;k++)
				if(let[t][j][k]!='.')
					pp[j][k]=let[t][j][k];
	}
	for(i=0;i<h;i++)
		for(j=0;j<w;j++)
			if(pp[i][j]!=pic[i][j])
				return 0;
	return 1;
}
void run()
{
	char mark[5],sk[10];
	int i,j,k;
	int pop,minh[5],maxh[5],minw[5],maxw[5];
	memset(let,'.',sizeof(let));
	memset(mark,0,sizeof(mark));
	for(i=0;i<5;i++)
	{
		minh[i]=2000;maxw[i]=0;
		maxh[i]=0;minw[i]=2000;
		for(j=0;j<h;j++)
			for(k=0;k<w;k++)
				if(pic[j][k]=='A'+i)
				{
					let[i][j][k]='A'+i;
					if(j<minh[i])minh[i]=j;
					if(j>maxh[i])maxh[i]=j;
					if(k<minw[i])minw[i]=k;
					if(k>maxw[i])maxw[i]=k;
				}
	}
	for(i=0;i<5;i++)
	{
		for(j=minw[i];j<=maxw[i];j++)
		{
			let[i][minh[i]][j]='A'+i;
			let[i][maxh[i]][j]='A'+i;
		}
		for(j=minh[i];j<=maxh[i];j++)
		{
			let[i][j][minw[i]]='A'+i;
			let[i][j][maxw[i]]='A'+i;
		}
	}
	pop=0;i='A';
	while(pop>=0)
	{
		if(pop==5)
		{
			sk[pop]='\0';
			if(check(sk))
				puts(sk);
			pop--;
			i=sk[pop]+1;
			mark[i-1-'A']=0;
		}
		else if(i=='F')
		{
			pop--;
			if(pop>=0)
			{
				i=sk[pop]+1;
				mark[i-1-'A']=0;
			}
		}
		else if(!mark[i-'A'])
		{
			sk[pop]=i;
			pop++;
			mark[i-'A']=1;
			i='A';
		}
		else i++;
	}
}
void main()
{
	int i;
	while(scanf("%d%d",&h,&w)!=-1)
	{
		for(i=0;i<h;i++)
			scanf("%s",pic[i]);
		run();
	}
}