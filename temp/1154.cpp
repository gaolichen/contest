#include<stdio.h>
#include<string.h>
char num[20000];
int niv[20000],b;
void run()
{
	int i,len,tot=0,t;
	len=strlen(num);
	for(i=0;i<len;i++)
	{
		niv[i]=num[i]-'0';
		tot+=niv[i];
	}
	t=0;i=0;
	do
	{
		if(t<tot)
		t=t*b+niv[i++];
		if(t>=tot)
		{
		t%=tot;
		}
	}while(i<len);
	if(!t)
		printf("yes\n");
	else printf("no\n");
}
void main()
{
	int t,now;
	scanf("%d",&t);
	for(now=0;now<t;now++)
	{
		if(now)putchar('\n');
		scanf("%d",&b);
		while(b)
		{
			scanf("%s",num);
			run();
			scanf("%d",&b);
		}
	}
}