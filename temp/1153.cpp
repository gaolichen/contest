#include<iostream.h>
#include<stdio.h>
#include<string.h>
int k2[10]={1,2,4,8,16,32,64,128,256,512};
int m,n;
void run()
{
	int i,j,k,h,r=0,a[200],count=0,b[200],temp[200],early;
	int sta,end,mid;
	while(k2[r]<n)r++;
	for(i=0;i<k2[r];i++)
		a[i]=i+1;
	for(i=2;i<=r;i++)
	{
		sta=0;end=k2[r];h=0;
		for(j=0;j<k2[r-i+1];j++)
		{
			for(k=0;k<k2[i-2];k++)
				temp[h++]=a[sta++];
			mid=k2[r]-sta;
			for(k=0;k<k2[i-2];k++)
				temp[h++]=a[mid++];
			end=mid;
		}
		memcpy(a,temp,sizeof(int)*k2[r]);
	}
	for(i=0;i<k2[r];i++)
		b[a[i]]=i;
	early=100;
	for(i=1;i*2<m;i++)
		if(m-i<=n)
		{
			j=b[i];k=b[m-i];
			if(j>k)
			{
				h=j;j=k;k=h;
			}
			sta=0;end=k2[r];
			while(1)
			{
				mid=sta+(end-sta)/2;
				if(j>=mid)
					sta=mid;
				else if(k<mid)
					end=mid;
				else break;
			}
			j=0;while(end-sta>k2[j])j++;
			if(early>j)
				early=j;
		}
	cout<<"Round"<<' '<<early<<endl;
}
int main()
{
	int i,t,tot;
	cin>>t;
	for(i=0;i<t;i++)
	{
		if(i)cout<<endl;
		tot=0;
		cin>>n>>m;
		while(n&&m)
		{
			cout<<"Case"<<' '<<++tot<<':'<<' ';
			run();
			cin>>n>>m;
		}
	}
	return 0;
}