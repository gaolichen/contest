#include<stdio.h>
#include<string.h>
#define N 10000
int open,close,sk[12][N],tot,op[N],nl[N],ol[N];
int rec[12][N][2],n,x[12],y[12];
int same(int k,int t,int s)
{
	int i;
	for(i=0;i<tot;i++)
		if(t==rec[k][i][0]&&s==rec[k][i][1])
			return 1;
	return 0;
}
int check(int k)
{
	int i,t;
	for(i=0;i<n;i++)
	{
		switch(k)
		{
		case 1:t=sk[i][open]+sk[i][nl[open]];break;
		case 2:t=sk[i][nl[open]]-sk[i][open];break;
		case 3:t=sk[i][open]*sk[i][nl[open]];break;
		case 4:if(sk[i][open]==0)return 0;
			t=sk[i][nl[open]]/sk[i][open];break;
		case 5:t=sk[i][open];break;
		}
		if(same(i,sk[i][open],t))return 0;
		rec[i][tot][0]=sk[i][open];
		rec[i][tot][1]=t;
	}
	tot++;
	return 1;
}
void f(int k)
{
	int i;
	for(i=0;i<n;i++)
	{
		switch(k)
		{
		case 1:sk[i][close]=sk[i][open]+sk[i][nl[open]];break;
		case 2:sk[i][close]=sk[i][nl[open]]-sk[i][open];break;
		case 3:sk[i][close]=sk[i][open]*sk[i][nl[open]];break;
		case 4:sk[i][close]=sk[i][nl[open]]/sk[i][open];break;
		case 5:sk[i][close]=sk[i][open];break;
		}
	}
	nl[close]=open;
//	putchar('a');
}
int ok()
{
	int i;
	for(i=0;i<n;i++)
		if(sk[i][close]!=y[i])return 0;
	return 1;
}
void print()
{
	int i=0,j;
	char opt[15][10];
	do
	{
		j=op[close];
		switch(j)
		{
		case 1:strcpy(opt[i++],"ADD");break;
		case 2:strcpy(opt[i++],"SUB");break;
		case 3:strcpy(opt[i++],"MUL");break;
		case 4:strcpy(opt[i++],"DIV");break;
		case 5:strcpy(opt[i++],"DUP");break;
		}
		close=ol[close];
	}while(close);
	for(j=i-1;j>=0;j--)
		printf("%s ",opt[j]);
}
void run()
{
	int i,onum[10000];
	tot=0;
	for(i=0;i<n;i++)
		if(x[i]!=y[i])
			break;
	if(i==n)
	{
		printf("Empty sequence\n");
		return ;
	}
	open=close=1;
	for(i=0;i<n;i++)
	{
		sk[i][1]=sk[i][0]=x[i];
		rec[i][tot][0]=rec[i][tot][1]=x[i];
	}
	tot++;
	nl[1]=0;
	nl[0]=-1;
	op[1]=5;op[0]=-1;onum[1]=1;
	while(open<=close&&onum[open]<10)
	{
//		printf("%d %d\n",open,ol[open]);
		for(i=1;i<=5;i++)
			if(check(i))
			{
				op[++close]=i;
				ol[close]=open;
				onum[close]=onum[open]+1;
				printf("%d %d\n",close,onum[close]);
				f(i);
			}	
		if(ok())
		{
			print();
			return;
		}
		open++;
	}
	printf("Impossible\n");
}
void main()
{
	int i,count=0;
	scanf("%d",&n);
	while(n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&x[i]);
		for(i=0;i<n;i++)
			scanf("%d",&y[i]);
		printf("Program %d\n",++count);
		run();
		printf("\n");
		scanf("%d",&n);
	}
}