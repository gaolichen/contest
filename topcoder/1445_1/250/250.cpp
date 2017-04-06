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


class Bonuses{
public:
	vector<int> getDivision(vector<int> po){
		int i,tot=0;
		VI ret;
		for(i=0;i<po.size();i++)
			tot+=po[i];
		int j=0;
		for(i=0;i<po.size();i++){
			ret.push_back(po[i]*100/tot);
			j+=po[i]*100/tot;
		}
		
		tot=100-j;
		cout<<tot<<endl;//return ret;
		char mark[1000];
		int max;
		memset(mark,0,sizeof(mark));
		for(i=0;i<tot;i++){
			max=-1;
			for(j=0;j<po.size();j++)
				if(!mark[j]&&(max==-1||po[j]>po[max]))
					max=j;
			ret[max]++;
			mark[max]=1;
		}
		return ret;
	}
};




void test0(){
	int _points[]={1,2,3,4,5};
	vector<int> points(_points+0,_points+sizeof(_points)/sizeof(int));
	int _getDivision[]= { 6,  13,  20,  27,  34 };
	vector<int> getDivision(_getDivision+0,_getDivision+sizeof(_getDivision)/sizeof(int));
	Bonuses _Bonuses;
	vector<int> ret=_Bonuses.getDivision(points);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"points = "<<points<<endl;
	cout<<"expected to return "<<getDivision<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getDivision)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int _points[]={5,5,5,5,5,5};
	vector<int> points(_points+0,_points+sizeof(_points)/sizeof(int));
	int _getDivision[]= { 17,  17,  17,  17,  16,  16 };
	vector<int> getDivision(_getDivision+0,_getDivision+sizeof(_getDivision)/sizeof(int));
	Bonuses _Bonuses;
	vector<int> ret=_Bonuses.getDivision(points);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"points = "<<points<<endl;
	cout<<"expected to return "<<getDivision<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getDivision)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int _points[]={485, 324, 263, 143, 470, 292, 304, 188, 100, 254, 296, 255, 360, 231, 311, 275,  93, 463, 115, 366, 197, 470};
	vector<int> points(_points+0,_points+sizeof(_points)/sizeof(int));
	int _getDivision[]={ 8,  6,  4,  2,  8,  5,  5,  3,  1,  4,  5,  4,  6,  3,  5,  4,  1,  8,  1,  6,  3,  8 };
	vector<int> getDivision(_getDivision+0,_getDivision+sizeof(_getDivision)/sizeof(int));
	Bonuses _Bonuses;
	vector<int> ret=_Bonuses.getDivision(points);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"points = "<<points<<endl;
	cout<<"expected to return "<<getDivision<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getDivision)
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
