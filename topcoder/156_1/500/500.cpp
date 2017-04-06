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


class SmartElevator{
public:
	VI ss,dd,aa;
	VI r;
	int ret;
	char mark[20];
	int calc(vector<int> r){
		int i,ret=0,j;
		j=1;
		char mark[20];
		cls(mark);
		for(i=0;i<r.size();i++){
			mark[r[i]]=1;
			if(r[i]%2&&!mark[r[i]-1])return 100000000;
		}
		for(i=0;i<r.size();i++){
			if(r[i]%2){
				ret+=abs(dd[r[i]/2]-j);
				j=dd[r[i]/2];
			}
			else {
				ret+=abs(ss[r[i]/2]-j);
				if(ret<=aa[r[i]/2])ret=aa[r[i]/2];
				j=ss[r[i]/2];
			}
		}
		return ret;
	}
	void dfs(int k){
		if(k==aa.size()*2){
			int t=calc(r);
			if(t<ret)ret=t;
		}
		int i;
		for(i=0;i<aa.size()*2;i++)
			if(!mark[i]){
				if(i%2&&mark[i-1]||i%2==0){
					mark[i]=1;
					r[k]=i;
					dfs(k+1);
					mark[i]=0;
				}
			}
	}
	int timeWaiting(vector<int> a,vector<int> s,vector<int> d){
		ret=1000000000;
		aa=a;ss=s;dd=d;
		r.clear();
		cls(mark);
		r.resize(a.size()*2);
		dfs(0);
		return ret;
	}
};




void test0(){
	int _arrivalTime[]={5};
	vector<int> arrivalTime(_arrivalTime+0,_arrivalTime+sizeof(_arrivalTime)/sizeof(int));
	int _startingFloor[]={30};
	vector<int> startingFloor(_startingFloor+0,_startingFloor+sizeof(_startingFloor)/sizeof(int));
	int _destinationFloor[]={50};
	vector<int> destinationFloor(_destinationFloor+0,_destinationFloor+sizeof(_destinationFloor)/sizeof(int));
	int timeWaiting= 49;
	SmartElevator _SmartElevator;
	int ret=_SmartElevator.timeWaiting(arrivalTime,startingFloor,destinationFloor);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"arrivalTime = "<<arrivalTime<<endl;
	cout<<"startingFloor = "<<startingFloor<<endl;
	cout<<"destinationFloor = "<<destinationFloor<<endl;
	cout<<"expected to return "<<timeWaiting<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==timeWaiting)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int _arrivalTime[]={100};
	vector<int> arrivalTime(_arrivalTime+0,_arrivalTime+sizeof(_arrivalTime)/sizeof(int));
	int _startingFloor[]={30};
	vector<int> startingFloor(_startingFloor+0,_startingFloor+sizeof(_startingFloor)/sizeof(int));
	int _destinationFloor[]={50};
	vector<int> destinationFloor(_destinationFloor+0,_destinationFloor+sizeof(_destinationFloor)/sizeof(int));
	int timeWaiting= 120;
	SmartElevator _SmartElevator;
	int ret=_SmartElevator.timeWaiting(arrivalTime,startingFloor,destinationFloor);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"arrivalTime = "<<arrivalTime<<endl;
	cout<<"startingFloor = "<<startingFloor<<endl;
	cout<<"destinationFloor = "<<destinationFloor<<endl;
	cout<<"expected to return "<<timeWaiting<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==timeWaiting)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int _arrivalTime[]={10,120};
	vector<int> arrivalTime(_arrivalTime+0,_arrivalTime+sizeof(_arrivalTime)/sizeof(int));
	int _startingFloor[]={1,100};
	vector<int> startingFloor(_startingFloor+0,_startingFloor+sizeof(_startingFloor)/sizeof(int));
	int _destinationFloor[]={210,200};
	vector<int> destinationFloor(_destinationFloor+0,_destinationFloor+sizeof(_destinationFloor)/sizeof(int));
	int timeWaiting= 230;
	SmartElevator _SmartElevator;
	int ret=_SmartElevator.timeWaiting(arrivalTime,startingFloor,destinationFloor);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"arrivalTime = "<<arrivalTime<<endl;
	cout<<"startingFloor = "<<startingFloor<<endl;
	cout<<"destinationFloor = "<<destinationFloor<<endl;
	cout<<"expected to return "<<timeWaiting<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==timeWaiting)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int _arrivalTime[]={10,500};
	vector<int> arrivalTime(_arrivalTime+0,_arrivalTime+sizeof(_arrivalTime)/sizeof(int));
	int _startingFloor[]={1,100};
	vector<int> startingFloor(_startingFloor+0,_startingFloor+sizeof(_startingFloor)/sizeof(int));
	int _destinationFloor[]={210,200};
	vector<int> destinationFloor(_destinationFloor+0,_destinationFloor+sizeof(_destinationFloor)/sizeof(int));
	int timeWaiting= 600;
	SmartElevator _SmartElevator;
	int ret=_SmartElevator.timeWaiting(arrivalTime,startingFloor,destinationFloor);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"arrivalTime = "<<arrivalTime<<endl;
	cout<<"startingFloor = "<<startingFloor<<endl;
	cout<<"destinationFloor = "<<destinationFloor<<endl;
	cout<<"expected to return "<<timeWaiting<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==timeWaiting)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int _arrivalTime[]={1000,1200,1600,2000,2400};
	vector<int> arrivalTime(_arrivalTime+0,_arrivalTime+sizeof(_arrivalTime)/sizeof(int));
	int _startingFloor[]={500,500,500,500,500};
	vector<int> startingFloor(_startingFloor+0,_startingFloor+sizeof(_startingFloor)/sizeof(int));
	int _destinationFloor[]={700,300,700,300,700};
	vector<int> destinationFloor(_destinationFloor+0,_destinationFloor+sizeof(_destinationFloor)/sizeof(int));
	int timeWaiting= 2600;
	SmartElevator _SmartElevator;
	int ret=_SmartElevator.timeWaiting(arrivalTime,startingFloor,destinationFloor);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"arrivalTime = "<<arrivalTime<<endl;
	cout<<"startingFloor = "<<startingFloor<<endl;
	cout<<"destinationFloor = "<<destinationFloor<<endl;
	cout<<"expected to return "<<timeWaiting<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==timeWaiting)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	int _arrivalTime[]={775397,261225,870141,287698,884334};
	vector<int> arrivalTime(_arrivalTime+0,_arrivalTime+sizeof(_arrivalTime)/sizeof(int));
	int _startingFloor[]={82225,958610,998971,413596,21922};
	vector<int> startingFloor(_startingFloor+0,_startingFloor+sizeof(_startingFloor)/sizeof(int));
	int _destinationFloor[]={769962,78706,477861,237168,258488};
	vector<int> destinationFloor(_destinationFloor+0,_destinationFloor+sizeof(_destinationFloor)/sizeof(int));
	int timeWaiting= 2724059;
	SmartElevator _SmartElevator;
	int ret=_SmartElevator.timeWaiting(arrivalTime,startingFloor,destinationFloor);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"arrivalTime = "<<arrivalTime<<endl;
	cout<<"startingFloor = "<<startingFloor<<endl;
	cout<<"destinationFloor = "<<destinationFloor<<endl;
	cout<<"expected to return "<<timeWaiting<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==timeWaiting)
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
