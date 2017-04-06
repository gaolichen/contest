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


class ObjectCounter{
public:
	int getCount(vector<int> kn,int target){
		int i,j,k,h;
		for(i=0;i<26;i++)
			for(j=0;j<26;j++)
				for(k=0;k<26;k++)
					for(h=0;h<26;h++){
						if(kn[0]!=-1&&i+j+k+h!=kn[0]||
							kn[1]!=-1&&i+j!=kn[1]||
							kn[2]!=-1&&k+h!=kn[2]||
							kn[3]!=-1&&i+k!=kn[3]||
							kn[4]!=-1&&j+h!=kn[4]||
							kn[5]!=-1&&i!=kn[5]||
							kn[6]!=-1&&j!=kn[6]||
							kn[7]!=-1&&k!=kn[7]||
							kn[8]!=-1&&h!=kn[8])continue;
						switch(target){
						case 0:return i+j+k+h;
						case 1:return i+j;
						case 2:return k+h;
						case 3:return i+k;
						case 4:return j+h;
						case 5:return i;
						case 6:return j;
						case 7:return k;
						case 8:return h;
						}
					}
			return -1;
	}
};




void test0(){
	int _known[]={50,-1,-1,-1,30,-1,-1,-1,-1};
	vector<int> known(_known+0,_known+sizeof(_known)/sizeof(int));
	int target=3;
	int getCount= 20;
	ObjectCounter _ObjectCounter;
	int ret=_ObjectCounter.getCount(known,target);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"known = "<<known<<endl;
	cout<<"target = "<<target<<endl;
	cout<<"expected to return "<<getCount<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getCount)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int _known[]={-1,25,-1,35,-1,15,-1,-1,0};
	vector<int> known(_known+0,_known+sizeof(_known)/sizeof(int));
	int target=0;
	int getCount= 45;
	ObjectCounter _ObjectCounter;
	int ret=_ObjectCounter.getCount(known,target);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"known = "<<known<<endl;
	cout<<"target = "<<target<<endl;
	cout<<"expected to return "<<getCount<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getCount)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int _known[]={-1,-1,-1,-1,-1,-1,-1,17,-1};
	vector<int> known(_known+0,_known+sizeof(_known)/sizeof(int));
	int target=7;
	int getCount= 17;
	ObjectCounter _ObjectCounter;
	int ret=_ObjectCounter.getCount(known,target);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"known = "<<known<<endl;
	cout<<"target = "<<target<<endl;
	cout<<"expected to return "<<getCount<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getCount)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int _known[]={0,-1,-1,-1,-1,-1,-1,-1,-1};
	vector<int> known(_known+0,_known+sizeof(_known)/sizeof(int));
	int target=2;
	int getCount= 0;
	ObjectCounter _ObjectCounter;
	int ret=_ObjectCounter.getCount(known,target);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"known = "<<known<<endl;
	cout<<"target = "<<target<<endl;
	cout<<"expected to return "<<getCount<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getCount)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int _known[]={23,-1,11,3,20,0,-1,-1,-1};
	vector<int> known(_known+0,_known+sizeof(_known)/sizeof(int));
	int target=6;
	int getCount= 12;
	ObjectCounter _ObjectCounter;
	int ret=_ObjectCounter.getCount(known,target);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"known = "<<known<<endl;
	cout<<"target = "<<target<<endl;
	cout<<"expected to return "<<getCount<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getCount)
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
