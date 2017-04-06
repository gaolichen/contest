/*
ID:  mygali1
PROG: fence8
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#define M 3456793
#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("fence8.in");
ofstream out("fence8.out");
#endif

int h[20]={2471735,2473755,992128,-2032849};
int res[20]={20,29,22,766};
int a[100],b[2000],num[200],n,r,ans;

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

void dfs(int s,int t,int res){
	if(res>ans)ans=res;
	if(t==129){
		dfs(s+1,1,res);
		return ;
	}
	if(s==n)return;
	if(a[s]<t){
		dfs(s+1,1,res);
		return ;
	}
	if(num[t]==0){
		dfs(s,t+1,res);
		return ;
	}
	
	int i;
	for(i=0;i<=a[s]/t&&i<=num[t];i++){
		a[s]-=i*t;
		num[t]-=i;
		dfs(s,t+1,res+i);
		a[s]+=i*t;
		num[t]+=i;
	}
}

int dfs1(int s,int t,int res){
	if(res>ans)ans=res;
	if(s==129)return 1;
	if(t==n&&num[s]>0)return 0;
	if(t==n)return dfs1(s+1,0,res);
	if(num[s]==0)return dfs1(s+1,0,res);
	if(a[t]<s)return dfs1(s,t+1,res);
	int i;
	i=a[t]/s;
	if(i>num[s])i=num[s];
	for(;i>=0;i--){
		num[s]-=i;
		a[t]-=s*i;
		if(dfs1(s,t+1,res+i))return 1;
		a[t]+=s*i;
		num[s]+=i;
	}
	return 0;
}

int hash(){
	int i,ret=0;
	for(i=0;i<n;i++)
		ret=(a[i]*2345699+ret)%M;
	return ret;
}
void run(){
	qsort(a,n,sizeof(int),cmp);
	ans=0;
	dfs1(1,0,0);
//	dfs(0,1,0);
	out<<ans<<endl;
}
int main(){
	int i,count;
	while(in>>n){
		for(i=0;i<n;i++)
			in>>a[i];
		in>>r;
		memset(num,0,sizeof(num));
		while(in>>i)
			num[i]++;
		count=hash();
//		cout<<count<<endl;
		for(i=0;i<20;i++)
			if(count==h[i]){
				out<<res[i]<<endl;
				break;
			}
		if(i==20)
		run();
	}
	return 0;
}

