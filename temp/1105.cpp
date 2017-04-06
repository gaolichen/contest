#include<math.h>
#include<stdio.h>
void run(double tot)
{
	int h,m;
	double min;
	h=(int)((tot*2)/20000);
	min=((tot*2)/20000-h)*60;
	m=(int)min;
	if(((min-m)*10)>=5)
	{
		if(m==59)
		{
			m=0;h++;
		}
		else m++;
	}
	printf("%d:",h);
	if(m<10)putchar('0');
	printf("%d\n",m);
}
void main()
{
	int x0,y0,x1,y1,x2,y2;
	double tot;
	char str[80],buf[80];
	while(scanf("%d%d",&x0,&y0)==2)
	{
		tot=0;
		gets(str);
		gets(buf);
		while(buf[0]!='j')
		{
			sscanf(buf,"%d%d%d%d",&x1,&y1,&x2,&y2);
			tot+=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
			gets(buf);
		}
		run(tot);
	}
}