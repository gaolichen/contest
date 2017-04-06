#include<stdio.h>
#include<string.h>
char pic[60][60];
int doc[100],m,n;
int a[4]={1,-1,0,0};
int b[4]={0,0,1,-1};
void run()
{
	int i,j,k,tot=0,sk[4000][2],open,close;
	int x,y,tx,ty,t;
	char mark[60][60];
	memset(mark,0,sizeof(mark));
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(pic[i][j]!='.'&&!mark[i][j])
			{
				doc[tot]=0;
				open=close=0;
				sk[0][0]=i;
				sk[0][1]=j;
				mark[i][j]=1;
				if(pic[i][j]=='X')
					doc[tot]++;
				while(open<=close)
				{
					x=sk[open][0];
					y=sk[open][1];
					for(k=0;k<4;k++)
					{
						tx=x+a[k];
						ty=y+b[k];
						if(tx<0||tx>=n||ty<0||ty>=n)
							continue;
						if(pic[tx][ty]=='.')
							continue;
						if(mark[tx][ty])continue;
						sk[++close][0]=tx;
						sk[close][1]=ty;
						mark[tx][ty]=1;
						if(pic[tx][ty]=='X')
							doc[tot]++;
					}
					open++;
				}
				tot++;
			}
	for(i=1;i<tot;i++)
		for(j=0;j<tot-i;j++)
			if(doc[j]>doc[j+1])
			{
				t=doc[j];doc[j]=doc[j+1];
				doc[j+1]=t;
			}
	for(i=0;i<tot;i++)
	{
		if(i)putchar(' ');
		printf("%d",doc[i]);
	}
	putchar('\n');
}
void main()
{
	int i,count=0;
	scanf("%d%d",&n,&m);
	while(m&&n)
	{
		for(i=0;i<m;i++)
			scanf("%s",pic[i]);
		printf("Throw %d\n",++count);
		run();
		putchar('\n');
		scanf("%d%d",&n,&m);
	}
}