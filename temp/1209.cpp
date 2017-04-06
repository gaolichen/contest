#include<stdio.h>
#include<math.h>
int h,m;
void run()
{
	int th,tm,t;
	printf("%5d%9d",h,m);
	tm=h*5+m/12;
	if(m-(m/12)*12>=6)
		tm++;
	if(tm>=60)tm-=60;
	th=(m-(m/5)*5)*12;
	t=abs(tm-th);
	if(t>30)t=60-t;
	printf("%17d%15d%14d",tm,th,t);
	if(t<=12)
	{
		t=m/5;
		if(!t)t=12;
		printf("%9d%9d\n",t,tm);
	}
	else printf("       --       --\n");
}
void main()
{
	int i,count=0;
	while(scanf("%d%d",&h,&m)==2)
	{
		if(!count)
		{
			printf("Problem 3 by team x\n");
			for(i=0;i<78;i++)
				putchar('=');
			printf("\n True     True");
			printf("     Minutes From   Minutes From   ");
			printf("Discrepancy  ");
			printf("Swapped  Swapped\n");
			printf("Hours  Minutes   ");
			printf("Minute Hand In   Hour Hand In");
			printf("    Of Minutes");
			printf("    Hours  Minutes\n");
			printf("                  ");
			printf("Swapped Clock  Swapped Clock\n");
			for(i=0;i<78;i++)
				putchar('=');
			putchar('\n');
			count=1;
		}
		run();
	}
	for(i=0;i<78;i++)
		putchar('=');
	printf("\nEnd of problem 3 by team x\n");
}