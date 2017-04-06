#include<stdio.h>
char word[27][27][27][27][27];
void init(str)
{
	int i,j,len;
	len=strlen(str);
	for(j=1;j<=len;j++)
	{
		pop=i=0;
		while(pop>=0)
		{
			if(pop==j)
			{
				word[
			}
		}
	}
}
void main()
{
	char str[10];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		memstr(word,0,sizeof(word));
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%s",str);
			init(str);
		}
		for(;;)
		{
			scanf("%s",str);
			if(str[0]=='#')break;
			run();
		}
	}
}