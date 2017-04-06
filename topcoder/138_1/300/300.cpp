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
i64 gcd(i64 a,i64 b){for(int c;b;c=a,a=b,b=c%b);return a;}
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


class LongLine{
public:
	int count(vector<int> pa){
		i64 i,j,w,h;
		w=pa[0];h=pa[1];
		i64 x,y;
		x=pa[2];y=pa[3];
		i64 dx,dy;
		dx=pa[4];dy=pa[5];
		i64 cnt=0;
		i64 tmp=gcd(dx,dy);
		dx/=tmp;dy/=tmp;
		if(dx==0&&dy){
			return 1;
		}
		if(dy==0&&dx)return 1;
		if(dy==0&&dx==0)return 0;
		for(i=1;;i++){
			if((x+i*dx)%w==0&&(y+i*dy)%h==0)
				cnt++;
			if((i*dx)%w==0&&(i*dy)%h==0)break;	
		}
		j=abs(i*dy/h);
		i=abs(i*dx/w);
//		if(x!=0&&y!=0)i--;
		return (int)(i+j-cnt);
	}
};




void test0(){
	int _params[]={997, 991, 976, 31, 9949, 9941};
	vector<int> params(_params+0,_params+sizeof(_params)/sizeof(int));
	int count= 889051;
	LongLine _LongLine;
	int ret=_LongLine.count(params);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"params = "<<params<<endl;
	cout<<"expected to return "<<count<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==count)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int _params[]={10, 10, 1, 0, 2, 10};
	vector<int> params(_params+0,_params+sizeof(_params)/sizeof(int));
	int count= 6;
	LongLine _LongLine;
	int ret=_LongLine.count(params);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"params = "<<params<<endl;
	cout<<"expected to return "<<count<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==count)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int _params[]={3, 2, 1, 1, 2, 4};
	vector<int> params(_params+0,_params+sizeof(_params)/sizeof(int));
	int count= 4;
	LongLine _LongLine;
	int ret=_LongLine.count(params);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"params = "<<params<<endl;
	cout<<"expected to return "<<count<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==count)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int _params[]={1000, 1000, 0, 0, 4000, 4000};
	vector<int> params(_params+0,_params+sizeof(_params)/sizeof(int));
	int count= 1;
	LongLine _LongLine;
	int ret=_LongLine.count(params);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"params = "<<params<<endl;
	cout<<"expected to return "<<count<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==count)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int _params[]={1000, 1000, 0, 1, -555, 1000};
	vector<int> params(_params+0,_params+sizeof(_params)/sizeof(int));
	int count= 311;
	LongLine _LongLine;
	int ret=_LongLine.count(params);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"params = "<<params<<endl;
	cout<<"expected to return "<<count<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==count)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	int _params[]={97, 101, 25, 32, 11, 19};
	vector<int> params(_params+0,_params+sizeof(_params)/sizeof(int));
	int count= 2953;
	LongLine _LongLine;
	int ret=_LongLine.count(params);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"params = "<<params<<endl;
	cout<<"expected to return "<<count<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==count)
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
