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

struct NODE{
	i64 a,b;
	bool operator<(const NODE &c)const {
		if(a!=c.a)return a<c.a;
		return b<c.b;
	}
};

class Gauss{
public:
	VI prime;
	VI a,sk;
	vector<i64> b;
	VS ret;
	vector<NODE> rett;
	i64 nn;
	void dfs(int k){
		if(k==a.size()){
			int i,j;
			i64 tmp=1;
			for(i=0;i<a.size();i++){
				j=0;
				while(j<sk[i]){
					tmp*=b[i];j++;
				}
			}
			i64 t=nn/tmp;
			i64 b,a;
			b=(t+tmp)/2;
			if(t>b)a=t-b;
			else a=tmp-b;
			if(a<=0||(a+b)*(b-a+1)!=nn||a==b)return ;
			NODE aa;
			aa.a=a;aa.b=b;
			rett.push_back(aa);
			return ;
		}
		for(sk[k]=0;sk[k]<=a[k];sk[k]++){
			dfs(k+1);
		}
	}
	void calc(){
		sk.resize(a.size());
		dfs(0);
	}
	void makeprime(){
		int i,j;
		char mark[400000];
		cls(mark);
		for(i=2;i<400000;i++)
			if(!mark[i]){
				for(j=i*i;j>0&&j<400000;j+=i)
					mark[j]=1;
				prime.push_back(i);
			}
	}
	vector<string> whichSums(string s){
		int i;
		i64 n;
		s2in(s,in);
		in>>n;
		
		n*=2;nn=n;
		int p2=0;
		while(n%2==0){
			n/=2;p2++;
		}
		makeprime();
		for(i=0;i<prime.size()&&(i64)prime[i]*prime[i]<=n;i++)
			if(n%prime[i]==0){
				int t=0;
				while(n%prime[i]==0){
					n/=prime[i];
					t++;
				}
				a.push_back(t);
				b.push_back(prime[i]);
			}
		if(n>1){
			cout<<n<<endl;
			a.push_back(1);
			b.push_back(n);
		}
		calc();
		sort(rett.begin(),rett.end());
		for(i=0;i<rett.size();i++){
			ostringstream out;
			out<<"["<<rett[i].a<<", "<<rett[i].b<<"]";
			ret.push_back(out.str());
		}
		return ret;
	}
};




void test0(){
	string target="9999999967";
	string _whichSums[]= { "[3, 9]",  "[9, 12]",  "[13, 15]" };
	vector<string> whichSums(_whichSums+0,_whichSums+sizeof(_whichSums)/sizeof(string));
	Gauss _Gauss;
	vector<string> ret=_Gauss.whichSums(target);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"target = "<<target<<endl;
	cout<<"expected to return "<<whichSums<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==whichSums)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string target="4";
	vector<string> whichSums(0);
	Gauss _Gauss;
	vector<string> ret=_Gauss.whichSums(target);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"target = "<<target<<endl;
	cout<<"expected to return "<<whichSums<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==whichSums)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string target="17";
	string _whichSums[]= { "[8, 9]" };
	vector<string> whichSums(_whichSums+0,_whichSums+sizeof(_whichSums)/sizeof(string));
	Gauss _Gauss;
	vector<string> ret=_Gauss.whichSums(target);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"target = "<<target<<endl;
	cout<<"expected to return "<<whichSums<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==whichSums)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string target="55";
	string _whichSums[]= { "[1, 10]",  "[9, 13]",  "[27, 28]" };
	vector<string> whichSums(_whichSums+0,_whichSums+sizeof(_whichSums)/sizeof(string));
	Gauss _Gauss;
	vector<string> ret=_Gauss.whichSums(target);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"target = "<<target<<endl;
	cout<<"expected to return "<<whichSums<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==whichSums)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

int main(){
	test0();
	test1();
	test2();
	test3();
	return 0;
}

/*
"9999999967"]
    EXPECTED: {"[4999999983, 4999999984]"}
    RECEIVED: {}

*/
