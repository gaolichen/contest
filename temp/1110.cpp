#include<stdio.h>
int s,p,y,j;
void run()
{
	int i,k,h;
	for(i=0;;i++)
		for(h=y+i;h<=y+i+1;h++)
			for(k=i+p;k<=i+p+1;k++)
				if((h==k+s||h==k+s+1)&&i+h+k==12+j)
				{
					printf("%d %d %d\n",h,k,i);
					return;
				}
}
void main()
{
	while(scanf("%d%d%d%d",&s,&p,&y,&j)==4)
	{
		run();
	}
}