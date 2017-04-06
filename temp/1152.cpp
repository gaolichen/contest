#include<stdio.h>
void main()
{
	int i,j,t,n,m,tot,now,count;
	scanf("%d",&t);
	for(now=0;now<t;now++)
	{
		count=1;
		if(now)printf("\n");
		scanf("%d%d",&n,&m);
		while(m||n)
		{
			tot=0;
			for(i=1;i<n;i++)
				for(j=i+1;j<n;j++)
			if((i*i+j*j+m)%(i*j)==0)
					tot++;
		printf("Case %d: %d\n",count++,tot);
		scanf("%d%d",&n,&m);
		}
	}
}