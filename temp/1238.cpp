#include<iostream.h>
#include<string.h>
#include<math.h>
char num[500010];
int dig[500010],num2[500010],count,len,pri[200];
void init()
{
	double i,j;
	memset(dig,0,sizeof(dig));
	for(i=3;i<=100005;i++)
	{
		j=i*log10(i);
		dig[(int)j+1]=(int)i;
	}
}
void init2()
{
	int i,j,mark[100001];
	count=0;
	memset(mark,0,sizeof(mark));
	for(i=2;i*i<=100000;i++)
		if(!mark[i])
		{
			for(j=i;j*i<=100000;j++)
				mark[j*i]=1;
			pri[count++]=i;
		}
}
int mod(int k)
{
	int i=0,j=0,t=0;
	while(i<=len)
	{
		if(t<k)
		{
			if(i<len)
			t=t*10+num2[i];
			i++;
			if(j)num2[j++]=0;
		}
		if(t>=k)
		{
			num2[j++]=t/k;
			t%=k;
			if(i<len)t=10*t+num2[i];
			i++;
		}
	}
	len=j;
	if(!len)return 0;
	if(t)return 0;
	else return 1;
}
void run()
{
	int i,j,t,k,temp;
	len=strlen(num);
	if(len==1)
	{
		if(num[0]=='1')
			cout<<1<<endl;
		else if(num[0]=='4')
			cout<<2<<endl;
		else cout<<-1<<endl;
		return;
	}
	if(!dig[len])
	{
		cout<<-1<<endl;
		return;
	}
	for(i=0;i<len;i++)
		num2[i]=num[i]-'0';
	for(i=1;i<count;i++)
		if(dig[len]%pri[i]==0&&i!=2)
			break;
	k=dig[len];
	if(i!=count)
	{
		for(j=0;j<3;j++)
			if(!mod(k))
			{
				cout<<-1<<endl;
				return;
			}
		cout<<k<<endl;
		return;
	}
	t=0;
	while(k%10==0)
	{
		k/=10;t++;
	}
	for(i=1;i<=t*dig[len];i++)
		if(num2[len-i])
		{
			cout<<-1<<endl;
			return;
		}
	if(k==1)
	{
		if(num2[0]!=1)
			cout<<-1<<endl;
		else 
		cout<<dig[len]<<endl;
		return;
	}
	temp=dig[len];
	len=len-t*dig[len];t=0;
	j=k;
	if(j%2==0)
		while(j%2==0)
	{
		j/=2;t++;
	}
	else while(j%5==0)
	{
		j/=5;t++;
	}
	for(i=0;i<=len/t+4&&i<temp&&i<3;i++)
		if(!mod(k))
		{
			cout<<-1<<endl;
			return;
		}
	cout<<temp<<endl;
}
int main()
{
	int i,t;
	init();
	for(i=0;i<=500000;i++)
		if(dig[i]==65536)break;
	cout<<i<<endl;
	init2();
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>num;
		run();
	}
	return 0;
}
