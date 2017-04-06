#include<stdio.h>
#include<string.h>
char num[2][100],str[2][100],res[100];
void run()
{
	int i,j,k,len[2],p,t;
	len[0]=strlen(str[0]);
	len[1]=strlen(str[1]);
	for(i=0;i<2;i++)
	{
		k=0;
		for(j=len[i]-1;j>=0;j--)
			num[i][len[i]-j-1]=str[i][j];
		num[i][len[i]]='\0';
	}
	j=0;
	for(i=0;i<len[0]&&i<len[1];i++)
	{
		if(num[0][i]>='a')
			j+=num[0][i]-'a'+10;
		else j+=num[0][i]-'0';
		if(num[1][i]>='a')
			j+=num[1][i]-'a'+10;
		else j+=num[1][i]-'0';
		res[i]=j%20;
		j/=20;
	}
	if(num[0][i]!='\0')
	{
		p=0;t=len[0];
	}
	else 
	{
		p=1;t=len[1];
	}
	for(;i<t;i++)
	{
		if(num[p][i]>='a')
			j+=num[p][i]-'a'+10;
		else j+=num[p][i]-'0';
		res[i]=j%20;
		j/=20;
	}
	if(j)
		res[i++]=j;
	for(i--;i>=0;i--)
	{
		if(res[i]>9)
			putchar(res[i]+'a'-10);
		else putchar(res[i]+'0');
	}
	putchar('\n');
}
void main()
{
	while(scanf("%s%s",str[0],str[1])==2)
	{
		run();
	}
}