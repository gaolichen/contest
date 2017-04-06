#include<stdio.h>
#include<string.h>
#define N 500
char str[20];
int res[N],real,k,n,m;
void init()
{
	int i,s,tail;
	for(i=0;i<N;i++)
		res[i]=0;
	real=0;
	for(i=5;i>=0;i--)
		if(str[i]!='0')
		{tail=i;break;}
	for(i=tail;i>=0;i--)
		if(str[i]=='.')
		{k=tail-i;break;}
	for(i=0;i<=tail;i++)
		if(str[i]!='.')
		real=10*real+str[i]-'0';
	s=real;
	for(i=0;s;i++)
	{
		res[i]=s%10;
		s/=10;
	}
	m=i;
	if(str[7]==' ')str[7]='0';
	n=(str[7]-'0')*10+str[8]-'0';
}
void run()
{
	int i,t;
	for(i=0;i<m;i++)
		res[i]*=real;
	for(i=0;i<m+10;i++)
	{
		t=res[i];
		res[i]%=10;
		res[i+1]+=t/10;
	}
	while(res[i]==0)i--;
	m=i+1;
}
void main()
{
	int i;
	while(gets(str))
	{
	init();
	for(i=0;i<n-1;i++)
		run();
	if(m<k*n)
	{
		printf(".");
		for(i=k*n;i>m;i--)
			printf("0");
	}
	for(i=m-1;i>=0;i--)
	{
		if(i==k*n-1)
			printf(".");
		printf("%d",res[i]);	
	}
	printf("\n");
	}
}