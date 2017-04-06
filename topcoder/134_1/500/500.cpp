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


class QuickCount{
public:
	vector<int> howMany(int f,int l,int b){
		int i;
		vector<int> ret;
		for(i=1;i<b;i++)
			ret.push_back(0);
		while(l){
			for(i=1;i<=l%b;i++)
				ret[i-1]++;
			for(i=1;i<b;i++)
				ret[i-1]+=l/b;
			l/=b;
		}
		f--;
		while(f){
			for(i=1;i<=f%b;i++)
				ret[i-1]--;
			for(i=1;i<b;i++)
				ret[i-1]-=f/b;
			f/=b;
		}
		return ret;
	}
};




void test0(){
	int first=1;
	int last=9;
	int numBase=10;
	int _howMany[]= { 1,  1,  1,  1,  1,  1,  1,  1,  1 };
	vector<int> howMany(_howMany+0,_howMany+sizeof(_howMany)/sizeof(int));
	QuickCount _QuickCount;
	vector<int> ret=_QuickCount.howMany(first,last,numBase);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"first = "<<first<<endl;
	cout<<"last = "<<last<<endl;
	cout<<"numBase = "<<numBase<<endl;
	cout<<"expected to return "<<howMany<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howMany)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int first=1;
	int last=20;
	int numBase=10;
	int _howMany[]= { 3,  3,  2,  2,  2,  2,  2,  2,  2 };
	vector<int> howMany(_howMany+0,_howMany+sizeof(_howMany)/sizeof(int));
	QuickCount _QuickCount;
	vector<int> ret=_QuickCount.howMany(first,last,numBase);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"first = "<<first<<endl;
	cout<<"last = "<<last<<endl;
	cout<<"numBase = "<<numBase<<endl;
	cout<<"expected to return "<<howMany<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howMany)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int first=16;
	int last=31;
	int numBase=4;
	int _howMany[]= { 6,  5,  5 };
	vector<int> howMany(_howMany+0,_howMany+sizeof(_howMany)/sizeof(int));
	QuickCount _QuickCount;
	vector<int> ret=_QuickCount.howMany(first,last,numBase);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"first = "<<first<<endl;
	cout<<"last = "<<last<<endl;
	cout<<"numBase = "<<numBase<<endl;
	cout<<"expected to return "<<howMany<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howMany)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int first=1;
	int last=2000000000;
	int numBase=2;
	int _howMany[]= { 2000000000 };
	vector<int> howMany(_howMany+0,_howMany+sizeof(_howMany)/sizeof(int));
	QuickCount _QuickCount;
	vector<int> ret=_QuickCount.howMany(first,last,numBase);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"first = "<<first<<endl;
	cout<<"last = "<<last<<endl;
	cout<<"numBase = "<<numBase<<endl;
	cout<<"expected to return "<<howMany<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howMany)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int first=1;
	int last=1;
	int numBase=2;
	int _howMany[]= { 1 };
	vector<int> howMany(_howMany+0,_howMany+sizeof(_howMany)/sizeof(int));
	QuickCount _QuickCount;
	vector<int> ret=_QuickCount.howMany(first,last,numBase);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"first = "<<first<<endl;
	cout<<"last = "<<last<<endl;
	cout<<"numBase = "<<numBase<<endl;
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
