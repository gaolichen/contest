#include<stdio.h>
#include<string.h>
int num[20],right[20],left[20],sk[20],pop,op[20];
int tot,res;
int fit(int i)
{
	if(tot-pop<=0)return 0;
	if(i==1||i==0)
		return 1;
	if(i==2&&num[tot-pop]&&sk[pop-1]%num[tot-pop]==0)
		return 1;
	return 0;
}
int cal(int i)
{
	if(i==0)
		return sk[pop-1]-num[tot-pop];
	if(i==1)
		return sk[pop-1]+num[tot-pop];
	return sk[pop-1]/num[tot-pop];
}
void print()
{
	int i;
	printf("%d=",res);
	while(left[0]--)putchar('(');
	printf("%d",num[0]);
	while(right[0]--)putchar(')');
	i=pop-1;
	while(i>0)
	{
		if(op[i]==0)
			putchar('+');
		if(op[i]==1)
			putchar('-');
		if(op[i]==2)
			putchar('*');
		while(left[tot-i]--)putchar('(');
		printf("%d",num[tot-i]);
		while(right[tot-i]--)putchar(')');
		i--;
	}
	putchar('\n');
}
void run(char *str)
{
	int i,j=0,t=0;
	for(i=0;str[i]!='=';i++)
		if(str[i]>='0'&&str[i]<='9')
			t=t*10+str[i]-'0';
	res=t;t=0;
	memset(right,0,sizeof(right));
	memset(left,0,sizeof(left));
	for(;str[i]!='\0';i++)
	{
		if(str[i]>='0'&&str[i]<='9')
			t=10*t+str[i]-'0';
		else if(str[i]==' '&&t)
		{num[j++]=t;t=0;}
		else if(str[i]=='('||str[i]==')')
		{
			if(t)
				num[j++]=t;
			if(str[i]=='(')
				left[j]++;
			if(str[i]==')')
				right[j-1]++;
			t=0;
		}
	}
	if(t)
		num[j++]=t;
	tot=j;
	pop=1;
	i=0;sk[0]=res;op[0]=0;
	while(pop>0)
	{
		if(pop==tot)
		{
			if(sk[pop-1]==num[0])
			{
				print();
				return;
			}
			pop--;
			i=op[pop]+1;
		}
		else if(i==3)
		{
			pop--;
			if(pop>0)
			i=op[pop]+1;
		}
		else if(fit(i))
		{
			sk[pop]=cal(i);
			op[pop]=i;
			i=0;
			pop++;
		}
		else i++;	
	}
	puts("Impossible");
}
void main()
{
	int count=0;
	char str[1000];
	gets(str);
	while(str[0]!='0')
	{
		while(str[0]=='\0')gets(str);
		printf("Equation #%d:\n",++count);
		run(str);
		putchar('\n');
		gets(str);
	}
}