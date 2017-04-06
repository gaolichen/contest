#include<stdio.h>
#include<math.h>
int w,d;
void run()
{
	double year;
	int y;
	year=5730*(log(810)-log(d/(double)w))/log(2);
	if(year<10000)
	{
		y=100*(int)(year/100);
		if(year-y>=50)
			y+=100;
printf("The approximate age is %d years.\n",y);
	}
	else 
	{
		y=1000*(int)(year/1000);
		if(year-y>=500)
			y+=1000;
printf("The approximate age is %d years.\n",y);
	}
}
void main()
{
	int count=0;
	scanf("%d%d",&w,&d);
	while(w&&d)
	{
		printf("Sample #%d\n",++count);
		run();
		putchar('\n');
		scanf("%d%d",&w,&d);
	}
}