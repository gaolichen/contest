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


class CoinExchange{
public:
	int minCoins(vector<int> jo,vector<int> ma,int de){
		int i,tot=0,j;
		int f[2600];
		sort(jo.begin(),jo.end());
		sort(ma.begin(),ma.end());
		memset(f,0,sizeof(f));
		f[0]=0;
		for(i=0;i<jo.size();i++)
			tot+=jo[i];
		for(i=0;i<jo.size();i++){
			for(j=tot;j>=0;j--)
				if(j==0||f[j]){
					if(f[j+jo[i]]&&f[j+jo[i]]<=f[j]+1)continue;
					f[j+jo[i]]=f[j]+1;
				}
		}
//		for(i=1;i<=tot;i++)
//			cout<<f[i]<<' ';
//		cout<<endl;
		for(i=0;i<ma.size();i++){
			for(j=1;j<=tot;j++)
				if(f[j]){
					if(ma[i]>=j)continue;
					if(f[j-ma[i]]&&f[j-ma[i]]<=f[j]+1)continue;
					f[j-ma[i]]=f[j]+1;
				}
		}
		/*
		for(i=0;;i++){
			cnt=0;
			for(j=0;j<=tot;j++)if(f[j]==i){
				for(k=0;k<jo.size()&&jo[k]+j<=tot;k++){
					if(f[jo[k]+j]&&f[jo[k]+j]<=i+1)continue;
					f[jo[k]+j]=i+1;
					cnt++;
				}
				for(k=0;k<ma.size()&&j-ma[k]>0;k++){
					if(f[j-ma[k]]&&f[j-ma[k]]<=i)continue;
					f[j-ma[k]]=i+1;
					cnt++;
				}
			}
			if(!cnt)break;
		}*/
		if(f[de])
		return f[de];
		else return -1;
	}
};




void test0(){
	int _johnCoins[]={1,1,1,10,10,50};
	vector<int> johnCoins(_johnCoins+0,_johnCoins+sizeof(_johnCoins)/sizeof(int));
	int _maryCoins[]={1,1,25};
	vector<int> maryCoins(_maryCoins+0,_maryCoins+sizeof(_maryCoins)/sizeof(int));
	int debt=23;
	int minCoins= 4;
	CoinExchange _CoinExchange;
	int ret=_CoinExchange.minCoins(johnCoins,maryCoins,debt);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"johnCoins = "<<johnCoins<<endl;
	cout<<"maryCoins = "<<maryCoins<<endl;
	cout<<"debt = "<<debt<<endl;
	cout<<"expected to return "<<minCoins<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minCoins)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int _johnCoins[]={1,5,10,25,50};
	vector<int> johnCoins(_johnCoins+0,_johnCoins+sizeof(_johnCoins)/sizeof(int));
	int _maryCoins[]={1,5,10,25,50};
	vector<int> maryCoins(_maryCoins+0,_maryCoins+sizeof(_maryCoins)/sizeof(int));
	int debt=8;
	int minCoins= -1;
	CoinExchange _CoinExchange;
	int ret=_CoinExchange.minCoins(johnCoins,maryCoins,debt);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"johnCoins = "<<johnCoins<<endl;
	cout<<"maryCoins = "<<maryCoins<<endl;
	cout<<"debt = "<<debt<<endl;
	cout<<"expected to return "<<minCoins<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minCoins)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int _johnCoins[]={1,5,1,10,25,25,10,50,25,25};
	vector<int> johnCoins(_johnCoins+0,_johnCoins+sizeof(_johnCoins)/sizeof(int));
	int _maryCoins[]={50,25,5,5,1,1,1,50,25};
	vector<int> maryCoins(_maryCoins+0,_maryCoins+sizeof(_maryCoins)/sizeof(int));
	int debt=138;
	int minCoins= 8;
	CoinExchange _CoinExchange;
	int ret=_CoinExchange.minCoins(johnCoins,maryCoins,debt);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"johnCoins = "<<johnCoins<<endl;
	cout<<"maryCoins = "<<maryCoins<<endl;
	cout<<"debt = "<<debt<<endl;
	cout<<"expected to return "<<minCoins<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minCoins)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int _johnCoins[]={50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50};
	vector<int> johnCoins(_johnCoins+0,_johnCoins+sizeof(_johnCoins)/sizeof(int));
	int _maryCoins[]={1,1,1,1,1,1,1,1,1,1,1,1};
	vector<int> maryCoins(_maryCoins+0,_maryCoins+sizeof(_maryCoins)/sizeof(int));
	int debt=1188;
	int minCoins= 36;
	CoinExchange _CoinExchange;
	int ret=_CoinExchange.minCoins(johnCoins,maryCoins,debt);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"johnCoins = "<<johnCoins<<endl;
	cout<<"maryCoins = "<<maryCoins<<endl;
	cout<<"debt = "<<debt<<endl;
	cout<<"expected to return "<<minCoins<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minCoins)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int _johnCoins[]={5,5,5,5,5,5,5,10,10,10,10,10,10,10,10,25,25,25,25,50,50,50,50,50,50,50};
	vector<int> johnCoins(_johnCoins+0,_johnCoins+sizeof(_johnCoins)/sizeof(int));
	int _maryCoins[]={1,1,1,1,1,1,5,5,5,10,10,10,10,10,25,25,25,25,50,50,50,50};
	vector<int> maryCoins(_maryCoins+0,_maryCoins+sizeof(_maryCoins)/sizeof(int));
	int debt=482;
	int minCoins= 18;
	CoinExchange _CoinExchange;
	int ret=_CoinExchange.minCoins(johnCoins,maryCoins,debt);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"johnCoins = "<<johnCoins<<endl;
	cout<<"maryCoins = "<<maryCoins<<endl;
	cout<<"debt = "<<debt<<endl;
	cout<<"expected to return "<<minCoins<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minCoins)
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
