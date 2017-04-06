#include<stdio.h>
#include<math.h>
#define K 1.0
#define pai 3.1415926536
double d,x,y,R,totle;
void init()
{
	scanf("%lf%lf%lf",&d,&x,&y);
	R=36000*d/pai;
}
void solve(double i)
{
	int m;
	line L;
	makeline(&L,i);
	for(m=0;m<R;m++)
}
void main()
{
	double i,j,det;
	det=pai/18000;
	init();
	for(i=det;i<180;i=i+det)
	{
		solve(i);
	}
	printf("%d\n",(int)totle);
}