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

struct NODE {
	int p,len;
};
int cnt;
vector<NODE > vn;
VI vi;
int w;

void add(NODE tmp){
	if(cnt+tmp.len>w){
		if(cnt){
			NODE t=tmp;
			t.len=w-cnt;
			tmp.len-=t.len;
			cnt=0;
			vn.push_back(t);
		}
		if(tmp.len>w){
			cnt=tmp.len%w;
			tmp.len-=cnt;
			NODE t=tmp;
			t.len=cnt;
			vn.push_back(tmp);vn.push_back(t);
		}
	}
	else {
		cnt+=tmp.len;
		if(cnt==w)cnt=0;
		vn.push_back(tmp);
	}
}
void run(){
	sort(all(vi));
	vi.resize(unique(all(vi))-vi.begin());
//	fr(i,vi.size())cout<<vi[i]<<' ';cout<<endl;
}
int main(){
	while(cin>>w){
		if(!w)break;
		vi.clear();
		NODE tmp;
		cnt=0;
		while(cin>>tmp.p>>tmp.len){
			if(!tmp.p&&!tmp.len)break;
			vi.push_back((cnt+tmp.len)%w);
			add(tmp);
		}
		run();
	}
	return 0;
}