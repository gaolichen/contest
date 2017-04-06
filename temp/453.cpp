#include<stdio.h>
#include<math.h>
void main()
{
	double d,y1,y2,x1,x2,inx1,inx2,iny1,iny2,co,si,r1,r2;
	double dx1,dy1,dx2,dy2,temp;
	while(scanf("%lf%lf%lf",&x1,&y1,&r1)==3)
	{
		scanf("%lf%lf%lf",&x2,&y2,&r2);
		d=x1*x1+x2*x2+y1*y1+y2*y2-2*(x1*x2+y1*y2);
		if(r1<0)r1=-r1;
		if(r2<0)r2=-r2;
		if(r1<1e-6)
		{
	if(fabs((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)-r2*r2)<1e-6)
			printf("(%.3lf,%.3lf)\n",x1,y1);
			else 
				printf("NO INTERSECTION\n");
		}
		else if(r2<1e-6)
		{
	if(fabs((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)-r1*r1)<1e-6)
			printf("(%.3lf,%.3lf)\n",x2,y2);
			else printf("NO INTERSECTION\n");
		}
		else if(d>(r1+r2)*(r1+r2)+0.000001)
		{
			printf("NO INTERSECTION\n");
		}
		else 
		if(fabs(d-(r1+r2)*(r1+r2))<1e-6)
		{
			inx1=(r1*x2+r2*x1)/(r1+r2);
			iny1=(r1*y2+r2*y1)/(r1+r2);
			printf("(%.3lf,%.3lf)\n",inx1,iny1);
		}
		else 
		if(d>r1*r1+r2*r2-2*r1*r2+0.000001)
		{
			co=(r1*r1+d-r2*r2)/(2*r1*sqrt(d));
			si=sqrt(1-co*co);
			dx1=x2*co+y1*si-(x1*co+y2*si);
			dy1=y2*co+x2*si-(y1*co+x1*si);
			dx2=x2*co+y2*si-(x1*co+y1*si);
			dy2=y2*co+x1*si-(y1*co+x2*si);
			inx1=x1+dx1*r1/sqrt(d);
			iny1=y1+dy1*r1/sqrt(d);
			inx2=x1+dx2*r1/sqrt(d);
			iny2=y1+dy2*r1/sqrt(d);
			if(inx1>inx2+0.001)
			{
				temp=inx1;inx1=inx2;
				inx2=temp;temp=iny1;
				iny1=iny2;iny2=temp;
			}
			else 
		if(fabs(inx1-inx2)<1e-6&&iny1>iny2+0.001)
			{
				temp=iny1;iny1=iny2;
				iny2=temp;
			}
			printf("(%.3lf,%.3lf)",inx1,iny1);
			printf("(%.3lf,%.3lf)\n",inx2,iny2);
		}
		else 
		if(d>1e-6&&fabs(d+2*r1*r2-(r1*r1+r2*r2))<1e-6)
		{
			inx1=(r1*x2-r2*x1)/(r1-r2);
			iny1=(r1*y2-r2*y1)/(r1-r2);
			printf("(%.3lf,%.3lf)\n",inx1,iny1);
		}
		else if(d>1e-6)
			printf("NO INTERSECTION\n");
		else if(fabs(r1-r2)<0.001)
			printf("THE CIRCLES ARE THE SAME\n");
		else 
			printf("NO INTERSECTION\n");
	}
}