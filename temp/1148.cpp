#include<stdio.h>
#include<string.h>
char map[80][80];
int mark[80][80],dis[80][80],w,h;
int sx,sy,ex,ey;
void run()
{
	int i,j,find,k;
	for(i=0;i<=w+1;i++)
		for(j=0;j<=h+1;j++)
			mark[i][j]=0;
	mark[sx][sy]=1;dis[sx][sy]=0;
	do
	{
		find=0;
	for(i=0;i<=w+1;i++)
		for(j=0;j<=h+1;j++)
			if(mark[i][j])
			{
				for(k=i+1;k<=w+1;k++)
				{
					if(map[k][j]!=' '&&(k!=ex||j!=ey))
						break;
					if(!mark[k][j])
					{
						dis[k][j]=dis[i][j]+1;
						if(!find)find=1;
						if(k==ex&&j==ey)
						{
							printf("%d segments.\n",dis[k][j]);
							return;
						}
						mark[k][j]=1;
					}
				}
				for(k=j+1;k<=h+1;k++)
				{
					if(map[i][k]!=' '&&(i!=ex||k!=ey))
						break;
					if(!mark[i][k])
					{
						dis[i][k]=dis[i][j]+1;
						if(!find)find=1;
						if(i==ex&&k==ey)
						{
							printf("%d segments.\n",dis[i][k]);
							return;
						}
						mark[i][k]=1;
					}
				}
				for(k=i-1;k>=0;k--)
				{
					if(map[k][j]!=' '&&(k!=ex||j!=ey))
						break;
					if(!mark[k][j])
					{
						dis[k][j]=dis[i][j]+1;
						if(!find)find=1;
						if(k==ex&&j==ey)
						{
							printf("%d segments.\n",dis[k][j]);
							return;
						}
						mark[k][j]=1;
					}
				}
				for(k=j-1;k>=0;k--)
				{
					if(map[i][k]!=' '&&(i!=ex||k!=ey))
						break;
					if(!mark[i][k])
					{
						dis[i][k]=dis[i][j]+1;
						if(!find)find=1;
						if(i==ex&&k==ey)
						{
							printf("%d segments.\n",dis[i][k]);
							return;
						}
						mark[i][k]=1;
					}
				}
			}
	}while(find);
	printf("impossible.\n");
}

void main()
{
	int i,j,count=0,tot=0;
	char ch;
	scanf("%d%d",&w,&h);
	while(w&&h)
	{
		ch=getchar();
		memset(map,' ',sizeof(map));
		for(i=1;i<=h;i++)
		{
			while(ch=='\n')ch=getchar();
			for(j=1;j<=w;j++)
			{
				map[j][i]=ch;
				ch=getchar();
			}
		}
		count=0;
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		while(sx||sy||ex||ey)
		{
			if(!count)
				printf("Board #%d:\n",++tot);
			printf("Pair %d: ",++count);
			run();
			scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		}
		putchar('\n');
		scanf("%d%d",&w,&h);
	}
}