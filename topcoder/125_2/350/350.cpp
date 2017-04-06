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


class Taxes{
public:
	int calcTaxes(vector<int> b,vector<int> c,int in){
		int i,j,tot[100];
		tot[0]=0;
		for(i=1;i<c.size();i++)
			tot[i]=tot[i-1]+(int)((c[i]-c[i-1])*b[i-1]/100.0);
		i=c.size()-1;
		while(i>=0&&c[i]>=in)i--;
		if(i<0)return 0;
		int ret=0;
		ret+=(int)((in-c[i])*b[i]/100.0);
		if(i>0)ret+=tot[i];
		return ret;
	}
};




void test0(){
	int _brackets[]={15, 22, 28, 40};
	vector<int> brackets(_brackets+0,_brackets+sizeof(_brackets)/sizeof(int));
	int _cutoffs[]={4500, 20000, 55000, 120000};
	vector<int> cutoffs(_cutoffs+0,_cutoffs+sizeof(_cutoffs)/sizeof(int));
	int income=70000;
	int calcTaxes= 14225;
	Taxes _Taxes;
	int ret=_Taxes.calcTaxes(brackets,cutoffs,income);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"brackets = "<<brackets<<endl;
	cout<<"cutoffs = "<<cutoffs<<endl;
	cout<<"income = "<<income<<endl;
	cout<<"expected to return "<<calcTaxes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==calcTaxes)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int _brackets[]={15, 22, 28, 40};
	vector<int> brackets(_brackets+0,_brackets+sizeof(_brackets)/sizeof(int));
	int _cutoffs[]={4500, 20000, 55000, 120000};
	vector<int> cutoffs(_cutoffs+0,_cutoffs+sizeof(_cutoffs)/sizeof(int));
	int income=170000;
	int calcTaxes= 48225;
	Taxes _Taxes;
	int ret=_Taxes.calcTaxes(brackets,cutoffs,income);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"brackets = "<<brackets<<endl;
	cout<<"cutoffs = "<<cutoffs<<endl;
	cout<<"income = "<<income<<endl;
	cout<<"expected to return "<<calcTaxes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==calcTaxes)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int _brackets[]={5};
	vector<int> brackets(_brackets+0,_brackets+sizeof(_brackets)/sizeof(int));
	int _cutoffs[]={0};
	vector<int> cutoffs(_cutoffs+0,_cutoffs+sizeof(_cutoffs)/sizeof(int));
	int income=100000;
	int calcTaxes= 5000;
	Taxes _Taxes;
	int ret=_Taxes.calcTaxes(brackets,cutoffs,income);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"brackets = "<<brackets<<endl;
	cout<<"cutoffs = "<<cutoffs<<endl;
	cout<<"income = "<<income<<endl;
	cout<<"expected to return "<<calcTaxes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==calcTaxes)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int _brackets[]={50};
	vector<int> brackets(_brackets+0,_brackets+sizeof(_brackets)/sizeof(int));
	int _cutoffs[]={0};
	vector<int> cutoffs(_cutoffs+0,_cutoffs+sizeof(_cutoffs)/sizeof(int));
	int income=500;
	int calcTaxes= 250;
	Taxes _Taxes;
	int ret=_Taxes.calcTaxes(brackets,cutoffs,income);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"brackets = "<<brackets<<endl;
	cout<<"cutoffs = "<<cutoffs<<endl;
	cout<<"income = "<<income<<endl;
	cout<<"expected to return "<<calcTaxes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==calcTaxes)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int _brackets[]={15, 22, 28, 40};
	vector<int> brackets(_brackets+0,_brackets+sizeof(_brackets)/sizeof(int));
	int _cutoffs[]={4500, 20000, 55000, 120000};
	vector<int> cutoffs(_cutoffs+0,_cutoffs+sizeof(_cutoffs)/sizeof(int));
	int income=4000;
	int calcTaxes= 0;
	Taxes _Taxes;
	int ret=_Taxes.calcTaxes(brackets,cutoffs,income);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"brackets = "<<brackets<<endl;
	cout<<"cutoffs = "<<cutoffs<<endl;
	cout<<"income = "<<income<<endl;
	cout<<"expected to return "<<calcTaxes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==calcTaxes)
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

