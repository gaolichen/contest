
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


class RunLengthEncode{
public:
	string encode(string in){
		int i,j,k;
		string ret;
		for(i=j=0;i<=in.length();i++){
			if(!i||in[i]!=in[i-1]){
				if(j>=5){
					ret+="/";
						ret+=j/10+'0';
						ret+=j%10+'0';
						ret+=in[i-1];
				}
				else {
					for(k=0;k<j;k++)
						ret+=in[i-1];
				}
				j=1;
			}
			else j++;
		}
		return ret;
	}
};




void test0(){
	string input="a";
	string encode= "/05a";
	RunLengthEncode _RunLengthEncode;
	string ret=_RunLengthEncode.encode(input);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"input = "<<input<<endl;
	cout<<"expected to return "<<encode<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==encode)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string input="aaaa";
	string encode= "aaaa";
	RunLengthEncode _RunLengthEncode;
	string ret=_RunLengthEncode.encode(input);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"input = "<<input<<endl;
	cout<<"expected to return "<<encode<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==encode)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string input="abcabcabcabcabc";
	string encode= "abcabcabcabcabc";
	RunLengthEncode _RunLengthEncode;
	string ret=_RunLengthEncode.encode(input);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"input = "<<input<<endl;
	cout<<"expected to return "<<encode<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==encode)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string input="if(a){if(b){if(c){if(d){if(e){5 deeeeeeep}}}}}";
	string encode= "if(a){if(b){if(c){if(d){if(e){5 d/07ep/05}";
	RunLengthEncode _RunLengthEncode;
	string ret=_RunLengthEncode.encode(input);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"input = "<<input<<endl;
	cout<<"expected to return "<<encode<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==encode)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string input="";
	string encode= "";
	RunLengthEncode _RunLengthEncode;
	string ret=_RunLengthEncode.encode(input);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"input = "<<input<<endl;
	cout<<"expected to return "<<encode<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==encode)
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
