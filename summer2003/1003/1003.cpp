#include<iostream>
#include<cmath>
#include<cstdio>

#include<algorithm>
using namespace std;

struct NODE{
	int v;
	double e;
	bool operator<(const NODE &a)const {
		return e/v<a.e/a.v;
	}
};

NODE wash[110];
int vol,n,m;
double ret;

void dfs(int k,int tv,double ans){
	if(ans<ret)ret=ans;
	if(k==n)return ;
	if(ans+tv*wash[k].e/wash[k].v>=ret)return ;
	int i;
	i=floor(tv/wash[k].v);
	for(;i>=0;i--){
		dfs(k+1,tv-i*wash[k].v,ans+i*wash[k].e);
	}
}

void run(){
	ret=0;
	dfs(0,vol,0);
	double a;
	a=ret-floor(ret);
	a=pow(10,a);
	printf("%.2fe%d\n",a,(int)floor(ret));
}



int main(){
	int cnt=0;
	int i;
	while(cin>>n){
		if(n<=0)break;
		printf("Case %d:\n",++cnt);
		for(i=0;i<n;i++){
			cin>>wash[i].v>>wash[i].e;
			wash[i].e=log10(1-wash[i].e);
		}
		sort(wash,wash+n);
		cin>>m;
		while(m--){
			cin>>vol;
			run();
		}
		putchar('\n');
	}
	return 0;
}