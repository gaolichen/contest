#include<stdio.h>
#include<string.h>
#define N 200
int step[N*N][2],a[N][N],mark[N][N],f[N][N],n,k,max;
void mysort()
{
	int i,j,min,h;
	memset(mark,0,sizeof(mark));
	mark[0][0]=1;
	step[0][0]=0;step[0][1]=0;
	for(i=1;i<n*n;i++)
	{
		min=-1;
		for(j=0;j<n;j++)
		for(h=0;h<n;h++)
		if(!mark[j][h]&&(min==-1||a[j][h]<min))
		{
			min=a[j][h];
			step[i][0]=j;
			step[i][1]=h;
		}
		mark[step[i][0]][step[i][1]]=1;
	}
}
int check(int x,int y,int z,int w)
{
	if(mark[x][y])return 0;
	if(a[x][y]>=a[z][w])return 0;
	if(f[x][y]+a[z][w]<=max)
		return 0;
	return 1;
}
void run()
{
	int i,j,best,tx,ty;
	mysort();
	mark[0][0]=0;
	f[0][0]=a[0][0];
	best=f[0][0];
	for(i=1;i<n*n;i++)
	{
		tx=step[i][0];
		ty=step[i][1];
		max=0;
		for(j=1;j<=k;j++)
		{
			if(tx-j<0)break;
			if(check(tx-j,ty,tx,ty))
		max=f[tx-j][ty]+a[tx][ty];
		}
		for(j=1;j<=k;j++)
		{
			if(tx+j>=n)break;
			if(check(tx+j,ty,tx,ty))
		max=f[tx+j][ty]+a[tx][ty];
		}
		for(j=1;j<=k;j++)
		{
			if(ty-j<0)break;
			if(check(tx,ty-j,tx,ty))
		max=f[tx][ty-j]+a[tx][ty];
		}
		for(j=1;j<=k;j++)
		{
			if(ty+j>=n)break;
			if(check(tx,ty+j,tx,ty))
		max=f[tx][ty+j]+a[tx][ty];
		}
		if(max>a[tx][ty])
		{
			f[tx][ty]=max;
			mark[tx][ty]=0;
		if(f[tx][ty]>best)
			best=f[tx][ty];
		}
	}
	printf("%d\n",best);

}
void main()
{
	int i,j;
	scanf("%d%d",&n,&k);
	while(n!=-1&&k!=-1)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
		run();
		scanf("%d%d",&n,&k);
	}
}