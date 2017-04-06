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


class PossibleOrders{
public:
	i64 f[20][20];
	i64 calc(int n){
		int i,j;
		cls(f);
		f[1][0]=0;
		f[1][1]=1;f[1][2]=0;
		for(i=2;i<=n;i++)
			for(j=1;j<=n;j++)
				f[i][j]=(f[i-1][j]+f[i-1][j-1])*j;
		i64 ret=0;
		for(i=1;i<=n;i++)
			ret+=f[n][i];
		return ret;
	}
	i64 howMany(int n,vector<string> vs){
		int i,j;
		char mark[20][20];
		cls(mark);
		for(i=0;i<vs.size();i++){
			string tmp;
			int a,b;
			tmp=vs[i].substr(0,vs[i].find('='));
			s2in(tmp,in);
			in>>a;
			tmp=vs[i].substr(vs[i].find('=')+1);
			s2in(tmp,in1);
			in1>>b;
			mark[a][b]=mark[b][a]=1;
		}
		char done[20];
		cls(done);
		int k;
		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				if(i!=k&&mark[i][k])
					for(j=0;j<n;j++)
						if(j!=i&&j!=k&&mark[j][k]&&!mark[i][j])
							mark[i][j]=mark[j][i]=1;
		int ret=0;
		for(i=0;i<n;i++)
			if(!done[i]){
				done[i]=1;
				for(j=i+1;j<n;j++)
					if(mark[i][j])done[j]=1;
				ret++;
			}
		return calc(ret);
	}
};




void test0(){
	int num=4;
	string _facts[]={"0=2","1=3"};
	vector<string> facts(_facts+0,_facts+sizeof(_facts)/sizeof(string));
	i64 howMany= 3;
	PossibleOrders _PossibleOrders;
	i64 ret=_PossibleOrders.howMany(num,facts);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"num = "<<num<<endl;
	cout<<"facts = "<<facts<<endl;
	cout<<"expected to return "<<howMany<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howMany)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int num=4;
	vector<string> facts(0);
	i64 howMany= 75;
	PossibleOrders _PossibleOrders;
	i64 ret=_PossibleOrders.howMany(num,facts);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"num = "<<num<<endl;
	cout<<"facts = "<<facts<<endl;
	cout<<"expected to return "<<howMany<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howMany)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int num=3;
	string _facts[]={"1=1"};
	vector<string> facts(_facts+0,_facts+sizeof(_facts)/sizeof(string));
	i64 howMany= 13;
	PossibleOrders _PossibleOrders;
	i64 ret=_PossibleOrders.howMany(num,facts);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"num = "<<num<<endl;
	cout<<"facts = "<<facts<<endl;
	cout<<"expected to return "<<howMany<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howMany)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int num=3;
	string _facts[]={"1=2","2=1"};
	vector<string> facts(_facts+0,_facts+sizeof(_facts)/sizeof(string));
	i64 howMany= 3;
	PossibleOrders _PossibleOrders;
	i64 ret=_PossibleOrders.howMany(num,facts);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"num = "<<num<<endl;
	cout<<"facts = "<<facts<<endl;
	cout<<"expected to return "<<howMany<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howMany)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int num=17;
	vector<string> facts(0);
	i64 howMany= 130370767029135901;
	PossibleOrders _PossibleOrders;
	i64 ret=_PossibleOrders.howMany(num,facts);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"num = "<<num<<endl;
	cout<<"facts = "<<facts<<endl;
	cout<<"expected to return "<<howMany<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howMany)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

int main(){
	test0();
	test1();
	test2();
	test3();
	test4();
	return 0;
}
