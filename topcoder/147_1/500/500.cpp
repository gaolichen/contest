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
int gcd(int a,int b){for(int c;b;c=a,a=b,b=c%b);return a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}

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


class Flags{
public:
	i64 numStripes(string numFlags,vector<string> forbidden){
		int i;
		string s;
		
		int j;
		for(i=0;i<forbidden.size();i++){
			s2in(forbidden[i],myin);
			ostringstream myout;
			while(myin>>j){
				cout<<j<<endl;
				myout<<j<<' ';
			}
			cout<<myout.str()<<endl;
		}
		return 0;
	}
};




void test0(){
	string numFlags="10";
	string _forbidden[]={"0","1 2","1 2"};
	vector<string> forbidden(_forbidden+0,_forbidden+sizeof(_forbidden)/sizeof(string));
	i64 numStripes= 3;
	Flags _Flags;
	i64 ret=_Flags.numStripes(numFlags,forbidden);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"numFlags = "<<numFlags<<endl;
	cout<<"forbidden = "<<forbidden<<endl;
	cout<<"expected to return "<<numStripes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numStripes)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string numFlags="100";
	string _forbidden[]={"0","1","2"};
	vector<string> forbidden(_forbidden+0,_forbidden+sizeof(_forbidden)/sizeof(string));
	i64 numStripes= 6;
	Flags _Flags;
	i64 ret=_Flags.numStripes(numFlags,forbidden);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"numFlags = "<<numFlags<<endl;
	cout<<"forbidden = "<<forbidden<<endl;
	cout<<"expected to return "<<numStripes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numStripes)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string numFlags="100000000000000000";
	string _forbidden[]={"0","1"};
	vector<string> forbidden(_forbidden+0,_forbidden+sizeof(_forbidden)/sizeof(string));
	i64 numStripes= 50000000000000000;
	Flags _Flags;
	i64 ret=_Flags.numStripes(numFlags,forbidden);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"numFlags = "<<numFlags<<endl;
	cout<<"forbidden = "<<forbidden<<endl;
	cout<<"expected to return "<<numStripes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numStripes)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string numFlags="10000000000000000";
	string _forbidden[]={"0 1", "0 1", "2 3 4", "2 3 4", "2 3 4"};
	vector<string> forbidden(_forbidden+0,_forbidden+sizeof(_forbidden)/sizeof(string));
	i64 numStripes= 40;
	Flags _Flags;
	i64 ret=_Flags.numStripes(numFlags,forbidden);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"numFlags = "<<numFlags<<endl;
	cout<<"forbidden = "<<forbidden<<endl;
	cout<<"expected to return "<<numStripes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numStripes)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string numFlags="10000000000000000";
	string _forbidden[]={"0 1 2 3 4 5 6 7 8 9", "0 1 3 4 5 6 7 8 9", "0 2 3 4 5 6 7 8 9", "0 1 2 3 4 5 6 7 8 9", "0 1 2 3 4 5 6 7 8 9", "0 1 2 3 4 5 6 7 8 9", "0 1 2 3 4 5 6 7 8 9", "0 1 2 3 4 5 6 7 8 9", "0 1 2 3 4 5 6 7 8 9", "0 1 2 3 4 5 6 7 8 9"};
	vector<string> forbidden(_forbidden+0,_forbidden+sizeof(_forbidden)/sizeof(string));
	i64 numStripes= 4999999999999996;
	Flags _Flags;
	i64 ret=_Flags.numStripes(numFlags,forbidden);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"numFlags = "<<numFlags<<endl;
	cout<<"forbidden = "<<forbidden<<endl;
	cout<<"expected to return "<<numStripes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numStripes)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string numFlags="5";
	string _forbidden[]={"0","1","2","3","4","5"};
	vector<string> forbidden(_forbidden+0,_forbidden+sizeof(_forbidden)/sizeof(string));
	i64 numStripes= 1;
	Flags _Flags;
	i64 ret=_Flags.numStripes(numFlags,forbidden);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"numFlags = "<<numFlags<<endl;
	cout<<"forbidden = "<<forbidden<<endl;
	cout<<"expected to return "<<numStripes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numStripes)
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
	test5();
	return 0;
}
