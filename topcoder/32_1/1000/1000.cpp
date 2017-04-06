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
#define N 20
#define MAXN 362881
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

int p[20];
//传入n，将0到n阶乘存到p[]中
void nfactor(int n,int *p){
	int i;
	p[0]=1;
	for(i=1;i<=n;i++)
		p[i]=i*p[i-1];
}
//p[]是1到n的一个排列，返回此排列是第几个排列，1到n的顺序排列为第1排列
//调用 nfactor
int ranknum(int n,int *a){
	int i,j,mark[N],k,ans;
	memset(mark,0,sizeof(int)*(n+1));
	nfactor(n,p);
	for(i=0,ans=0;i<n;i++)
	{
		for(j=1,k=0;j<a[i];j++)
			if(!mark[j])k++;
		ans+=p[n-i-1]*k;
		mark[a[i]]=1;
	}
	return ans+1;
}
//将n排列的第r个排列存到a[]中，若r>p[n]返回0，若r<1返回－1，否则返回1
//调用nfactor
int numrank(int n,int r,int *a){
	int i,j,mark[N],k;
	if(r>p[n])return 0;
	if(r<1)return -1;
	memset(mark,0,sizeof(int)*(n+1));
	mark[0]=1;
	for(i=0,r--;i<n;i++){
		k=r/p[n-i-1];
		r-=k*p[n-i-1];
		j=0;a[i]=0;k++;
		while(j<k){
			a[i]++;
			if(mark[a[i]]==0)j++;
		}
		mark[a[i]]=1;
	}
	return 1;
}
struct SlidingPuzzle{
	int sx,sy,sk[MAXN],step[MAXN];
	char x[MAXN],y[MAXN];
	int tmp[9],opn,cls;
	char mark[MAXN];
	int vi[N];
	int bfs(){
		int i;
		while(opn<=cls){
		for(i=0;i<4;i++)
			if(inmat(x[opn]+mx[i],y[opn]+my[i],3,3)){
				numrank(9,sk[opn],tmp);
				tmp[x[opn]*3+y[opn]]=tmp[(x[opn]+mx[i])*3+y[opn]+my[i]];
				tmp[(x[opn]+mx[i])*3+y[opn]+my[i]]=9;
				if(mark[ranknum(9,tmp)])continue;
				sk[++cls]=ranknum(9,tmp);
				mark[sk[cls]]=1;
				x[cls]=x[opn]+mx[i];
				y[cls]=y[opn]+my[i];
				step[cls]=step[opn]+1;
				if(sk[cls]==0)return step[cls];
			}
		opn++;
		}
		return -1;
	}
	int minMoves(string s1, string s2, string s3){
		int i,j;
		VS vs;
		vs.push_back(s1);
		vs.push_back(s2);
		vs.push_back(s3);
		for(i=0;i<3;i++)
			for(j=0;j<3;j++){
				if(vs[i][j]==' '){
					vi[i*3+j]=9;
					sx=i;sy=j;
				}
				else vi[i*3+j]=vs[i][j]-'0';
			}
		
		int t=0;
		for(i=0;i<9;i++)
			for(j=i+1;j<9;j++)
				if(vi[i]>vi[j])t++;
		if(t%2!=(sx+sy)%2)return -1;
		nfactor(9,p);
		opn=cls=0;
		sk[0]=ranknum(9,vi);
		x[0]=sx;y[0]=sy;
		step[0]=0;
		if(sk[0]==0)return 0;
		cls(mark);
		mark[sk[0]]=1;
		return bfs();
	}
};

int main(){
	SlidingPuzzle a;
	string s1,s2,s3;
	s1="357";
	s2="2 4";
	s3="618";
	cout<<a.minMoves(s1,s2,s3)<<endl;
	return 0;
}