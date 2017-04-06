#include<stdio.h>
#include<math.h>
int f[250][250][40];
int n,m,res[250];
void run()
{
	int i,j,k,h,min,tot;
	for(h=0;h<n;h++)
	for(i=h;i<n;i++)
	{
		min=-1;
		for(j=h;j<=i;j++)
		{
			for(k=h,tot=0;k<=i;k++)
				tot+=abs(res[j]-res[k]);
			if(min==-1||tot<min)
				min=tot;
		}
		f[h][i][1]=min;
	}
	for(i=2;i<=m;i++)
		for(j=0;j<n;j++)
			for(k=j+i-1;k<n;k++)
				for(h=k-1,f[j][k][i]=-1;h>=j;h--)
				{
					if(i-1>h-j+1)break;
	if(f[j][k][i]==-1||f[j][h][i-1]+f[h+1][k][1]<f[j][k][i])
				f[j][k][i]=f[j][h][i-1]+f[h+1][k][1];
				}
	printf("Total distance sum = %d\n",f[0][n-1][m]);
}
void main()
{
	int i,count=0;
	scanf("%d%d",&n,&m);
	while(n&&m)
	{
		for(i=0;i<n;i++)
			scanf("%d",&res[i]);
		printf("Chain %d\n",++count);
		run();
		putchar('\n');
		scanf("%d%d",&n,&m);
	}
}