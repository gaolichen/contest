#include<stdio.h>
#include<string.h>
int p[4]={1,10,100,1000};
int num1[300000],num2[300000],res[300000];
int l;
void muti(int *num1,int *num2,int *res)
{
	int i,j,t;
	memset(res,0,sizeof(res));
	res[0]=num2[0];
	for(i=1;i<=num1[0];i++)
	{
		for(j=1,t=0;j<=num2[0];j++)
		{
			res[i+j-1]+=num1[i]*num2[j]+t;
			if(res[i+j-1]>=10000)
			{
				t=res[i+j-1]/10000;
				res[i+j-1]%=10000;
			}
			else t=0;
		}
		while(t)
		{
			res[++res[0]]=t%10000;
			t/=10000;
		}
	}
}
int main()
{
	int n,i,k,j;
	char ch1,ch2;
	while(scanf("%d%d",&l,&n)==2)
	{
		getchar();
		k=l/4+!!(l%4);
		j=l-(k-1)*4;
		num1[0]=num2[0]=k;
		num1[k]=num2[k]=0;
		for(i=0;i<j;i++)
		{
			ch1=getchar();
			ch2=getchar();
			getchar();
			num1[k]=10*num1[k]+(ch1-'0');
			num2[k]=10*num2[k]+(ch2-'0');
		}
		for(i=k-1;i>=1;i--)
			for(j=0,num1[i]=num2[i]=0;j<4;j++)
			{
				ch1=getchar();
				ch2=getchar();
				getchar();
				num1[i]=10*num1[i]+(ch1-'0');
				num2[i]=10*num2[i]+(ch2-'0');
			}
		muti(num1,num2,res);
		for(i=0;i<n;i++)
		{
			scanf("%d",&k);
			if(k>res[0]*4)
			{
				printf("0\n");continue;
			}
			j=k/4+1;
			k++;
			k=k-(j-1)*4;
			printf("%d\n",(res[j]/p[k-1])%10);
		}
	}
	return 0;
}