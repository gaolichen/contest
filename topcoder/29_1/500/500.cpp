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
string cap="CcDdEFfGgAaB";
struct Music{
	VI change(string tmp){
		s2in(tmp,in);
		string s;
		VI ret;
		int i;
		while(in>>s){
			if(s.length()==2){
				s[0]=s[0]-'A'+'a';
			}
			for(i=0;i<12;i++)
				if(s[0]==cap[i]){
					ret.push_back(i);
					break;
				}
		}
		return ret;
	}
	int same(string s1,string s2){
		string tmp1,tmp2;
		VI v1,v2;
		tmp1=s1;
		int i,j;
		for(i=0;i<tmp1.size();i++)
			if(tmp1[i]=='|')tmp1[i]=' ';
		tmp2=s2;
		for(i=0;i<tmp2.size();i++)
			if(tmp2[i]=='|')tmp2[i]=' ';
		v1=change(tmp1);
		v2=change(tmp2);
		if(v1.size()>v2.size()){
			swap(v1,v2);
		}
		if(v2.size()!=v1.size())return 0;
		for(i=0;i<=12;i++){
			for(j=0;j<v1.size();j++)
				v1[j]=(v1[j]+1)%12;
			for(j=0;j<v2.size();j++)
				if(v2[j]!=v1[j%v1.size()])break;
			if(j==v2.size())return 1;
		}
		return 0;
	}
	int nameThatTune(vector <string> vs, string tu){
		int i,ret=0;
		for(i=0;i<vs.size();i++)
			if(same(vs[i],tu))ret++;
		return ret;
	}
};