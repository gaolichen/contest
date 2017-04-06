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


class PackingObjects{
public:
	int smallestBox(int ow,int ol,vector<int> bw,vector<int> bl){
		int i,ret=-1,best=0;
		for(i=0;i<bw.size();i++)
			if(bw[i]>=ow&&bl[i]>=ol||bw[i]>=ol&&bl[i]>=ow){
				if(ret==-1||bw[i]*bl[i]<best){
					ret=i;
					best=bw[i]*bl[i];
				}
			}
		if(ret!=-1)
		return best;
		return -1;
	}
};




void test0(){
	int objWidth=7;
	int objLength=3;
	int _boxWidth[]={3};
	vector<int> boxWidth(_boxWidth+0,_boxWidth+sizeof(_boxWidth)/sizeof(int));
	int _boxLength[]={7};
	vector<int> boxLength(_boxLength+0,_boxLength+sizeof(_boxLength)/sizeof(int));
	int smallestBox= 21;
	PackingObjects _PackingObjects;
	int ret=_PackingObjects.smallestBox(objWidth,objLength,boxWidth,boxLength);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"objWidth = "<<objWidth<<endl;
	cout<<"objLength = "<<objLength<<endl;
	cout<<"boxWidth = "<<boxWidth<<endl;
	cout<<"boxLength = "<<boxLength<<endl;
	cout<<"expected to return "<<smallestBox<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==smallestBox)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int objWidth=5;
	int objLength=8;
	int _boxWidth[]={6,9,3};
	vector<int> boxWidth(_boxWidth+0,_boxWidth+sizeof(_boxWidth)/sizeof(int));
	int _boxLength[]={7,4,5};
	vector<int> boxLength(_boxLength+0,_boxLength+sizeof(_boxLength)/sizeof(int));
	int smallestBox= -1;
	PackingObjects _PackingObjects;
	int ret=_PackingObjects.smallestBox(objWidth,objLength,boxWidth,boxLength);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"objWidth = "<<objWidth<<endl;
	cout<<"objLength = "<<objLength<<endl;
	cout<<"boxWidth = "<<boxWidth<<endl;
	cout<<"boxLength = "<<boxLength<<endl;
	cout<<"expected to return "<<smallestBox<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==smallestBox)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int objWidth=17;
	int objLength=5;
	int _boxWidth[]={19,10,12,40};
	vector<int> boxWidth(_boxWidth+0,_boxWidth+sizeof(_boxWidth)/sizeof(int));
	int _boxLength[]={12,20,15,5};
	vector<int> boxLength(_boxLength+0,_boxLength+sizeof(_boxLength)/sizeof(int));
	int smallestBox= 200;
	PackingObjects _PackingObjects;
	int ret=_PackingObjects.smallestBox(objWidth,objLength,boxWidth,boxLength);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"objWidth = "<<objWidth<<endl;
	cout<<"objLength = "<<objLength<<endl;
	cout<<"boxWidth = "<<boxWidth<<endl;
	cout<<"boxLength = "<<boxLength<<endl;
	cout<<"expected to return "<<smallestBox<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==smallestBox)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int objWidth=20;
	int objLength=44;
	int _boxWidth[]={36,42,18,37,33,5,30,10,29,9,11,16,48,50,34,44,33,12,31,41};
	vector<int> boxWidth(_boxWidth+0,_boxWidth+sizeof(_boxWidth)/sizeof(int));
	int _boxLength[]={42,45,46,24,23,21,21,8,26,25,48,12,10,45,18,6,12,22,42,45};
	vector<int> boxLength(_boxLength+0,_boxLength+sizeof(_boxLength)/sizeof(int));
	int smallestBox= 1845;
	PackingObjects _PackingObjects;
	int ret=_PackingObjects.smallestBox(objWidth,objLength,boxWidth,boxLength);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"objWidth = "<<objWidth<<endl;
	cout<<"objLength = "<<objLength<<endl;
	cout<<"boxWidth = "<<boxWidth<<endl;
	cout<<"boxLength = "<<boxLength<<endl;
	cout<<"expected to return "<<smallestBox<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==smallestBox)
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
