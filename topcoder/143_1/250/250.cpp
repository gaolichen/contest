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


class NiceNumbers{
public:
	int check(int n){
		int i=n,j;
		while(i%10==0){
			i/=10;
		}
		if(i<10)return 1;
		char mark[10];
		memset(mark,0,sizeof(mark));
		i=n;
		int k=0,flag=1;
		j=i%10-1;
		while(i>=1){
			mark[i%10]=1;
			if(abs(i%10-j)!=1)flag=0;
			j=i%10;
			k=k*10+i%10;
			i/=10;
		}
		for(i=j=0;i<10;i++)
			if(mark[i])j++;
		if(j<=2)return 2;
		if(k==n)return 3;
		if(flag==1)return 4;
		return 0;
	}
	int howMany(int n){
		int i=n;
		while(!check(n))n++;
//		cout<<check(n)<<endl;
		return n-i;
	}
};




void test0(){
	int n=102;
	int howMany= 0;
	NiceNumbers _NiceNumbers;
	int ret=_NiceNumbers.howMany(n);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"expected to return "<<howMany<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howMany)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int n=29915;
	int howMany= 7;
	NiceNumbers _NiceNumbers;
	int ret=_NiceNumbers.howMany(n);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"expected to return "<<howMany<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howMany)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int n=234793273;
	int howMany= 4159;
	NiceNumbers _NiceNumbers;
	int ret=_NiceNumbers.howMany(n);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"expected to return "<<howMany<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howMany)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int n=78765123;
	int howMany= 309;
	NiceNumbers _NiceNumbers;
	int ret=_NiceNumbers.howMany(n);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"n = "<<n<<endl;
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
	return 0;
}
