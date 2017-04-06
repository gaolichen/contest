#include<stdio.h>
#include<math.h>
int si[3];
void run()
{
	int i,unknow,other;
	for(i=0;i<3;i++)
		if(si[i]==-1)
			break;
	unknow=i;
	if(unknow==2)
	{
		printf("c = %.3lf\n",sqrt(si[0]*si[0]+si[1]*si[1]));
		return;
	}
	if(unknow==1)
		other=0;
	else other=1;
	if(si[2]<=si[other])
	{
		printf("Impossible.\n");
		return;
	}
printf("%c = %.3lf\n",'a'+unknow,sqrt(si[2]*si[2]-si[other]*si[other]));
}
void main()
{
	int count=0;
	scanf("%d%d%d",&si[0],&si[1],&si[2]);
	while(si[0]&&si[1]&&si[2])
	{
		printf("Triangle #%d\n",++count);
		run();
		putchar('\n');
		scanf("%d%d%d",&si[0],&si[1],&si[2]);
	}
}