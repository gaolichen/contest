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


class Skyscraper{
public:
	double dis(int x1,int y1,int x2,int y2){
		return (sqrt((double)(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
	}
	int wire(int w,int x1,int y1,int x2,int y2){
		double tmp,tmp1;
		if(x1==200){
			x1=0;
			tmp=dis(x1,y1,x2,y2);
		}
		else if(x2==0){
			x2=200;
			tmp=dis(x1,y1,x2,y2);
		}
		else {
			tmp=dis(x1,y1,x2+200,y2);
			tmp1=dis(x1,y1,200,0)+dis(x2,y2,0,0);
			if(tmp1<tmp)tmp=tmp1;
			tmp1=dis(x1-200,-y1,0,w)+dis(x2,y2,w,0);
			if(tmp1<tmp)tmp=tmp1;
			int x3,y3,x4,y4;
			x4=w-x2;y4=w+y2;
			x3=y2;y3=x2;
			x1=x1-200;y1=-y1;
			tmp1=y1*(x1-x3)/(double)(y3-y1)+(double)x1;
			if(tmp1<=0){
				tmp1=dis(x1,y1,x3,y3);
				if(tmp1<tmp)
					tmp=tmp1;
			}
			tmp1=(w-y1)*(x4-x1)/(double)(y4-y1)+(double)x1;
			if(tmp1<=0){
				tmp1=dis(x1,y1,x4,y4);
				if(tmp1<tmp)tmp=tmp1;
			}
		}
		int ret;
		ret=(int)tmp;
		if(tmp-ret>1e-6)ret++;
		return ret;
	}
};




void test0(){
	int w=300;
	int xfront=200;
	int yfront=5;
	int xright=0;
	int yright=5;
	int wire= 0;
	Skyscraper _Skyscraper;
	int ret=_Skyscraper.wire(w,xfront,yfront,xright,yright);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"w = "<<w<<endl;
	cout<<"xfront = "<<xfront<<endl;
	cout<<"yfront = "<<yfront<<endl;
	cout<<"xright = "<<xright<<endl;
	cout<<"yright = "<<yright<<endl;
	cout<<"expected to return "<<wire<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==wire)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int w=300;
	int xfront=103;
	int yfront=50;
	int xright=29;
	int yright=50;
	int wire= 126;
	Skyscraper _Skyscraper;
	int ret=_Skyscraper.wire(w,xfront,yfront,xright,yright);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"w = "<<w<<endl;
	cout<<"xfront = "<<xfront<<endl;
	cout<<"yfront = "<<yfront<<endl;
	cout<<"xright = "<<xright<<endl;
	cout<<"yright = "<<yright<<endl;
	cout<<"expected to return "<<wire<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==wire)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int w=300;
	int xfront=103;
	int yfront=5;
	int xright=29;
	int yright=5;
	int wire= 108;
	Skyscraper _Skyscraper;
	int ret=_Skyscraper.wire(w,xfront,yfront,xright,yright);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"w = "<<w<<endl;
	cout<<"xfront = "<<xfront<<endl;
	cout<<"yfront = "<<yfront<<endl;
	cout<<"xright = "<<xright<<endl;
	cout<<"yright = "<<yright<<endl;
	cout<<"expected to return "<<wire<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==wire)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int w=399;
	int xfront=0;
	int yfront=270;
	int xright=399;
	int yright=17;
	int wire= 628;
	Skyscraper _Skyscraper;
	int ret=_Skyscraper.wire(w,xfront,yfront,xright,yright);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"w = "<<w<<endl;
	cout<<"xfront = "<<xfront<<endl;
	cout<<"yfront = "<<yfront<<endl;
	cout<<"xright = "<<xright<<endl;
	cout<<"yright = "<<yright<<endl;
	cout<<"expected to return "<<wire<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==wire)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

int main(){
	test0();
	test1();
	test2();
	test3();
	return 0;
}
