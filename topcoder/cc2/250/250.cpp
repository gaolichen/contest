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


class FleasFleas{
public:
	int population(int n,int k){
		int i,ret=0,j=1;
		i=k+5;
		while(1){
			i-=5;
			ret+=n*j;
			if(ret>10000000)return -1;
			if(i<0)break;
			j*=i;
		}
		return ret;
	}
};




void test0(){
	int n=30;
	int k=7;
	int population= 660;
	FleasFleas _FleasFleas;
	int ret=_FleasFleas.population(n,k);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"k = "<<k<<endl;
	cout<<"expected to return "<<population<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==population)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int n=100;
	int k=3;
	int population= 400;
	FleasFleas _FleasFleas;
	int ret=_FleasFleas.population(n,k);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"k = "<<k<<endl;
	cout<<"expected to return "<<population<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==population)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int n=100;
	int k=100;
	int population= -1;
	FleasFleas _FleasFleas;
	int ret=_FleasFleas.population(n,k);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"k = "<<k<<endl;
	cout<<"expected to return "<<population<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==population)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int n=50;
	int k=15;
	int population= 45800;
	FleasFleas _FleasFleas;
	int ret=_FleasFleas.population(n,k);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"k = "<<k<<endl;
	cout<<"expected to return "<<population<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==population)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int n=100;
	int k=0;
	int population= 100;
	FleasFleas _FleasFleas;
	int ret=_FleasFleas.population(n,k);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"k = "<<k<<endl;
	cout<<"expected to return "<<population<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==population)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	int n=56;
	int k=23;
	int population= 9970464;
	FleasFleas _FleasFleas;
	int ret=_FleasFleas.population(n,k);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"k = "<<k<<endl;
	cout<<"expected to return "<<population<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==population)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test6(){
	int n=2;
	int k=2;
	int population= 6;
	FleasFleas _FleasFleas;
	int ret=_FleasFleas.population(n,k);
	cout<<"--------------------test 6--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"k = "<<k<<endl;
	cout<<"expected to return "<<population<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==population)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test7(){
	int n=5;
	int k=5;
	int population= 30;
	FleasFleas _FleasFleas;
	int ret=_FleasFleas.population(n,k);
	cout<<"--------------------test 7--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"k = "<<k<<endl;
	cout<<"expected to return "<<population<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==population)
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
	test6();
	test7();
	return 0;
}
