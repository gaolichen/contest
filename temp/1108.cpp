#include<stdio.h>
#include<string.h>
#define N 2000
int mark[N],w[N],s[N],f[N],a[N],last[N];
int n;
void mysort()
{
	int i,j,max;	
	memset(mark,0,sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		max=-1;
		for(j=0;j<n;j++)
		{
	if(!mark[j]&&(max==-1||w[j]>w[max]))
		max=j;
	else if(!mark[j]&&w[j]==w[max]&&s[j]<s[max])
		max=j;
		}
		a[i]=max;
		mark[max]=1;
	}
}
void run()
{
	int i,j,max;
	mysort();
	f[0]=1;
	last[0]=-1;max=0;
	for(i=1;i<n;i++)
	{
	last[i]=-1;f[i]=1;
	for(j=0;j<i;j++)
	if(w[a[i]]<w[a[j]]&&s[a[i]]>s[a[j]]&&f[j]+1>f[i])
	{
		f[i]=f[j]+1;
		last[i]=j;
	}
		if(f[i]>=f[max])max=i;
	}
	printf("%d\n",f[max]);
	while(max!=-1)
	{
		printf("%d\n",a[max]+1);
		max=last[max];
	}
}
void main()
{
	n=0;
	for(n=0;;n++)
	if(scanf("%d%d",&w[n],&s[n])!=2)break;
	run();
}