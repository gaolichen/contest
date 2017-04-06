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


class Cassette{
public:
	int bestListen(int len,vector<string> s,int time){
		int i,j,m1,s,1,m2,s1,t1,t2,val;
		for(i=0;i<s.size();i++){
			if(s[i][0]=='A')flag=0;
			else flag=1;
			sscanf(s[i].c_str()+1,"%d:%d %d:%d %d",&m1,&s1,&m2,&s2,&val);
			t1=m1*60+s1;
			t2=m2*60+s2;
			for(j=t1;j<=t2;j++)
				v[flag][j]=val;
		}
	}
};




void test0(){
	int tapelength=36;
	string _songs[]={"A 00:05 00:05 4", "B 00:19 00:10 7", "A 00:14 00:04 6", "A 00:22 00:12 1", "B 00:03 00:09 3", "B 00:16 00:01 5", "A 00:00 00:05 2"};
	vector<string> songs(_songs+0,_songs+sizeof(_songs)/sizeof(string));
	int listeningtime=20;
	int bestListen= 110;
	Cassette _Cassette;
	int ret=_Cassette.bestListen(tapelength,songs,listeningtime);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"tapelength = "<<tapelength<<endl;
	cout<<"songs = "<<songs<<endl;
	cout<<"listeningtime = "<<listeningtime<<endl;
	cout<<"expected to return "<<bestListen<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestListen)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int tapelength=46;
	string _songs[]={"A 00:05 00:03 8", "A 00:04 00:01 2", "B 00:02 00:06 1", "B 00:22 00:04 4", "B 00:28 00:09 8", "B 00:16 00:01 8", "A 00:26 00:02 7", "A 00:10 00:07 5"};
	vector<string> songs(_songs+0,_songs+sizeof(_songs)/sizeof(string));
	int listeningtime=30;
	int bestListen= 143;
	Cassette _Cassette;
	int ret=_Cassette.bestListen(tapelength,songs,listeningtime);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"tapelength = "<<tapelength<<endl;
	cout<<"songs = "<<songs<<endl;
	cout<<"listeningtime = "<<listeningtime<<endl;
	cout<<"expected to return "<<bestListen<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestListen)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int tapelength=1320;
	string _songs[]={"B 00:02 02:41 38","A 13:10 02:12 35", "B 02:58 03:10 32","B 12:48 03:55 71", "A 06:51 00:20 45","A 17:39 01:41 13", "B 17:23 02:45 26","A 09:43 03:20 6", "A 19:25 01:26 24","B 02:47 00:09 53", "A 01:52 01:07 44","B 11:55 00:46 48", "A 15:25 00:50 34","B 20:13 00:10 75", "B 10:39 01:12 74","A 00:01 01:50 21", "B 06:15 03:14 52","A 03:01 03:41 47", "A 16:24 01:06 62","A 08:13 01:23 49", "B 16:48 00:35 59","B 09:35 01:00 20", "A 20:51 01:03 36","B 20:32 01:11 63", "A 07:13 00:51 48"};
	vector<string> songs(_songs+0,_songs+sizeof(_songs)/sizeof(string));
	int listeningtime=1765;
	int bestListen= 80314;
	Cassette _Cassette;
	int ret=_Cassette.bestListen(tapelength,songs,listeningtime);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"tapelength = "<<tapelength<<endl;
	cout<<"songs = "<<songs<<endl;
	cout<<"listeningtime = "<<listeningtime<<endl;
	cout<<"expected to return "<<bestListen<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestListen)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int tapelength=15;
	string _songs[]={"B 00:00 00:10 20","A 00:00 00:10 22"};
	vector<string> songs(_songs+0,_songs+sizeof(_songs)/sizeof(string));
	int listeningtime=11;
	int bestListen= 240;
	Cassette _Cassette;
	int ret=_Cassette.bestListen(tapelength,songs,listeningtime);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"tapelength = "<<tapelength<<endl;
	cout<<"songs = "<<songs<<endl;
	cout<<"listeningtime = "<<listeningtime<<endl;
	cout<<"expected to return "<<bestListen<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestListen)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int tapelength=5216;
	string _songs[]={"B 00:00 11:14 60","A 00:01 18:16 23", "B 11:14 06:43 26","B 17:59 01:07 33", "A 18:18 07:01 19","B 19:07 17:27 54", "A 25:24 11:13 97","A 36:38 09:19 90", "B 36:41 18:18 33","A 46:00 04:22 51", "A 50:28 19:32 41","B 55:06 16:18 62", "A 70:02 01:36 3", "B 71:31 12:29 32", "A 71:43 15:12 77"};
	vector<string> songs(_songs+0,_songs+sizeof(_songs)/sizeof(string));
	int listeningtime=5216;
	int bestListen= 330607;
	Cassette _Cassette;
	int ret=_Cassette.bestListen(tapelength,songs,listeningtime);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"tapelength = "<<tapelength<<endl;
	cout<<"songs = "<<songs<<endl;
	cout<<"listeningtime = "<<listeningtime<<endl;
	cout<<"expected to return "<<bestListen<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestListen)
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
