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


class Antidote{
public:
	vector<string> safeDrinks(vector<string> r,vector<string> d){
		int i,j;
		int mark[100];
		vector<string> ret;
		string temp;
		for(i=0;i<d.size();i++)
			ret.push_back("DRINK");
		memset(mark,0,sizeof(mark));
		for(i=0;i<d.size();i++)
			if(!mark[i]){
			temp="BAD:";
			temp+=d[i];
			for(j=0;j<r.size();j++)
				if(temp==r[j])break;
			if(j<r.size()){
					mark[i]=1;
					ret[i]="PASS";
					continue;
			}
			if(i!=d.size()-1){
				temp+='+';
				temp+=d[i+1];
				for(j=0;j<r.size();j++)
					if(temp==r[j])break;
				if(j<r.size()){
					mark[i+1]=1;
					ret[i+1]="PASS";
				}
			}
		}
		return ret;
	}
};




void test0(){
	string _rules[]={"BAD:RelakShok+Antimurpas"};
	vector<string> rules(_rules+0,_rules+sizeof(_rules)/sizeof(string));
	string _drinks[]={"RelakShok","Antimurpas"};
	vector<string> drinks(_drinks+0,_drinks+sizeof(_drinks)/sizeof(string));
	string _safeDrinks[]= { "DRINK",  "PASS" };
	vector<string> safeDrinks(_safeDrinks+0,_safeDrinks+sizeof(_safeDrinks)/sizeof(string));
	Antidote _Antidote;
	vector<string> ret=_Antidote.safeDrinks(rules,drinks);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"rules = "<<rules<<endl;
	cout<<"drinks = "<<drinks<<endl;
	cout<<"expected to return "<<safeDrinks<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==safeDrinks)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _rules[]={"BAD:RelakShok+Antimurpas","BAD:RelakShok"};
	vector<string> rules(_rules+0,_rules+sizeof(_rules)/sizeof(string));
	string _drinks[]={"Antimurpas","RelakShok"};
	vector<string> drinks(_drinks+0,_drinks+sizeof(_drinks)/sizeof(string));
	string _safeDrinks[]= { "DRINK",  "PASS" };
	vector<string> safeDrinks(_safeDrinks+0,_safeDrinks+sizeof(_safeDrinks)/sizeof(string));
	Antidote _Antidote;
	vector<string> ret=_Antidote.safeDrinks(rules,drinks);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"rules = "<<rules<<endl;
	cout<<"drinks = "<<drinks<<endl;
	cout<<"expected to return "<<safeDrinks<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==safeDrinks)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _rules[]={"BAD:RelakShok","BAD:Minas"};
	vector<string> rules(_rules+0,_rules+sizeof(_rules)/sizeof(string));
	string _drinks[]={"RelakShok","Minas"};
	vector<string> drinks(_drinks+0,_drinks+sizeof(_drinks)/sizeof(string));
	string _safeDrinks[]= { "PASS",  "PASS" };
	vector<string> safeDrinks(_safeDrinks+0,_safeDrinks+sizeof(_safeDrinks)/sizeof(string));
	Antidote _Antidote;
	vector<string> ret=_Antidote.safeDrinks(rules,drinks);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"rules = "<<rules<<endl;
	cout<<"drinks = "<<drinks<<endl;
	cout<<"expected to return "<<safeDrinks<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==safeDrinks)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string _rules[]={"BAD:Minas+Antimurpas"};
	vector<string> rules(_rules+0,_rules+sizeof(_rules)/sizeof(string));
	string _drinks[]={"Minas","Antimurpas","Antimurpas"};
	vector<string> drinks(_drinks+0,_drinks+sizeof(_drinks)/sizeof(string));
	string _safeDrinks[]= { "DRINK",  "PASS",  "DRINK" };
	vector<string> safeDrinks(_safeDrinks+0,_safeDrinks+sizeof(_safeDrinks)/sizeof(string));
	Antidote _Antidote;
	vector<string> ret=_Antidote.safeDrinks(rules,drinks);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"rules = "<<rules<<endl;
	cout<<"drinks = "<<drinks<<endl;
	cout<<"expected to return "<<safeDrinks<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==safeDrinks)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string _rules[]={"BAD:Bitas"};
	vector<string> rules(_rules+0,_rules+sizeof(_rules)/sizeof(string));
	string _drinks[]={"Antimurpas","RelakShok"};
	vector<string> drinks(_drinks+0,_drinks+sizeof(_drinks)/sizeof(string));
	string _safeDrinks[]= { "DRINK",  "DRINK" };
	vector<string> safeDrinks(_safeDrinks+0,_safeDrinks+sizeof(_safeDrinks)/sizeof(string));
	Antidote _Antidote;
	vector<string> ret=_Antidote.safeDrinks(rules,drinks);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"rules = "<<rules<<endl;
	cout<<"drinks = "<<drinks<<endl;
	cout<<"expected to return "<<safeDrinks<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==safeDrinks)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string _rules[]={"BAD:A+B"};
	vector<string> rules(_rules+0,_rules+sizeof(_rules)/sizeof(string));
	string _drinks[]={"B","A"};
	vector<string> drinks(_drinks+0,_drinks+sizeof(_drinks)/sizeof(string));
	string _safeDrinks[]= { "DRINK",  "DRINK" };
	vector<string> safeDrinks(_safeDrinks+0,_safeDrinks+sizeof(_safeDrinks)/sizeof(string));
	Antidote _Antidote;
	vector<string> ret=_Antidote.safeDrinks(rules,drinks);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"rules = "<<rules<<endl;
	cout<<"drinks = "<<drinks<<endl;
	cout<<"expected to return "<<safeDrinks<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==safeDrinks)
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
