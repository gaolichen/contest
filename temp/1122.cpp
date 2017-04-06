
#include<stdio.h>
int count,sh,sm,em,eh;
void print()
{
	if(sh>9)
	printf("       %d:",sh);
	else printf("       0%d:",sh);
	if(sm>9)
		printf("%d",sm);
	else printf("0%d",sm);
	if(eh>9)
	printf("       %d:",eh);
	else printf("       0%d:",eh);
	if(em>9)
		printf("%d",em);
	else printf("0%d",em);
	printf("%8d\n",count);
}
void run()
{
	int teh;
	if(eh<sh)
		teh=eh+12;
	else if(eh==sh&&em<sm)
		teh=eh+12;
	else teh=eh;
	count=teh-sh;
	if(em<(eh*5)%60+em/12.0)
		count--;
	if(sm<(sh*5)%60+sm/12.0)
		count++;
	if((sh<12&&teh>=12)||(sh<24&&teh>=24))
		count--;
	print();
}
void main()
{
	int num=0;
	while(scanf("%d%d%d%d",&sh,&sm,&eh,&em)==4)
	{
		if(!num)
		{
			printf("Program 3 by team X\n");
	printf("Initial time  Final time  Passes\n");
			num=1;
		}
		run();
	}
	printf("End of program 3 by team X\n");
}