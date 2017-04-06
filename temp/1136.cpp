#include<stdio.h>
#include<string.h>
int a[20],n,m;
int check(int t)
{
	int i;
	while(t)
	{
		i=t%10;
		t/=10;
		if(!a[i])return 0;
	}
	return 1;
}
void run()
{
	int i,j,t=0;
	if(n%2==0)
	{
		for(i=0;i<10;i+=2)
			if(a[i])break;
		if(i==10)
		{
			printf("0\n");
			return;
		}
	}
	j=1;
	while(j<=n)j*=10;
	t=n;
	do
	{
		t+=n;
		if(check(t))
		{
			printf("%d\n",t);return;
		}
	}while(t<=n*j+n);
	printf("0\n");
}
void main()
{
	int i,j;
	while(scanf("%d",&n)==1)
	{
		memset(a,0,sizeof(a));
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&j);
			a[j]=1;
		}
		run();
	}
}