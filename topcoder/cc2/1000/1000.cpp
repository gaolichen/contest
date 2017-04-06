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


class Tether{
public:
	double dis(int x1,int y1,int x2,int y2){
		return sqrt((double)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
	}
	double check(int r,int x,int y){
		if(y<=-r){
			return sqrt((double)(x*x+(y+r)*(y+r)));
		}
		double ret=0.0,pi=acos(-1.0);
		ret+=sqrt((double)(x*x+y*y-r*r));
		double a,b;
		a=acos(r/sqrt((double)(x*x+y*y)));
		b=acos(x/sqrt((double)(x*x+y*y)));
		if(y<0)b=2*pi-b;
		double a1,a2;
		a1=b-a;a2=b+a;
		if(a1<0)a1+=2*pi;
		if(a2<0)a2+=2*pi;
		if(a1>=2*pi)a1-=2*pi;
		if(a2>=2*pi)a2-=2*pi;
		if(x<0)a1=a2;
		a=fabs(1.5*pi-a1);
		if(a>pi)a=2*pi-a;
		cout<<ret+a*r<<endl;
		return ret+a*r;
	}
	int deadTrees(int rop,int r,vector<int> x,vector<int> y){
		int i,ret=0;
		for(i=0;i<x.size();i++)
			if(check(r,x[i],y[i])<=rop)ret++;
		return ret;
	}
};




void test0(){
	int rope=13;
	int radius=3;
	int _x[]={5,-5,0};
	vector<int> x(_x+0,_x+sizeof(_x)/sizeof(int));
	int _y[]={-15,-15,-16};
	vector<int> y(_y+0,_y+sizeof(_y)/sizeof(int));
	int deadTrees=3;
	Tether _Tether;
	int ret=_Tether.deadTrees(rope,radius,x,y);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"rope = "<<rope<<endl;
	cout<<"radius = "<<radius<<endl;
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
	cout<<"expected to return "<<deadTrees<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==deadTrees)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

int main(){
	test0();
	return 0;
}
