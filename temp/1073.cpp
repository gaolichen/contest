#include<stdio.h>
#include<string.h>
#define N 70000
void main()
{
	int i,j,n,f[N];
	f[0]=0;memset(f,0,sizeof(f));
	for(i=0;i<60000;i++)
		for(j=1;i+j*j<=60000;j++)
			if(!f[i+j*j])
				f[i+j*j]=f[i]+1;
	while(scanf("%d",&n)!=-1)
		printf("%d\n",f[n]);
}