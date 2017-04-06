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

//无向图最小生成树,prim算法,邻接阵形式,复杂度O(n^2)
//返回最小生成树的长度,传入图的大小n和邻接阵mat,不相邻点边权inf
//可更改边权的类型,pre[]返回树的构造,用父结点表示,根节点(第一个)pre值为-1
//必须保证图的连通的!
#define MAXN 110
typedef double elem_t;

elem_t prim(int n,elem_t mat[][MAXN],int* pre){
	elem_t min[MAXN],ret=0;//cout<<"b"<<endl;
	int v[MAXN],i,j,k;
	for (i=0;i<n;i++)
		min[i]=inf,v[i]=0,pre[i]=-1;
	for (min[j=0]=0;j<n;j++){
		for (k=-1,i=0;i<n;i++)
			if (!v[i]&&(k==-1||min[i]<min[k]))
				k=i;
		for (v[k]=1,ret+=min[k],i=0;i<n;i++)
			if (!v[i]&&mat[k][i]<min[i])
				min[i]=mat[pre[i]=k][i];
	}cout<<"a"<<endl;
	return ret;
}

struct NODE{
	double x,y,z,r;
};

vector<NODE> vn;
VVI vvn;
VI ans;
int n;
//vector<vector<NODE> > vvn;
char mark[110];
double mat[110][110];

double dis(int a,int b){
	return sqrt((vn[a].x-vn[b].x)*(vn[a].x-vn[b].x)+(vn[a].y-vn[b].y)*(vn[a].y-vn[b].y)+(vn[a].z-vn[b].z)*(vn[a].z-vn[b].z));
}

int check(int a,int b){
	double t=dis(a,b);
	if(t<=vn[a].r+vn[b].r+eps)return 1;
	return 0;
}


double calc(int a,int b){
	double ret=inf;
	fr(i,vvn[a].size())fr(j,vvn[b].size())ret=min(ret,dis(vvn[a][i],vvn[b][j])-vn[vvn[a][i]].r-vn[vvn[b][j]].r);
	return ret;
}
void dfs(int k){
	mark[k]=1;
	ans.push_back(k);
	for(int i=0;i<n;i++)if(!mark[i]&&check(i,k))dfs(i);
}
void run(){
	cls(mark);
	vvn.clear();
	fr(i,n)if(!mark[i]){
		ans.clear();
		dfs(i);
		vvn.push_back(ans);
	}
//	cout<<vvn<<endl;
	fr(i,vvn.size())
	fr(j,vvn.size())if(i!=j){
		mat[i][j]=calc(i,j);
	}
	else mat[i][j]=0;
//	fr(i,vvn.size()){cout<<endl;fr(j,vvn.size())cout<<mat[i][j]<<' ';}
	int pre[110];
	printf("%.3lf\n",prim(vvn.size(),mat,pre));	
}

int main(){
	while(cin>>n){
		if(!n)break;vn.clear();
		fr(i,n){
			NODE tmp;
			cin>>tmp.x>>tmp.y>>tmp.z>>tmp.r;
			vn.push_back(tmp);
		}
		run();	
	}
	return 0;	
}