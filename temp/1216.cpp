#include<stdio.h>
double len[100000];
void init()
{
	int i;
	len[0]=0;
	for(i=1;i<100000;i++)
		len[i]=len[i-1]+1.0/(2*i);
}
void main()
{
	int count=0,n;
	init();
	while(scanf("%d",&n)==1)
	{
		if(!count)
		{
			printf("# Cards  Overhang\n");
			count=1;
		}
		printf("%5d%10.3lf\n",n,len[n]);
	}
}