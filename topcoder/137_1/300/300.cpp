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


class Rendezvous{
public:
	vector<int> interceptVector(int x,int y,int dx,int dy){
		int i,x0,y0;
		vector<int> ret;
		x0=x;y0=y;
		for(i=0;;i++){
			x+=dx;y+=dy;
//			if(abs(x)>10000||abs(y)>10000)break;
			if(x%(i+1)==0&&y%(i+1)==0&&abs(x/(i+1))<=1000&&abs(y/(i+1))<=1000)break;
//			if((abs(x)>(i+2)*1000&&abs(dx)>(i+2)&&(x>0&&dx>0||x<0&&dx<0)
//				||abs(y)>(i+2)*1000&&abs(dy)>(i+2)&&
//				(y>0&&dy>0||y<0&&dy<0)))break;
			if((i+1)>abs(x0)||(i+1)>abs(y0))break;
			if(i==0&&dx==0&&dy==0){
				i=100000;break;

			}
		}
		if((i+1)>abs(x0)||(i+1)>abs(y0))return ret;
		cout<<i<<endl;
		cout<<x<<' '<<y<<endl;
		ret.push_back(x/(i+1));
		ret.push_back(y/(i+1));
		return ret;
	}
};




void test0(){
	int x=0;
	int y=3988;
	int dx=500;
	int dy=0;
	int _interceptVector[]= { 555,  333 };
	vector<int> interceptVector(_interceptVector+0,_interceptVector+sizeof(_interceptVector)/sizeof(int));
	Rendezvous _Rendezvous;
	vector<int> ret=_Rendezvous.interceptVector(x,y,dx,dy);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
	cout<<"dx = "<<dx<<endl;
	cout<<"dy = "<<dy<<endl;
	cout<<"expected to return "<<interceptVector<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==interceptVector)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int x=500;
	int y=300;
	int dx=600;
	int dy=700;
	int _interceptVector[]= { 850,  850 };
	vector<int> interceptVector(_interceptVector+0,_interceptVector+sizeof(_interceptVector)/sizeof(int));
	Rendezvous _Rendezvous;
	vector<int> ret=_Rendezvous.interceptVector(x,y,dx,dy);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
	cout<<"dx = "<<dx<<endl;
	cout<<"dy = "<<dy<<endl;
	cout<<"expected to return "<<interceptVector<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==interceptVector)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int x=1;
	int y=1;
	int dx=1000;
	int dy=1000;
	vector<int> interceptVector(0);
	Rendezvous _Rendezvous;
	vector<int> ret=_Rendezvous.interceptVector(x,y,dx,dy);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
	cout<<"dx = "<<dx<<endl;
	cout<<"dy = "<<dy<<endl;
	cout<<"expected to return "<<interceptVector<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==interceptVector)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int x=9519;
	int y=-1002;
	int dx=857;
	int dy=-534;
	int _interceptVector[]= { 914,  -540 };
	vector<int> interceptVector(_interceptVector+0,_interceptVector+sizeof(_interceptVector)/sizeof(int));
	Rendezvous _Rendezvous;
	vector<int> ret=_Rendezvous.interceptVector(x,y,dx,dy);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
	cout<<"dx = "<<dx<<endl;
	cout<<"dy = "<<dy<<endl;
	cout<<"expected to return "<<interceptVector<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==interceptVector)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int x=-1024;
	int y=333;
	int dx=15;
	int dy=-186;
	vector<int> interceptVector(0);
	Rendezvous _Rendezvous;
	vector<int> ret=_Rendezvous.interceptVector(x,y,dx,dy);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
	cout<<"dx = "<<dx<<endl;
	cout<<"dy = "<<dy<<endl;
	cout<<"expected to return "<<interceptVector<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==interceptVector)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	int x=10000;
	int y=10000;
	int dx=1;
	int dy=1;
	int _interceptVector[]= { 626,  626 };
	vector<int> interceptVector(_interceptVector+0,_interceptVector+sizeof(_interceptVector)/sizeof(int));
	Rendezvous _Rendezvous;
	vector<int> ret=_Rendezvous.interceptVector(x,y,dx,dy);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
	cout<<"dx = "<<dx<<endl;
	cout<<"dy = "<<dy<<endl;
	cout<<"expected to return "<<interceptVector<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==interceptVector)
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
