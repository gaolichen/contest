#include<stdio.h>
#define N 600000
int n,kard[N];
void run()
{
	int i,a[N],j=1;
	a[0]=kard[0];
	for(i=1;i<n;i++)
		if(kard[i]!=a[j-1])
			a[j++]=kard[i];
	printf("%d\n",j-1);
}
void main()
{
	int i,t,now;
	char ch;
	scanf("%d",&t);
	for(now=0;now<t;now++)
	{
		if(now)printf("\n");
		scanf("%d",&n);
		i=0;
		do
		{
			ch=getchar();
			if(ch=='U')
				kard[i++]=0;
			else if(ch=='D')
				kard[i++]=1;
		}while(i<n);
		run();
	}
}