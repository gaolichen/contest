#include<stdio.h>
#include<string.h>
#define N 1000
int sta[N],end[N],len[N],r[N],n;
void msort()
{
	int i,j,mark[N];
	memset(mark,0,sizeof(mark));
	memset(r,-1,sizeof(r));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		if(!mark[j]&&(r[i]==-1||len[j]>len[r[i]]))
				r[i]=j;
		mark[r[i]]=1;
	}
}
void run()
{
	int i,j,max,f[N],last[N];
	msort();
	f[0]=1;max=0;last[0]=-1;
	for(i=1;i<n;i++)
	{
		f[i]=1;last[i]=-1;
		for(j=i-1;j>=0;j--)
if(sta[r[i]]>sta[r[j]]&&end[r[i]]<end[r[j]]&&f[j]+1>f[i])
			{
				f[i]=f[j]+1;
				last[i]=j;
			}
	if(f[i]>f[max])max=i;
	}
	printf("%d\n",f[max]);
	do
	{
	printf("%d ",r[max]+1);
		max=last[max];
	}while(max!=-1);
	printf("\n");
}
void main()
{
	int i;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&sta[i],&end[i]);
			len[i]=end[i]-sta[i];
		}
		run();
	}
}