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


class LongestRun{
public:
	int runLength(vector<string> c){
		int i,j,ret=0,k,tmp;
		int tal[30];
		vector<string> d;
		memset(tal,0,sizeof(tal));
		for(i=0;i<c.size();i++){
			for(j=0;j<c[i].length();j++)
				if(c[i][j]!=c[i][0])break;
				if(j==c[i].length()){
					tal[c[i][0]-'A']+=c[i].length();
				}
				else d.push_back(c[i]);
		}
		for(i=0;i<26;i++)
			if(tal[i]>ret)ret=tal[i];
		for(i=0;i<d.size();i++){
			for(j=1,tmp=1;j<d[i].length();j++){
				if(d[i][j]==d[i][j-1])tmp++;
				else {
					if(tmp>ret)ret=tmp;
					tmp=1;
				}
			}
		}
		for(i=0;i<d.size();i++)
			for(j=0;j<d.size();j++)
				if(i!=j&&d[i][d[i].length()-1]==d[j][0]){
					for(k=0;d[j][k]==d[j][0];k++);
					tmp=k;
					for(k=d[i].length()-1;d[i][k]==d[i][d[i].length()-1];k--);
					tmp+=d[i].length()-k-1;
					tmp+=tal[d[j][0]-'A'];
					if(tmp>ret)ret=tmp;
				}
		for(i=0;i<d.size();i++){
			for(k=0;d[i][k]==d[i][0];k++);
			if(k+tal[d[i][0]-'A']>ret)ret=k+tal[d[i][0]-'A'];
			for(k=d[i].length()-1;d[i][k]==d[i][d[i].length()-1];k--);
			k=d[i].length()-1-k+tal[d[i][d[i].length()-1]-'A'];
			if(k>ret)ret=k;
		}
		return ret;
	}
};




void test0(){
	string _collection[]={"ABC", "CBBB", "CC", "ABCDEFG"};
	vector<string> collection(_collection+0,_collection+sizeof(_collection)/sizeof(string));
	int runLength= 4;
	LongestRun _LongestRun;
	int ret=_LongestRun.runLength(collection);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"collection = "<<collection<<endl;
	cout<<"expected to return "<<runLength<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==runLength)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _collection[]={"ABC", "CBBBC","ABCDEFG", "AD", "AE", "AF"};
	vector<string> collection(_collection+0,_collection+sizeof(_collection)/sizeof(string));
	int runLength= 3;
	LongestRun _LongestRun;
	int ret=_LongestRun.runLength(collection);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"collection = "<<collection<<endl;
	cout<<"expected to return "<<runLength<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==runLength)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _collection[]={"GOOD","DOG","EGG","DO","GIGABYTE","OOO","G","G"};
	vector<string> collection(_collection+0,_collection+sizeof(_collection)/sizeof(string));
	int runLength= 5;
	LongestRun _LongestRun;
	int ret=_LongestRun.runLength(collection);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"collection = "<<collection<<endl;
	cout<<"expected to return "<<runLength<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==runLength)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string _collection[]={"AAABBBBAAA","BAABBBBAB"};
	vector<string> collection(_collection+0,_collection+sizeof(_collection)/sizeof(string));
	int runLength= 4;
	LongestRun _LongestRun;
	int ret=_LongestRun.runLength(collection);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"collection = "<<collection<<endl;
	cout<<"expected to return "<<runLength<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==runLength)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string _collection[]={"AAABBBBAAA","AABBBBA"};
	vector<string> collection(_collection+0,_collection+sizeof(_collection)/sizeof(string));
	int runLength= 5;
	LongestRun _LongestRun;
	int ret=_LongestRun.runLength(collection);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"collection = "<<collection<<endl;
	cout<<"expected to return "<<runLength<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==runLength)
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
