#include<stdio.h>
#define N 1000
#define M 2100000000
int h[N],n,k,f[N][N],m[N][N][2];
void run()
{
	int i,j,t,temp,temp1,temp2;
	for(i=0;i<n;i++)
	{
		f[0][i]=0;
		f[i+1][0]=M;
	}
	for(i=1;i<=k;i++)
	{
		f[1][i]=0;
		m[1][i][0]=m[1][i][1]=0;
	}
	m[1][1][h[1]]=1;
	for(i=2;i<=n;i++)
		for(j=1;j<=k;j++)
		{
			m[i][j][0]=m[i][j][1]=0;
			f[i][j]=M;
			if(f[i-1][j-1]<f[i][j])
			{
				f[i][j]=f[i-1][j-1];
				m[i][j][h[i]]=1;
			}
			t=i-m[i-1][j][0]-m[i-1][j][1]-1;
				if(h[i])
				{
					temp1=m[i-1][j][1]+1;
					temp2=m[i-1][j][0];
				}
				else 
				{
					temp1=m[i-1][j][1];
					temp2=m[i-1][j][0]+1;
				}
				temp=temp1*temp2;
				if(f[t][j-1]+temp<f[i][j])
				{
					f[i][j]=f[t][j-1]+temp;
					m[i][j][1]=temp1;
					m[i][j][0]=temp2;
				}
		}
	printf("%d\n",f[n][k]);
}
void main()
{
	int i;
	while(scanf("%d%d",&n,&k)==2)
	{
		for(i=0;i<n;i++)
  		scanf("%d",&h[i+1]);
		run();
	}
}