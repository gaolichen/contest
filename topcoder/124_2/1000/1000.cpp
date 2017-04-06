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


class AlphaWord{
public:
	string firstAlpha(string d){
		int i;
		char mat[50][50],mark[50];
		memset(mat,0,sizeof(mat));
		for(i=0;i<d.length();i++){
			if(d[i]=='A')mat[i+1][i]=1;
			else mat[i][i+1]=1;
		}
		int count=0;
		string ret;
		memset(mark,0,sizeof(mark));
		while(count<d.length()+1){
			for(i=0;i<d.length()+1;i++)
				if(!mark[i]){
					if(i&&mat[i-1][i])continue;
					if(mat[i+1][i]==0){
						ret=ret+char('a'+i);
						mat[i][i+1]=0;
						if(i)mat[i][i-1]=0;mark[i]=1;
						break;
						
					}
				}
			count++;
		}
		return ret;
	}
};




void test0(){
	string decree="BAA";
	string firstAlpha= "adcb";
	AlphaWord _AlphaWord;
	string ret=_AlphaWord.firstAlpha(decree);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"decree = "<<decree<<endl;
	cout<<"expected to return "<<firstAlpha<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==firstAlpha)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string decree="AAAA";
	string firstAlpha= "edcba";
	AlphaWord _AlphaWord;
	string ret=_AlphaWord.firstAlpha(decree);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"decree = "<<decree<<endl;
	cout<<"expected to return "<<firstAlpha<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==firstAlpha)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string decree="BBAA";
	string firstAlpha= "abedc";
	AlphaWord _AlphaWord;
	string ret=_AlphaWord.firstAlpha(decree);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"decree = "<<decree<<endl;
	cout<<"expected to return "<<firstAlpha<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==firstAlpha)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string decree="BABABABABABABABABABABABAB";
	string firstAlpha= "acbedgfihkjmlonqpsrutwvyxz";
	AlphaWord _AlphaWord;
	string ret=_AlphaWord.firstAlpha(decree);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"decree = "<<decree<<endl;
	cout<<"expected to return "<<firstAlpha<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==firstAlpha)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

int main(){
	test0();
	test1();
	test2();
	test3();
	return 0;
}
