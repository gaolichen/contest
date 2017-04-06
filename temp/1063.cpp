#include<iostream.h>
#include<string.h>
long long p[100],a[3][100],n,m;
void run()
{
	long long i,j;
	int flag;
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++)
		a[0][i]=1;
	for(i=1;i<=n;i++)
	{
		if(m==0)break;
		j=(m&1)+(m>>1);
		if(i%2==0)
		{
			j=3-j%3;
			if(j==3)j=0;
			a[0][i]=0;
			a[j][i]=1;
		}
		else
		{
			j%=3;
			a[0][i]=0;
			a[j][i]=3;
		}
		m>>=1;
	}
	for(i=0;i<3;i++)
	{
		cout<<char('A'+i)<<": ";
		for(j=n,flag=0;j>0;j--)
			if(a[i][j])
			{
				if(flag++)cout<<' ';
				cout<<j;
			}
		cout<<endl;
	}
	cout<<endl;
}
int main()
{
	int i;
	p[0]=1;
	for(i=1;i<64;i++)
		p[i]=p[i-1]*2;
	while(cin>>n>>m)
		run();
	return 0;
}
