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


class RoundRobin{
public:
	vector<int> order(vector<string> r){
		int i,j,m1,m2,t1,t2,k,l,ti;
		int socr[100],mark[100];
		vector<int> ret;
		memset(socr,0,sizeof(socr));
		memset(mark,0,sizeof(mark));
		m1=2100000000;m2=0;
		for(i=0;i<r.size();i++){
			for(j=0;j<r[i].length();j++)
				if(i!=j)socr[i]+=r[i][j]-'0';
			if(socr[i]<m1)m1=socr[i];
			if(socr[i]>m2)m2=socr[i];
		}
		for(i=0;i<r.size();i++){
			ti=-1;
			for(j=0;j<r.size();j++)
				if(!mark[j]){
					if(ti==-1||socr[j]>socr[ti])
						ti=j;
					else if(socr[j]==socr[ti]){
						for(k=m1-1;k<m2;k++){
							for(l=t1=t2=0;l<r.size();l++)
								if(socr[l]>k){
									if(l!=ti)t1+=r[ti][l]-'0';
									if(l!=j)t2+=r[j][l]-'0';
								}
							if(t1>t2)break;
							if(t1<t2){
								ti=j;
								break;
							}
						}
					}
				}
			ret.push_back(ti);
			mark[ti]=1;
		}
		return ret;
	}
};




void test0(){
	string _results[]={"-21112", "0-2221", "10-022", "102-01", "1002-2", "01010-"};
	vector<string> results(_results+0,_results+sizeof(_results)/sizeof(string));
	int _order[]= { 1,  0,  2,  4,  3,  5 };
	vector<int> order(_order+0,_order+sizeof(_order)/sizeof(int));
	RoundRobin _RoundRobin;
	vector<int> ret=_RoundRobin.order(results);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"results = "<<results<<endl;
	cout<<"expected to return "<<order<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==order)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _results[]={"-2110", "0-211", "10-12", "111-1", "2101-"};
	vector<string> results(_results+0,_results+sizeof(_results)/sizeof(string));
	int _order[]= { 0,  1,  2,  3,  4 };
	vector<int> order(_order+0,_order+sizeof(_order)/sizeof(int));
	RoundRobin _RoundRobin;
	vector<int> ret=_RoundRobin.order(results);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"results = "<<results<<endl;
	cout<<"expected to return "<<order<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==order)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _results[]={"-1102121", "1-010200", "12-00100", "212-2201", "0220-011", "10102-11", "022211-0", "1221112-"};
	vector<string> results(_results+0,_results+sizeof(_results)/sizeof(string));
	int _order[]= { 3,  7,  0,  6,  5,  4,  1,  2 };
	vector<int> order(_order+0,_order+sizeof(_order)/sizeof(int));
	RoundRobin _RoundRobin;
	vector<int> ret=_RoundRobin.order(results);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"results = "<<results<<endl;
	cout<<"expected to return "<<order<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==order)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string _results[]={"-12122111001121", "1-1012210221111", "01-010002021210", "122-22001100121", "0110-1121112112", "00201-111102122", "102211-12000111", "1122011-0011111", "12011102-212102", "202111220-11012", "2002122111-0002", "11120021012-100", "110111111221-01", "0110101121222-0", "11210011000212-"};
	vector<string> results(_results+0,_results+sizeof(_results)/sizeof(string));
	int _order[]= { 8,  1,  0,  9,  4,  3,  12,  10,  13,  5,  6,  7,  11,  14,  2 };
	vector<int> order(_order+0,_order+sizeof(_order)/sizeof(int));
	RoundRobin _RoundRobin;
	vector<int> ret=_RoundRobin.order(results);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"results = "<<results<<endl;
	cout<<"expected to return "<<order<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==order)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string _results[]={"-"};
	vector<string> results(_results+0,_results+sizeof(_results)/sizeof(string));
	int _order[]= { 0 };
	vector<int> order(_order+0,_order+sizeof(_order)/sizeof(int));
	RoundRobin _RoundRobin;
	vector<int> ret=_RoundRobin.order(results);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"results = "<<results<<endl;
	cout<<"expected to return "<<order<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==order)
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
