#pragma warning(disable:4786)
#include<map>
#include<iostream>

using namespace std;

//64 bit integer definition
#ifdef WIN32
#define in_routine(type,spec) \
istream& operator>>(istream& s,type &d){char b[30];s>>b;sscanf(b,spec,&d);return s;}
#define out_routine(type,spec) \
ostream& operator<<(ostream& s,type d){char b[30];sprintf(b,spec,d);s<<b;return s;}
typedef signed __int64 i64; in_routine(i64,"%I64d") out_routine(i64,"%I64d")
typedef unsigned __int64 u64; in_routine(u64,"%I64u") out_routine(u64,"%I64u")
#else
typedef signed long long i64;
typedef unsigned long long u64;
#endif

map< i64,int> mu;
i64 n;

void init(){
	i64 i=1,max=1,j=1,tmp;
	max=((max<<32)-1);
	while(i<=max){
		mu[i];
		tmp=i;
		i+=j;
		j=tmp;
	}
}

int calc(int n){
	if(mu.find(n)!=mu.end())return n;
	map<i64,int>::iterator it;
	for(it=mu.begin();it!=mu.end();++it)
		if(it->first>n)break;
	it--;
	return calc(n-it->first);
}
int main(){
	init();
	int cnt=0;
	while(1){
		cin>>n;
		if(n<0)break;
		cout<<"Test "<<++cnt<<":"<<endl;
		if(n==0){
			cout<<endl;
			continue;
		}
		if(n==1){
			cout<<"Yes 1"<<endl;
			continue;
		}
		if(mu.find(n)!=mu.end()){
			cout<<"No"<<endl;
		}
		else {
			map<i64,int>::iterator it;
			for(it=mu.begin();it!=mu.end();++it)
				if(it->first>n)break;
			--it;
			cout<<"Yes "<<calc(n-it->first)<<endl;
		}
	}
	return 0;
}