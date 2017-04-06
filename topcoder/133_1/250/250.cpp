
//program framework generated with WishingBone's parser :)-

//common header
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
#include <strstream>
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
#define fo(a,b) for((a)=0;(a)<(b);(a)++)
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


class RemoveDigits{
public:
	string ret;
	void del(string s,int m){
		if(m==0){
			ret=s;
			return;
		} 
		int i;
		fo(i,s.size()-1){
			if(s[i]<s[i+1])break;
		}
		char buf[100];
		strcpy(buf,s.c_str());
		strcpy(buf+i,s.c_str()+i+1);
		s=buf;
		del(s,m-1);
	}
	string maxNumber(string n,int m){
		ret="";
		del(n,m);
		return ret;
	}
};




void test0(){
	string n="834391370";
	int m=2;
	string maxNumber= "8491370";
	RemoveDigits _RemoveDigits;
	string ret=_RemoveDigits.maxNumber(n,m);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"m = "<<m<<endl;
	cout<<"expected to return "<<maxNumber<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==maxNumber)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string n="0021597002943020";
	int m=3;
	string maxNumber= "2597002943020";
	RemoveDigits _RemoveDigits;
	string ret=_RemoveDigits.maxNumber(n,m);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"m = "<<m<<endl;
	cout<<"expected to return "<<maxNumber<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==maxNumber)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string n="0000500390";
	int m=2;
	string maxNumber= "00500390";
	RemoveDigits _RemoveDigits;
	string ret=_RemoveDigits.maxNumber(n,m);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"m = "<<m<<endl;
	cout<<"expected to return "<<maxNumber<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==maxNumber)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string n="91459800928398113866079548895152924499";
	int m=22;
	string maxNumber= "9999995152924499";
	RemoveDigits _RemoveDigits;
	string ret=_RemoveDigits.maxNumber(n,m);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"m = "<<m<<endl;
	cout<<"expected to return "<<maxNumber<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==maxNumber)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string n="98";
	int m=1;
	string maxNumber= "9";
	RemoveDigits _RemoveDigits;
	string ret=_RemoveDigits.maxNumber(n,m);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"m = "<<m<<endl;
	cout<<"expected to return "<<maxNumber<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==maxNumber)
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
