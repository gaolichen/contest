#include<stdio.h>
int f[35],m,n;
void init()
{
	int i;
	for(i=0;i<35;i++)
		f[i]=i;
	f[2]=9;f[3]=20;f[5]=18;f[7]=16;
	f[6]=33;f[8]=31;f[14]=25;f[12]=27;
	f[10]=29;
	for(i=13;i<25;i+=2)
		f[i]=46-(i-13);
	f[34]=49;
}
void run()
{
	if(m>=35&&m<=n)
		printf("Let me try!\n");
	else if(m<35&&n>=f[m])
		printf("Let me try!\n");
	else printf("Don't make fun of me!\n");
}
void main()
{
	init();
	scanf("%d%d",&n,&m);
	while(m&&n)
	{
		run();
		scanf("%d%d",&n,&m);
	}
}