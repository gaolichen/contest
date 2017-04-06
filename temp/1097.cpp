#include<stdio.h>
#include<string.h>
int tree[200],son[200],mark[200][200];
void run(char *str)
{
	int i,j,min,t=0,len,n=0;
	int sk[200],sk1[200],pop,pop1;
	len=strlen(str);
	j=0;
	for(i=0;i<len;i++)
	{
		if(str[i]=='(')
		{
			if(t)
			{
				tree[j++]=t;
				if(t>n)n=t;
				t=0;
			}
			tree[j++]=-1;
		}
		else if(str[i]==')')
		{
			if(t)
			{
				tree[j++]=t;
				if(t>n)n=t;
				t=0;
			}
			tree[j++]=-2;
		}
		else if(str[i]!=' ')
			t=10*t+str[i]-'0';
	}
	len=j;
	memset(son,0,sizeof(int)*n+1);
	memset(mark,0,sizeof(mark));
	pop=pop1=0;
	for(i=0;i<len;i++)
	{
		if(tree[i]==-1)
			sk1[pop1++]=tree[i];
		else if(tree[i]==-2)
		{
			pop1--;
			pop--;
			if(pop)
			{
				mark[sk[pop-1]][sk[pop]]=1;
				mark[sk[pop]][sk[pop-1]]=1;
				son[sk[pop-1]]++;
				son[sk[pop]]++;
			}
		}
		else sk[pop++]=tree[i];
	}
	for(j=0;j<n-1;j++)
	{
	min=n+1;
	for(i=1;i<=n;i++)
		if(son[i]==1)
		{
			min=i;
			break;
		}
	son[min]--;
	for(i=1;i<=n;i++)
		if(i!=min&&son[i]&&mark[i][min])
		{t=i;break;}
	son[i]--;
	if(j)putchar(' ');
	printf("%d",t);
	}
	putchar('\n');
}
void main()
{
	char str[500];
	while(gets(str))run(str);
}