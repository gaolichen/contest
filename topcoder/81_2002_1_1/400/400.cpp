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


class UGroupOrder{
public:
	int gcd(int a,int b){
		if(b==0)return a;
		return gcd(b,a%b);
	}
	vector<int> findOrders(int n){
		int i,j,t;
		vector<int> ret;
		for(i=1;i<n;i++)
			if(gcd(i,n)==1){
				j=1;t=i;
				while(t!=1){
					t*=i;
					t%=n;
					j++;
				}
			ret.push_back(j);
		}
		return ret;
	}
};




void test0(){
	int N=9;
	int _findOrders[]= { 1,  6,  3,  6,  3,  2 };
	vector<int> findOrders(_findOrders+0,_findOrders+sizeof(_findOrders)/sizeof(int));
	UGroupOrder _UGroupOrder;
	vector<int> ret=_UGroupOrder.findOrders(N);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"N = "<<N<<endl;
	cout<<"expected to return "<<findOrders<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==findOrders)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int N=8;
	int _findOrders[]= { 1,  2,  2,  2 };
	vector<int> findOrders(_findOrders+0,_findOrders+sizeof(_findOrders)/sizeof(int));
	UGroupOrder _UGroupOrder;
	vector<int> ret=_UGroupOrder.findOrders(N);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"N = "<<N<<endl;
	cout<<"expected to return "<<findOrders<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==findOrders)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int N=15;
	int _findOrders[]= { 1,  4,  2,  4,  4,  2,  4,  2 };
	vector<int> findOrders(_findOrders+0,_findOrders+sizeof(_findOrders)/sizeof(int));
	UGroupOrder _UGroupOrder;
	vector<int> ret=_UGroupOrder.findOrders(N);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"N = "<<N<<endl;
	cout<<"expected to return "<<findOrders<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==findOrders)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int N=51;
	int _findOrders[]={ 1,  8,  4,  16,  16,  8,  16,  16,  4,  16,  2,  8,  16,  16,  16,  8,  8,  16,  16,  16,  8,  2,  16,  4,  16,  16,  8,  16,  16,  4,  8,  2 };
	vector<int> findOrders(_findOrders+0,_findOrders+sizeof(_findOrders)/sizeof(int));
	UGroupOrder _UGroupOrder;
	vector<int> ret=_UGroupOrder.findOrders(N);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"N = "<<N<<endl;
	cout<<"expected to return "<<findOrders<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==findOrders)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int N=10;
	int _findOrders[]= { 1,  4,  4,  2 };
	vector<int> findOrders(_findOrders+0,_findOrders+sizeof(_findOrders)/sizeof(int));
	UGroupOrder _UGroupOrder;
	vector<int> ret=_UGroupOrder.findOrders(N);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"N = "<<N<<endl;
	cout<<"expected to return "<<findOrders<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==findOrders)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	int N=2;
	int _findOrders[]= { 1 };
	vector<int> findOrders(_findOrders+0,_findOrders+sizeof(_findOrders)/sizeof(int));
	UGroupOrder _UGroupOrder;
	vector<int> ret=_UGroupOrder.findOrders(N);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"N = "<<N<<endl;
	cout<<"expected to return "<<findOrders<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==findOrders)
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
