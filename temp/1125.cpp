#include<stdio.h>
char num[20];
void run()
{
	int i,j,e,t;
	double p,k;
	for(i=1;i<16;i++)
		if(num[i]=='1')break;
	if(i==16)
	{
		printf(" 0.000000e+000\n");
		return;
	}
	j=1;e=0;
	for(i=7;i>0;i--)
	{
		e+=(num[i]-'0')*j;
		j*=2;
	}
	e=e-63;p=1;k=1;
	for(j=8;j<16;j++)
	{
		k/=2;
		p+=(num[j]-'0')*k;
	}
	t=e;
	if(e<0)
		for(i=0;i<-e;i++)
		{
			p/=2;
		}
	else for(i=0;i<e;i++)
		p*=2;
	e=0;
	while(p>=10)
	{
		p/=10;
		e++;
	}
	while(p<1)
	{
		p*=10;
		e++;
	}
	if(num[0]=='0')
		putchar(' ');
	else putchar('-');
	printf("%lfe",p);
	if(t>=0)putchar('+');
	else putchar('-');
	i=e/100;
	e=e-100*i;
	printf("%d%d%d\n",i,e/10,e%10);
}
void main()
{
	int count=0;
	while(scanf("%s",num)==1)
	{
		if(!count)
		{
			printf("Program 6 by team X\n");
			count=1;
		}
		run();
	}
	printf("End of program 6 by team X\n");
}