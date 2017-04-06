#include<stdio.h>
#define N 501
#define M 2000
#define MAX 2100000000
void main()
{
	int i,j,k,n,m,count=1,max1,max2,temp1,temp2,min;
	long dom[N][N],key[N],t,edg[M][3],mark[M];
	float max,s;
	scanf("%d%d",&n,&m);
	while(n!=0||m!=0)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				dom[i][j]=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&j,&k,&t);
			edg[i][0]=t;
			edg[i][1]=j;
            edg[i][2]=k;
			if(!dom[j][k]||dom[j][k]>t)
				dom[k][j]=dom[j][k]=t;
		}
		for(i=1;i<=n;i++)
		{
			key[i]=MAX;
			mark[i]=0;
		}
		key[1]=0;i=1;k=1;
		mark[1]=1;temp1=1;
		do
		{
			min=MAX;
			for(j=1;j<=n;j++)
				if(!mark[j])
			{
if(dom[i][j]&&(key[j]>key[i]+dom[i][j]))
key[j]=key[i]+dom[i][j];
			 if(key[j]<min)
			 {
				 min=key[j];
				 temp1=j;
			 }
			}
			i=temp1;
			mark[i]=1;
		}while(min!=MAX);
		max=0;max1=1;max2=0;
		for(i=1;i<=m;i++)
		{
			temp1=edg[i][1];
			temp2=edg[i][2];
			if(key[temp2]>key[temp1])
			{
			     k=temp1;
				 temp1=temp2;
				 temp2=k;
			}
if(key[temp1]-key[temp2]==edg[i][0])
		{
			s=(float)key[temp1];
			if(s>max+0.1)
			{
				max=s;
				max1=temp1;
				max2=0;
			}
		}
		else
		{
k=key[temp1]-key[temp2];
s=(float)(key[temp2]+(edg[i][0]+k)/2.0);
		if(s>max+0.1)
		{
			max=s;
			max1=temp1;
			max2=temp2;
		}
		}
		}
printf("System #%d\n",count);
printf("The last domino falls after %.1f seconds, ",max);
        if(!max2)
        printf("at key domino %d.\n",max1);
		else
		{
			if(max2<max1)
			{
				temp1=max2;
				max2=max1;
				max1=temp1;
			}
printf("between key dominoes %d and %d.\n",max1,max2);
		}
		printf("\n");
		count++;
		scanf("%d%d",&n,&m);
	}
}
	
