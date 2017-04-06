#include<stdio.h>
#include<math.h>
int m,n;
void run()
{
	int i,j,tj=-1,ti=1;
	int find=0;
	for(i=1;i<=n;i++)
	{
		j=i*m/n;
		if(j==0)j=1;
		for(;;j++)
		{
			if(abs(j*ti*n-i*m*ti)<abs(tj*i*n-i*m*ti))
			{
				find=1;
				tj=j;ti=i;
			}
			else 
			{
				if(find)
				{
					printf("%d/%d\n",tj,ti);
					find=0;break;
				}
				if(j*n>i*m)break;
			}
		}
	}
}
void main()
{
	int count=0;
	while(scanf("%d%d",&m,&n)==2)
	{
		if(count)putchar('\n');
		else count=1;
		run();
	}
}