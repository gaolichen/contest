#include<stdio.h>
#define N 1000
int stackl[N],stackn[N],mark[N];
int popl,popn;
int sum()
{
	int i,s=0;
	for(i=popl;i>=0;i--)
	{
		s+=stackn[stackl[i]];
	    mark[stackl[i]]=1;
	}
	popl--;
	return s;
}
void main()
{
	char ch;
	int num,n,i,find,sumtree,flag;
	while(scanf("%d",&n)==1)
	{
		popl=popn=-1;
		find=num=i=0;
	do
	{
		ch=getchar();
		if(ch=='(')
		{
			popl++;
			stackl[popl]=-1;
			num=0;
		}
		else if(ch<='9'&&ch>='0'||ch=='-')
		{
			if(num==0)
			{
				popn++;
				stackl[popl]=popn;
				mark[popn]=0;
				num=1;
				stackn[popn]=0;
				if(ch=='-')flag=1;
				else 
				{
					stackn[popn]=ch-'0';
				    flag=0;
				}
			}
		    else if(flag)
			stackn[popn]=stackn[popn]*10-ch+'0';
			else
			stackn[popn]=stackn[popn]*10+ch-'0';
		}
		else if(ch==')')
		{
		 i=stackl[popl];
		 if(!find&&!mark[i]&&i!=-1) 
		 {
			sumtree=sum();
			if(sumtree==n)find=1;
		 }
		 else popl--;
		}
	}while(popl>-1||ch!=')');
	if(find==1)
		printf("\nyes\n");
	else printf("\nno\n");
	}
}