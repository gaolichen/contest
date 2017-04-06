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


class Datatype{
public:
	string getType(string var){
		int i;
		string tmp;
		for(i=0;i<var.length();i++)
			if(var[i]>='A'&&var[i]<='Z')
				var[i]=var[i]+'a'-'A';
		int del=0,oth=0;
		tmp=var;
		for(i=0;i<tmp.length();i++){
			if(tmp[i]=='.')del++;
			else if(!(tmp[i]>='0'&&tmp[i]<='9'))oth=1;
		}
		if(!del&&!oth)return "INTEGER";
		if(del==1&&!oth)return "DECIMAL";
		if(del>1)return "STRING";
		if(tmp=="true"||tmp=="false")return "BOOLEAN";
		return "STRING";
	}
};




void test0(){
	string var="123";
	string getType= "INTEGER";
	Datatype _Datatype;
	string ret=_Datatype.getType(var);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"var = "<<var<<endl;
	cout<<"expected to return "<<getType<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getType)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string var="324.1";
	string getType= "DECIMAL";
	Datatype _Datatype;
	string ret=_Datatype.getType(var);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"var = "<<var<<endl;
	cout<<"expected to return "<<getType<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getType)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string var=".12";
	string getType= "DECIMAL";
	Datatype _Datatype;
	string ret=_Datatype.getType(var);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"var = "<<var<<endl;
	cout<<"expected to return "<<getType<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getType)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string var="453.";
	string getType= "DECIMAL";
	Datatype _Datatype;
	string ret=_Datatype.getType(var);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"var = "<<var<<endl;
	cout<<"expected to return "<<getType<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getType)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string var="770.555.1212";
	string getType= "STRING";
	Datatype _Datatype;
	string ret=_Datatype.getType(var);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"var = "<<var<<endl;
	cout<<"expected to return "<<getType<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getType)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string var="TrUe";
	string getType= "BOOLEAN";
	Datatype _Datatype;
	string ret=_Datatype.getType(var);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"var = "<<var<<endl;
	cout<<"expected to return "<<getType<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getType)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test6(){
	string var="this is just a string";
	string getType= "STRING";
	Datatype _Datatype;
	string ret=_Datatype.getType(var);
	cout<<"--------------------test 6--------------------"<<endl;
	cout<<"var = "<<var<<endl;
	cout<<"expected to return "<<getType<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getType)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test7(){
	string var="453 ducks flew 4739.45 miles.";
	string getType= "STRING";
	Datatype _Datatype;
	string ret=_Datatype.getType(var);
	cout<<"--------------------test 7--------------------"<<endl;
	cout<<"var = "<<var<<endl;
	cout<<"expected to return "<<getType<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getType)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test8(){
	string var=".";
	string getType= "DECIMAL";
	Datatype _Datatype;
	string ret=_Datatype.getType(var);
	cout<<"--------------------test 8--------------------"<<endl;
	cout<<"var = "<<var<<endl;
	cout<<"expected to return "<<getType<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getType)
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
	test6();
	test7();
	test8();
	return 0;
}
