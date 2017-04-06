#include<iostream.h>
int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int main()
{
	int n,i,j;
	while(cin>>n)
	{
		j=0;
		for(i=1;i<=n;i++)
			if(gcd(n,i)==1)j++;
		cout<<j<<endl;
	}
	return 0;
}