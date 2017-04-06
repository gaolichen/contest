#include<stdio.h>
#include<string.h>
int x[3],y[3],z[3][2];
int check(int j,int k)
{
	int i,res[3],tx,ty;
	for(i=0;i<3;i++)
	{
		tx=j-x[i];
		ty=k-y[i];
		res[i]=tx*z[i][1]-ty*z[i][0];
		if(i)
		{
			if(res[i]*res[i-1]<=0)return 0;
			
		}
	}
	return 1;
}
void run()
{
	int i,j,minx=10,miny=10,maxx=-10,maxy=-10,t;
	int top=-10,low=10,right=-10,left=10,mark[20][20];
	memset(mark,0,sizeof(mark));
	for(i=0;i<3;i++)
	{
		if(x[i]<minx)minx=x[i];
		if(x[i]>maxx)maxx=x[i];
		if(y[i]<miny)miny=y[i];
		if(y[i]>maxy)maxy=y[i];
	}
	z[0][0]=x[1]-x[0];z[0][1]=y[1]-y[0];
	z[1][0]=x[2]-x[1];z[1][1]=y[2]-y[1];
	z[2][0]=x[0]-x[2];z[2][1]=y[0]-y[2];
	for(i=minx+1;i<maxx;i++)
		for(j=miny+1;j<maxy;j++)
			if(check(i,j))
			{
				mark[i+9][j+9]=1;
				if(j>top)top=j;
				if(j<low)low=j;
				if(i>right)right=i;
				if(i<left)left=i;
			}
	for(j=top;j>=low;j--)
	{
		for(i=right;i>=left;i--)
			if(mark[i+9][j+9]){t=i;break;}
		for(i=left;i<=t;i++)
		{
			if(i!=left)putchar(' ');
			if(mark[i+9][j+9])
			{
				printf("(%2d,%3d)",i,j);
			}
			else printf("        ");
		}
		putchar('\n');
	}
}
void main()
{
	int tot=0;
while(scanf("%d%d%d%d%d%d",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2])==6)
{
	if(!tot)
	{
		printf("Program 4 by team X\n");
		tot=1;
	}
	run();
	putchar('\n');
}
printf("End of program 4 by team X\n");
}