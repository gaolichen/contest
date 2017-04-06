#include<stdio.h>
#include<string.h>
#define N 1000
int dec[3*N],len,num[3*N];
char oct[N];
void con(int *num)
{
	int j=0,t=num[0];
	while(j<3*len)
	{
		if(t>=8)
		{
			num[j++]=t/8;
			t=t-(t/8)*8;
			t=t*10+num[j];
		}
		else 
		{
			t=t*10+num[++j];
			num[j-1]=0;
		}
	}
}
void plus(int *num)
{
	int i;
	for(i=0;i<3*len;i++)
		dec[i]+=num[i];
}
void run()
{
	int i,j,k;
	len=strlen(oct);
	for(i=0;i<len;i++)
		if(oct[i]>='0'&&oct[i]<='9')
			oct[i]-='0';
	memset(dec,0,sizeof(int)*3*(len+1));
	for(i=2,k=1;i<len;i++)
	{
		memset(num,0,sizeof(int)*3*len);
		num[0]=oct[i];
		for(j=0;j<k;j++)
			con(num);
		plus(num);
		k++;
	}
	for(i=3*len;i>0;i--)
		if(dec[i]>9)
		{
			dec[i-1]+=dec[i]/10;
			dec[i]%=10;
		}
	i=3*len;
	while(dec[i]==0)i--;
	for(j=0;j<=i;j++)
	{
		if(j==1)
			putchar('.');
		printf("%d",dec[j]);
	}
	printf(" [10]\n");
}
void main()
{
	while(gets(oct))
	{
		printf("%s [8] = ",oct);
		run();
	}
}