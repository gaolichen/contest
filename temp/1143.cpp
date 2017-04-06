#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 600
#define M 2100000000
int path[N];
double x[N],y[N],f[N];
int n,sta,end;
void insert(int k,int j)
{
	int t;
	if(k==sta-1)
		path[--sta]=j;
	else if(k==end)path[++end]=j;
	return;
	for(t=++end;t>k+1;t--)
		path[t]=path[t-1];
	path[k+1]=j;
}
double dis(int i,int j)
{
	double t;
	t=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	return t;
}
void run()
{
	int j,ins,k;
	double min,d1,d2,d3;
		path[300]=0;
		sta=300;end=301;
		f[1]=dis(0,1);
		path[301]=1;
		for(j=2;j<n;j++)
		{
			min=M;ins=sta;
			for(k=sta;k<end;k++)
			{
				d1=dis(path[k],j);
				d2=dis(j,path[k+1]);
				d3=dis(path[k],path[k+1]);
				if(d1+d2-d3<min)
				{
					min=d1+d2-d3;
					ins=k;
				}
			}
			d1=dis(path[sta],j);
			if(d1<min)
			{
				min=d1;ins=sta-1;
			}
			d2=dis(path[end],j);
			if(d2<min)
			{
				min=d2;ins=end;
			}
			f[j]=f[j-1]+min;
			insert(ins,j);
		}
	printf("%.3lf\n",f[n-1]);
}
void main()
{
	int i;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%lf%lf",&x[i],&y[i]);
		memcpy(x+n,x,sizeof(double)*n);
		memcpy(y+n,y,sizeof(double)*n);
		run();
	}
}