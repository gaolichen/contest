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
	int x,y;
};


NODE mat[110][110];
char mark[110][110];
int cnt;
map<string ,int> ms;

void init(int &a,int &b){
	int c=gcd(a,b);
	a/=c;b/=c;
}

void update(){
	for(int k=0;k<cnt;k++)
		for(int i=0;i<cnt;i++)
			if(mark[i][k])
			for(int j=0;j<cnt;j++)
				if(i!=j&&mark[k][j]&&!mark[i][j]){
					NODE a;
					a.x=mat[i][k].x*mat[k][j].x;
					a.y=mat[i][k].y*mat[k][j].y;
					init(a.x,a.y);
					mat[i][j]=a;
					swap(a.x,a.y);
					mat[j][i]=a;
					mark[i][j]=mark[j][i]=1;
				}
}

int add(string &s){
	if(ms.find(s)==ms.end())ms[s]=cnt++;
	return ms[s];
}

int found(string &s){
	return ms.find(s)!=ms.end();
}
void run(string s){
	if(s[0]=='?'){
		iss in(s);
		string a,b,c,d;
		in>>a>>b>>c>>d;
		if(!found(b)||!found(d)||mat[ms[b]][ms[d]].x==0){
			cout<<"? "<<b<<" = ? "<<d<<endl;
		}
		else {
			NODE tmp=mat[ms[b]][ms[d]];
			cout<<tmp.x<<" "<<b<<" = "<<tmp.y<<" "<<d<<endl;
		}
	}
	else {
		iss in(s);
		string a,b,c,d;
		int i,j;
		in>>a>>i>>b>>c>>j>>d;
		init(i,j);
		int t1,t2;
		NODE tmp;tmp.x=i;tmp.y=j;
		t1=add(b);t2=add(d);
		if(mark[t1][t2])return ;
		mat[t1][t2]=tmp;
		mark[t1][t2]=mark[t2][t1]=1;
		swap(tmp.x,tmp.y);mat[t2][t1]=tmp;
		update();
	}
}

int main(){
	string s;
	ms.clear();
	memset(mark,0,sizeof(mark));
	cnt=0;
	memset(mat,0,sizeof(mat));
	while(getline(cin,s)){
		if(s==".")break;
		run(s);
	}
	return 0;
}