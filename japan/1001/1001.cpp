#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct NODE {
	int h,d,w;
	bool operator <(const NODE & a)const {
		if( h!=a.h)return h<a.h;
		if(d!=a.d)return d<a.d;
		return w>a.w;
	}
};

NODE doll[110*2];
char mark[110*2];
int n,f[110*2],pre[110*2],sk[110*2];

int check(int i,int j){
	return doll[i].d-2*doll[i].w>=doll[j].d&&
		doll[i].h-doll[i].w*2>=doll[j].h;
}

void run(){
	int i,j;
	memset(mark,0,sizeof(mark));
	sort(doll,doll+n+n);
	memset(f,0,sizeof(f));
	f[0]=1;
	pre[0]=-1;
	int max=0;
	for(i=1;i<n+n;i++){
		f[i]=1;
		pre[i]=-1;
		for(j=i-1;j>=0;j--)
			if(f[j]+1>f[i]&&check(i,j)){
				f[i]=f[j]+1;
				pre[i]=j;
			}
		if(f[i]>f[max])max=i;
	}
	i=max;
	while(1){
		if(i==-1)break;
		mark[i]=1;
		i=pre[i];
	}
	int ret=0;
	for(i=0;i<n+n;i++)
		if(!mark[i])sk[ret++]=i;
	if(!ret){
		for(i=n+n-1;i>n-1;i--)
			cout<<doll[i].h<<' '<<doll[i].d<<' '<<doll[i].w<<endl;
		cout<<"-"<<endl;
		for(i=n-1;i>=0;i--)
			cout<<doll[i].h<<' '<<doll[i].d<<' '<<doll[i].w<<endl;
		return ;
	}
	int haha=ret;
	for(i=j=0;i<n+n&&j<ret&&haha<n;)
		if(mark[i]){
			if(check(sk[j],i)){
				mark[i]=0;
				haha++;
				i++;
			}
			else {
				while(i<n+n&&!check(i,sk[j]))i++;
				j++;
			}
		}
	if(haha<n){
		for(;i<n+n&&haha<n;i++)
			if(mark[i]&&check(i,sk[ret-1])){
				mark[i]=0;
				haha++;
			}
	}
	for(i=n+n-1;i>=0;i--)
		if(mark[i]==mark[n+n-1])
			cout<<doll[i].h<<' '<<doll[i].d<<' '<<doll[i].w<<endl;
	cout<<'-'<<endl;
	for(i=n+n-1;i>=0;i--)
		if(mark[i]!=mark[n+n-1])
			cout<<doll[i].h<<' '<<doll[i].d<<' '<<doll[i].w<<endl;
}
int main(){
	int i,cnt=0;
	while(1){
		cin>>n;
		if(!n)break;
		if(cnt++)cout<<endl;
		for(i=0;i<n+n;i++)
			cin>>doll[i].h>>doll[i].d>>doll[i].w;
		run();
	}
	return 0;
}