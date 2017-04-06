//program framework generated with WishingBone's parser :)-

//common header
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <strstream>
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


class DQuads{
public:
	int count(vector<string> f){
		int i,j,k,h;
		int con[100][100];
		memset(con,0,sizeof(con));
		for(i=0;i<f.size();i++){
			istrstream msin(f[i].c_str());
			while(msin>>j)con[i][j]++;
		}
		i64 ret=0;
		for(i=0;i<f.size();i++)
			for(j=0;j<f.size();j++)
				if(j!=i)
				for(k=0;k<f.size();k++)
					if(k!=j&&k!=i&&!con[i][k]&&!con[k][i])
					for(h=0;h<f.size();h++)
						if(h!=i&&h!=j&&h!=k&&!con[j][h]&&!con[h][j])
							ret+=(i64)con[i][j]*con[j][k]*con[k][h]*con[h][i];
		ret/=4;
		return (int)ret;
	}
};




void test0(){
	string _flights[]={"1 1 1 1 1 1 1 1 1 1","2","3","0"};
	vector<string> flights(_flights+0,_flights+sizeof(_flights)/sizeof(string));
	int count= 10;
	DQuads _DQuads;
	int ret=_DQuads.count(flights);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"flights = "<<flights<<endl;
	cout<<"expected to return "<<count<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==count)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _flights[]={"1 1 1 1 1 1 1 1 1 1","2","3","0 1"};
	vector<string> flights(_flights+0,_flights+sizeof(_flights)/sizeof(string));
	int count= 0;
	DQuads _DQuads;
	int ret=_DQuads.count(flights);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"flights = "<<flights<<endl;
	cout<<"expected to return "<<count<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==count)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _flights[]={"","6 0 2","","6 6 4","6 5 5 0","",""};
	vector<string> flights(_flights+0,_flights+sizeof(_flights)/sizeof(string));
	int count= 0;
	DQuads _DQuads;
	int ret=_DQuads.count(flights);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"flights = "<<flights<<endl;
	cout<<"expected to return "<<count<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==count)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string _flights[]={"1", "0 2", "3 1", "0"};
	vector<string> flights(_flights+0,_flights+sizeof(_flights)/sizeof(string));
	int count= 1;
	DQuads _DQuads;
	int ret=_DQuads.count(flights);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"flights = "<<flights<<endl;
	cout<<"expected to return "<<count<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==count)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string _flights[]={"3 4 8 3 7","0","4 0","","1 7 7 0","0 0 2","5 4 8 3 8","5 4 5 5 6",""};
	vector<string> flights(_flights+0,_flights+sizeof(_flights)/sizeof(string));
	int count= 6;
	DQuads _DQuads;
	int ret=_DQuads.count(flights);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"flights = "<<flights<<endl;
	cout<<"expected to return "<<count<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==count)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string _flights[]={"3 3 6","0","5 5 6 3","2 4 1 4","6 3 6 6","3","5 0 2"};
	vector<string> flights(_flights+0,_flights+sizeof(_flights)/sizeof(string));
	int count= 26;
	DQuads _DQuads;
	int ret=_DQuads.count(flights);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"flights = "<<flights<<endl;
	cout<<"expected to return "<<count<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==count)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test6(){
	string _flights[]={"8 1 2 4 8 12 4 5 11 10 6 2","5 3 15 7 15 15 12 0 8 9 2 0 13 9 8 7 4 7 9 11 11", "6 7 11 9 10 1 12 9","6 6 9 7 6 1 14 1 6 7 10 6 15 6 14 16 10 11 13 4 7", "14 15 16 0 13 2 5 16 6","2 7 16 13 16 10 16 0 8 6 0 2 6", "8 8 4 11 3 14 9 14 14 0 5 10 13 3 11 9 5 7","13 15 6 1 3 13 6 6 8 9 6 4 10", "4 0 1 4 12 1 2 0 14 9 6 4 16 10 7 6 9 7 13 14","11 12 4 12", "6 4 4 9 3 1 8 0 14 14 9 14 16 5 8 16 5 12 4 5 1 12", "14 7 14 8 4 16 6 3 13 6 10 7 13 3","15 4","12 14 14 0 8 12 11 4 3 1 12 1", "13 4 4 6 12 0","9 0 2 9 5 10","6 15 6 13 4 5 1 6"};
	vector<string> flights(_flights+0,_flights+sizeof(_flights)/sizeof(string));
	int count= 140;
	DQuads _DQuads;
	int ret=_DQuads.count(flights);
	cout<<"--------------------test 6--------------------"<<endl;
	cout<<"flights = "<<flights<<endl;
	cout<<"expected to return "<<count<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==count)
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
	return 0;
}
