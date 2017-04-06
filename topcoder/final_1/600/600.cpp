//program framework generated with WishingBone's parser :)-

//common header
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <strstream>
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
int mm;
int a[10];
int calc(int c,int d){
	i64 i,tmp[10],res[10];
	for(i=0;i<=7;i++){tmp[i]=(i64)a[i];}
	memset(res,0,sizeof(res));
	for(i=7;i>0;i--){
		if(tmp[i]%c)return 0;
		res[i-1]=tmp[i]/c;
		tmp[i-1]-=tmp[i]/c*d;
		tmp[i]=0;
	}
	if(tmp[0])return 0;
	for(i=0;i<=7;i++){
		a[i]=(int)res[i];
		if(a[i])mm=i;
	}
	return 1;
}

class FactorPoly{
public:
	string remove(string p){
		int i,j,k;
		char buf[100];
		string ret;
		memset(a,0,sizeof(a));
		for(i=0;i<p.size();i++)
			if(p[i]=='+'||p[i]=='x'||p[i]=='^')p[i]=' ';
		istrstream myin(p.c_str());
		while(myin>>j>>k)a[k]=j;
		for(i=2;i<=99;i++){
			while(1){
			for(j=0;j<=7;j++)if(a[j]%i)break;
			if(j>7)
				for(j=0;j<=7;j++)a[j]/=i;
			else break;
			}
		}
		for(i=0;i<=7;i++)if(a[i])break;
		for(j=0;j+i<=7;j++)a[j]=a[j+i];
		for(;j<=7;j++)a[j]=0;
		for(i=7;i>=0;i--)if(a[i])break;
		mm=i;
		for(i=1;i<100;i++)
			if(a[mm]%i==0)
				for(j=-99;j<100&&mm;j++)
					if(j&&a[0]%j==0)
						while(calc(i,j));
		if(a[mm]<0)for(i=0;i<=7;i++)a[i]=-a[i];
		for(i=7,j=0;i>=0;i--)
			if(a[i]){
				if(j)ret+='+';
				sprintf(buf,"%dx^%d",a[i],i);
				j=1;
				ret+=buf;
			}
		return ret;
	}
};




void test0(){
	string poly="-98x^7+99x^6+-99x^5+99x^4+-99x^3+99x^0";
	string remove= "98x^7+-99x^6+99x^5+-99x^4+99x^3+-99x^0";
	FactorPoly _FactorPoly;
	string ret=_FactorPoly.remove(poly);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"poly = "<<poly<<endl;
	cout<<"expected to return "<<remove<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==remove)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string poly="2x^3+8x^2+8x^1+6x^0";
	string remove= "1x^2+1x^1+1x^0";
	FactorPoly _FactorPoly;
	string ret=_FactorPoly.remove(poly);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"poly = "<<poly<<endl;
	cout<<"expected to return "<<remove<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==remove)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string poly="2x^4+8x^3+8x^2+6x^1";
	string remove= "1x^2+1x^1+1x^0";
	FactorPoly _FactorPoly;
	string ret=_FactorPoly.remove(poly);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"poly = "<<poly<<endl;
	cout<<"expected to return "<<remove<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==remove)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string poly="1x^3+3x^2+3x^1+1x^0";
	string remove= "1x^0";
	FactorPoly _FactorPoly;
	string ret=_FactorPoly.remove(poly);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"poly = "<<poly<<endl;
	cout<<"expected to return "<<remove<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==remove)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string poly="-2x^4+-6x^3+-6x^2+-2x^1";
	string remove= "1x^0";
	FactorPoly _FactorPoly;
	string ret=_FactorPoly.remove(poly);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"poly = "<<poly<<endl;
	cout<<"expected to return "<<remove<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==remove)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string poly="2x^0+-2x^2";
	string remove= "1x^0";
	FactorPoly _FactorPoly;
	string ret=_FactorPoly.remove(poly);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"poly = "<<poly<<endl;
	cout<<"expected to return "<<remove<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==remove)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test6(){
	string poly="1x^4+-1x^0";
	string remove= "1x^2+1x^0";
	FactorPoly _FactorPoly;
	string ret=_FactorPoly.remove(poly);
	cout<<"--------------------test 6--------------------"<<endl;
	cout<<"poly = "<<poly<<endl;
	cout<<"expected to return "<<remove<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==remove)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test7(){
	string poly="64x^7+1x^1+64x^0";
	string remove= "64x^7+1x^1+64x^0";
	FactorPoly _FactorPoly;
	string ret=_FactorPoly.remove(poly);
	cout<<"--------------------test 7--------------------"<<endl;
	cout<<"poly = "<<poly<<endl;
	cout<<"expected to return "<<remove<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==remove)
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
	return 0;
}
