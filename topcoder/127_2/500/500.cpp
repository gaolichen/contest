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


class SpeedDial{
public:
	int num[60];
	int assignNumbers(vector<int> n,vector<int> h,int s){
		int i,j,ret=0;
		int r[60];
		for(i=0;i<n.size();i++){
			j=n[i];
			num[i]=0;
			while(j){
				num[i]++;
				j/=10;
			}
		}
		for(i=0;i<n.size();i++){
			ret+=num[i]*h[i];
			r[i]=i;
		}
		char mark[60];
		int tj,t;
		memset(mark,0,sizeof(mark));
		for(i=0;i<n.size();i++){
			t=-2100000000;
			for(j=0;j<n.size();j++)
				if(!mark[j]){
					if((num[j]-2)*h[j]>t){
						t=(num[j]-2)*h[j];
						tj=j;
					}
				}
			mark[tj]=1;
			r[i]=tj;
		}
		ret=0;
		for(i=j=0;i<n.size()&&j<s;i++){
			if(num[r[i]]>2){
				ret+=2*h[r[i]];
				j++;
			}
			else ret+=num[r[i]]*h[r[i]];
		}
		for(;i<n.size();i++)
			ret+=num[r[i]]*h[r[i]];
		return ret;
	}
};




void test0(){
	int _numbers[]={9753,1245987,4833,34473,8733,1437};
	vector<int> numbers(_numbers+0,_numbers+sizeof(_numbers)/sizeof(int));
	int _howMany[]={5,2,4,3,2,4};
	vector<int> howMany(_howMany+0,_howMany+sizeof(_howMany)/sizeof(int));
	int slots=4;
	int assignNumbers= 52;
	SpeedDial _SpeedDial;
	int ret=_SpeedDial.assignNumbers(numbers,howMany,slots);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"numbers = "<<numbers<<endl;
	cout<<"howMany = "<<howMany<<endl;
	cout<<"slots = "<<slots<<endl;
	cout<<"expected to return "<<assignNumbers<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==assignNumbers)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int _numbers[]={124839,9876,43823};
	vector<int> numbers(_numbers+0,_numbers+sizeof(_numbers)/sizeof(int));
	int _howMany[]={73,95,102};
	vector<int> howMany(_howMany+0,_howMany+sizeof(_howMany)/sizeof(int));
	int slots=5;
	int assignNumbers= 540;
	SpeedDial _SpeedDial;
	int ret=_SpeedDial.assignNumbers(numbers,howMany,slots);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"numbers = "<<numbers<<endl;
	cout<<"howMany = "<<howMany<<endl;
	cout<<"slots = "<<slots<<endl;
	cout<<"expected to return "<<assignNumbers<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==assignNumbers)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int _numbers[]={8925135,6046333,68260,29405,4830502,378742,13561,6090,976234,71994};
	vector<int> numbers(_numbers+0,_numbers+sizeof(_numbers)/sizeof(int));
	int _howMany[]={5,35,2,34,33,14,43,42,29,10};
	vector<int> howMany(_howMany+0,_howMany+sizeof(_howMany)/sizeof(int));
	int slots=5;
	int assignNumbers= 695;
	SpeedDial _SpeedDial;
	int ret=_SpeedDial.assignNumbers(numbers,howMany,slots);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"numbers = "<<numbers<<endl;
	cout<<"howMany = "<<howMany<<endl;
	cout<<"slots = "<<slots<<endl;
	cout<<"expected to return "<<assignNumbers<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==assignNumbers)
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
