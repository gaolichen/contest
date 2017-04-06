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


class Errors{
public:
	double max1(double a,double b){
		if(a>b)return a;
		return b;
	}
	double min1(double a,double b){
		if(a>b)return b;
		return a;
	}
	string range(int m1,int m2,int ei,int op){
		double t,a,b,t1,t2,d,e;
		string ret;
		char tmp=op,c[20];
		t=(double)(ei)/1000.0;
		if(tmp=='-'||tmp=='+'){
			a=4*t;
			sprintf(c,"%.3lf",4*t);
		}
		if(tmp=='*'){
			a=(m1-t)*(m2-t);
			b=(m1-t)*(m2+t);
			d=(m1+t)*(m2-t);
			e=(m1+t)*(m2+t);
			t1=max(a,b);
			t1=max1(t1,d);t1=max1(t1,e);
			t2=min1(a,b);t2=min1(t2,d);
			t2=min1(t2,e);
			if(t>=abs(m1)||t>=abs(m2)){
				t1=max1(0,t1);
				t2=min1(0,t2);
			}
			sprintf(c,"%.3lf",t1-t2);
		}
		if(tmp=='/'){
			if(t>=abs(m2)){
				sprintf(c,"INFINITY");
			}
			else{
				a=(m1-t)/(m2-t);
			b=(m1-t)/(m2+t);
			d=(m1+t)/(m2-t);
			e=(m1+t)/(m2+t);
			t1=max1(a,b);
			t1=max1(t1,d);t1=max1(t1,e);
			t2=min1(a,b);t2=min1(t2,d);
			t2=min1(t2,e);
			sprintf(c,"%.3lf",t1-t2);
			}
		}
		if(c[0]=='0')ret=c+1;
		else ret=c;
		return ret;
	}
};




void test0(){
	int m1=-1;
	int m2=2;
	int e=500;
	int op='-';
	string range= "2.000";
	Errors _Errors;
	string ret=_Errors.range(m1,m2,e,op);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"m1 = "<<m1<<endl;
	cout<<"m2 = "<<m2<<endl;
	cout<<"e = "<<e<<endl;
	cout<<"op = "<<op<<endl;
	cout<<"expected to return "<<range<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==range)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int m1=2;
	int m2=-1;
	int e=1250;
	int op='*';
	string range= "8.125";
	Errors _Errors;
	string ret=_Errors.range(m1,m2,e,op);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"m1 = "<<m1<<endl;
	cout<<"m2 = "<<m2<<endl;
	cout<<"e = "<<e<<endl;
	cout<<"op = "<<op<<endl;
	cout<<"expected to return "<<range<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==range)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int m1=2;
	int m2=1;
	int e=1200;
	int op='/';
	string range= "INFINITY";
	Errors _Errors;
	string ret=_Errors.range(m1,m2,e,op);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"m1 = "<<m1<<endl;
	cout<<"m2 = "<<m2<<endl;
	cout<<"e = "<<e<<endl;
	cout<<"op = "<<op<<endl;
	cout<<"expected to return "<<range<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==range)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int m1=7237;
	int m2=3590;
	int e=2;
	int op='+';
	string range= ".008";
	Errors _Errors;
	string ret=_Errors.range(m1,m2,e,op);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"m1 = "<<m1<<endl;
	cout<<"m2 = "<<m2<<endl;
	cout<<"e = "<<e<<endl;
	cout<<"op = "<<op<<endl;
	cout<<"expected to return "<<range<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==range)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int m1=2;
	int m2=-5;
	int e=5000;
	int op='/';
	string range= "INFINITY";
	Errors _Errors;
	string ret=_Errors.range(m1,m2,e,op);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"m1 = "<<m1<<endl;
	cout<<"m2 = "<<m2<<endl;
	cout<<"e = "<<e<<endl;
	cout<<"op = "<<op<<endl;
	cout<<"expected to return "<<range<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==range)
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
