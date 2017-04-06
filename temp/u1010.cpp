#include<stdio.h>
#define N 150000
void main()
{
	int i,f[N],best,n;
	while(scanf("%d",&n)==1)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&f[i]);
		best=1;
		for(i=2;i<n;i++)
			if(f[i+1]-f[i]>f[best+1]-f[best])
				best=i;
		printf("%d %d\n",best,best+1);
	}
}