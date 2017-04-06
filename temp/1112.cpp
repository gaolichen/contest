#include<stdio.h>
#include<math.h>
#include<string.h>
#define T double
char p[500][50],p1[50],p2[50],p3[50];
double w[500],l[500],x[500],y[500],z[500];
double pi=3.1415926536;
int count;
void run()
{
	int i,t1=-1,t2=-1,t3=-1;
	double d1,d2,d,a,dx,dy,dz;
	for(i=0;i<count;i++)
	{
		if(strcmp(p1,p[i])==0)
			t1=i;
	    if(strcmp(p2,p[i])==0)
			t2=i;
		if(strcmp(p3,p[i])==0)
			t3=i;
	}
	printf("%s is ",p3);
	if(t1!=-1&&t2!=-1&&t3!=-1)
	{
		dx=x[t1]-x[t2];
		dy=y[t1]-y[t2];
		dz=z[t1]-z[t2];
		d1=fabs(dx*x[t3]+dy*y[t3]+dz*z[t3]);
		d2=sqrt(dx*dx+dy*dy+dz*dz);
		if(d2>1e-6)
		{
			a=asin(d1/(d2*6378));
			d=a*6378;
		}
		else d=0;
		if(d>pi*0.5*6378)
			d=pi*6378-d;
		printf("%.0lf ",d);
	}
	else printf("? ");
	printf("km off %s/%s equidistance.\n",p1,p2);
}
void init()
{
	int i;
	double k=3.14159265/180;
	for(i=0;i<count;i++)
	{
		z[i]=6378*sin(w[i]*k);
		x[i]=6378*cos(w[i]*k)*cos(l[i]*k);
		y[i]=6378*cos(w[i]*k)*sin(l[i]*k);
	}
}
void main()
{
	int i;
	while(1)
	{
	i=0;
	if(scanf("%s",p[i])!=1)break;
	while(p[i][0]!='#')
	{
		scanf("%lf%lf",&w[i],&l[i]);
		i++;
		scanf("%s",p[i]);
	}
	count=i;
	init();
	scanf("%s",p1);
	while(p1[0]!='#')
	{
		scanf("%s%s",p2,p3);
		run();
		scanf("%s",p1);
	}
	}
}