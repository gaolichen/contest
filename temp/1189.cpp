#include<stdio.h>
#include<string.h>
char num[16][100];
void sum(char *num1,char *num2)
{
	int i,j,tot[10],len,count1,count2;
	memset(tot,0,sizeof(tot));
	len=strlen(num1);
	for(i=0;i<len;i++)
		tot[num1[i]-'0']++;
	j=0;
	for(i=0;i<=9;i++)
		if(tot[i])
		{
			count1=tot[i]%10;
			tot[i]/=10;
			count2=tot[i]%10;
			if(count2)
				num2[j++]=count2+'0';
			num2[j++]=count1+'0';
			num2[j++]=i+'0';
		}
	num2[j]='\0';
}
void run()
{
	int i,j,len;
	len=strlen(num[0]);
	sum(num[0],num[1]);
	if(strcmp(num[0],num[1])==0)
	{
		printf("%s is self-inventorying\n",num[0]);
		return;
	}
	for(i=2;i<=15;i++)
	{
		sum(num[i-1],num[i]);
		if(strcmp(num[i],num[i-1])==0)
		{
printf("%s is self-inventorying after %d steps\n",num,i-1);
            return;
		}
		for(j=i-2;j>=0;j--)
			if(strcmp(num[i],num[j])==0)
			{
printf("%s enters an inventory loop of length %d\n",num,i-j);
                 return;
			}
	}
printf("%s can not be classified after 15 iterations\n",num);
}
void main()
{
	int t,now;
	scanf("%d",&t);
	for(now=0;now<t;now++)
	{
		if(now)putchar('\n');
		scanf("%s",num[0]);
		while(num[0][0]!='-')
		{
		run();
		scanf("%s",num[0]);
		}
	}
}