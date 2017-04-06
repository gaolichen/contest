#include<stdio.h>
#include<string.h>
double f[550][550],tot[550];
void run()
{
	int i,j,k;
	memset(f,0,sizeof(f));
	memset(tot,0,sizeof(tot));
	for(i=1;i<=500;i++)
		f[i][i]=1;
	for(i=1;i<500;i++)
		for(j=1;j<=i;j++)
			if(f[i][j]>0)
			for(k=j+1;i+k<=500;k++)
			f[i+k][k]=f[i+k][k]+f[i][j];
	for(i=1;i<=500;i++)
		for(j=1;j<i;j++)
			tot[i]=tot[i]+f[i][j];
}
void main()
{
	int n;
	run();
	scanf("%d",&n);
	while(n)
	{
		printf("%.0lf\n",tot[n]);
		scanf("%d",&n);
	}
}