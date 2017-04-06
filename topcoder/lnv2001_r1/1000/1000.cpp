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

struct Prerequisites{
	int getnum(string s){
		int i;
		for(i=0;i<s.length();i++)
			if(s[i]>='0'&&s[i]<='9')
				break;
		string tmp(&s[i],&s[s.length()]);
		s2in(tmp,in);
		in>>i;
		return i;
	}
	int check(string s1,string s2){
		int i,j;
		i=getnum(s1);
		j=getnum(s2);
		if(i<j)return 1;
		return 0;
	}
	vector <string> orderClasses(vector <string> vs){
		int i,j;
		string tmp;
		VS name;
		char mat[100][100],mark[100];
		name.resize(vs.size());
		for(i=0;i<vs.size();i++){
			s2in(vs[i],in);
			in>>tmp;
			for(j=0;j<tmp.length()-1;j++)
				name[i]+=tmp[j];
//			name[i]-='.';
		}
		cout<<"hehe"<<endl;
		cls(mat);
		for(i=0;i<vs.size();i++){
			s2in(vs[i],in2);
			in2>>tmp;
			while(in2>>tmp){
				for(j=0;j<name.size();j++)
					if(name[j]==tmp)break;
				if(j==name.size()){
					name.clear();
					return name;
				}
				mat[i][j]=1;
			}
		}
		cout<<"kak"<<endl;
		VS ret;
		int tot=0;
		cls(mark);
		int k;
		while(1){
			if(tot==vs.size())break;
			k=-1;
			for(i=0;i<vs.size();i++)if(!mark[i]){
				for(j=0;j<vs.size();j++)
					if(mat[i][j]&&!mark[j])break;
				if(j==vs.size()){
					if(k==-1||check(name[i],name[k]))
						k=i;
				}
			}
			if(k!=-1){
				ret.push_back(name[k]);
				mark[k]=1;
				tot++;
			}
			else break;
		}
		cout<<"wuwu"<<endl;
		if(tot==vs.size())return ret;
		ret.clear();
		return ret;
	}
};
/*
int main(){
	Prerequisites a;
	VS s;
	s.push_back("CSE121: CSE110");
	s.push_back("CSE110:");
	s.push_back("MATH122:");
	cout<<a.orderClasses(s)<<endl;
	return 0;
}*/