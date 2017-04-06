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
VS name;
V64 win;
	int c[100],b[100];
	char s[100],u[100];

	int cmp(const void*a,const void*b){
		if(win[*(int*)a]!=win[*(int*)b])
			return win[*(int*)a]-win[*(int*)b];
		return name[*(int*)a]>name[*(int*)b];
	}

class Lottery{
public:
	i64 calc2(int m,int n){
		int i;
		i64 ret=1;
		for(i=0;i<n;i++)
			ret*=m-i;
		for(i=0;i<n;i++)
			ret/=(i+1);
		return ret;
	}
	i64 calc(int k){
		i64 ret=1;
		int i,j;
		if(u[k]=='T'){
			fo(i,b[k])
				ret*=c[k]-i;
			if(s[k]=='T')
				fo(i,b[k])
				ret/=i+1;
			return ret;
		}
		else{
			i64 tmp;
			ret=0;
			for(i=1;i<=b[k];i++){
				tmp=1;
				tmp*=calc2(c[k],i);
				tmp*=calc2(b[k]-1,i-1);
				if(s[k]=='F')
					for(j=0;j<b[k];j++)
						tmp*=j+1;
				ret+=tmp;
			}
			return ret;
		}
		return ret;
	}
	string cut(string r,int k){
		char buf[100];
		strcpy(buf,r.c_str());
		buf[k]='\0';
		return buf;
	}
	vector<string> sortByOdds(vector<string> r){
		int i,j,t;
		win.clear();
		name.clear();
		fo(i,r.size()){
			fo(j,r[i].length())
				if(r[i][j]==':')break;
			name.push_back(cut(r[i],j));
			t=j+2;
			sscanf(r[i].c_str()+j+2,"%d %d %c %c",&c[i],&b[i],&s[i],&u[i]);
		}
		fo(i,r.size()){
			win.push_back(calc(i));
		}
		cout<<win<<endl;
		int ri[100];
		for(i=0;i<win.size();i++){
			ri[i]=i;
		}
		qsort(ri,win.size(),sizeof(int),cmp);
		VS ret;
		fo(i,win.size())
			ret.push_back(name[ri[i]]);
		return ret;
	}
};




void test0(){
	string _rules[]={"PICK ANY TWO: 10 2 F F","PICK TWO IN ORDER: 10 2 T F","PICK TWO DIFFERENT: 10 2 F T","PICK TWO LIMITED: 10 2 T T"};
	vector<string> rules(_rules+0,_rules+sizeof(_rules)/sizeof(string));
	string _sortByOdds[]={ "PICK TWO LIMITED", "PICK TWO IN ORDER", "PICK TWO DIFFERENT", "PICK ANY TWO" };
	vector<string> sortByOdds(_sortByOdds+0,_sortByOdds+sizeof(_sortByOdds)/sizeof(string));
	Lottery _Lottery;
	vector<string> ret=_Lottery.sortByOdds(rules);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"rules = "<<rules<<endl;
	cout<<"expected to return "<<sortByOdds<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==sortByOdds)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _rules[]={"INDIGO: 93 8 T F", "ORANGE: 29 8 F T", "VIOLET: 76 6 F F", "BLUE: 100 8 T T", "RED: 99 8 T T", "GREEN: 78 6 F T", "YELLOW: 75 6 F F"};
	vector<string> rules(_rules+0,_rules+sizeof(_rules)/sizeof(string));
	string _sortByOdds[]= { "RED",  "ORANGE",  "YELLOW",  "GREEN",  "BLUE",  "INDIGO",  "VIOLET" };
	vector<string> sortByOdds(_sortByOdds+0,_sortByOdds+sizeof(_sortByOdds)/sizeof(string));
	Lottery _Lottery;
	vector<string> ret=_Lottery.sortByOdds(rules);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"rules = "<<rules<<endl;
	cout<<"expected to return "<<sortByOdds<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==sortByOdds)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	vector<string> rules(0);
	vector<string> sortByOdds(0);
	Lottery _Lottery;
	vector<string> ret=_Lottery.sortByOdds(rules);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"rules = "<<rules<<endl;
	cout<<"expected to return "<<sortByOdds<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==sortByOdds)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

int main(){
	test0();
	test1();
	test2();
	return 0;
}
