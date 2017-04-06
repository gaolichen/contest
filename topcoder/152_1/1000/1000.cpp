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


class Roundabout{
public:
	int clearUpTime(string n,string e,string s,string w){
		int ret=0,i;
		int p[4],cir,port[4];
		VS d;
		d.push_back(n);
		d.push_back(e);
		d.push_back(s);
		d.push_back(w);
		cls(p);
		cls(cir);
		while(1){
//			memcpy(tmp,0,sizeof(tmp));
			for(i=0;i<4;i++)
				tmp[(i+3)%4]=cir[i];
			for(i=0;i<4;i++)
				if(port[i]&&p[(i+1)%4]==0&&cir[(i+1)%4]==0){
					tmp[i]+=prot[i];
					port[i]=0;
				}
			for(i=0;i<4;i++){
				if(p[i]<d[i].size()){
					if(d[i][p[i]]!='-')port[i]++;
					p[i]++;
				}
			}
			for(i=0;i<4;i++)
				if(tmp[i]||prot[i])break;
			if(i==4){
				for(i=0;i<4;i++)
					if(p[i]!=d[i].size())break;
				if(i==4)break;
			}
			ret++;
			copy(cir,cir+4,tmp);
		}
		return ret;
	}
};




void test0(){
	string north="--";
	string east="--";
	string south="WE";
	string west="-S";
	int clearUpTime= 6;
	Roundabout _Roundabout;
	int ret=_Roundabout.clearUpTime(north,east,south,west);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"north = "<<north<<endl;
	cout<<"east = "<<east<<endl;
	cout<<"south = "<<south<<endl;
	cout<<"west = "<<west<<endl;
	cout<<"expected to return "<<clearUpTime<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==clearUpTime)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string north="WWW";
	string east="NNN";
	string south="---";
	string west="---";
	int clearUpTime= 9;
	Roundabout _Roundabout;
	int ret=_Roundabout.clearUpTime(north,east,south,west);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"north = "<<north<<endl;
	cout<<"east = "<<east<<endl;
	cout<<"south = "<<south<<endl;
	cout<<"west = "<<west<<endl;
	cout<<"expected to return "<<clearUpTime<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==clearUpTime)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string north="SSS";
	string east="WW-";
	string south="N";
	string west="S------";
	int clearUpTime= 13;
	Roundabout _Roundabout;
	int ret=_Roundabout.clearUpTime(north,east,south,west);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"north = "<<north<<endl;
	cout<<"east = "<<east<<endl;
	cout<<"south = "<<south<<endl;
	cout<<"west = "<<west<<endl;
	cout<<"expected to return "<<clearUpTime<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==clearUpTime)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string north="SSS-";
	string east="--W---W";
	string south="WE";
	string west="-S";
	int clearUpTime= 14;
	Roundabout _Roundabout;
	int ret=_Roundabout.clearUpTime(north,east,south,west);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"north = "<<north<<endl;
	cout<<"east = "<<east<<endl;
	cout<<"south = "<<south<<endl;
	cout<<"west = "<<west<<endl;
	cout<<"expected to return "<<clearUpTime<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==clearUpTime)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string north="E";
	string east="-N";
	string south="W";
	string west="-S";
	int clearUpTime= 5;
	Roundabout _Roundabout;
	int ret=_Roundabout.clearUpTime(north,east,south,west);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"north = "<<north<<endl;
	cout<<"east = "<<east<<endl;
	cout<<"south = "<<south<<endl;
	cout<<"west = "<<west<<endl;
	cout<<"expected to return "<<clearUpTime<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==clearUpTime)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string north="";
	string east="";
	string south="";
	string west="";
	int clearUpTime= 0;
	Roundabout _Roundabout;
	int ret=_Roundabout.clearUpTime(north,east,south,west);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"north = "<<north<<endl;
	cout<<"east = "<<east<<endl;
	cout<<"south = "<<south<<endl;
	cout<<"west = "<<west<<endl;
	cout<<"expected to return "<<clearUpTime<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==clearUpTime)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test6(){
	string north="ES";
	string east="N";
	string south="E";
	string west="";
	int clearUpTime= 9;
	Roundabout _Roundabout;
	int ret=_Roundabout.clearUpTime(north,east,south,west);
	cout<<"--------------------test 6--------------------"<<endl;
	cout<<"north = "<<north<<endl;
	cout<<"east = "<<east<<endl;
	cout<<"south = "<<south<<endl;
	cout<<"west = "<<west<<endl;
	cout<<"expected to return "<<clearUpTime<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==clearUpTime)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test7(){
	string north="E";
	string east="SN";
	string south="-N";
	string west="S-E";
	int clearUpTime= 12;
	Roundabout _Roundabout;
	int ret=_Roundabout.clearUpTime(north,east,south,west);
	cout<<"--------------------test 7--------------------"<<endl;
	cout<<"north = "<<north<<endl;
	cout<<"east = "<<east<<endl;
	cout<<"south = "<<south<<endl;
	cout<<"west = "<<west<<endl;
	cout<<"expected to return "<<clearUpTime<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==clearUpTime)
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
	return 0;
}
