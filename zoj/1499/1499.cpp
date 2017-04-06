#ifdef WIN32
#	pragma warning(disable:4786)
#define for if(0);else for
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
#define mit(a,b) map<a,b>::iterator
#define fr(a,b) for(int a=0;a<(b);a++)
#define all(a) a.begin(),a.end()
#define iss istringstream
#define oss ostringstream
#define inmat(i,j,m,n) ((i)>=0&&(i)<(m)&&(j)>=0&&(j)<(n))
#define cls(a) memset((a),0,sizeof(a))
#define isCap(a) ((a)>='A'&&(a)<='Z')
#define isLow(a) ((a)>='a'&&(a)<='z')
typedef vector<int> VI; typedef vector<vector<int> > VVI;
typedef vector<i64> V64; typedef vector<vector<i64> > VV64;
typedef vector<string> VS; typedef vector<vector<string> > VVS;
typedef vector<double> VD; typedef vector<vector<double> > VVD;
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


//parsing routine
template <class T>
vector<basic_string<T> > parse(const basic_string<T> &s,const basic_string<T> &delim){
	vector<basic_string<T> > ret(0);
	for (int b,e=0;;ret.push_back(s.substr(b,e-b)))
		if ((b=s.find_first_not_of(delim,e))==(e=s.find_first_of(delim,b)))
			return ret;
}

VS ret,sk;
string s;
int ans;

int cmp(string &a,string &b){
	int i,j;i=j=0;
	while(i<a.length()&&a[i]=='0')i++;
	while(j<b.length()&&b[j]=='0')j++;
	if(a.length()-i!=b.length()-j)return a.length()-i-(b.length()-j);
	int k;
	for(k=0;k+i<a.length()&&k+j<b.length();k++)
		if(a[k+i]!=b[j+k]){
			return a[k+i]-b[j+k];
		}
	if(k+i==a.length()&&k+j<b.length())return -1;
	else if(k+i==a.length()&&k+j==b.length())return 0;
	else return 1;
}

int mycmp(VS &sk,int k,VS &ret,int ans){
	int t=cmp(sk[k-1],ret[ans-1]);
	if(t)return t;
	for(int i=0;i<k&&i<ans;i++){
		t=cmp(sk[i],ret[i]);
		if(t)return -t;
	}
	return 0;
}
void dfs(int k,int t){
	if(t==s.length()){
		if(mycmp(sk,k,ret,ans)<0){
			ret=sk;ans=k;
		}
		return ;
	}
	for(int i=1;i+t<=s.length();i++){
		sk[k]=s.substr(t,i);
		if(k&&cmp(sk[k],sk[k-1])<=0)continue;
		dfs(k+1,t+i);
	}
}
void run(){
	ans=1;
	sk.clear();
	ret.resize(80);sk.resize(80);
	ret[0]="9";
	for(int i=0;i<80;i++)ret[0]+="9";
	dfs(0,0);
	for(int i=0;i<ans;i++){
		if(i)cout<<",";
		cout<<ret[i];
	}
	cout<<endl;
}
int main(){
	while(cin>>s){
		if(s=="0")break;
		run();
	}
	return 0;
}