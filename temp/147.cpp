#include<stdio.h>
#define N 1100
int a[11]={1,2,4,10,20,40,100,200,400,1000,2000};
void main()
{
	int i,j,k,n,t;
	double f[11][N];
	float m;
	scanf("%f",&m);
	while(m!=0)
	{
		n=(int)(m*20.0000001);
		t=0;
		while(a[t]<=n)t++;
		for(i=0;i<11;i++)
			for(j=0;j<=n;j++)
				f[i][j]=0;
		for(i=0;i<=n;i++)
			f[0][i]=1;
		for(i=1;i<=t;i++)
			for(j=0;j<=n;j++)
				for(k=0;k<=j/a[i];k++)
				f[i][j]+=f[i-1][j-k*a[i]];
		printf("%5.2f%12.0lf\n",m,f[t][n]);
		scanf("%f",&m);
	}
}