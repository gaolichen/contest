#include<stdio.h>
#include<string.h>
int a[50],b[50],c[50],d[50],e[50],f[50];
int m,n,big;
int calc(int k,int m)
{
	int i,j;
	if(m<b[k])return 0;
	i=m-b[k];
	if(i>=c[k]*d[k])
		j=d[k];
	else j=i/c[k];
	j++;
	return j*=e[k];
}
void mysort()
{
	int i,j,t;
	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
			if(f[j]>f[j+1])
			{
				t=a[j];a[j]=a[j+1];
				a[j+1]=t;t=b[j];
				b[j]=b[j+1];b[j+1]=t;
				t=c[j];c[j]=c[j+1];
				c[j+1]=t;t=d[j];
				d[j]=d[j+1];d[j+1]=t;
				t=e[j];e[j]=e[j+1];
				e[j+1]=t;t=f[j];
				f[j]=f[j+1];f[j+1]=t;
			}
	for(i=0;i<n;i++)
		if(f[i]==2)break;
	big=i-1;
}
int res(int k1,int t1,int k2,int t2)
{
	int i,j,h,t=0,min=0,l;
	if(!t1&&!t2)return 0;
	for(i=0;i<=t1;i++)
	{
		h=2100000000;
		l=(100-i*a[k1])/a[k2];
		if(100-i*a[k1]>0&&(100-i*a[k1])%a[k2]!=0)l++;
		if(l>t2)continue;
		if(l<0)l=0;
		if(i&&t1)h=t1/i;
		if(l&&t2&&t2/l<h)h=t2/l;
		t1-=h*i;t2-=h*l;
		j=res(k1,t1,k2,t2);
		if(h+j>min)min=h+j;
		t1+=i*h;t2+=l*h;
		if(i*a[k1]>=100)break;
	}
	return min;
}
void run()
{
	int i,j,t2,max,best=0,k;
	mysort();
	for(i=0;i<=big;i++)
		for(j=big+1;j<n;j++)
			for(k=0;k<=d[i]+1;k++)
			{
				if(k&&(k-1)*c[i]+b[i]>m)break;
				if(k)t2=calc(j,m-(k-1)*c[i]-b[i]);
				else t2=calc(j,m);
				max=res(i,k*e[i],j,t2);
				if(max>best)best=max;
			}
	if(big==-1||big==n-1)
	{
		for(j=0;j<n;j++)
		{
			t2=calc(j,m);
			k=100/a[j];
			if(100%a[j]!=0)k++;
			if(t2/k>best)best=t2/k;
		}
	}
	printf("%d\n",best);
}
int main()
{
	int i;
	while(1)
	{
		scanf("%d",&n);
		if(!n)break;
		scanf("%d",&m);
		for(i=0;i<n;i++)
		scanf("%d%d%d%d%d%d",&a[i],&b[i],&c[i],&d[i],&e[i],&f[i]);
		run();
	}
	return 0;
}