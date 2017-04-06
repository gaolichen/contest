#include<stdio.h>
int x[2],y[2],r[2];
void run()
{
	int d;
	double x0,y0;
	if(r[0]==r[1])
	{
		printf("Impossible.\n");
		return;
	}
	d=(x[0]-x[1])*(x[0]-x[1])+(y[0]-y[1])*(y[0]-y[1]);
	if(d<=(r[0]-r[1])*(r[0]-r[1]))
	{
		printf("Impossible.\n");
		return;
	}
	x0=(r[0]*x[1]-r[1]*x[0])/(double)(r[0]-r[1]);
	y0=(r[0]*y[1]-r[1]*y[0])/(double)(r[0]-r[1]);
	printf("%.2lf %.2lf\n",x0,y0);
}
void main()
{
	int t,now;
	scanf("%d",&t);
	for(now=0;now<t;now++)
	{
		scanf("%d%d%d",&x[0],&y[0],&r[0]);
		scanf("%d%d%d",&x[1],&y[1],&r[1]);
		run();
	}
}