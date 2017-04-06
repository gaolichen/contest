#ifdef WIN32
#	pragma warning(disable:4786)
#define for if(0);else for
#endif
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
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

#define all(a) a.begin(),a.end()


inline int max(int a,int b){
	return a>b?a:b;
}
inline int min(int a,int b){
	return a>b?b:a;
}
struct NODE{
	int s,e,c;
	bool operator<(const NODE& t)const {
		if(s!=t.s)return s<t.s;
		return e<t.e;	
	}
/*	bool operator == (const NODE &t)const {
		return s==t.s&&e==t.e&&c==t.c;
	}*/
};

bool lt(NODE a,NODE b){
	if(a.e!=b.e)return a.e<b.e;
	return a.s<b.s;
}
vector<NODE> vn;
int n;
char mark[50012];

void run(){
	for(int i=0;i<n;i++){
		vn[i].e++;
		mark[vn[i].s]=mark[vn[i].e]=1;
	}
	sort(all(vn));
	int st;
	for(int i=0;i<vn.size();i++){
		int j=i;
		while(j<vn.size()&&vn[j].s==vn[i].s)j++;
		for(int k=j-1;k>i;k--){
			int t=max(0,vn[k].c-vn[k-1].c);
			t=min(vn[k].e-vn[k-1].e,t);
			vn[k-1].c=max(vn[k-1].c,vn[k].c-t);
			vn[k].s=vn[k-1].e;
			vn[k].c=t;
		}
		i=j-1;
	}
	int cnt=0;
	for(int i=0;i<vn.size();i++){
		if(vn[i].s<vn[i].e)vn[cnt++]=vn[i];
	}
	vn.resize(cnt);
	sort(all(vn),lt);
	for(int i=0;i<vn.size();i++){
		int j=i;
		while(j<vn.size()&&vn[j].e==vn[i].e)j++;
		for(int k=i;k<j-1;k++){
			int t=max(0,vn[k].c-vn[k+1].c);
			t=min(vn[k+1].s-vn[k].s,t);
			vn[k+1].c=max(vn[k+1].c,vn[k].c-t);
			vn[k].e=vn[k+1].s;
			vn[k].c=t;
		}
		i=j-1;
	}
	cnt=0;
	for(int i=0;i<vn.size();i++){
		if(vn[i].s<vn[i].e)vn[cnt++]=vn[i];
	}
	vn.resize(cnt);
//	for(int i=0;i<vn.size();i++){
//		cout<<vn[i].s<<' '<<vn[i].e<<' '<<vn[i].c<<endl;
//	}
	sort(all(vn));
	for(int i=0;i<vn.size();i++){
		int j=i;
		while(j<vn.size()&&vn[j].s==vn[i].s)j++;
		for(int k=j-1;k>i;k--){
			int t=max(0,vn[k].c-vn[k-1].c);
			t=min(vn[k].e-vn[k-1].e,t);
			vn[k-1].c=max(vn[k-1].c,vn[k].c-t);
			vn[k].s=vn[k-1].e;
			vn[k].c=t;
		}
		i=j-1;
	}
	cnt=0;
	for(int i=0;i<vn.size();i++){
		if(vn[i].s<vn[i].e)vn[cnt++]=vn[i];
	}
	vn.resize(cnt);
	sort(all(vn),lt);
	for(int i=0;i<vn.size();i++){
		int j=i;
		while(j<vn.size()&&vn[j].e==vn[i].e)j++;
		for(int k=i;k<j-1;k++){
			int t=max(0,vn[k].c-vn[k+1].c);
			t=min(vn[k+1].s-vn[k].s,t);
			vn[k+1].c=max(vn[k+1].c,vn[k].c-t);
			vn[k].e=vn[k+1].s;
			vn[k].c=t;
		}
		i=j-1;
	}
	cnt=0;
	for(int i=0;i<vn.size();i++){
		if(vn[i].s<vn[i].e)vn[cnt++]=vn[i];
	}
	vn.resize(cnt);
//	for(int i=0;i<vn.size();i++){
//		cout<<vn[i].s<<' '<<vn[i].e<<' '<<vn[i].c<<endl;
//	}
	sort(all(vn));
	int ret=0,pre=-1;
	st=0;
	for(int i=0;i<50002;i++)if(mark[i]){
		if(pre!=-1){
			int t=0,j;
			for(j=st;j<vn.size();j++){
				if(vn[j].s!=pre)break;
				t=max(t,vn[j].c-(vn[j].e-i));
			}
			t=min(i-pre,t);
			for(int k=st;k<j;k++){
				vn[k].s=i;
				vn[k].c-=t;
				if(vn[k].c<0)vn[k].c=0;
			}
			int cur=j;
			for(int k=j-1;k>=st;k--){
				if(vn[k].s<vn[k].e)vn[--cur]=vn[k];
			}
			st=cur;
			ret+=t;
		}
		pre=i;
	}
	cout<<ret<<endl;
}
int main(){
	while(scanf("%d",&n)==1){
		vn.clear();
//		n=50000;
		for(int i=0;i<n;i++){
			NODE tmp;
			scanf("%d %d %d",&tmp.s,&tmp.e,&tmp.c);
//			tmp.s=i;tmp.e=n;tmp.c=n-i+1;
			if(tmp.s>tmp.e)swap(tmp.s,tmp.e);
			vn.push_back(tmp);
		}
		run();
	}
	return 0;	
}