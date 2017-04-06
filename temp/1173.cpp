#include<stdio.h>
int x[30],y[30],n;
double s[30];
void run()
{
	int i,j;
	for(i=1;i<n;i++)
		if(y[i]==0)
			break;
	s[0]=0;t=0;l[t]=fabs(x[i+1]-x[i]);
	j=i-1;k=i+2;last=i;
	do{
		if(y[j]<y[k])
		{
		dx=(y[j]-y[last])*(x[k]-x[k-1])/(double)(y[k]-y[k-1]);
			l[++t]=x[k-1]-x[j]+dx;
//			s[t]=cou(j)+s[t-1];
			last=j;
			j--;
		}
		else 
		{
		dx=(y[j]-y[last])*(x[k]-x[k-1])/(double)(y[k]-y[k-1]);
			s[++t]=cou(k)+s[t-1];
			k++;
		}
	}while(j);
	sum=s[t]/48.0;tot=0;
	j=0;
	for(i=1;i<48;i++)
	{
		tot+=sum;
		while(s[j]<tot-1e-6)j++;
		if(fabs(s[j]-tot)<1e-6)
			len[i]=y[j];
		else
		{
			t=tot-s[j-1];
			ds=s[j]-s[j-1];
		}
	}
}
void main()
{
	int i,j;
	scanf("%d",&t);
	for(now=0;now<t;now++)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d%d",&x[i],&y[i]);
		run();
	}
}