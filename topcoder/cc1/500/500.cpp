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


class RoadWork{
public:
	int in(int s1,int e1,int s2,int e2){
		return s1>=s2&&e1<=e2;
	}
	int fraudFeet(vector<int> st,vector<int> en){
		int i,j,ret=0,k;
		vector<int> tmp;
		tmp=st;
		for(i=0;i<en.size();i++)
			tmp.push_back(en[i]);
		sort(tmp.begin(),tmp.end());
		for(i=1;i<tmp.size();i++){
			for(j=k=0;j<st.size();j++){
				if(in(tmp[i-1],tmp[i],st[j],en[j]))k++;
				if(k>1)break;
			}
			if(j<st.size())
			ret+=tmp[i]-tmp[i-1];
		}
		return ret;
	}
};




void test0(){
	int _start[]={50,50,50};
	vector<int> start(_start+0,_start+sizeof(_start)/sizeof(int));
	int _end[]={58,58,60};
	vector<int> end(_end+0,_end+sizeof(_end)/sizeof(int));
	int fraudFeet= 8;
	RoadWork _RoadWork;
	int ret=_RoadWork.fraudFeet(start,end);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"start = "<<start<<endl;
	cout<<"end = "<<end<<endl;
	cout<<"expected to return "<<fraudFeet<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==fraudFeet)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int _start[]={171234,12,20,30};
	vector<int> start(_start+0,_start+sizeof(_start)/sizeof(int));
	int _end[]={171236,20,30,40};
	vector<int> end(_end+0,_end+sizeof(_end)/sizeof(int));
	int fraudFeet= 0;
	RoadWork _RoadWork;
	int ret=_RoadWork.fraudFeet(start,end);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"start = "<<start<<endl;
	cout<<"end = "<<end<<endl;
	cout<<"expected to return "<<fraudFeet<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==fraudFeet)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int _start[]={12,32,92};
	vector<int> start(_start+0,_start+sizeof(_start)/sizeof(int));
	int _end[]={991,161,1093};
	vector<int> end(_end+0,_end+sizeof(_end)/sizeof(int));
	int fraudFeet= 959;
	RoadWork _RoadWork;
	int ret=_RoadWork.fraudFeet(start,end);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"start = "<<start<<endl;
	cout<<"end = "<<end<<endl;
	cout<<"expected to return "<<fraudFeet<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==fraudFeet)
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
