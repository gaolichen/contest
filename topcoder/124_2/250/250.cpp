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


class MakeTeam{
public:
	string lastOne(int n,vector<string> names){
		int i,j;
		string ret;
		if(names.size()<n){
			ret="NO TEAM";
			return ret;
		} 
		int min=100000;
		for(i=0;i<n;i++)
		if(names[i].length()<=min){
			min=names[i].length();
			j=i;
		}
		for(i=n;i<names.size();i++)
			if(names[i].length()>min){
				min=names[i].length();
				j=i;
			}
		return names[j];
	}
};




void test0(){
	int n=4;
	string _names[]={"BO","CHUCK","AL","DON","TOM"};
	vector<string> names(_names+0,_names+sizeof(_names)/sizeof(string));
	string lastOne= "TOM";
	MakeTeam _MakeTeam;
	string ret=_MakeTeam.lastOne(n,names);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"names = "<<names<<endl;
	cout<<"expected to return "<<lastOne<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==lastOne)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int n=2;
	string _names[]={"BOB"};
	vector<string> names(_names+0,_names+sizeof(_names)/sizeof(string));
	string lastOne= "NO TEAM";
	MakeTeam _MakeTeam;
	string ret=_MakeTeam.lastOne(n,names);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"names = "<<names<<endl;
	cout<<"expected to return "<<lastOne<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==lastOne)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int n=3;
	string _names[]={"JIM","BOB","TOM","AL","HAL"};
	vector<string> names(_names+0,_names+sizeof(_names)/sizeof(string));
	string lastOne= "TOM";
	MakeTeam _MakeTeam;
	string ret=_MakeTeam.lastOne(n,names);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"names = "<<names<<endl;
	cout<<"expected to return "<<lastOne<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==lastOne)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int n=6;
	string _names[]={"SAM","SAP","SAX","BO","SAD","SSM","SAL","HAL","RED"};
	vector<string> names(_names+0,_names+sizeof(_names)/sizeof(string));
	string lastOne= "SAL";
	MakeTeam _MakeTeam;
	string ret=_MakeTeam.lastOne(n,names);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"names = "<<names<<endl;
	cout<<"expected to return "<<lastOne<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==lastOne)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int n=2;
	string _names[]={"STOTTLEMEYER","EMPENTHALLERSTEIN","AL","DEFORESTATION","JON"};
	vector<string> names(_names+0,_names+sizeof(_names)/sizeof(string));
	string lastOne= "DEFORESTATION";
	MakeTeam _MakeTeam;
	string ret=_MakeTeam.lastOne(n,names);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"names = "<<names<<endl;
	cout<<"expected to return "<<lastOne<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==lastOne)
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
