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
	for (vector<T>::iterator i=d.begin();i!=d.end();i++)
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


class Plates{
public:
	i64 numLeft(string p){
		int i;
		i64 ret,d[60];
		ret=0;
		d[p.size()-1]=1;
		for(i=p.size()-1;i>0;i--){
			if(p[i]>='A'&&p[i]<='Z')
				d[i-1]=d[i]*26;
			else d[i-1]=d[i]*10;
		}
		for(i=0;i<p.size();i++){
			if(p[i]>='A'&&p[i]<='Z'){
				ret+=('Z'-p[i])*d[i];
			}
			else {
				ret+=d[i]*('9'-p[i]);
			}
		}
		return ret;
	}
};




void test0(){
	string plateNum="222";
	i64 numLeft= 777;
	Plates _Plates;
	i64 ret=_Plates.numLeft(plateNum);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"plateNum = "<<plateNum<<endl;
	cout<<"expected to return "<<numLeft<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numLeft)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string plateNum="TA4KA";
	i64 numLeft= 1227355;
	Plates _Plates;
	i64 ret=_Plates.numLeft(plateNum);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"plateNum = "<<plateNum<<endl;
	cout<<"expected to return "<<numLeft<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numLeft)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string plateNum="KAPETA";
	i64 numLeft= 189835177;
	Plates _Plates;
	i64 ret=_Plates.numLeft(plateNum);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"plateNum = "<<plateNum<<endl;
	cout<<"expected to return "<<numLeft<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numLeft)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string plateNum="MAPA3M";
	i64 numLeft= 63875149;
	Plates _Plates;
	i64 ret=_Plates.numLeft(plateNum);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"plateNum = "<<plateNum<<endl;
	cout<<"expected to return "<<numLeft<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numLeft)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string plateNum="ZZZZZ";
	i64 numLeft= 0;
	Plates _Plates;
	i64 ret=_Plates.numLeft(plateNum);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"plateNum = "<<plateNum<<endl;
	cout<<"expected to return "<<numLeft<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numLeft)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string plateNum="D43";
	i64 numLeft= 2256;
	Plates _Plates;
	i64 ret=_Plates.numLeft(plateNum);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"plateNum = "<<plateNum<<endl;
	cout<<"expected to return "<<numLeft<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numLeft)
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
