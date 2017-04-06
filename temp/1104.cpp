#include<stdio.h>
#include<math.h>
double x[200],h[200],pi=3.14159265359;
int n;
void run()
{
	int i;
	double d,maxh=0,vx,vy,v=0,a=0,t;
	d=x[n];d=d*0.5;
	for(i=1;i<n;i++)
	{
	if(h[i]*d*d/(x[i]*(2*d-x[i]))>maxh)
		maxh=h[i]*d*d/(x[i]*(2*d-x[i]));
	if(h[i-1]*d*d/(x[i]*(2*d-x[i]))>maxh)
		maxh=h[i-1]*d*d/(x[i]*(2*d-x[i]));
	}
	vy=sqrt(2*9.8*maxh);
	t=2*sqrt(maxh/4.9);
	if(t>1e-6)
	{vx=x[n]/t;	
	v=sqrt(vx*vx+vy*vy);
	a=atan(vy/vx);a*=180/pi;
	}
	printf("%.2lf %.2lf\n",a,v);

}
void main()
{
	int i;
	while(scanf("%d",&n)==1)
	{
		x[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf",&h[i-1],&x[i]);
			x[i]+=x[i-1];
		}
		run();
	}
}