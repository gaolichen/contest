#include<map>
#include<iostream>
#define MAXN 51000
#define inf 2100000000

using namespace std;

int a[MAXN],f[MAXN],n;

int mybsearch(int low,int top,int key){
	int mid=(low+top)/2;
	if(mid==low){
		if(f[low]>=key)return low-1;
		if(f[top]>=key)return top-1;
		return top;
	}
	if(f[mid]>=key){
		return mybsearch(low,mid,key);
	}
	else return mybsearch(mid,top,key);
}

void run(){
	int i,k,j;
	if(n==0){
		cout<<0<<endl;
		return ;
	}
	for(i=0;i<=n;i++)f[i]=inf;
	int max=1;
	f[1]=a[0];
	for(i=1;i<n;i++){
		k=mybsearch(1,max,a[i]);
//		cout<<k<<endl;
		if(f[k+1]>a[i])f[k+1]=a[i];
		j=k;
		while(j>=1&&f[j]>a[i])f[j--]=a[i];
		if(k+1>max)max=k+1;
//		for(j=0;j<=max;j++)
//			cout<<f[j]<<' ';
//		cout<<endl;
	}
	cout<<max<<endl;
}

int main(){
	int i;
	while(cin>>n){
		for(i=0;i<n;i++)
			cin>>a[i];
		run();
	}
	return 0;
}