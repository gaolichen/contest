#include<stdio.h>
#include <math.h>
#define N 200
int a[N],b[N],mak[N],n;
int prime()
{
	int i,j;
	for(i=2;i<=n;i++)
	   mak[i]=1;
	for(i=2;i<=sqrt(n);i++)
	{
		if(mak[i])
		for(j=i*i;j<=n;j+=i)
			if(mak[j])mak[j]=0;
	}
	for(i=2,j=0;i<=n;i++)
		if(mak[i])
		{
			a[j++]=i;
			mak[i]=j;
		}
	return j;
}
void main()
{
	int i,j,m,pop,k;
	scanf("%d",&n);
	while(n)
	{
		m=prime();
		for(i=0;i<m;i++)
		   b[i]=0;
		pop=-1;
		for(i=2;i<=n;i++)
		{
			if(mak[i]!=0)
			{
				b[mak[i]-1]++;
				pop++;
			}
			else 
			{
				j=pop;
				k=i;
				while(j>=0)
				{
					while(k%a[j]==0)
					{
						k/=a[j];
						b[j]++;
					};
					j--;
				}
			}
		}
		j=0;
		printf("%3d! =",n);
		if(n==1)
			printf("%3d",0);
		else
		for(i=0;i<m;i++)
		{
			if(i&&!(i%15))
			{
				printf("\n");
				printf("      ");
			}
			printf("%3d",b[i]);
		}
		printf("\n");
		scanf("%d",&n);
	}
}