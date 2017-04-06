#include<stdio.h>
#define M 2100000000
short k,n;
int bad[5050][1010];
int ch[5050];
void run()
{
	int i,j;
	for(i=0;i<=n+1;i++)
		bad[i][0]=0;
	for(i=n-2;i>0;i--)
		for(j=1;j<=k+8&&j*3<=n-i+1;j++)
		{
			bad[i][j]=M;
			if(j*3<=n-i&&bad[i+1][j]<bad[i][j])
				bad[i][j]=bad[i+1][j];
if(bad[i+3][j-1]+(ch[i]-ch[i+1])*(ch[i]-ch[i+1])<bad[i][j])
bad[i][j]=bad[i+3][j-1]+(ch[i]-ch[i+1])*(ch[i]-ch[i+1]);
if(3*(j-1)<n-i-1&&bad[i+2][j-1]+(ch[i]-ch[i+1])*(ch[i]-ch[i+1])<bad[i][j])
bad[i][j]=bad[i+2][j-1]+(ch[i]-ch[i+1])*(ch[i]-ch[i+1]);
		}
		printf("%d\n",bad[1][k+8]);
}
void main()
{
	int i,j,t;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&k,&n);
		for(j=1;j<=n;j++)
			scanf("%d",&ch[j]);
		run();
	}
}