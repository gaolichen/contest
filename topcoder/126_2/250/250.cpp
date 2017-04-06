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


class Battle{
public:
	string firstDefeated(string w1,string w2){
		int i,t1,t2,h1,d1,a1,h2,d2,a2;
		char name[200],name1[200],name2[200];
		sscanf(w1.c_str(),"%s %d %d %d",name1,&h1,&d1,&a1);
		sscanf(w2.c_str(),"%s %d %d %d",name2,&h2,&d2,&a2);
		t1=a2-d1;
		t2=a1-d2;
		if(t1<0)t1=0;
		if(t2<0)t2=0;
		int win=2,min=2100000000;
		win=2;
		if(t1){
			min=h1/t1+!!(h1%t1);
			win=0;
		}
		if(t2){
			i=h2/t2+!!(h2%t2);
			if(i<min){
				min=i;
				win=1;
			}
			else if(i==min)
				win=2;
		}
		string ret;
		if(min<=1000){
			if(win==0){
				ret+=name1;
			}
			else if(win==1)ret+=name2;
			else ret="NONE";
		}
		if(min>1000){
			min=1000;
			ret="NONE";
		}
		sprintf(name," %d",min);
		ret+=name;
		return ret;
	}
};




void test0(){
	string warrior1="Rynos 100 20 30";
	string warrior2="UnkaTarkal 1000 7 50";
	string firstDefeated= "Rynos 4";
	Battle _Battle;
	string ret=_Battle.firstDefeated(warrior1,warrior2);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"warrior1 = "<<warrior1<<endl;
	cout<<"warrior2 = "<<warrior2<<endl;
	cout<<"expected to return "<<firstDefeated<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==firstDefeated)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string warrior1="UnkaTarkalA 1000 7 50";
	string warrior2="UnkaTarkalB 1000 7 50";
	string firstDefeated= "NONE 24";
	Battle _Battle;
	string ret=_Battle.firstDefeated(warrior1,warrior2);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"warrior1 = "<<warrior1<<endl;
	cout<<"warrior2 = "<<warrior2<<endl;
	cout<<"expected to return "<<firstDefeated<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==firstDefeated)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string warrior1="Murp 1000000 1000 0";
	string warrior2="Rynos 100 20 30";
	string firstDefeated= "NONE 1000";
	Battle _Battle;
	string ret=_Battle.firstDefeated(warrior1,warrior2);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"warrior1 = "<<warrior1<<endl;
	cout<<"warrior2 = "<<warrior2<<endl;
	cout<<"expected to return "<<firstDefeated<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==firstDefeated)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string warrior1="AntA 1001 0 1";
	string warrior2="AntB 1000 0 1";
	string firstDefeated= "AntB 1000";
	Battle _Battle;
	string ret=_Battle.firstDefeated(warrior1,warrior2);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"warrior1 = "<<warrior1<<endl;
	cout<<"warrior2 = "<<warrior2<<endl;
	cout<<"expected to return "<<firstDefeated<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==firstDefeated)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string warrior1="AntA 1001 0 1";
	string warrior2="AntB 1002 0 1";
	string firstDefeated= "NONE 1000";
	Battle _Battle;
	string ret=_Battle.firstDefeated(warrior1,warrior2);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"warrior1 = "<<warrior1<<endl;
	cout<<"warrior2 = "<<warrior2<<endl;
	cout<<"expected to return "<<firstDefeated<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==firstDefeated)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string warrior1="Wizard 100000 500 500";
	string warrior2="Cow 1000 0 0";
	string firstDefeated= "Cow 2";
	Battle _Battle;
	string ret=_Battle.firstDefeated(warrior1,warrior2);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"warrior1 = "<<warrior1<<endl;
	cout<<"warrior2 = "<<warrior2<<endl;
	cout<<"expected to return "<<firstDefeated<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==firstDefeated)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test6(){
	string warrior1="A 1000 0 2";
	string warrior2="B 1000 1 1";
	string firstDefeated= "NONE 1000";
	Battle _Battle;
	string ret=_Battle.firstDefeated(warrior1,warrior2);
	cout<<"--------------------test 6--------------------"<<endl;
	cout<<"warrior1 = "<<warrior1<<endl;
	cout<<"warrior2 = "<<warrior2<<endl;
	cout<<"expected to return "<<firstDefeated<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==firstDefeated)
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
	return 0;
}
