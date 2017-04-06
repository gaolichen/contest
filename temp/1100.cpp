#include<stdio.h>
#include<string.h>
int p[13]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096};
int m,n,now;
double a[12][10000];
void put(int i,int j,int k)
{
	while(j&p[k])k++;
	if(k>=m)
	{

		a[i][now]+=a[i-1][j];
		return;
	}
	now+=p[k];
	put(i,j,k+1);
	now-=p[k];
	if(k<m-1&&!(j&p[k+1]))
		put(i,j,k+2);
}
void run()
{
	int i,j;
	if(m>n)
	{
		i=n;n=m;m=i;
	}
	memset(a,0,sizeof(a));
	a[0][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<p[m+1];j++)
			if(a[i-1][j]>0)
			{
				now=0;
				put(i,j,0);
			}
	}
	printf("%.0lf\n",a[n][0]);
}
void main()
{
	scanf("%d%d",&m,&n);
	while(m&&n)
	{
		if(m*n%2)
			printf("0\n");
		else run();
		scanf("%d%d",&m,&n);
	}
}