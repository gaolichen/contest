#include<stdio.h>
#include<math.h>
double h[10],a[10],d[10];
int n;
void run()
{
	int i;
	double len=0;
	h[0]=0;
	for(i=1;i<=n;i++)
	{
		h[i]=h[i-1]+sin(a[i-1])*d[i];
		len+=cos(a[i-1])*d[i];
	}
	len-=h[n]/tan(a[n]);
	putchar('\n');
	for(i=1;i<=n;i++)
	{
		printf("Altitude of peak %d =",i);
		printf("%7.1lf\n",h[i]);
	}
	printf("Pipeline length    =");
	printf("%7.1lf\n",len);
}
void main()
{
	char ch;
	double pi=3.14159265;
	d[0]=0;n=0;
	printf("Problem 6 by team x\n");
	while(scanf("%lf%c",&a[n],&ch)==2)
	{
		a[n]=a[n]*pi/180;
		while(1)
		{
			n++;
			scanf("%lf%c",&d[n],&ch);
			scanf("%lf%c",&a[n],&ch);
			a[n]=a[n]*pi/180;
			if(ch=='\n')break;
		}
		run();
		n=0;
	}
	printf("End of problem 6 by team x\n");
}