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


class Lexer{
public:
	int check(const char *a,const char *b){
		int i;
		for(i=0;b[i];i++){
			if(!a[i])return 0;
			if(a[i]!=b[i])return 0;
		}
		return i;
	}
	vector<string> tokenize(vector<string> tokens,string input){
		int i,j,min,t,k;
		vector<string> ret;
		for(i=0;i<input.length();i++){
			min=0;
			for(j=0;j<tokens.size();j++){
				k=check(input.c_str()+i,tokens[j].c_str());
				if(k>min){
					min=k;
					t=j;
				}
			}
			if(min){
				ret.push_back(tokens[t]);
				i+=tokens[t].length()-1;
			}
		}
		return ret;
	}
};




void test0(){
	string _tokens[]={"ab","aba","A"};
	vector<string> tokens(_tokens+0,_tokens+sizeof(_tokens)/sizeof(string));
	string input="ababbbaAab";
	string _tokenize[]= { "aba",  "A",  "ab" };
	vector<string> tokenize(_tokenize+0,_tokenize+sizeof(_tokenize)/sizeof(string));
	Lexer _Lexer;
	vector<string> ret=_Lexer.tokenize(tokens,input);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"tokens = "<<tokens<<endl;
	cout<<"input = "<<input<<endl;
	cout<<"expected to return "<<tokenize<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==tokenize)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _tokens[]={"a","a","aa","aaa","aaaa","aaaaa","aa"};
	vector<string> tokens(_tokens+0,_tokens+sizeof(_tokens)/sizeof(string));
	string input="aaaaaaaaaaaaaaaaaaaaaaaaa";
	string _tokenize[]= { "aaaaa",  "aaaaa",  "aaaaa",  "aaaaa",  "aaaaa" };
	vector<string> tokenize(_tokenize+0,_tokenize+sizeof(_tokenize)/sizeof(string));
	Lexer _Lexer;
	vector<string> ret=_Lexer.tokenize(tokens,input);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"tokens = "<<tokens<<endl;
	cout<<"input = "<<input<<endl;
	cout<<"expected to return "<<tokenize<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==tokenize)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _tokens[]={"wow","wo","w"};
	vector<string> tokens(_tokens+0,_tokens+sizeof(_tokens)/sizeof(string));
	string input="awofwwofowwowowowwwooo";
	string _tokenize[]= { "wo",  "w",  "wo",  "w",  "wow",  "wow",  "w",  "wo" };
	vector<string> tokenize(_tokenize+0,_tokenize+sizeof(_tokenize)/sizeof(string));
	Lexer _Lexer;
	vector<string> ret=_Lexer.tokenize(tokens,input);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"tokens = "<<tokens<<endl;
	cout<<"input = "<<input<<endl;
	cout<<"expected to return "<<tokenize<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==tokenize)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string _tokens[]={"int","double","long","char","boolean","byte","float"};
	vector<string> tokens(_tokens+0,_tokens+sizeof(_tokens)/sizeof(string));
	string input="intlongdoublecharintintboolean";
	string _tokenize[]= { "int",  "long",  "double",  "char",  "int",  "int",  "boolean" };
	vector<string> tokenize(_tokenize+0,_tokenize+sizeof(_tokenize)/sizeof(string));
	Lexer _Lexer;
	vector<string> ret=_Lexer.tokenize(tokens,input);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"tokens = "<<tokens<<endl;
	cout<<"input = "<<input<<endl;
	cout<<"expected to return "<<tokenize<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==tokenize)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	vector<string> tokens(0);
	string input="Great";
	vector<string> tokenize(0);
	Lexer _Lexer;
	vector<string> ret=_Lexer.tokenize(tokens,input);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"tokens = "<<tokens<<endl;
	cout<<"input = "<<input<<endl;
	cout<<"expected to return "<<tokenize<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==tokenize)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string _tokens[]={"AbCd","dEfG","GhIj"};
	vector<string> tokens(_tokens+0,_tokens+sizeof(_tokens)/sizeof(string));
	string input="abCdEfGhIjAbCdEfGhIj";
	string _tokenize[]= { "dEfG",  "AbCd",  "GhIj" };
	vector<string> tokenize(_tokenize+0,_tokenize+sizeof(_tokenize)/sizeof(string));
	Lexer _Lexer;
	vector<string> ret=_Lexer.tokenize(tokens,input);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"tokens = "<<tokens<<endl;
	cout<<"input = "<<input<<endl;
	cout<<"expected to return "<<tokenize<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==tokenize)
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
