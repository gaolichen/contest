#include <stdio.h>
#include <math.h>
#define N 1000000
int array[N+1];
int prime(int i,int j)
{
	int k;
	do
	{
		k=i%j;
		i=j;
		j=k;
	}while(k);
	return i;
}
void main()
{
	int j,sq,k;
	long n,a,b,c,t,i,num,nump;
	while(scanf("%ld",&n)==1)
	{
		sq=(int)sqrt(n);
		num=nump=0;
		for(i=1;i<=n;i++)
		    array[i]=0;
		for(i=2;i<=sq;i++)
		{
			if(i%2)j=2;
			else j=1;
				for(;j<i;j=j+2)
				{
				if((c=i*i+j*j)>n)break;
				a=i*i-j*j;
				b=2*i*j;
				if(prime(c,a)==1)
				nump++;
				t=(int)n/c;
				for(k=1;k<=t;k++)
				{
				if(!array[k*a])
				{array[k*a]=1;num++;}
				if(!array[k*b])
				{array[k*b]=1;num++;}
				if(!array[k*c])
				{array[k*c]=1;num++;}
				}
				}
		}
		printf("%ld %ld\n",nump,n-num);
	}
}