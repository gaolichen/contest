/*
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
#ifdef WIN32
#define in_routine(type,spec) \
istream& operator>>(istream& s,type &d){char b[30];if(!s||!(s>>b))return(istream)0;sscanf(b,spec,&d);return s;}
#define out_routine(type,spec) \
ostream& operator<<(ostream& s,type d){char b[30];sprintf(b,spec,d);s<<b;return s;}
typedef signed __int64 i64; in_routine(i64,"%I64d") out_routine(i64,"%I64d")
typedef unsigned __int64 u64; in_routine(u64,"%I64u") out_routine(u64,"%I64u")
#else
typedef signed long long i64;
typedef unsigned long long u64;
#endif



class NumCombine
{
public:
	int count,len;
	int ans;
	char buf[1000];
	void dfs(int k,i64 n){
//	cout<<n<<endl;
	if(k==len){
		if(n<=ans)
			count++;
		return;
	}
	int j=k;
	i64 x=0;
	while(k<len){
		x=10*x+buf[k++]-'0';
		dfs(k,n+x);
		if(j)dfs(k,n-x);
	}
	}
	int numCombos(string a,int n){
		strcpy(buf,a.c_str());
		len=strlen(buf);
		count=0;
		ans=n;
		dfs(0,0);
		return count;
	}
};

int main(){
	string b;
	NumCombine a;
	int n;
	char str[100];
	while(cin>>str>>n){
		b=str;
		cout<<a.numCombos(b,n)<<endl;
	}
	return 0;
}*/

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


class NumCombine
{
public:
	int count,len;
	int ans;
	char buf[1000];
	void dfs(int k,i64 n){
//	cout<<n<<endl;
	if(k==len){
		if(n<=ans)
			count++;
		return;
	}
	int j=k;
	i64 x=0;
	while(k<len){
		x=10*x+buf[k++]-'0';
		dfs(k,n+x);
		if(j)dfs(k,n-x);
	}
	}
	int numCombos(string a,int n){
		strcpy(buf,a.c_str());
		len=strlen(buf);
		count=0;
		ans=n;
		dfs(0,0);
		return count;
	}
};




void test0(){
	string input="123";
	int target=10;
	int numCombos= 6;
	NumCombine _NumCombine;
	int ret=_NumCombine.numCombos(input,target);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"input = "<<input<<endl;
	cout<<"target = "<<target<<endl;
	cout<<"expected to return "<<numCombos<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numCombos)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string input="0000";
	int target=1;
	int numCombos= 27;
	NumCombine _NumCombine;
	int ret=_NumCombine.numCombos(input,target);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"input = "<<input<<endl;
	cout<<"target = "<<target<<endl;
	cout<<"expected to return "<<numCombos<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numCombos)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string input="5";
	int target=4;
	int numCombos= 0;
	NumCombine _NumCombine;
	int ret=_NumCombine.numCombos(input,target);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"input = "<<input<<endl;
	cout<<"target = "<<target<<endl;
	cout<<"expected to return "<<numCombos<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numCombos)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string input="4";
	int target=5;
	int numCombos= 1;
	NumCombine _NumCombine;
	int ret=_NumCombine.numCombos(input,target);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"input = "<<input<<endl;
	cout<<"target = "<<target<<endl;
	cout<<"expected to return "<<numCombos<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numCombos)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string input="927572819283748";
	int target=123456789;
	int numCombos= 4780782;
	NumCombine _NumCombine;
	int ret=_NumCombine.numCombos(input,target);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"input = "<<input<<endl;
	cout<<"target = "<<target<<endl;
	cout<<"expected to return "<<numCombos<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numCombos)
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
