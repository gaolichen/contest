#include<stdio.h>
#include<string.h>
#define N 300
int count,mark[N][N],li[N],tot,x[N],y[N];
void mysort()
{
	int i,j,t;
	for(i=1;i<count;i++)
		for(j=0;j<count-i;j++)
		{
			if(x[j]>x[j+1])
			{
			t=x[j];x[j]=x[j+1];
			x[j+1]=t;t=y[j];
			y[j]=y[j+1];y[j+1]=t;
			}
		else if(x[j]==x[j+1]&&y[j]>y[j+1])
			{
				t=y[j];y[j]=y[j+1];
				y[j+1]=t;
			}
		}
}
void print(int i,int j)
{
	int k;
	printf("(%4d,%4d)",x[i],y[i]);
	printf("(%4d,%4d)",x[j],y[j]);
	for(k=0;k<tot;k++)
	printf("(%4d,%4d)",x[li[k]],y[li[k]]);
	putchar('\n');
}
int check(int i,int j,int k)
{
if((y[j]-y[i])*(x[k]-x[i])==(x[j]-x[i])*(y[k]-y[i]))
		return 1;
	return 0;
}
void run()
{
	int i,j,find=0,k,h;
	mysort();
	for(i=0;i<count;i++)
		for(j=0;j<count;j++)
			mark[i][j]=-1;
	for(i=0;i<count;i++)
	for(j=i+1;j<count;j++)
		if(mark[i][j]<0)
		{
			tot=0;
		for(k=j+1;k<count;k++)
if(mark[i][k]<0&&mark[j][k]<0&&check(i,j,k))
		{
			mark[j][k]=mark[k][j]=i;
			mark[i][k]=mark[k][i]=i;
			for(h=0;h<tot;h++)
		mark[k][li[h]]=mark[li[h]][k]=i;
			li[tot++]=k;
		}
			if(tot)
			{
			mark[i][j]=mark[j][i]=i;
				if(!find){
	printf("The following lines were found:\n");
				find=1;
				}
				print(i,j);
			}
		}
	if(!find)
	printf("No lines were found\n");
}
void main()
{
	int i;
	scanf("%d%d",&x[0],&y[0]);
	while(x[0]||y[0])
	{
		i=0;
		while(x[i]||y[i])
		{
		if(i&&x[i]==x[i-1]&&y[i]==y[i-1])i--;
		i++;
		scanf("%d%d",&x[i],&y[i]);
		}
		count=i;
		run();
		scanf("%d%d",&x[0],&y[0]);
	}
}