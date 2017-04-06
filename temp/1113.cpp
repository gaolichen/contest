#include<stdio.h>
void main()
{
	int i,j,a[15];
	double e;
	printf("n e\n");
	printf("- -----------\n");
	a[0]=1;
	for(i=1;i<10;i++)
		a[i]=a[i-1]*i;
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	for(i=3;i<10;i++)
	{
		e=0;
		for(j=i;j>=0;j--)
			e+=1.0/(double)a[j];
		printf("%d %.9lf\n",i,e);
	}
}