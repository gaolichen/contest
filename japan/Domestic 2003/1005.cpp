
#define WIN32
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
#define inmat(i,j,m,n) ((i)>=0&&(i)<(m)&&(j)>=0&&(j)<(n))
#define cls(a) memset((a),0,sizeof(a))
#define isCap(a) ((a)>='A'&&(a)<='Z')
#define isLow(a) ((a)>='a'&&(a)<='z')
#define inf 2100000000
#define eps 1e-8
typedef istringstream iss;
typedef ostringstream oss;
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
	s<<endl;
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
VVI mat,rec;
int w,h;
char mark[11000];
int ret;
int searchCnt;
struct NODE {
	int x,y,a;
	bool operator<(const NODE & t)const {
		if(a!=t.a)return a>t.a;
		if(x!=t.x)return x>t.x;
		return y>t.y;	
	}	
};
vector<NODE > vn1,vn;
vector< vector< vector<int > > > rect;
NODE sn[200],tsn[200];
void dfs(int x,int y,int ans){
	if(searchCnt>100000)return ;
	if(ans>=ret)return ;
	if(x>=h){
		ret=ans;
//		cout<<ret<<' '<<searchCnt<<endl;
		return ;
	}
	if(y>=w){
		dfs(x+1,0,ans);return ;
	}
	if(mat[x][y]!=1){
		dfs(x,y+1,ans);
		return ;
	}
	searchCnt++;
	fr(i,rect[x][y].size())if(!mark[rect[x][y][i]]){
		NODE tmp=vn[rect[x][y][i]];
		mark[rect[x][y][i]]=1;
		for(int j=tmp.x;j<tmp.x+tmp.a;j++)
		for(int k=tmp.y;k<tmp.y+tmp.a;k++)
		mat[j][k]++;
		dfs(x,y+1,ans+1);
		mark[rect[x][y][i]]=0;
		for(int j=tmp.x;j<tmp.x+tmp.a;j++)
		for(int k=tmp.y;k<tmp.y+tmp.a;k++)
		mat[j][k]--;
	}
}

int calc(int x,int y){
	for(int i=1;i+x<=h&&i+y<=w;i++){
		for(int j=x;j<x+i;j++)for(int k=y;k<y+i;k++)if(!mat[j][k])return i-1;
	}
	return min(h-x,w-y);
}

int contain(NODE &n1,NODE &n2){
	if(n2.x>=n1.x&&n2.x<n1.x+n1.a&&
	n2.y>=n1.y&&n2.y<n1.y+n1.a&&
	n2.x+n2.a>=n1.x&&n2.x+n2.a<=n1.x+n1.a&&
	n2.y+n2.a>=n1.y&&n2.y+n2.a<=n1.y+n1.a)return 1;
	return 0;
}

void run(){
	ret=inf;
	vn1.clear();vn.clear();rect.clear();
	for(int i=0;i<h;i++)for(int j=0;j<w;j++)if(mat[i][j]){
		NODE tmp;
		tmp.x=i;tmp.y=j;
		tmp.a=calc(i,j);
		vn1.push_back(tmp);
	}
	fr(i,vn1.size()){
		int flag=1;
		fr(j,vn1.size())if(i!=j&&contain(vn1[j],vn1[i])){flag=0;break;}
		if(flag)vn.push_back(vn1[i]);
	}
	sort(all(vn));
//	fr(i,vn.size())cout<<vn[i].x<<' '<<vn[i].y<<' '<<vn[i].a<<endl;
//	cout<<endl;
	rect.resize(h,vector<vector<int > >(w));
	fr(i,vn.size()){
		for(int j=vn[i].x;j<vn[i].x+vn[i].a;j++)
		for(int k=vn[i].y;k<vn[i].y+vn[i].a;k++)
		rect[j][k].push_back(i);
	}
	cls(mark);
//	fr(i,h){cout<<endl;fr(j,w)cout<<rect[i][j].size()<<' ';}
//	fr(i,h)fr(j,w)sort(all(rect[i][j]));
	searchCnt=0;
	dfs(0,0,0);
	cout<<ret<<endl;	
}

int main(){
	while(cin>>w>>h){
		if(!w&&!h)break;
		mat.resize(h);
		fr(i,h)mat[i].resize(w);
		fr(i,h)fr(j,w)cin>>mat[i][j];
		run();	
	}
	return 0;
}
