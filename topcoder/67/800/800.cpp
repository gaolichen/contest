//program framework generated with WishingBone's parser :)-

//common header
#ifdef WIN32
#	pragma warning(disable:4786)
#endif
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
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

//common routines
#ifdef WIN32
#define min(a,b) _cpp_min(a,b)
#define max(a,b) _cpp_max(a,b)
#endif
#define abs(a) ((a)>0?(a):-(a))
#define s2in(s,in) istringstream in(s)
#define inmat(i,j,m,n) ((i)>=0&&(i)<(m)&&(j)>=0&&(j)<(n))
#define cls(a) memset((a),0,sizeof(a))
#define VI vector<int>
#define V64 vector<i64>
#define VS vector<string>
#define VD vector<double>
int mx[8]={0,1,0,-1,1,1,-1,-1};
int my[8]={1,0,-1,0,1,-1,-1,1};
template <class T>
T gcd(T a,T b){for(T c;b;c=a,a=b,b=c%b);return a;}
template <class T>
T lcm(T a,T b){return a/gcd(a,b)*b;}

template <class T>
void remove(vector<T>&v,const T&e){
	v.resize(remove(v.begin(),v.end(),e)-v.begin());
}
template <class T>
void insert(vector<T>&v,int isnum,const T&e){
	v.resize(v.size()+1);
	for(int i=v.size()-1;i>isnum;v[i--]=v[i-1]);
	v[isnum]=e;
}
void insert(string &s,int isnum,const string&is){
string t=s;s.resize(isnum);s+=is+(t.c_str()+isnum);
}
//output routine
ostream& operator<<(ostream& s,string d){
	s<<'\"'<<d.c_str()<<'\"';
	return s;
}
template <class T>
ostream& operator<<(ostream& s,vector<T> d){
	s<<"{";
	for (typename vector<T>::iterator i=d.begin();i!=d.end();i++)
		s<<(i!=d.begin()?",":"")<<*i;
	s<<"}";
	return s;
}

//parsing routine
template <class T>
vector<basic_string<T> > parse(const basic_string<T> &s,const basic_string<T> &delim){
	vector<basic_string<T> > ret(0);
	for (int b,e=0;;ret.push_back(s.substr(b,e-b)))
		if ((b=s.find_first_not_of(delim,e))==(e=s.find_first_of(delim,b)))
			return ret;
}

struct ltstr{
	bool operator()(int i,int j){
		return i-j<0;
	}
};
struct Parenthese{
	int countInts(string p){
		int i,j,k,num[100],cnt;
		char op[100][2];
		vector< vector < map<int,int,ltstr> > > f;
		vector< vector<int> > g;
		s2in(p,in);
		in>>num[i=0];
		i++;
		while(in>>op[i]>>num[i])i++;
		cnt=i;
		f.resize(cnt);
		g.resize(cnt);
		for(i=0;i<cnt;i++){
			f[i].resize(i+1);
			g[i].resize(i+1);
		}
		for(i=0;i<g.size();i++)
			for(j=0;j<g[i].size();j++)
				g[i][j]=0;
		f[0][0][num[0]]=g[0][0]++;
		for(i=1;i<cnt;i++)
			for(j=i;j>=0;j--){
				if(j==i){
					f[i][j][num[i]]=g[i][j]++;
					continue;
				}
				for(k=i;k>j;k--){
					for(map<int, int, ltstr>::iterator h=f[k-1][j].begin();h!=f[k-1][j].end();h++)
						for(map<int, int, ltstr>::iterator l=f[i][k].begin();l!=f[i][k].end();l++){
							int a=(*h).first;
							int b=(*l).first;
							i64 ans;
							switch(op[k][0]){
					        case '+':ans=a+b;break;
							case '-':ans=a-b;break;
							case '*':ans=a*b;break;
							case '/':if(!b)ans=((i64)1<<62);else ans=a/b;break;
							case '%':if(!b)ans=((i64)1<<62);else ans=a%b;break;
							}
							if(ans==((i64)1<<62))continue;
							f[i][j][ans]=g[i][j]++;
						}
				}
			}
			return f[cnt-1][0].size();
	}
};
/*
struct Parenthese{
	int countInts(string p){
		int i,j,k,h,l,m,num[100],cnt;
		char op[100][2];
		vector< vector < vector<int> > > f;
		s2in(p,in);
		in>>num[i=0];
		i++;
		while(in>>op[i]>>num[i])i++;
		cnt=i;
//		cout<<cnt<<endl;
//		for(i=0;i<cnt;i++)
//			cout<<num[i]<<' ';
//		cout<<endl;
		f.resize(cnt);
		for(i=0;i<cnt;i++)
			f[i].resize(i+1);
		f[0][0].push_back(num[0]);
		for(i=1;i<cnt;i++)
			for(j=i;j>=0;j--){
				if(j==i){
					f[i][j].push_back(num[i]);
//					cout<<i<<' '<<j<<endl;
//					cout<<f[i][j]<<endl;
					continue;
				}
				for(k=i;k>j;k--){
					for(h=0;h<f[k-1][j].size();h++)
						for(l=0;l<f[i][k].size();l++){
							int a=f[k-1][j][h];
							int b=f[i][k][l];
//							cout<<"a="<<a<<op[k][0]<<"b="<<b<<endl;
							i64 ans;
							switch(op[k][0]){
					        case '+':ans=a+b;break;
							case '-':ans=a-b;break;
							case '*':ans=a*b;break;
							case '/':if(!b)ans=((i64)1<<62);else ans=a/b;break;
							case '%':if(!b)ans=((i64)1<<62);else ans=a%b;break;
							}
//							cout<<"ans="<<ans<<endl;
							if(ans==((i64)1<<62))continue;
							for(m=0;m<f[i][j].size();m++)
								if(f[i][j][m]==ans)break;
//								cout<<"m="<<m<<endl;
							if(m==f[i][j].size())
								f[i][j].push_back(ans);
						}
				}
//				cout<<i<<' '<<j<<':'<<endl;
//				cout<<f[i][j]<<endl;
			}
			return f[cnt-1][0].size();
	}
};*/

int  main(){
	Parenthese a;
	string s;
	s="9 * 8 + 7 * 6 - 5 + 7 * 93 - 6 * 4 + 5 * 9 - 8 * 7";
	cout<<a.countInts(s)<<endl;
	return 0;
}
