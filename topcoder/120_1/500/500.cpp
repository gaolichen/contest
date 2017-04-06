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


class Vending{
public:
	int getDrinks(int c,vector<int> d,vector<int> coin,vector<string> e){
		int i,j,k,l,ret=0,t,s,t1,t2,t3;
		for(i=0;i<e.size();i++){
			sscanf(e[i].c_str(),"%d %d %d %d",&t,&j,&k,&l);
			if(d[l]==0)continue;
			s=t*25+j*10+k*5;
			t1=t;t2=j;t3=k;
			if(s<c)continue;
			s-=c;
			coin[0]+=t1;
			coin[1]+=t2;coin[2]+=t3;
			for(j=min(s/25,coin[0]);j>=0;j--){
				for(k=min((s-j*25)/10,coin[1]);k>=0;k--)
					if((s-j*25-k*10)%5==0&&(s-j*25-k*10)/5<=coin[2])
						break;
				if(k>=0)break;
			}
			if(j<0){
				coin[0]-=t1;
			coin[1]-=t2;coin[2]-=t3;
				continue;
			}
			coin[0]+=-j;
			coin[1]+=-k;
			coin[2]+=-(s-j*25-k*10)/5;
			d[l]--;ret++;
		}
		return ret;
	}
};




void test0(){
	int cost=65;
	int _drinkCounts[]={2, 4, 1};
	vector<int> drinkCounts(_drinkCounts+0,_drinkCounts+sizeof(_drinkCounts)/sizeof(int));
	int _coinCounts[]={0, 0, 0};
	vector<int> coinCounts(_coinCounts+0,_coinCounts+sizeof(_coinCounts)/sizeof(int));
	string _events[]={ "2 1 1 2",  "2 1 1 2",  "3 0 0 1",  "3 0 0 1",  "0 6 4 1" };
	vector<string> events(_events+0,_events+sizeof(_events)/sizeof(string));
	int getDrinks= 3;
	Vending _Vending;
	int ret=_Vending.getDrinks(cost,drinkCounts,coinCounts,events);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"cost = "<<cost<<endl;
	cout<<"drinkCounts = "<<drinkCounts<<endl;
	cout<<"coinCounts = "<<coinCounts<<endl;
	cout<<"events = "<<events<<endl;
	cout<<"expected to return "<<getDrinks<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getDrinks)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int cost=25;
	int _drinkCounts[]={1, 1, 0};
	vector<int> drinkCounts(_drinkCounts+0,_drinkCounts+sizeof(_drinkCounts)/sizeof(int));
	int _coinCounts[]={1, 0, 0};
	vector<int> coinCounts(_coinCounts+0,_coinCounts+sizeof(_coinCounts)/sizeof(int));
	string _events[]={ "0 0 5 2",  "0 3 0 1" };
	vector<string> events(_events+0,_events+sizeof(_events)/sizeof(string));
	int getDrinks= 0;
	Vending _Vending;
	int ret=_Vending.getDrinks(cost,drinkCounts,coinCounts,events);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"cost = "<<cost<<endl;
	cout<<"drinkCounts = "<<drinkCounts<<endl;
	cout<<"coinCounts = "<<coinCounts<<endl;
	cout<<"events = "<<events<<endl;
	cout<<"expected to return "<<getDrinks<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getDrinks)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int cost=200;
	int _drinkCounts[]={ 10, 10, 10 };
	vector<int> drinkCounts(_drinkCounts+0,_drinkCounts+sizeof(_drinkCounts)/sizeof(int));
	int _coinCounts[]={ 0, 0, 1 };
	vector<int> coinCounts(_coinCounts+0,_coinCounts+sizeof(_coinCounts)/sizeof(int));
	string _events[]={ "7 3 0 0",  "7 2 1 0",  "7 3 0 0" };
	vector<string> events(_events+0,_events+sizeof(_events)/sizeof(string));
	int getDrinks= 3;
	Vending _Vending;
	int ret=_Vending.getDrinks(cost,drinkCounts,coinCounts,events);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"cost = "<<cost<<endl;
	cout<<"drinkCounts = "<<drinkCounts<<endl;
	cout<<"coinCounts = "<<coinCounts<<endl;
	cout<<"events = "<<events<<endl;
	cout<<"expected to return "<<getDrinks<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getDrinks)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int cost=40;
	int _drinkCounts[]={ 10 };
	vector<int> drinkCounts(_drinkCounts+0,_drinkCounts+sizeof(_drinkCounts)/sizeof(int));
	int _coinCounts[]={ 0, 0, 0 };
	vector<int> coinCounts(_coinCounts+0,_coinCounts+sizeof(_coinCounts)/sizeof(int));
	string _events[]={ "1 2 0 0",  "2 0 0 0" };
	vector<string> events(_events+0,_events+sizeof(_events)/sizeof(string));
	int getDrinks= 0;
	Vending _Vending;
	int ret=_Vending.getDrinks(cost,drinkCounts,coinCounts,events);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"cost = "<<cost<<endl;
	cout<<"drinkCounts = "<<drinkCounts<<endl;
	cout<<"coinCounts = "<<coinCounts<<endl;
	cout<<"events = "<<events<<endl;
	cout<<"expected to return "<<getDrinks<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getDrinks)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int cost=40;
	int _drinkCounts[]={ 10 };
	vector<int> drinkCounts(_drinkCounts+0,_drinkCounts+sizeof(_drinkCounts)/sizeof(int));
	int _coinCounts[]={ 0, 0, 1 };
	vector<int> coinCounts(_coinCounts+0,_coinCounts+sizeof(_coinCounts)/sizeof(int));
	string _events[]={ "1 2 0 0",  "2 0 0 0" };
	vector<string> events(_events+0,_events+sizeof(_events)/sizeof(string));
	int getDrinks= 2;
	Vending _Vending;
	int ret=_Vending.getDrinks(cost,drinkCounts,coinCounts,events);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"cost = "<<cost<<endl;
	cout<<"drinkCounts = "<<drinkCounts<<endl;
	cout<<"coinCounts = "<<coinCounts<<endl;
	cout<<"events = "<<events<<endl;
	cout<<"expected to return "<<getDrinks<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getDrinks)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	int cost=55;
	int _drinkCounts[]={ 10 };
	vector<int> drinkCounts(_drinkCounts+0,_drinkCounts+sizeof(_drinkCounts)/sizeof(int));
	int _coinCounts[]={ 0, 0, 0 };
	vector<int> coinCounts(_coinCounts+0,_coinCounts+sizeof(_coinCounts)/sizeof(int));
	string _events[]={ "2 0 0 0",  "2 0 1 0",  "2 0 1 0",  "2 1 0 0",  "2 1 0 0",  "3 0 0 0" };
	vector<string> events(_events+0,_events+sizeof(_events)/sizeof(string));
	int getDrinks= 5;
	Vending _Vending;
	int ret=_Vending.getDrinks(cost,drinkCounts,coinCounts,events);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"cost = "<<cost<<endl;
	cout<<"drinkCounts = "<<drinkCounts<<endl;
	cout<<"coinCounts = "<<coinCounts<<endl;
	cout<<"events = "<<events<<endl;
	cout<<"expected to return "<<getDrinks<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getDrinks)
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
