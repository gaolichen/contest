#include<stdio.h>
#define N 10000
int a[6]={-1,-1,0,1,0,1};
int b[6]={0,1,-1,-1,1,0};
int mc[2],c[2],rq[N][2],last[N],way[N];
int open,close;
void run(int i,int j)
{
	int temp;
	c[0]=rq[open][0];
	c[1]=rq[open][1];
	if(i==-1)
		c[j]=mc[j];
	else if(j==-1)
		c[i]=0;
	else
	{
	    c[j]+=c[i];temp=c[j];
	    if(c[j]>mc[j])
		  c[j]=mc[j];
	    c[i]=temp-c[j];
	}
}
int same(int i)
{
	if(rq[i][0]==c[0]&&rq[i][1]==c[1])
		return 1;
	else return 0;
}
void mycopy(int i)
{
	rq[i][0]=c[0];
	rq[i][1]=c[1];
}
void print(int i)
{
	int t[N],j=0;
	do
	{
		t[j++]=way[i];
		i=last[i];
	}while(i);
	for(i=j-1;i>=0;i--)
		switch(t[i])
	{
		case 0:printf("fill A\n");break;
		case 1:printf("fill B\n");break;
		case 2:printf("empty A\n");break;
		case 3:printf("empty B\n");break;
		case 4:printf("pour A B\n");break;
		case 5:printf("pour B A\n");break;
	}
	printf("success\n");
}
void main()
{
	int i,j,n,find;
	while(scanf("%d%d%d",&mc[0],&mc[1],&n)==3)
	{
		find=0;
		open=close=0;
		rq[0][0]=rq[0][1]=0;
		while(open<=close&&!find)
		{
			for(i=0;i<6;i++)
			{	
				run(a[i],b[i]);
				for(j=0;j<=close;j++)
					if(same(j))
					break;
				if(j>close)
				{
					mycopy(j);
					close++;
				last[close]=open;
					way[close]=i;
				}
				if(c[1]==n)
				{
			        print(close);
			        find=1;
					break;
				}
			}
			open++;
		}
	}
}