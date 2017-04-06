#include<stdio.h>
#include<string.h>
int num[11][100],num1[200],res[100],len[11];
int sta,end;
void init(char *str)
{
	int i,j,t;
	len[0]=strlen(str);
	for(i=0;i<len[0];i++)
	{
		num[1][len[0]-i-1]=str[i]-'0';
		num[0][i]=0;
	}
	len[1]=len[0];
	for(i=2;i<=10;i++)
	{
		for(j=0;j<len[0];j++)
			num[i][j]=num[i-1][j]+num[1][j];
		for(;j<len[i-1];j++)
			num[i][j]=num[i-1][j];
		t=0;
		for(j=0;j<len[i-1];j++)
		{
			num[i][j]+=t;
			t=num[i][j]/10;
			num[i][j]%=10;
		}
		len[i]=len[i-1];
		if(t)
		{
			num[i][j]=t;
			len[i]++;
		}
	}
}
int cmp(int i)
{
	int j;
	if(sta-end>len[i]-1)return -1;
	if(sta-end<len[i]-1)return 1;
	for(j=sta;j>=end;j--)
	{
		if(num1[j]>num[i][len[i]-1-sta+j])
			return -1;
		if(num1[j]<num[i][len[i]-1-sta+j])
			return 1;
	}
	return 0;
}
void des(int i)
{
	int j;
	for(j=0;j<len[i];j++)
	{
		if(num1[end+j]<num[i][j])
		{
			num1[end+j]+=10;
			num1[end+j+1]--;
		}
		num1[end+j]-=num[i][j];
	}
}
void run(char *str)
{
	int i,j,t;
	init(str);
	sta=160,end=160-len[0]+1;
	t=sta-end;
	memset(num1,0,sizeof(num1));
	num1[160]=1;i=j=0;
	do
	{
		i=0;
		while(cmp(i)<=0)i++;
		des(i-1);
		res[j++]=i-1;
		end--;
		while(sta>end&&!num1[sta])sta--;
	}while(sta!=end);
	for(i=0;i<t;i++)
	{
		if(i==1)
			putchar('.');
		putchar('0');
	}
	for(i=0;i<j;i++)
	{
		if(i+t==1)
			putchar('.');
		printf("%d",res[i]);
	}
	putchar('\n');
}
void main()
{
	char str[100];
	int count=0;
	while(gets(str))
	{
		if(!count)
		{
			printf("Problem 4 by team x\n");
			count=1;
		}
		putchar('\n');
		printf("1 / ");
		printf("%s =\n",str);
		run(str);
	}
	printf("End of problem 4 by team x\n");
}