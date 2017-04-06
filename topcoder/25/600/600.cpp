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

bool cmp(string a,string b){
	return a.size()>b.size();
}

struct ContainedPalindromes{
	int ok(string s){
//		string s(&ss[a],&ss[b+1]);
		int i;
		for(i=0;2*i<s.length();i++)
			if(s[i]!=s[s.length()-1-i]&&abs(s[i]-s[s.length()-1-i])!='a'-'A')return 0;
		return 1;
	}
	int check(VS &v1,VS &v2){
		if(v2.empty())return 1;
		VS vv1,vv2;
		int i;
		vv1=v1;vv2=v2;
		sort(vv1.begin(),vv1.end(),cmp);
		sort(vv2.begin(),vv2.end(),cmp);
		for(i=0;i<vv1.size();i++){
			if(vv1[i].length()>vv2[i].length())return 1;
			if(vv1[i].length()<vv2[i].length())return 0;
		}
		for(i=0;i<v1.size();i++){
			if(v1[i].length()>v2[i].length())return 1;
			if(v1[i].length()<v2[i].length())return 0;
		}
		return 0;
	}
	vector <string> getPalindromes(string s){
		int i,j;
		char mat[100][100];
		cls(mat);
		for(i=0;i<s.length();i++)
			for(j=i;j<s.length();j++)
				if(ok(string(&s[i],&s[j+1]))){
					mat[i][j]=1;
//					cout<<string(&s[i],&s[j+1])<<endl;
				}
		vector< VS > ret;
		ret.resize(s.length()+1);
		ret[0].clear();
		for(i=1;i<=s.length();i++){
			
			for(j=1;j<=i;j++)
				if(mat[j-1][i-1]){
					VS tmp;
					tmp=ret[j-1];
					tmp.push_back(string(&s[j-1],&s[i]));
					if(check(tmp,ret[i]))ret[i]=tmp;
//					cout<<i<<endl;
				}
		}
		return ret[s.length()];
	}
};
/*
bool cmp(string a,string b){
	return a.size()>b.size();
}

struct ContainedPalindromes{
	VS ret;
	VS tret;
	int _max;
	string ss;
	char mat[100][100];
	int check(int tmax,VS t1,VS t2){
		int i;
		if(tmax>_max){
			_max=tmax;
			return 1;
		}
		VS t=t1;
		sort(t1.begin(),t1.end(),cmp);
		for(i=0;i<t1.size();i++){
			if(t1[i].length()>t2[i].length())
				return 1;
			if(t1[i].length()<t2[i].length())
				return 0;
		}
		for(i=0;i<t.size();i++){
			if(t[i].length()>ret[i].length())
				return 1;
			if(t[i].length()<ret[i].length())
				return 0;
		}
		return 0;
	}
	void dfs(int k,int tmax,VS& tmp){
		if(k==ss.length()){
			if(tmax>=_max&&check(tmax,tmp,tret)){
				tret=ret=tmp;
				sort(tret.begin(),tret.end(),cmp);
			}
			return ;
		}
		if(tmax<_max&&ss.length()-k<_max)return ;
		int i;
		for(i=ss.length()-1;i>=k;i--)
			if(mat[k][i]){
//				cout<<'a';
				tmp.push_back(string(&ss[k],&ss[i+1]));
				dfs(i+1,max(i-k+1,tmax),tmp);
				tmp.pop_back();
			}
	}
	int ok(int a,int b){
		string s(&ss[a],&ss[b+1]);
		int i;
		for(i=0;2*i<s.length();i++)
			if(s[i]!=s[s.length()-1-i]&&abs(s[i]-s[s.length()-1-i])!='a'-'A')return 0;
		return 1;
	}
	vector <string> getPalindromes(string s){
		int i,j;
		cls(mat);
		ss=s;
		for(i=0;i<s.length();i++)
			for(j=i;j<s.length();j++)
				if(ok(i,j)){
					mat[i][j]=1;
					cout<<string(&s[i],&s[j+1])<<endl;
				}
		_max=0;
		ret.clear();
		tret.clear();
		VS tmp;
		dfs(0,0,tmp);
		return ret;
	}
};
*/
int main(){
	ContainedPalindromes a;
	VS t;
	t=a.getPalindromes("aAbBcCdDeEfFgGgGhHiIjJkKlLmMnNoOpPQqRrsSRrQQPVaBbA");
	for(int i=0;i<t.size();i++)
		cout<<t[i]<<endl;
	return 0;
}

/*{"aA", "bB", "cC", "dD", "eE", "fF", "gGgG", "hH", "iI", "jJ", "kK", "lL", "mM", "nN", "oO", "p", "PQqRrsSRrQQP", "V", "aBbA"}*/