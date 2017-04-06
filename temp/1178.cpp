#include<stdio.h>
int n;
void run()
{
	int i,j,b;
	i=(n-1)/4;
	i++;b=4*i;
	printf("Printing order for %d pages:\n",n);
	for(j=0;j<i;j++)
	{
		printf("Sheet %d, front: ",j+1);
		if(b<=n)printf("%d, ",b);
		else printf("Blank, ");
		printf("%d\n",2*j+1);
		b--;
		if(2*j+2<=n||b<=n)
		{
			printf("Sheet %d, back : ",j+1);
			if(2*j+2<=n)
				printf("%d, ",2*j+2);
			else printf("Blank, ");
			if(b<=n)
				printf("%d\n",b);
			else printf("Blank\n");
			b--;
		}
	}
}
void main()
{
	scanf("%d",&n);
	while(n)
	{
		run();
		scanf("%d",&n);
	}
}