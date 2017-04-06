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

int num[30] = { 0,1,2,3,0,1,2,-1,0,2,2,
		4,5,5,0,1,2,6,2,3,0,1,-1,2,0,2};
class Soundex{
public:
	string encode(string name){
		int i,j,temp[100];
		string ret;
		ret+=name[0];
		if(ret[0]>='a'&&ret[0]<='z')
			ret[0]=ret[0]-'a'+'A';
		if(name.length()==1){
			ret+='0';ret+='0';ret+='0';
			return ret;
		}
		for(i=0;i<name.length();i++)
			if(name[i]>='a'&&name[i]<='z')
				name[i]=name[i]-'a'+'A';
		for(i=0;i<name.length();i++)
			temp[i]=num[name[i]-'A'];
		j=temp[0];
		for(i=1;i<name.length();i++){
			if(temp[i]==j)temp[i]=0;
			else if(temp[i]==0)j=1000;
			else if(temp[i]==-1)temp[i]=0;
			else j=temp[i];
		}
		for(i=1;i<name.length();i++)
			cout<<temp[i]<<' ';
		cout<<endl;
		j=1;
		for(i=1;i<name.length()&&j<4;i++)
			if(temp[i]&&temp[i]!=-1){
			ret+=temp[i]+'0';
			j++;
			}
		if(ret.length()<4){
			i=4-ret.length();
			while(i--)ret+='0';
		}
		return ret;
	}
};




void test0(){
	string name="TopCoder";
	string encode= "T123";
	Soundex _Soundex;
	string ret=_Soundex.encode(name);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"name = "<<name<<endl;
	cout<<"expected to return "<<encode<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==encode)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string name="Jackson";
	string encode= "J250";
	Soundex _Soundex;
	string ret=_Soundex.encode(name);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"name = "<<name<<endl;
	cout<<"expected to return "<<encode<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==encode)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string name="Pfister";
	string encode= "P236";
	Soundex _Soundex;
	string ret=_Soundex.encode(name);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"name = "<<name<<endl;
	cout<<"expected to return "<<encode<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==encode)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string name="ashcroft";
	string encode= "A261";
	Soundex _Soundex;
	string ret=_Soundex.encode(name);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"name = "<<name<<endl;
	cout<<"expected to return "<<encode<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==encode)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string name="Cwhhwqhgjhwaj";
	string encode= "C200";
	Soundex _Soundex;
	string ret=_Soundex.encode(name);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"name = "<<name<<endl;
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
