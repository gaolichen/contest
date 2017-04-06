#include<stdio.h>
int n,w[2000];
void mysort()
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
			if(w[j]<w[j+1])
			{
				temp=w[j];
				w[j]=w[j+1];
				w[j+1]=temp;
			}
	}
}
int found(int t,int *mid)
{
	int sta,end,find=0;
	sta=0;end=n-1;	
	if(t>w[0])
	{
		*mid=0;
		return 0;
	}
	if(t<w[n-1])
	{
		*mid=n;
		return 0;
	}
	while(sta<end-1&&find==0)
	{
		*mid=(sta+end)/2;
		if(w[*mid]==t)find=1;
		else if(w[*mid]>t)
			sta=*mid;
		else end=*mid;
	}
	if(!find)
	{
		if(w[sta]==t)find=1;
		else if(w[end]==t)find=1;
	}
	return find;
}
void run()
{
	int i,j,k,st,en,s,t;
	mysort();
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-2;j++)
		if(j!=i)
		{
			found(w[i]-w[j]-w[n-1],&st);
			found(w[i]-w[j]-w[0],&en);
			if(en<n-1)en++;
			if(st<j)st=j;
			for(k=st;k<=en;k++)
			if(k!=j&&k!=i)
			{
				t=w[i]-w[j]-w[k];
				if(t>=w[k])break;
				if(t!=w[i]&&t!=w[j]&&t!=w[k]&&found(t,&s))
				{
					printf("%d\n",w[i]);
					return;
				}
			}
		}
	}
	printf("no solution\n");
}
int main()
{
	int i;
	scanf("%d",&n);
	while(n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&w[i]);
		run();
		scanf("%d",&n);
	}
	return 0;
}