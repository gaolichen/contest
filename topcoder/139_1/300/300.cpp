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


class Tourney{
public:
	string winner(vector<string> br,string r){
		int i,j;
		string tmp;
		vector<string> a;
		tmp="bye";
		j=0;
		while(1){
			if(br.size()==1)break;
			for(i=0;i<br.size();i+=2){
				if(br[i]==tmp){
					a.push_back(br[i+1]);
				}
				else if(br[i+1]==tmp)
					a.push_back(br[i]);
				else{
					if(r[j]=='H')a.push_back(br[i]);
					else a.push_back(br[i+1]);
					j++;
				}
			}
			br=a;
			a.clear();
		}
		return br[0];
	}
};




void test0(){
	string _bracket[]={"DUKE","UCLA","bye","MIT"};
	vector<string> bracket(_bracket+0,_bracket+sizeof(_bracket)/sizeof(string));
	string results="HL";
	string winner= "MIT";
	Tourney _Tourney;
	string ret=_Tourney.winner(bracket,results);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"bracket = "<<bracket<<endl;
	cout<<"results = "<<results<<endl;
	cout<<"expected to return "<<winner<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==winner)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _bracket[]={"A","B","C","bye","D","E","F","bye"};
	vector<string> bracket(_bracket+0,_bracket+sizeof(_bracket)/sizeof(string));
	string results="LHHLH";
	string winner= "B";
	Tourney _Tourney;
	string ret=_Tourney.winner(bracket,results);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"bracket = "<<bracket<<endl;
	cout<<"results = "<<results<<endl;
	cout<<"expected to return "<<winner<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==winner)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}
/*
void test2(){
	string _bracket[]={"MIT","bye"}	""Returns: "MIT"3)????{"STANFORD","bye","STANFORD","bye"};
	vector<string> bracket(_bracket+0,_bracket+sizeof(_bracket)/sizeof(string));
	string results="L";
	string winner= "STANFORD";
	Tourney _Tourney;
	string ret=_Tourney.winner(bracket,results);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"bracket = "<<bracket<<endl;
	cout<<"results = "<<results<<endl;
	cout<<"expected to return "<<winner<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==winner)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}*/

int main(){
	test0();
	test1();
//	test2();
	return 0;
}
