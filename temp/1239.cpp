#include<iostream.h>
#include<string.h>
int n,mark[10000],peg[60],tot[60];
void init()
{
	int i;
	memset(mark,0,sizeof(mark));
	for(i=1;i<100;i++)
		mark[i*i]=1;
}
void run()
{
	int i,j,count=1;
	init();
	peg[0]=1;
	for(i=2;i<4000;i++)
	{
		for(j=0;j<count;j++)
			if(mark[peg[j]+i])
			{
				peg[j]=i;
				break;
			}
		if(j==count)
		{
			peg[count]=i;
			tot[count]=i-1;
			if(count==55)break;
			count++;
		}
	}
}
int main()
{
	int i,t;
	run();
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		cout<<tot[n]<<endl;
	}
	return 0;
}