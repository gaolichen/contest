#include<stdio.h>
#include<string.h>
int p[4]={2,4,8,6};
int ln[10]={6,6,2,6,4,4,4,8,4,6};
int n,num[5000],len;
char chnum[5000];
void dive(int *num)
{
	int i=len-1,j,t=0;
	j=len-1;
	if(num[0]>=5)
		j++;
	len=j;
	for(;i>=0;i--)
	{
		num[j]=num[i]*2+t;
		t=num[j]/10;
		num[j--]%=10;
	}
	if(t)num[0]=t;
}
int mod(int *num)
{
	int t;
	if(len==1)t=num[0];
	else t=num[len-1]+num[len-2]*10;
	t%=4;
	return t;
}
void run()
{
	int i,j=0,last=1;
	len=strlen(chnum);
	for(i=0;i<len;i++)
		num[i]=chnum[i]-'0';
	if(len==1)
	{
		for(i=1;i<=num[0];i++)
			last*=i;
		while(last%10==0)last/=10;
		printf("%d\n",last%10);
		return;
	}
	while(len>0)
	{
		if(len>1)last*=ln[num[len-1]];
		else 
		{
			for(i=1;i<=num[0];i++)
		{
			if(i==5)j++;
			else last*=i;
		}
		last%=10;
		break;
		}
		last%=10;
		dive(num);
		j+=mod(num);
		j%=4;
	}
	for(i=0;i<4;i++)
		if(p[i]==last)break;
	printf("%d\n",p[(i+4-j)%4]);
}
int main()
{
	while(scanf("%s",chnum)==1)
		run();
	return 0;
}
