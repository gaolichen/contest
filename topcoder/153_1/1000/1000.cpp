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

struct car{
	int d,p;
	bool operator <(const car & a) const {
		if(d!=a.d)return d<a.d;
		return p<a.p;
	}
};

class GasStations{
public:
	vector<car> vc;
	double tripCost(vector<int> d,vector<int> p,int mpg,int ts,int len){
		int i,j;
		vc.clear();
		car tmp;
		tmp.d=0;tmp.p=1000000;
		vc.push_back(tmp);
		for(i=0;i<d.size();i++){
			tmp.d=d[i];
			tmp.p=p[i];
			vc.push_back(tmp);
		}
		sort(vc.begin(),vc.end());
		for(i=j=0;i<vc.size();i++)
			if(i==0||vc[i].d!=vc[i-1].d)
				vc[j++]=vc[i];
		vc.resize(j);
		double f[100][100];
		cls(f);
	}
};




void test0(){
	int _dist[]={100,100};
	vector<int> dist(_dist+0,_dist+sizeof(_dist)/sizeof(int));
	int _price[]={1000,1500};
	vector<int> price(_price+0,_price+sizeof(_price)/sizeof(int));
	int mpg=20;
	int tankSize=10;
	int tripLength=300;
	double tripCost= 5000.0;
	GasStations _GasStations;
	double ret=_GasStations.tripCost(dist,price,mpg,tankSize,tripLength);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"dist = "<<dist<<endl;
	cout<<"price = "<<price<<endl;
	cout<<"mpg = "<<mpg<<endl;
	cout<<"tankSize = "<<tankSize<<endl;
	cout<<"tripLength = "<<tripLength<<endl;
	cout<<"expected to return "<<tripCost<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==tripCost)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int _dist[]={300,450,525};
	vector<int> dist(_dist+0,_dist+sizeof(_dist)/sizeof(int));
	int _price[]={1659,1529,1439};
	vector<int> price(_price+0,_price+sizeof(_price)/sizeof(int));
	int mpg=20;
	int tankSize=20;
	int tripLength=600;
	double tripCost= 15277.5;
	GasStations _GasStations;
	double ret=_GasStations.tripCost(dist,price,mpg,tankSize,tripLength);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"dist = "<<dist<<endl;
	cout<<"price = "<<price<<endl;
	cout<<"mpg = "<<mpg<<endl;
	cout<<"tankSize = "<<tankSize<<endl;
	cout<<"tripLength = "<<tripLength<<endl;
	cout<<"expected to return "<<tripCost<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==tripCost)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int _dist[]={300,450,525};
	vector<int> dist(_dist+0,_dist+sizeof(_dist)/sizeof(int));
	int _price[]={1659,1439,1529};
	vector<int> price(_price+0,_price+sizeof(_price)/sizeof(int));
	int mpg=20;
	int tankSize=20;
	int tripLength=600;
	double tripCost= 14940.0;
	GasStations _GasStations;
	double ret=_GasStations.tripCost(dist,price,mpg,tankSize,tripLength);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"dist = "<<dist<<endl;
	cout<<"price = "<<price<<endl;
	cout<<"mpg = "<<mpg<<endl;
	cout<<"tankSize = "<<tankSize<<endl;
	cout<<"tripLength = "<<tripLength<<endl;
	cout<<"expected to return "<<tripCost<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==tripCost)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int _dist[]={300,125,450,525};
	vector<int> dist(_dist+0,_dist+sizeof(_dist)/sizeof(int));
	int _price[]={1659,1729,1439,1529};
	vector<int> price(_price+0,_price+sizeof(_price)/sizeof(int));
	int mpg=20;
	int tankSize=20;
	int tripLength=600;
	double tripCost= 14940.0;
	GasStations _GasStations;
	double ret=_GasStations.tripCost(dist,price,mpg,tankSize,tripLength);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"dist = "<<dist<<endl;
	cout<<"price = "<<price<<endl;
	cout<<"mpg = "<<mpg<<endl;
	cout<<"tankSize = "<<tankSize<<endl;
	cout<<"tripLength = "<<tripLength<<endl;
	cout<<"expected to return "<<tripCost<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==tripCost)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int _dist[]={200};
	vector<int> dist(_dist+0,_dist+sizeof(_dist)/sizeof(int));
	int _price[]={1000};
	vector<int> price(_price+0,_price+sizeof(_price)/sizeof(int));
	int mpg=20;
	int tankSize=20;
	int tripLength=400;
	double tripCost= 0.0;
	GasStations _GasStations;
	double ret=_GasStations.tripCost(dist,price,mpg,tankSize,tripLength);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"dist = "<<dist<<endl;
	cout<<"price = "<<price<<endl;
	cout<<"mpg = "<<mpg<<endl;
	cout<<"tankSize = "<<tankSize<<endl;
	cout<<"tripLength = "<<tripLength<<endl;
	cout<<"expected to return "<<tripCost<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==tripCost)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	int _dist[]={100,400};
	vector<int> dist(_dist+0,_dist+sizeof(_dist)/sizeof(int));
	int _price[]={1549,1649};
	vector<int> price(_price+0,_price+sizeof(_price)/sizeof(int));
	int mpg=25;
	int tankSize=16;
	int tripLength=600;
	double tripCost= 12792.0;
	GasStations _GasStations;
	double ret=_GasStations.tripCost(dist,price,mpg,tankSize,tripLength);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"dist = "<<dist<<endl;
	cout<<"price = "<<price<<endl;
	cout<<"mpg = "<<mpg<<endl;
	cout<<"tankSize = "<<tankSize<<endl;
	cout<<"tripLength = "<<tripLength<<endl;
	cout<<"expected to return "<<tripCost<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==tripCost)
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
	return 0;
}
