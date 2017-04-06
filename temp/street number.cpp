#include <stdio.h>
#include <math.h>
void main()
{
	double num[10][2];
	double j,t;
	int i=0;
	for(j=6;i<10;j++)
	{
		t=(int)sqrt(2*j*j);
		if(2*j*j==t*(t+1))
		{
			num[i][0]=j;
			num[i++][1]=t;
		}
	}
	for(i=0;i<10;i++)
		printf("%.0lf %.0lf\n",num[i][0],num[i][1]);
}