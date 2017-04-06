//program framework generated with WishingBone's parser :)-

//common header
#ifdef WIN32
#	pragma warning(disable:4786)
#endif
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
#include <sstream>
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
#define s2in(s,in) istringstream in(s)
#define inmat(i,j,m,n) ((i)>=0&&(i)<(m)&&(j)>=0&&(j)<(n))
#define cls(a) memset((a),0,sizeof(a))
#define VI vector<int>
#define V64 vector<i64>
#define VS vector<string>
#define VD vector<double>
int mx[8]={0,1,0,-1,1,1,-1,-1};
int my[8]={1,0,-1,0,1,-1,-1,1};
template <class T>
T gcd(T a,T b){for(T c;b;c=a,a=b,b=c%b);return a;}
template <class T>
T lcm(T a,T b){return a/gcd(a,b)*b;}

template <class T>
void remove(vector<T>&v,const T&e){
	v.resize(remove(v.begin(),v.end(),e)-v.begin());
}
template <class T>
void insert(vector<T>&v,int isnum,const T&e){
	v.resize(v.size()+1);
	for(int i=v.size()-1;i>isnum;v[i--]=v[i-1]);
	v[isnum]=e;
}
void insert(string &s,int isnum,const string&is){
string t=s;s.resize(isnum);s+=is+(t.c_str()+isnum);
}
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


class PaternityTest{
public:
	int check(string a,string b,string c){
		int i;
		int t1,t2,t3;
		t1=t2=t3=0;
		for(i=0;i<a.length();i++){
			if(a[i]==b[i]&&a[i]==c[i])
				t1++;
			else if(a[i]==b[i])t2++;
			else if(c[i]==a[i])t3++;
			else return 0;
		}
		if((t1+t3)*2>=a.length())return 1;
		return 0;
	}
	vector<int> possibleFathers(string c,string m,vector<string> men){
		int i;
		VI ret;
		for(i=0;i<men.size();i++)
			if(check(c,m,men[i]))ret.push_back(i);
		return ret;
	}
};




void test0(){
	string child="ABCD";
	string mother="AXCY";
	string _men[]={ "SBTD", "QRCD" };
	vector<string> men(_men+0,_men+sizeof(_men)/sizeof(string));
	int _possibleFathers[]= { 0 };
	vector<int> possibleFathers(_possibleFathers+0,_possibleFathers+sizeof(_possibleFathers)/sizeof(int));
	PaternityTest _PaternityTest;
	vector<int> ret=_PaternityTest.possibleFathers(child,mother,men);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"child = "<<child<<endl;
	cout<<"mother = "<<mother<<endl;
	cout<<"men = "<<men<<endl;
	cout<<"expected to return "<<possibleFathers<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==possibleFathers)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}


int main(){
	test0();
	return 0;
}
