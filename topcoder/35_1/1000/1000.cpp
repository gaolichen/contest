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

struct Ampersands{
	VS vs;
	int k;
	string ret;
	string calc(string s){
		if(k++>1000)return "***";
//		if(k==77)cout<<s<<' '<<s.length()<<endl;
//		cout<<k<<endl;
//		cout<<s<<endl;
		if(s.length()==0)return "";
		if(s.length()==1){
			if(s=="&")return "";
			if(k==997)cout<<"wuwu"<<endl;
			return s;
		}
		if(s[0]=='&'){
			if(s[1]!=s[0]){
				if(!(s[1]>='0'&&s[1]<='9')){
//					cout<<s<<endl;
					string tmp(&s[2],&s[s.length()]);
					return calc(tmp);
				}
				else{
					string tmp;
					tmp=vs[s[1]-'0']+string(&s[2],&s[s.length()]);
//					cout<<tmp<<endl;
					return calc(tmp);
				}
			}
			else {
				string tmp(&s[1],&s[s.length()]),t1;
//				cout<<s<<"55555"<<endl;
				t1=calc(tmp);
				if(t1=="***")return t1;
				tmp="&";
				tmp+=t1;
				cout<<tmp<<' '<<s<<endl;
				return calc(tmp);
			}
		}
		else {
//			cout<<s<<"1111111111111"<<endl;
			string tmp(&s[1],&s[s.length()]),t1;
			t1+=s[0];
			t1=calc(tmp);
			if(t1=="***")return t1;
//			cout<<s[0]+tmp<<endl;
			t1+=tmp;
			return t1;
		}
	}
	string resolve(string s, vector <string> ss){
		vs.clear();
		vs=ss;
		ret="";
		k=0;
		return calc(s);
	}
};

int main(){
	Ampersands a;
	string s="&&&0";
	VS vs;
	vs.push_back("2&&1");
	vs.push_back("2&&2");
	vs.push_back("3a&&");
//	vs.push_back("AbC&");
	cout<<a.resolve(s,vs)<<endl;
	return 0;
}

/*
["&&&0", {"2&&1", "2&&2", "3a&&"}]
    EXPECTED: "a"
    RECEIVED: "segmentation fault"
*/