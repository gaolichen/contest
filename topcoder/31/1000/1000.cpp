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
//#define min(a,b) _cpp_min(a,b)
#define max(a,b) _cpp_max(a,b)
#endif
#define min(a,b)  ((a)<=(b)?(a):(b))
#define abs(a) ((a)>0?(a):-(a))
#define s2in(s,in) istringstream in(s)
#define inmat(i,j,m,n) ((i)>=0&&(i)<(m)&&(j)>=0&&(j)<(n))
#define cls(a) memset((a),0,sizeof(a))
#define VI vector<int>
#define V64 vector<i64>
#define VS vector<string>
#define VD vector<double>
#define inf 2100000000
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

bool cmp(const VI &a,const VI &b){
	return b.size()<a.size();
}

//求网络最大流,邻接阵形式
//回返最大流量,flow返回每条边的流量
//传入网络节点数n,容量mat,源点source,汇点sink
#define MAXN 100
typedef int elem_t;

elem_t maxflow(int n,elem_t mat[][MAXN],int source,int sink,elem_t flow[][MAXN]){
	int pre[MAXN],que[MAXN],p,q,t,i,j;
	elem_t d[MAXN],s;
	if (source==sink)
		return inf;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			flow[i][j]=0;
	for (pre[sink]=1;pre[sink];){
		for (i=0;i<n;pre[i++]=0);
		pre[t=source]=source+1,d[t]=inf;
		for (p=0,q=1;p<q&&!pre[sink];t=que[++p])
			for (i=0;i<n;i++)
				if (!pre[i]&&mat[t][i]&&(s=mat[t][i]-flow[t][i])>0)
					pre[que[q++]=i]=t+1,d[i]=d[t]<s?d[t]:s;
				else if (!pre[i]&&mat[i][t]&&(s=flow[i][t])>0)
					pre[que[q++]=i]=-t-1,d[i]=d[t]<s?d[t]:s;
		for (i=sink;pre[i]&&i!=source;)
			if (pre[i]>0)
				flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
			else
				flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
	}
	for (s=i=0;i<n;i++)
		s+=flow[source][i];
	return s;
}

struct TargetGrid{
	int minShots(vector <string> vs){
		int i,j;
		int mat[100][100];
		int flow[100][100];
		for(i=0;i<vs.size();i++)
			for(j=0;j<vs[i].length();j++)
				if(vs[i][j]=='T')
					mat[i][j+25]=1;
		for(i=0;i<25;i++){
			mat[50][i]=1;
			mat[i+25][51]=1;
		}
		return maxflow(52,mat,50,51,flow);
	}
};

int main(){
	VS tmp;
	tmp.push_back("NTNTNTT");
	tmp.push_back("TNNNNNN");
	tmp.push_back("TTNTTNT");
	tmp.push_back("TNNTNNT");
	tmp.push_back("NTNTNTN");
	tmp.push_back("NTNTNTT");
	tmp.push_back("NNNTTTT");
//	tmp.push_back("NNNNNNNN");
	TargetGrid a;
	cout<<a.minShots(tmp)<<endl;
	return 0;
}
/*
[{"NTNTNTT", "TNNNNNN", "TTNTTNT", "TNNTNNT", "NTNTNTN", "NTNTNTT", "NNNTTTT"}]
    EXPECTED: 6
    RECEIVED: 7*/

/*
[{"TNTTTNTTTTTTTTNTTTTT", "TNNNTTNTTNNTNNNTTNTT", "NNNTTTTTNNNNNNNTTNTN", "NTTTNNNTNTNNTTTTNNNN", "TNTNTNTTNTTNNNNNTTNT", "TTNNTTNNNTTNTNTNTNTN", "TNNTTTTNTNTNTTNNTTNN", "NTTTTNTTTNNTNNTTNNNN", "NTTNNTTNNTNTNNNNNNNT", "TTNNTTNNNTNNTTTTTTNT", "TNTTNTNTNNNTTTTTTNTT", "NNTTNTNTNTNTNTTNTNTN", "NNTTTNNTTTTNTTNTNNNN", "TTTTNTNNTNNTTNNNTNNN", "TTTTNTTNNTNNTNNTTTTN", "TNNTNTNTNNTNTTTTTTTN", "NNNTTTNTTNTNTNNTNNTT", "NTNNNTNNTTTNNTNNTTTN", "NNNTTTTNNTTTTTNTNTNN", "TNTNTTTNTTTTNNTTNNTT"}]
    EXPECTED: 20
*/