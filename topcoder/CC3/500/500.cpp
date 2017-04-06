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


class Coherence{
public:
	int minBndry(int r,int c,int k){
		int i,j,ret,t,tmp;
		if(k*2>r*c)k=r*c-k;
		if(k==0)return 0;
		ret=2100000000;
		for(i=1;i<=r;i++){
			if(i*c<k)continue;
			j=k/i;
			t=k%i;
			tmp=0;
			if(i<r)tmp+=j;
			if(j<c)tmp+=i;
			if(t){
				tmp++;
				if(j+1==c)tmp-=t;
			}
			if(tmp<ret)ret=tmp;
//			if(tmp==4)cout<<i<<endl;
		}
		for(i=1;i<=c;i++){
			if(i*r<k)continue;
			j=k/i;
			t=k%i;
			tmp=0;
			if(i<c)tmp+=j;
			if(j<r)tmp+=i;
			if(t){
				tmp++;
				if(j+1==r)tmp-=t;
			}
			if(tmp<ret)ret=tmp;
		}
		return ret;
	}
};




void test0(){
	int numRows=30;
	int numCols=30;
	int k=895;
	int minBndry= 5;
	Coherence _Coherence;
	int ret=_Coherence.minBndry(numRows,numCols,k);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"numRows = "<<numRows<<endl;
	cout<<"numCols = "<<numCols<<endl;
	cout<<"k = "<<k<<endl;
	cout<<"expected to return "<<minBndry<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minBndry)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int numRows=4;
	int numCols=6;
	int k=16;
	int minBndry= 4;
	Coherence _Coherence;
	int ret=_Coherence.minBndry(numRows,numCols,k);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"numRows = "<<numRows<<endl;
	cout<<"numCols = "<<numCols<<endl;
	cout<<"k = "<<k<<endl;
	cout<<"expected to return "<<minBndry<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minBndry)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int numRows=9;
	int numCols=5;
	int k=0;
	int minBndry= 0;
	Coherence _Coherence;
	int ret=_Coherence.minBndry(numRows,numCols,k);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"numRows = "<<numRows<<endl;
	cout<<"numCols = "<<numCols<<endl;
	cout<<"k = "<<k<<endl;
	cout<<"expected to return "<<minBndry<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minBndry)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

int main(){
	test0();
	test1();
	test2();
	return 0;
}
