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


class TupleLine{
public:
	int s;
	int sameline(string a1,string b1,string c1){
		int i;
		vector<int> a,b,c;
		for(i=0;i<a1.length();i++)
			a.push_back(a1[i]-'0');
		for(i=0;i<b1.length();i++)
			b.push_back(b1[i]-'0');
		for(i=0;i<c1.length();i++)
			c.push_back(c1[i]-'0');
		for(i=0;i<a.size();i++)
			if(a[i]!=b[i])break;
		int t1,t2;
		t1=c[i]-a[i];t2=b[i]-a[i];
		for(i=0;i<a.size();i++){
			if((b[i]-a[i])*t1-(c[i]-a[i])*t2)break;
		}
		if(i==a.size())return 1;
		return 0;
	}
	int check(string a1,string b1){
		int i,tmp1,tmp2;
		vector<int> a,b;
		for(i=0;i<a1.length();i++)
			a.push_back(a1[i]-'0');
		for(i=0;i<b1.length();i++)
			b.push_back(b1[i]-'0');
		for(i=0;i<a.size();i++)
			if(a[i]!=b[i])break;
		int j;
		tmp1=a[i];tmp2=b[i];
		for(i=0;i<a.size();i++)if(a[i]!=b[i]){
			if((tmp1*b[i]-tmp2*a[i])%(tmp1-tmp2))break;
			j=(tmp1*b[i]-tmp2*a[i])/(tmp1-tmp2);
			if(j&&abs(j)!=s-1)break;
		}
		if(i<a.size())return 0;
		j=abs(tmp1-tmp2);
		for(i=0;i<a.size();i++)
			if(a[i]!=b[i]&&abs(a[i]-b[i])!=j)break;
		return i==a.size();
	}
	int quickLine(int size,vector<string> ch){
		int i,j,k,cnt;
		vector<string> tmp;
		s=size;
		for(i=0;i<ch.size();i++){
			for(j=i+1;j<ch.size();j++)
				if(ch[i]==ch[j])break;
			if(j==ch.size())
				tmp.push_back(ch[i]);
		}
		int ret=1;
		for(i=0;i<tmp.size();i++)
			for(j=i+1;j<tmp.size();j++)
				if(check(tmp[i],tmp[j])){
				for(k=j+1,cnt=2;k<tmp.size();k++)
					if(sameline(tmp[i],tmp[j],tmp[k]))cnt++;
				if(cnt>ret)ret=cnt;
			}
		return size-ret;
	}
};




void test0(){
	int size=4;
	string _chosen[]={"00","02","21"};
	vector<string> chosen(_chosen+0,_chosen+sizeof(_chosen)/sizeof(string));
	int quickLine= 2;
	TupleLine _TupleLine;
	int ret=_TupleLine.quickLine(size,chosen);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"size = "<<size<<endl;
	cout<<"chosen = "<<chosen<<endl;
	cout<<"expected to return "<<quickLine<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==quickLine)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int size=4;
	string _chosen[]={"00","32","21","32"};
	vector<string> chosen(_chosen+0,_chosen+sizeof(_chosen)/sizeof(string));
	int quickLine= 3;
	TupleLine _TupleLine;
	int ret=_TupleLine.quickLine(size,chosen);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"size = "<<size<<endl;
	cout<<"chosen = "<<chosen<<endl;
	cout<<"expected to return "<<quickLine<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==quickLine)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int size=3;
	string _chosen[]={"0022","0202","0112","0000","0112"};
	vector<string> chosen(_chosen+0,_chosen+sizeof(_chosen)/sizeof(string));
	int quickLine= 0;
	TupleLine _TupleLine;
	int ret=_TupleLine.quickLine(size,chosen);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"size = "<<size<<endl;
	cout<<"chosen = "<<chosen<<endl;
	cout<<"expected to return "<<quickLine<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==quickLine)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int size=9;
	string _chosen[]={"2355846","6355842","3355848"};
	vector<string> chosen(_chosen+0,_chosen+sizeof(_chosen)/sizeof(string));
	int quickLine= 7;
	TupleLine _TupleLine;
	int ret=_TupleLine.quickLine(size,chosen);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"size = "<<size<<endl;
	cout<<"chosen = "<<chosen<<endl;
	cout<<"expected to return "<<quickLine<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==quickLine)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

int main(){
	test0();
	test1();
	test2();
	test3();
	return 0;
}
