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
#include <strstream>
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
#define fo(a,b) for((a)=0;(a)<(b);(a)++)
#define inmat(i,j,m,n) ((i)>=0&&(i)<(m)&&(j)>=0&&(j)<(n))
#define cls(a) memset((a),0,sizeof(a))
#define VI vector<int>
#define V64 vector<i64>
#define VS vector<string>
#define VD vector<double>
int mx[8]={0,1,0,-1,1,1,-1,-1};
int my[8]={1,0,-1,0,1,-1,-1,1};
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


class Masterbrain{
public:
	int check(char *buf,vector<string> g,vector<string> r){
		int i,b,w,j,k,lie=0;
		char mark[10],done[10];
		for(i=0;i<g.size();i++){
			if(lie>1)return 0;
			b=w=0;
			memset(mark,0,sizeof(mark));
			cls(done);
			for(j=0;j<4;j++)
				if(g[i][j]==buf[j]){
					b++;
					mark[j]=done[j]=1;
				}
				if(b!=r[i][0]-'0'){
					lie++;
					continue;
				}
			for(j=0;j<4;j++)
				if(!mark[j])
					for(k=0;k<4;k++)
						if(!done[k]&&buf[j]==g[i][k]){
							w++;
							done[k]=1;
							break;
						}
				if(w!=r[i][3]-'0'){
							lie++;
				}
		}
		return lie==1;
	}
	int possibleSecrets(vector<string> g,vector<string> r){
		int ret=0;
		char buf[10];
		for(buf[0]='1';buf[0]<='7';buf[0]++)
			for(buf[1]='1';buf[1]<='7';buf[1]++)
				for(buf[2]='1';buf[2]<='7';buf[2]++)
					for(buf[3]='1';buf[3]<='7';buf[3]++){
						buf[4]='\0';
						if(check(buf,g,r))ret++;
					}
		return ret;
	}
};
