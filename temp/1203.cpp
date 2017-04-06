#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 200
double x[N],y[N],g[N][N];
int mark[N],n;
double dis(int i,int j)
{
	double d;
	d=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
	return sqrt(d);
}
void run()
{
	int i,j,k,tj,tk;
	double min,tot=0;
	memset(mark,0,sizeof(mark));
	for(j=0;j<n;j++)
	for(i=0;i<n;i++)
	{
		if(i==j)
			g[i][j]=0;
		else g[i][j]=dis(i,j);
	}
	mark[0]=1;
	for(i=1;i<n;i++)
	{
		min=-1;
		for(j=0;j<n;j++)
			if(mark[j])
				for(k=0;k<n;k++)
					if(k!=j&&!mark[k]&&(min<0||g[j][k]<min))
					{
						min=g[j][k];
						tj=j;
						tk=k;
					}
		mark[tk]=1;
		tot+=min;
	}
	printf("The minimal distance is: %.2lf\n",tot);
}
void main()
{
	int i,count=0;
	scanf("%d",&n);
	while(n)
	{
		if(count)putchar('\n');
		for(i=0;i<n;i++)
			scanf("%lf%lf",&x[i],&y[i]);
		printf("Case #%d:\n",++count);
		run();
		scanf("%d",&n);
	}
}