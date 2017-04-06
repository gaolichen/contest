#include<stdio.h>
char p[30];
int x[30],y[30],n;
void mysort()
{
	int i,j,temp;
	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
			if(p[j]>p[j+1])
			{
				temp=p[j];p[j]=p[j+1];
				p[j+1]=temp;
				temp=x[i];x[i]=x[i+1];
				x[i+1]=temp;
				temp=y[i];y[i]=y[i+1];
				y[i+1]=temp;
			}
}
void run()
{
	int i,j,k,h,count=0;
	mysort();
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		if(j!=i)
		{
			if(y[j]!=y[i])continue;
			if(x[j]<=x[i])continue;
			for(k=0;k<n;k++)
				if(k!=i&&k!=j)
				{
					if(x[k]!=x[j])continue;
					if(y[k]>=y[j])continue;
					for(h=0;h<n;h++)
				if(h!=i&&h!=j&&h!=k&&x[h]==x[i]&&y[h]==y[k])
				{
					if(!count)putchar('\n');
					printf(" %c%c%c%c",p[i],p[j],p[k],p[h]);
					count++;
					if(count%10==0)
						putchar('\n');
				}
				}
		}
	if(count&&count%10!=0)
		putchar('\n');
	if(!count)
		printf(" No rectangles\n");
}
void main()
{
	int i,tx,ty,tot=1;
	char str[2];
	scanf("%d",&n);
	while(n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%s%d%d",str,&tx,&ty);
			p[i]=str[0];
			x[i]=tx;y[i]=ty;
		}
		printf("Point set %d:",tot++);
		run();
		scanf("%d",&n);
	}
}