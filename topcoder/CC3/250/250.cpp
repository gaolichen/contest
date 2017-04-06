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


class Pareto{
public:
	int optima(vector<string> p){
		int i,j,t,cnt,k,flag;
		int a[60][50];
		string tmp;
		for(i=0;i<p.size();i++){
			for(j=0,cnt=t=0;j<=(p[i].length());j++)
				if(p[i][j]==' '||p[i][j]=='\0'){
					tmp="";
					for(k=t;k<j;k++)
						tmp+=p[i][k];
					t=j+1;
					if(tmp=="awful")a[i][cnt++]=0;
					if(tmp=="bad")a[i][cnt++]=1;
					if(tmp=="fair")a[i][cnt++]=2;
					if(tmp=="fairly-happy")a[i][cnt++]=3;
					if(tmp=="happy")a[i][cnt++]=4;
					if(tmp=="ecstatic")a[i][cnt++]=5;
			}
		}
		int ret=0;
		for(i=0;i<p.size();i++){
			for(j=0;j<p.size();j++){
				for(k=flag=0;k<cnt;k++){
					if(a[i][k]>a[j][k])break;
					if(a[i][k]<a[j][k])flag=1;
				}
				if(flag&&k==cnt)break;
			}
			if(j<p.size())ret++;
		}
		return p.size()-ret;
	}
};




void test0(){
	string _policy[]={"bad bad fairly-happy awful","bad bad bad awful","ecstatic awful ecstatic ecstatic"};
	vector<string> policy(_policy+0,_policy+sizeof(_policy)/sizeof(string));
	int optima= 2;
	Pareto _Pareto;
	int ret=_Pareto.optima(policy);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"policy = "<<policy<<endl;
	cout<<"expected to return "<<optima<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==optima)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _policy[]={"bad ecstatic","bad bad", "awful ecstatic", "fair happy", "fairly-happy fair","fairly-happy fairly-happy", "fair happy"};
	vector<string> policy(_policy+0,_policy+sizeof(_policy)/sizeof(string));
	int optima= 4;
	Pareto _Pareto;
	int ret=_Pareto.optima(policy);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"policy = "<<policy<<endl;
	cout<<"expected to return "<<optima<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==optima)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _policy[]={"happy","bad","fairly-happy","bad","happy"};
	vector<string> policy(_policy+0,_policy+sizeof(_policy)/sizeof(string));
	int optima= 2;
	Pareto _Pareto;
	int ret=_Pareto.optima(policy);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"policy = "<<policy<<endl;
	cout<<"expected to return "<<optima<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==optima)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string _policy[]={"bad bad bad bad bad happy fairly-happy"};
	vector<string> policy(_policy+0,_policy+sizeof(_policy)/sizeof(string));
	int optima= 1;
	Pareto _Pareto;
	int ret=_Pareto.optima(policy);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"policy = "<<policy<<endl;
	cout<<"expected to return "<<optima<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==optima)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string _policy[]={"fair fair fair fair fair fair fair fair","bad fair fair fair fair fair fair fair","fairly-happy fair fair fair fair fair fair fair","happy bad bad bad bad bad bad bad","bad happy happy happy happy happy happy happy"};
	vector<string> policy(_policy+0,_policy+sizeof(_policy)/sizeof(string));
	int optima= 3;
	Pareto _Pareto;
	int ret=_Pareto.optima(policy);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"policy = "<<policy<<endl;
	cout<<"expected to return "<<optima<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==optima)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string _policy[]={ "happy bad awful ecstatic fair bad fair awful", "fair awful bad awful ecstatic awful bad awful", "awful awful happy awful ecstatic awful bad fair", "bad bad bad happy happy ecstatic awful ecstatic", "bad bad awful awful fairly-happy fair fair happy", "fair bad bad fair happy bad ecstatic fair"};
	vector<string> policy(_policy+0,_policy+sizeof(_policy)/sizeof(string));
	int optima= 6;
	Pareto _Pareto;
	int ret=_Pareto.optima(policy);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"policy = "<<policy<<endl;
	cout<<"expected to return "<<optima<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==optima)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test6(){
	string _policy[]={ "fair happy fair fairly-happy happy happy happy", "happy fair fairly-happy fair fair fair happy", "happy happy fair fair fairly-happy fair happy", "happy fair fair fairly-happy happy happy happy", "happy fair happy fairly-happy happy happy happy", "fair fair happy fair fair fair fairly-happy"};
	vector<string> policy(_policy+0,_policy+sizeof(_policy)/sizeof(string));
	int optima= 3;
	Pareto _Pareto;
	int ret=_Pareto.optima(policy);
	cout<<"--------------------test 6--------------------"<<endl;
	cout<<"policy = "<<policy<<endl;
	cout<<"expected to return "<<optima<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==optima)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test7(){
	string _policy[]={ "ecstatic bad fair fair fair ecstatic ecstatic", "ecstatic happy ecstatic awful awful fair awful", "happy fairly-happy bad happy fair fair ecstatic", "awful happy fair fairly-happy fair fair bad", "awful fairly-happy fair bad happy happy happy", "happy happy bad fair happy ecstatic fairly-happy", "fair happy ecstatic bad fairly-happy fair fair", "fairly-happy bad awful bad awful bad ecstatic", "fairly-happy awful bad fair ecstatic bad awful", "fairly-happy bad bad bad awful awful fair", "awful bad bad ecstatic ecstatic fair bad", "fair bad bad fair ecstatic fair ecstatic", "bad awful happy happy fairly-happy happy happy", "ecstatic fair fair awful happy fair happy", "fairly-happy fair awful awful happy awful fair", "bad fair fair fairly-happy bad happy happy", "bad bad fair ecstatic fairly-happy ecstatic bad", "bad fair happy fair awful fair ecstatic", "awful bad bad awful bad awful fairly-happy", "fair fair ecstatic bad bad happy awful", "awful bad ecstatic awful fair fairly-happy happy", "happy bad fair awful awful ecstatic bad", "happy bad bad ecstatic fair fair bad", "bad fairly-happy bad awful fair happy ecstatic", "awful awful happy bad happy ecstatic bad", "awful fair awful awful ecstatic fair fair", "bad fairly-happy awful happy awful bad ecstatic", "ecstatic happy happy fair fairly-happy fair bad", "happy awful happy bad bad fairly-happy fair", "ecstatic fair awful awful awful bad fairly-happy", "fair fair bad fairly-happy awful fair fair", "fair fairly-happy bad happy happy awful fair", "happy ecstatic awful fair fair awful ecstatic", "ecstatic awful fair ecstatic ecstatic happy bad", "awful bad fair ecstatic happy awful fair", "ecstatic happy fair happy happy bad ecstatic", "bad awful awful awful happy ecstatic bad", "ecstatic fair fair bad awful ecstatic bad", "bad happy bad ecstatic bad awful happy", "fairly-happy bad ecstatic awful fair fair awful", "fairly-happy fair awful awful ecstatic bad fair", "fairly-happy bad happy bad fair happy happy", 
		"happy ecstatic fair fairly-happy fair bad bad", 
"bad bad fairly-happy happy bad bad bad", "happy happy fair fair bad fair awful", "awful fair bad bad happy fair fair", "fair ecstatic happy happy awful fair bad", "awful fairly-happy happy fair happy awful bad", "awful fair bad happy happy ecstatic ecstatic", "bad bad fair ecstatic happy ecstatic ecstatic"};
	vector<string> policy(_policy+0,_policy+sizeof(_policy)/sizeof(string));
	int optima= 35;
	Pareto _Pareto;
	int ret=_Pareto.optima(policy);
	cout<<"--------------------test 7--------------------"<<endl;
	cout<<"policy = "<<policy<<endl;
	cout<<"expected to return "<<optima<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==optima)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test8(){
	string _policy[]={"fair happy fairly-happy", "fair happy fair", "awful ecstatic fair", "awful ecstatic fair", "fair happy fair", "fair happy fair"};
	vector<string> policy(_policy+0,_policy+sizeof(_policy)/sizeof(string));
	int optima= 3;
	Pareto _Pareto;
	int ret=_Pareto.optima(policy);
	cout<<"--------------------test 8--------------------"<<endl;
	cout<<"policy = "<<policy<<endl;
	cout<<"expected to return "<<optima<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==optima)
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
	test8();
	return 0;
}
