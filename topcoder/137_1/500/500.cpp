
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


class ViscoverExpress{
public:
	int calc(string a){
		int i,j;
		int tmp[20];
		j=0;
		for(i=0;i<a.length()-1;i+=2){
			tmp[j++]=(a[i]-'0')*2;
		}
		int t=0;
		for(i=0;i<j;i++){
			if(tmp[i]<10)t+=tmp[i];
			else t+=tmp[i]%10+tmp[i]/10;
		}
		for(i=1;i<a.length()-1;i+=2){
			t+=a[i]-'0';
		}
		return (10-t%10)%10;
	}
	vector<string> possibleMatches(string num){
		int i,j,k;
		char ch;
		string tmp;
		vector<string> ret;
		for(i=0;i<num.length();i++){
			tmp=num;
//			cout<<tmp<<endl;
			for(j=0;j<10;j++){
				tmp[i]=j+'0';
			if(calc(tmp)==tmp[tmp.length()-1]-'0'&&
				tmp[0]=='3'&&tmp[1]=='0'&&tmp[2]=='1'&&tmp[3]=='4'){
				for(k=0;k<ret.size();k++)
					if(ret[k]==tmp)break;
				if(k==ret.size())ret.push_back(tmp);
			}
			}
		}
		for(i=0;i<num.length()-1;i++){
			tmp=num;
//			cout<<tmp<<endl;
			ch=tmp[i];
			tmp[i]=tmp[i+1];
			tmp[i+1]=ch;
			if(calc(tmp)==tmp[tmp.length()-1]-'0'&&
				tmp[0]=='3'&&tmp[1]=='0'&&tmp[2]=='1'&&tmp[3]=='4'){
				for(j=0;j<ret.size();j++)
					if(ret[j]==tmp)break;
				if(j==ret.size())ret.push_back(tmp);
			}
		}
		sort(ret.begin(),ret.end());
		return ret;
	}
};




void test0(){
	string number="3041123456789013";
	string _possibleMatches[]= { "3014123456789013" };
	vector<string> possibleMatches(_possibleMatches+0,_possibleMatches+sizeof(_possibleMatches)/sizeof(string));
	ViscoverExpress _ViscoverExpress;
	vector<string> ret=_ViscoverExpress.possibleMatches(number);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"number = "<<number<<endl;
	cout<<"expected to return "<<possibleMatches<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==possibleMatches)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string number="3014000000000008";
	string _possibleMatches[]= { "3014000000000008" };
	vector<string> possibleMatches(_possibleMatches+0,_possibleMatches+sizeof(_possibleMatches)/sizeof(string));
	ViscoverExpress _ViscoverExpress;
	vector<string> ret=_ViscoverExpress.possibleMatches(number);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"number = "<<number<<endl;
	cout<<"expected to return "<<possibleMatches<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==possibleMatches)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string number="3014123456789013";
	string _possibleMatches[]= { "3014123456780913",  "3014123456789013" };
	vector<string> possibleMatches(_possibleMatches+0,_possibleMatches+sizeof(_possibleMatches)/sizeof(string));
	ViscoverExpress _ViscoverExpress;
	vector<string> ret=_ViscoverExpress.possibleMatches(number);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"number = "<<number<<endl;
	cout<<"expected to return "<<possibleMatches<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==possibleMatches)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string number="2014123456789012";
	vector<string> possibleMatches(0);
	ViscoverExpress _ViscoverExpress;
	vector<string> ret=_ViscoverExpress.possibleMatches(number);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"number = "<<number<<endl;
	cout<<"expected to return "<<possibleMatches<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==possibleMatches)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string number="3014123451234555";
	string _possibleMatches[]={ "3014121451234555", "3014123051234555", "3014123451034555", "3014123451232555", "3014123451234155", "3014123451234551", "3014123451234585", "3014123451294555", "3014123457234555", "3014123481234555", "3014183451234555", "3014423451234555" };
	vector<string> possibleMatches(_possibleMatches+0,_possibleMatches+sizeof(_possibleMatches)/sizeof(string));
	ViscoverExpress _ViscoverExpress;
	vector<string> ret=_ViscoverExpress.possibleMatches(number);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"number = "<<number<<endl;
	cout<<"expected to return "<<possibleMatches<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==possibleMatches)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string number="3014757575757575";
	string _possibleMatches[]={ "3014577575757575", "3014657575757575", "3014737575757575", "3014755775757575", "3014756575757575", "3014757375757575", "3014757557757575", "3014757565757575", "3014757573757575", "3014757575577575", "3014757575657575", "3014757575737575", "3014757575755775", "3014757575756575", "3014757575757375", "3014757575757557", "3014757575757565", "3014757575757573", "3014757575757755", "3014757575775575", "3014757577557575", "3014757755757575", "3014775575757575" };
	vector<string> possibleMatches(_possibleMatches+0,_possibleMatches+sizeof(_possibleMatches)/sizeof(string));
	ViscoverExpress _ViscoverExpress;
	vector<string> ret=_ViscoverExpress.possibleMatches(number);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"number = "<<number<<endl;
	cout<<"expected to return "<<possibleMatches<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==possibleMatches)
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
