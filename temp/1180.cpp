#include<stdio.h>
#include<string.h>
int d(int i)
{
	int t=i;
	while(t)
	{
		i+=t%10;
		t/=10;
	}
	return i;
}
void main()
{
	int i,j;
	char mark[1000001];
	memset(mark,0,sizeof(mark));
	for(i=1;i<=1000000;i++)
		if(!mark[i])
		{
			printf("%d\n",i);
			j=i;
			do
			{
				mark[j]=1;
				j=d(j);
			}while(j<=1000000&&!mark[j]);
		}
}
