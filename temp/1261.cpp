#include<stdio.h>
#include<string.h>
int p[3600],num,time[3600],pre[3600],a[3600],n,e[3600];
void run()
{
	int i,j,num=1;
	for(i=0;i<n;i++)
		for(j=0;j<e[i];j++)
			num*=a[i];
	num--;j=0;
	for(i=0;;i++)
	{
		if(num==1)break;
		if(num%p[i]==0)
		{
			pre[j]=p[i];
			time[j]=0;
			while(num%p[i]==0)
			{
				num/=p[i];
				time[j]++;
			}
			j++;
		}
	}
	for(i=j-1;i>=0;i--)
	{
		if(i!=j-1)putchar(' ');
		printf("%d %d",pre[i],time[i]);
	}
	putchar('\n');
}
void init()
{
	int i,j,k=0;
	char mark[33000];
	memset(mark,0,sizeof(mark));
	for(i=2;i<=32767;i++)
		if(!mark[i])
		{
			for(j=i;j*i<=32768;j++)
				mark[j*i]=1;
			p[k++]=i;
		}
}
void main()
{
	int i;
	char ch;
	init();
	scanf("%d",&a[0]);
	while(a[0])
	{
		i=1;
		scanf("%d%c",&e[0],&ch);
		while(ch!='\n')
		{
			scanf("%d %d%c",&a[i],&e[i],&ch);
			i++;
		}
		n=i;
		run();
		scanf("%d",&a[0]);
	}
}