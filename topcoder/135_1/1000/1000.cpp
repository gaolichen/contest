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


class CircleHighway{
public:
	int pour(int curr,int a){
		curr+=a;
		if(curr>500000000)curr=500000000;
		return curr;
	}
	int closest(vector<int> d,vector<int> g,int y){
		int i,ret=-1,j;
		int curr=y,size=d.size();
		for(i=0;i<size;i++){
			d.push_back(1000000000+d[i]);
			g.push_back(g[i]);
		}
		for(i=0;i<size;i++){
			curr=y;
			for(j=i;j<i+size;j++){
				curr=pour(curr,g[j]);
				if(d[j+1]-d[j]>curr)break;
				curr-=d[j+1]-d[j];
				
			}
			if(j==i+size)break;
		}
		if(i==size)return -1;
		cout<<d[i]<<endl;
		int top,low;
		top=y;low=0;curr=(top+low)/2;
		while(curr>low){
			for(j=i;j<i+size;j++){
				curr=pour(curr,g[j]);
				if(d[j+1]-d[j]>curr)break;
				curr-=d[j+1]-d[j];
			}
			if(j==i+size)top=curr;
			else low=curr;
			curr=(top+low)/2;
		}
		curr=low;
		for(j=i;j<i+size;j++){
				curr=pour(curr,g[j]);
				if(d[j+1]-d[j]>curr)break;
				curr-=d[j+1]-d[j];
		}
		if(j==i+size)ret=curr;
		else ret=top;
		ret=d[i]-(y-ret);
		if(ret<0)ret+=1000000000;
		return ret;
	}
};




void test0(){
	int _distances[]={1,5,100,101,1000,2000,3000,4000,5000,6000};
	vector<int> distances(_distances+0,_distances+sizeof(_distances)/sizeof(int));
	int _gas[]={0,1000000000,0,0,0,0,0,0,0,0};
	vector<int> gas(_gas+0,_gas+sizeof(_gas)/sizeof(int));
	int yourGas=0;
	int closest= -1;
	CircleHighway _CircleHighway;
	int ret=_CircleHighway.closest(distances,gas,yourGas);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"distances = "<<distances<<endl;
	cout<<"gas = "<<gas<<endl;
	cout<<"yourGas = "<<yourGas<<endl;
	cout<<"expected to return "<<closest<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==closest)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int _distances[]={1,5,100,101,1000,2000,3000,4000,5000,6000};
	vector<int> distances(_distances+0,_distances+sizeof(_distances)/sizeof(int));
	int _gas[]={0,0,500000000,0,0,0,0,500000000,0,0};
	vector<int> gas(_gas+0,_gas+sizeof(_gas)/sizeof(int));
	int yourGas=0;
	int closest= -1;
	CircleHighway _CircleHighway;
	int ret=_CircleHighway.closest(distances,gas,yourGas);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"distances = "<<distances<<endl;
	cout<<"gas = "<<gas<<endl;
	cout<<"yourGas = "<<yourGas<<endl;
	cout<<"expected to return "<<closest<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==closest)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int _distances[]={100,200,1000,2000,3000,4000,5000,500001000,600000000,699999999};
	vector<int> distances(_distances+0,_distances+sizeof(_distances)/sizeof(int));
	int _gas[]={0,0,500000000,0,0,0,0,500000000,0,0};
	vector<int> gas(_gas+0,_gas+sizeof(_gas)/sizeof(int));
	int yourGas=0;
	int closest= 1000;
	CircleHighway _CircleHighway;
	int ret=_CircleHighway.closest(distances,gas,yourGas);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"distances = "<<distances<<endl;
	cout<<"gas = "<<gas<<endl;
	cout<<"yourGas = "<<yourGas<<endl;
	cout<<"expected to return "<<closest<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==closest)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int _distances[]={100,200,1000,2000,3000,4000,5000,500001000,600000000,699999999};
	vector<int> distances(_distances+0,_distances+sizeof(_distances)/sizeof(int));
	int _gas[]={0,0,500000000,0,0,0,0,499999975,0,0};
	vector<int> gas(_gas+0,_gas+sizeof(_gas)/sizeof(int));
	int yourGas=25;
	int closest= 975;
	CircleHighway _CircleHighway;
	int ret=_CircleHighway.closest(distances,gas,yourGas);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"distances = "<<distances<<endl;
	cout<<"gas = "<<gas<<endl;
	cout<<"yourGas = "<<yourGas<<endl;
	cout<<"expected to return "<<closest<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==closest)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int _distances[]={1,100000001,200000001,300000001,400000001,500000001,600000001,700000001,800000001,900000001};
	vector<int> distances(_distances+0,_distances+sizeof(_distances)/sizeof(int));
	int _gas[]={100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000};
	vector<int> gas(_gas+0,_gas+sizeof(_gas)/sizeof(int));
	int yourGas=0;
	int closest= 1;
	CircleHighway _CircleHighway;
	int ret=_CircleHighway.closest(distances,gas,yourGas);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"distances = "<<distances<<endl;
	cout<<"gas = "<<gas<<endl;
	cout<<"yourGas = "<<yourGas<<endl;
	cout<<"expected to return "<<closest<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==closest)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	int _distances[]={0,1,2,3,499999999,500000000,600000000,700000000,800000000,900000000};
	vector<int> distances(_distances+0,_distances+sizeof(_distances)/sizeof(int));
	int _gas[]={0,0,0,0,500000000,0,0,0,0,0};
	vector<int> gas(_gas+0,_gas+sizeof(_gas)/sizeof(int));
	int yourGas=500000000;
	int closest= 999999999;
	CircleHighway _CircleHighway;
	int ret=_CircleHighway.closest(distances,gas,yourGas);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"distances = "<<distances<<endl;
	cout<<"gas = "<<gas<<endl;
	cout<<"yourGas = "<<yourGas<<endl;
	cout<<"expected to return "<<closest<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==closest)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test6(){
	int _distances[]={14001234,25790093,29205405,133628031,216203501,241968487,335747855,358411989,409099026,436935534};
	vector<int> distances(_distances+0,_distances+sizeof(_distances)/sizeof(int));
	int _gas[]={41068575,102880168,22811826,60528045,52885843,54609765,161190371,98070914,112850585,185668492};
	vector<int> gas(_gas+0,_gas+sizeof(_gas)/sizeof(int));
	int yourGas=107435416;
	int closest= 906565818;
	CircleHighway _CircleHighway;
	int ret=_CircleHighway.closest(distances,gas,yourGas);
	cout<<"--------------------test 6--------------------"<<endl;
	cout<<"distances = "<<distances<<endl;
	cout<<"gas = "<<gas<<endl;
	cout<<"yourGas = "<<yourGas<<endl;
	cout<<"expected to return "<<closest<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==closest)
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
	return 0;
}
