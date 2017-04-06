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


class Patterns{
public:
	int firstMatch(string s,string pat){
		int i,j,count=0,k,t;
		int mark[100],done[100];
		memset(mark,0,sizeof(mark));
		for(i=0;i<pat.length();i++)
			if(!mark[i])
				for(j=i,count++;j<pat.length();j++)
					if(pat[j]==pat[i])mark[j]=count;
		for(i=0;i<pat.length();i++)
			cout<<mark[i]<<' ';
		cout<<endl;
		if(s.length()<pat.length())return -1;
		for(i=0;i+pat.length()<=s.length();i++){
			memset(done,0,sizeof(done));
			t=0;
			for(j=0;j<pat.length();j++)
				if(!done[j])
					for(k=j,t++;k<pat.length();k++)
						if(s[i+j]==s[i+k])done[k]=t;
			for(j=0;j<pat.length();j++)
			cout<<done[j]<<' ';
			cout<<endl;
			for(j=0;j<pat.length();j++)
				if(done[j]!=mark[j])break;
			if(j==pat.length())return i;
		}
		return -1;
	}
};




void test0(){
	string s="nowisthetree";
	string pat="ABCA";
	int firstMatch= 5;
	Patterns _Patterns;
	int ret=_Patterns.firstMatch(s,pat);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"s = "<<s<<endl;
	cout<<"pat = "<<pat<<endl;
	cout<<"expected to return "<<firstMatch<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==firstMatch)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string s="abcdefghijklmnop";
	string pat="ZYX";
	int firstMatch= 0;
	Patterns _Patterns;
	int ret=_Patterns.firstMatch(s,pat);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"s = "<<s<<endl;
	cout<<"pat = "<<pat<<endl;
	cout<<"expected to return "<<firstMatch<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==firstMatch)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string s="abcdefghijklmnop";
	string pat="QQ";
	int firstMatch= -1;
	Patterns _Patterns;
	int ret=_Patterns.firstMatch(s,pat);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"s = "<<s<<endl;
	cout<<"pat = "<<pat<<endl;
	cout<<"expected to return "<<firstMatch<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==firstMatch)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string s="cd";
	string pat="CDCD";
	int firstMatch= -1;
	Patterns _Patterns;
	int ret=_Patterns.firstMatch(s,pat);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"s = "<<s<<endl;
	cout<<"pat = "<<pat<<endl;
	cout<<"expected to return "<<firstMatch<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==firstMatch)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string s="abab";
	string pat="CDCD";
	int firstMatch= 0;
	Patterns _Patterns;
	int ret=_Patterns.firstMatch(s,pat);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"s = "<<s<<endl;
	cout<<"pat = "<<pat<<endl;
	cout<<"expected to return "<<firstMatch<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==firstMatch)
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
