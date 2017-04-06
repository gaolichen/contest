#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define N 2100000000
int m[1100][12],t[1100],n,dead[12][12];
int cmp(const void *t1,const void *t2)
{
	if(t[*(int *)(t1)]>t[*(int *)(t2)])
		return 1;
	return -1;
}
void run()
{
	int i,j,h,live=n,last=0,min,ok,k,temp=0;
	int mark[1200],a[1100],st[12];
	for(i=1;i<=n;i++)a[i]=i;
	qsort(a+1,n,sizeof(int),cmp);
	for(i=1;i<=10;i++)
		for(j=0;j<i;j++)
			dead[i][j]=0;
	st[1]=1;
	for(i=1;i<=10;i++)
	{
		for(j=0;j<i;j++)
		{
			for(h=st[i],ok=0;h<=n&&t[a[h]]==i;h++)
			{
				if(!dead[i][j])
				{
					dead[i][j]=a[h];
					ok=1;
				}
				else if(m[dead[i][j]][j]>m[a[h]][j])
				{
					dead[i][j]=a[h];
					ok=1;
				}
				else if(m[dead[i][j]][j]==m[a[h]][j])
					ok=-1;
			}
			dead[i][j]*=ok;
		}
		st[i+1]=h;
	}
	memset(mark,0,sizeof(int)*(n+1));
	for(i=0;;i++)
	{
		if(i-last>=2520)break;
		if(live==0)
		{
			printf("%d %d\n",live,last);
			return;
		}
		min=-1;ok=0;
		for(j=1;j<=10;j++)
		if(dead[j][i%j])
		{
			k=abs(dead[j][i%j]);
			if(min==-1||m[k][i%j]<min)
			{
				min=m[k][i%j];
				ok=j;
				if(dead[j][i%j]<0)ok=-ok;
			}
			else if(m[k][i%j]==min)
				ok=-j;
		}
		if(ok>0)
		{
			live--;
			mark[dead[ok][i%ok]]=1;
			last=i+1;temp=abs(dead[ok][i%ok]);
			for(j=0;j<ok;j++)
		if(abs(dead[ok][j])==temp||dead[ok][j]<0)
			{
				dead[ok][j]=0;min=0;
				for(k=st[ok];k<=n&&t[a[k]]==ok;k++)
				if(!mark[a[k]])
				{
					if(!dead[ok][j])
					{
						dead[ok][j]=a[k];
						min=1;
					}
					else if(m[dead[ok][j]][j]>m[a[k]][j])
					{
						dead[ok][j]=a[k];
						min=1;
					}
					else if(m[dead[ok][j]][j]==m[a[k]][j])
						min=-1;
				}
				dead[ok][j]*=min;
			}
		}
	}
	printf("%d %d\n",live,last);
}
void main()
{
	int i,j,h,k;
	scanf("%d",&h);
	for(i=0;i<h;i++)
	{
		scanf("%d",&n);
		for(j=1;j<=n;j++)
			for(k=0;k<11;k++)
				m[j][k]=N;
		for(j=1;j<=n;j++)
		{
			scanf("%d",&t[j]);
			for(k=0;k<t[j];k++)
				scanf("%d",&m[j][k]);
		}
		run();
	}
}