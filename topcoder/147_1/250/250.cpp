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


class PeopleCircle{
public:
	string order(int m,int f,int k){
		int i=0,s=0,j,t;
		char mark[200];
		memset(mark,0,sizeof(mark));
		for(i=0;i<f;i++){
			for(j=s,t=0;t<k;j=(j+1)%(m+f))
				if(!mark[j]){
					t++;
//					mark[j]=1;
					if(t==k)break;
				}
			cout<<j<<' ';
			s=(j+1)%(m+f);
			mark[j]=1;
		}
		string ret;
		for(i=0;i<m+f;i++){
			if(mark[i])
				ret+='F';
			else ret+='M';
		}
		return ret;
	}
};




void test0(){
	int numMales=25;
	int numFemales=25;
	int K=1000;
	string order= "MFMFMFMM";
	PeopleCircle _PeopleCircle;
	string ret=_PeopleCircle.order(numMales,numFemales,K);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"numMales = "<<numMales<<endl;
	cout<<"numFemales = "<<numFemales<<endl;
	cout<<"K = "<<K<<endl;
	cout<<"expected to return "<<order<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==order)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int numMales=7;
	int numFemales=3;
	int K=1;
	string order= "FFFMMMMMMM";
	PeopleCircle _PeopleCircle;
	string ret=_PeopleCircle.order(numMales,numFemales,K);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"numMales = "<<numMales<<endl;
	cout<<"numFemales = "<<numFemales<<endl;
	cout<<"K = "<<K<<endl;
	cout<<"expected to return "<<order<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==order)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int numMales=25;
	int numFemales=25;
	int K=1000;
	string order= "MMMMMFFFFFFMFMFMMMFFMFFFFFFFFFMMMMMMMFFMFMMMFMFMMF";
	PeopleCircle _PeopleCircle;
	string ret=_PeopleCircle.order(numMales,numFemales,K);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"numMales = "<<numMales<<endl;
	cout<<"numFemales = "<<numFemales<<endl;
	cout<<"K = "<<K<<endl;
	cout<<"expected to return "<<order<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==order)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int numMales=5;
	int numFemales=5;
	int K=3;
	string order= "MFFMMFFMFM";
	PeopleCircle _PeopleCircle;
	string ret=_PeopleCircle.order(numMales,numFemales,K);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"numMales = "<<numMales<<endl;
	cout<<"numFemales = "<<numFemales<<endl;
	cout<<"K = "<<K<<endl;
	cout<<"expected to return "<<order<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==order)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int numMales=1;
	int numFemales=0;
	int K=245;
	string order= "M";
	PeopleCircle _PeopleCircle;
	string ret=_PeopleCircle.order(numMales,numFemales,K);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"numMales = "<<numMales<<endl;
	cout<<"numFemales = "<<numFemales<<endl;
	cout<<"K = "<<K<<endl;
	cout<<"expected to return "<<order<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==order)
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
	return 0;
}
