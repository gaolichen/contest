#include<stdio.h>
int up,down,n;
double t;
void run()
{
	double time;
printf("Chair %3d meets chair %3d, remaining time =",up,down);
    if(up<down)up+=n;
	time=t*(up-down-0.5)/(n-1);
	printf("%6.1lf\n",time);
}
int main()
{
	printf("Program 1 by team X\n");
	while(scanf("%d%lf",&n,&t)==2)
	{
	printf("N =");
	printf("%4d, ",n);
	printf("T =");
	printf("%6.1lf\n",t);
	while(scanf("%d%d",&up,&down)==2)
		run();
	}
	printf("End of program 1 by team X\n");
	return 0;
}
