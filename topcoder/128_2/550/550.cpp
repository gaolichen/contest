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
	for (vector<T>::iterator i=d.begin();i!=d.end();i++)
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


class PermutationCycles{
public:
	int cycles(vector<int> p){
		int i,j,mark[100],ret=0;
		memset(mark,0,sizeof(mark));
		for(i=0;i<p.size();i++)
			if(!mark[i]){
				j=i;
				while(!mark[j]){
					mark[j]=1;
					j=p[j]-1;
				}
				ret++;
			}
		return ret;
	}
};




void test0(){
	int _permutation[]={ 3, 5, 4, 1, 2 };
	vector<int> permutation(_permutation+0,_permutation+sizeof(_permutation)/sizeof(int));
	int cycles= 2;
	PermutationCycles _PermutationCycles;
	int ret=_PermutationCycles.cycles(permutation);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"permutation = "<<permutation<<endl;
	cout<<"expected to return "<<cycles<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==cycles)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int _permutation[]={ 1, 2, 3, 5, 6, 4 };
	vector<int> permutation(_permutation+0,_permutation+sizeof(_permutation)/sizeof(int));
	int cycles= 4;
	PermutationCycles _PermutationCycles;
	int ret=_PermutationCycles.cycles(permutation);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"permutation = "<<permutation<<endl;
	cout<<"expected to return "<<cycles<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==cycles)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int _permutation[]={ 5, 4, 3, 2, 1 };
	vector<int> permutation(_permutation+0,_permutation+sizeof(_permutation)/sizeof(int));
	int cycles= 3;
	PermutationCycles _PermutationCycles;
	int ret=_PermutationCycles.cycles(permutation);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"permutation = "<<permutation<<endl;
	cout<<"expected to return "<<cycles<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==cycles)
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
