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
	class point{
	public:
		int x,y;
	};
	int cmp(const void *c,const void*d){
		return ((point*)c)->x-((point*)d)->x;
	}

class PointSeq{
public:
	vector<int> a;
	int check(int x1,int y1,int x2,int y2,int x3,int y3){
		return (i64)((x1-x2))*(y3-y2)-(i64)((x3-x2))*(y1-y2)>0;
	}
	string num(int k){
		char buf[100];
		string ret;
		sprintf(buf,"%d",k);
		ret=buf;
		return ret;
	}
	
	vector<string> makeSeq(vector<int> xs,vector<int> ys){
		int i,j;
		vector<string> ret;
		vector<int> tx,ty;
		point p[100];
		string tmp;
		for(i=0;i<xs.size();i++){
			p[i].x=xs[i];
			p[i].y=ys[i];
		}
		qsort(p,xs.size(),sizeof(point),cmp);
		for(i=0;i<xs.size();i++){
			tx.push_back(p[i].x);
			ty.push_back(p[i].y);
			while(tx.size()>=3){
				j=tx.size();
				if(!check(tx[j-3],ty[j-3],tx[j-2],ty[j-2],tx[j-1],ty[j-1])){
					j=tx[tx.size()-1];
					tx.pop_back();
					tx.pop_back();
					tx.push_back(j);
					j=ty[ty.size()-1];
					ty.pop_back();
					ty.pop_back();
					ty.push_back(j);
				}
				else break;
			}
		}
		for(i=0;i<tx.size();i++){
			tmp=num(tx[i]);
			tmp+=',';
			tmp+=num(ty[i]);
			ret.push_back(tmp);
		}
		return ret;
	}
};




void test0(){
	int _xs[]={5,10,15,20};
	vector<int> xs(_xs+0,_xs+sizeof(_xs)/sizeof(int));
	int _ys[]={5,5,5,4};
	vector<int> ys(_ys+0,_ys+sizeof(_ys)/sizeof(int));
	string _makeSeq[]= { "5,5",  "15,5",  "20,4" };
	vector<string> makeSeq(_makeSeq+0,_makeSeq+sizeof(_makeSeq)/sizeof(string));
	PointSeq _PointSeq;
	vector<string> ret=_PointSeq.makeSeq(xs,ys);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"xs = "<<xs<<endl;
	cout<<"ys = "<<ys<<endl;
	cout<<"expected to return "<<makeSeq<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==makeSeq)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int _xs[]={0,5,10};
	vector<int> xs(_xs+0,_xs+sizeof(_xs)/sizeof(int));
	int _ys[]={0,5,0};
	vector<int> ys(_ys+0,_ys+sizeof(_ys)/sizeof(int));
	string _makeSeq[]= { "0,0",  "5,5",  "10,0" };
	vector<string> makeSeq(_makeSeq+0,_makeSeq+sizeof(_makeSeq)/sizeof(string));
	PointSeq _PointSeq;
	vector<string> ret=_PointSeq.makeSeq(xs,ys);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"xs = "<<xs<<endl;
	cout<<"ys = "<<ys<<endl;
	cout<<"expected to return "<<makeSeq<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==makeSeq)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int _xs[]={10,9,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
	vector<int> xs(_xs+0,_xs+sizeof(_xs)/sizeof(int));
	int _ys[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	vector<int> ys(_ys+0,_ys+sizeof(_ys)/sizeof(int));
	string _makeSeq[]= { "-10,0",  "10,0" };
	vector<string> makeSeq(_makeSeq+0,_makeSeq+sizeof(_makeSeq)/sizeof(string));
	PointSeq _PointSeq;
	vector<string> ret=_PointSeq.makeSeq(xs,ys);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"xs = "<<xs<<endl;
	cout<<"ys = "<<ys<<endl;
	cout<<"expected to return "<<makeSeq<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==makeSeq)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int _xs[]={-3058,-6953,-2111,6350,-9345,-115,-8288,5120,-7013,-4452,-8991,439, -187,-6636,6493,-7694,-1258,206,-7785,4823,-7788,5081,-986,-2641,9029, -302,-4969,-5534,7866,-9222,9318,6776,1239,8878,-444,187,-6530,3485, 9896,-4433,-8842,-840,9937,6264,9671,-7525,-9138,5682,4175,-5459};
	vector<int> xs(_xs+0,_xs+sizeof(_xs)/sizeof(int));
	int _ys[]={-4131,-9232,-1401,1942,-4900,2067,5353,7408,-22,9789,358,-7986,7409, -6401,-733,-4263,1243,1538,7568,-2141,3793,-1614,1125,4171,9563,-2577,5378,7136,-9683,-9024,-5180,6913,5638,137,-587,6127,-1898,9055,9568,-3729,-2772,-5821,-3659,-1359,1330,3851,8480,7688,-8584,8641};
	vector<int> ys(_ys+0,_ys+sizeof(_ys)/sizeof(int));
	string _makeSeq[]= { "-9345,-4900",  "-9138,8480",  "-4452,9789",  "9896,9568",  "9937,-3659" };
	vector<string> makeSeq(_makeSeq+0,_makeSeq+sizeof(_makeSeq)/sizeof(string));
	PointSeq _PointSeq;
	vector<string> ret=_PointSeq.makeSeq(xs,ys);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"xs = "<<xs<<endl;
	cout<<"ys = "<<ys<<endl;
	cout<<"expected to return "<<makeSeq<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==makeSeq)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int _xs[]={-100000,99999,100000};
	vector<int> xs(_xs+0,_xs+sizeof(_xs)/sizeof(int));
	int _ys[]={0,20000,19999};
	vector<int> ys(_ys+0,_ys+sizeof(_ys)/sizeof(int));
	string _makeSeq[]= { "-100000,0",  "99999,20000",  "100000,19999" };
	vector<string> makeSeq(_makeSeq+0,_makeSeq+sizeof(_makeSeq)/sizeof(string));
	PointSeq _PointSeq;
	vector<string> ret=_PointSeq.makeSeq(xs,ys);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"xs = "<<xs<<endl;
	cout<<"ys = "<<ys<<endl;
	cout<<"expected to return "<<makeSeq<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==makeSeq)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	int _xs[]={15,5,0};
	vector<int> xs(_xs+0,_xs+sizeof(_xs)/sizeof(int));
	int _ys[]={0,0,5};
	vector<int> ys(_ys+0,_ys+sizeof(_ys)/sizeof(int));
	string _makeSeq[]= { "0,5",  "15,0" };
	vector<string> makeSeq(_makeSeq+0,_makeSeq+sizeof(_makeSeq)/sizeof(string));
	PointSeq _PointSeq;
	vector<string> ret=_PointSeq.makeSeq(xs,ys);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"xs = "<<xs<<endl;
	cout<<"ys = "<<ys<<endl;
	cout<<"expected to return "<<makeSeq<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==makeSeq)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test6(){
	int _xs[]={-7168, 13471, 30562};
	vector<int> xs(_xs+0,_xs+sizeof(_xs)/sizeof(int));
	int _ys[]={-9537, 89464, 37788};
	vector<int> ys(_ys+0,_ys+sizeof(_ys)/sizeof(int));
	string _makeSeq[]= { "-7168,-9537",  "13471,89464",  "30562,37788" };
	vector<string> makeSeq(_makeSeq+0,_makeSeq+sizeof(_makeSeq)/sizeof(string));
	PointSeq _PointSeq;
	vector<string> ret=_PointSeq.makeSeq(xs,ys);
	cout<<"--------------------test 6--------------------"<<endl;
	cout<<"xs = "<<xs<<endl;
	cout<<"ys = "<<ys<<endl;
	cout<<"expected to return "<<makeSeq<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==makeSeq)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test7(){
	int _xs[]={0,5,10};
	vector<int> xs(_xs+0,_xs+sizeof(_xs)/sizeof(int));
	int _ys[]={0,5,10};
	vector<int> ys(_ys+0,_ys+sizeof(_ys)/sizeof(int));
	string _makeSeq[]= { "0,0",  "10,10" };
	vector<string> makeSeq(_makeSeq+0,_makeSeq+sizeof(_makeSeq)/sizeof(string));
	PointSeq _PointSeq;
	vector<string> ret=_PointSeq.makeSeq(xs,ys);
	cout<<"--------------------test 7--------------------"<<endl;
	cout<<"xs = "<<xs<<endl;
	cout<<"ys = "<<ys<<endl;
	cout<<"expected to return "<<makeSeq<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==makeSeq)
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
