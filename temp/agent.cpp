#include<stdio.h>
#define N 301
double safe[N][N],array[N][N];
int path[N][N],max[N][N],n,m;
void init()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n+1;i++)
		for(j=0;j<=n+1;j++)
		{
			safe[i][j]=0;
			max[i][j]=0;
		}
	for(i=1;i<=n;i++)
	{scanf("%lf",&safe[i][0]);
	safe[0][i]=safe[i][0];path[1][i]=0;}
	for(i=1;i<=n;i++)
	{scanf("%d",&max[0][i]);max[i][0]=max[0][i];}
	for(i=1;i<=n;i++)
	{scanf("%lf",&safe[i][n+1]);
	safe[n+1][i]=safe[i][n+1];
	max[n+1][i]=max[i][n+1]=N;}
	safe[0][n+1]=safe[n+1][0]=0;
	scanf("%d%d",&i,&j);
	while(i!=-1||j!=-1)
	{
		scanf("%lf%d",&safe[i][j],&max[i][j]);
		safe[j][i]=safe[i][j];
		max[j][i]=max[i][j];
		scanf("%d%d",&i,&j);
	}
}
double pass()
{
	int i,j,k;
	double temp;
	for(i=1;i<=n+1;i++)
	{
		if(max[i][0])
		array[1][i]=safe[i][0];
		else array[1][i]=0;
		path[1][i]=0;
	}
	for(i=2;i<=n+1;i++)
		for(j=1;j<=n+1;j++)
		{
			path[i][j]=j;
			temp=array[i-1][j];
			for(k=1;k<=n+1;k++)                                     
				if(array[i-1][k]&&max[j][k])
					if(array[i-1][k]*safe[j][k]>temp)
					{
						temp=array[i-1][k]*safe[j][k];
						path[i][j]=k;
					}
			array[i][j]=temp;
		}
		j=path[n+1][n+1];
	for(i=n;i>0;i--)
		if(path[i][j]!=j)
		{max[path[i][j]][j]--;
		max[j][path[i][j]]--;
		j=path[i][j];}
	return array[n+1][n+1];
}
void main()
{
	int i;
	char ch;
	double s=1.0,temp;
	init();
	for(i=m;i>0;i--)
	{
		temp=pass();
		s=s*temp;
	}
	if(s>1e-12)printf("%.12lf",s);
	for(;(ch=getchar())!='e';);
}
