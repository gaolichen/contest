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


class BoardGame{
public:
	vector<int> trackMoves(vector<int> d1,vector<int> d2,int np){
		int i,j,p=0,mark[100];
		vector<int> po;
		memset(mark,0,sizeof(mark));
		for(i=0;i<np;i++)
			po.push_back(0);
		for(i=j=0;i<d1.size();i++){
			if(p==np)p=0;
			if(d1[i]!=d2[i]){
				if(mark[p]){
					p++;
					continue;
				}
				po[p]+=d1[i]+d2[i];
				po[p++]%=64;
				j=0;
			}
			else{
				j++;
				if(mark[p]){
					mark[p]=j=0;
					po[p]=(po[p]+d1[i]+d2[i])%64;
					p++;
					continue;
				}
				if(j==3){
					mark[p]=1;
					po[p++]=31;
					j=0;
				}
				else po[p]=(po[p]+d1[i]+d2[i])%64;
			}
		}
		for(i=0;i<np;i++)
			po[i]++;
		return po;
	}
};




void test0(){
	int _die1[]={1,2,6,6,6,6,1,1,1,6,6,5};
	vector<int> die1(_die1+0,_die1+sizeof(_die1)/sizeof(int));
	int _die2[]={3,1,4,6,6,5,1,1,1,6,6,3};
	vector<int> die2(_die2+0,_die2+sizeof(_die2)/sizeof(int));
	int numPlayers=2;
	int _trackMoves[]= { 32,  7 };
	vector<int> trackMoves(_trackMoves+0,_trackMoves+sizeof(_trackMoves)/sizeof(int));
	BoardGame _BoardGame;
	vector<int> ret=_BoardGame.trackMoves(die1,die2,numPlayers);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"die1 = "<<die1<<endl;
	cout<<"die2 = "<<die2<<endl;
	cout<<"numPlayers = "<<numPlayers<<endl;
	cout<<"expected to return "<<trackMoves<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==trackMoves)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int _die1[]={1,2,3,4,5,6,1,2,3,4,5,6,1,2,3,4,5,6,1,2,3,4,5,6};
	vector<int> die1(_die1+0,_die1+sizeof(_die1)/sizeof(int));
	int _die2[]={6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6};
	vector<int> die2(_die2+0,_die2+sizeof(_die2)/sizeof(int));
	int numPlayers=8;
	int _trackMoves[]= { 26,  29,  39,  30,  33,  30,  20,  29 };
	vector<int> trackMoves(_trackMoves+0,_trackMoves+sizeof(_trackMoves)/sizeof(int));
	BoardGame _BoardGame;
	vector<int> ret=_BoardGame.trackMoves(die1,die2,numPlayers);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"die1 = "<<die1<<endl;
	cout<<"die2 = "<<die2<<endl;
	cout<<"numPlayers = "<<numPlayers<<endl;
	cout<<"expected to return "<<trackMoves<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==trackMoves)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int _die1[]={1};
	vector<int> die1(_die1+0,_die1+sizeof(_die1)/sizeof(int));
	int _die2[]={1};
	vector<int> die2(_die2+0,_die2+sizeof(_die2)/sizeof(int));
	int numPlayers=1;
	int _trackMoves[]= { 3 };
	vector<int> trackMoves(_trackMoves+0,_trackMoves+sizeof(_trackMoves)/sizeof(int));
	BoardGame _BoardGame;
	vector<int> ret=_BoardGame.trackMoves(die1,die2,numPlayers);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"die1 = "<<die1<<endl;
	cout<<"die2 = "<<die2<<endl;
	cout<<"numPlayers = "<<numPlayers<<endl;
	cout<<"expected to return "<<trackMoves<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==trackMoves)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int _die1[]={5,5,5};
	vector<int> die1(_die1+0,_die1+sizeof(_die1)/sizeof(int));
	int _die2[]={5,5,5};
	vector<int> die2(_die2+0,_die2+sizeof(_die2)/sizeof(int));
	int numPlayers=8;
	int _trackMoves[]= { 32,  1,  1,  1,  1,  1,  1,  1 };
	vector<int> trackMoves(_trackMoves+0,_trackMoves+sizeof(_trackMoves)/sizeof(int));
	BoardGame _BoardGame;
	vector<int> ret=_BoardGame.trackMoves(die1,die2,numPlayers);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"die1 = "<<die1<<endl;
	cout<<"die2 = "<<die2<<endl;
	cout<<"numPlayers = "<<numPlayers<<endl;
	cout<<"expected to return "<<trackMoves<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==trackMoves)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	vector<int> die1(0);
	vector<int> die2(0);
	int numPlayers=5;
	int _trackMoves[]= { 1,  1,  1,  1,  1 };
	vector<int> trackMoves(_trackMoves+0,_trackMoves+sizeof(_trackMoves)/sizeof(int));
	BoardGame _BoardGame;
	vector<int> ret=_BoardGame.trackMoves(die1,die2,numPlayers);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"die1 = "<<die1<<endl;
	cout<<"die2 = "<<die2<<endl;
	cout<<"numPlayers = "<<numPlayers<<endl;
	cout<<"expected to return "<<trackMoves<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==trackMoves)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	int _die1[]={5,4,4,3,5,6,5,3,2,5,6,5,3,2};
	vector<int> die1(_die1+0,_die1+sizeof(_die1)/sizeof(int));
	int _die2[]={6,6,6,6,6,6,6,6,6,6,6,6,6,6};
	vector<int> die2(_die2+0,_die2+sizeof(_die2)/sizeof(int));
	int numPlayers=1;
	int _trackMoves[]= { 15 };
	vector<int> trackMoves(_trackMoves+0,_trackMoves+sizeof(_trackMoves)/sizeof(int));
	BoardGame _BoardGame;
	vector<int> ret=_BoardGame.trackMoves(die1,die2,numPlayers);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"die1 = "<<die1<<endl;
	cout<<"die2 = "<<die2<<endl;
	cout<<"numPlayers = "<<numPlayers<<endl;
	cout<<"expected to return "<<trackMoves<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==trackMoves)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test6(){
	int _die1[]={5,1,4,1,4,1,1,1};
	vector<int> die1(_die1+0,_die1+sizeof(_die1)/sizeof(int));
	int _die2[]={6,2,6,2,6,1,1,1};
	vector<int> die2(_die2+0,_die2+sizeof(_die2)/sizeof(int));
	int numPlayers=2;
	int _trackMoves[]= { 32,  32 };
	vector<int> trackMoves(_trackMoves+0,_trackMoves+sizeof(_trackMoves)/sizeof(int));
	BoardGame _BoardGame;
	vector<int> ret=_BoardGame.trackMoves(die1,die2,numPlayers);
	cout<<"--------------------test 6--------------------"<<endl;
	cout<<"die1 = "<<die1<<endl;
	cout<<"die2 = "<<die2<<endl;
	cout<<"numPlayers = "<<numPlayers<<endl;
	cout<<"expected to return "<<trackMoves<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==trackMoves)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test7(){
	int _die1[]={1,1,1,1,1,1};
	vector<int> die1(_die1+0,_die1+sizeof(_die1)/sizeof(int));
	int _die2[]={1,1,1,2,1,1};
	vector<int> die2(_die2+0,_die2+sizeof(_die2)/sizeof(int));
	int numPlayers=2;
	int _trackMoves[]= { 34,  6 };
	vector<int> trackMoves(_trackMoves+0,_trackMoves+sizeof(_trackMoves)/sizeof(int));
	BoardGame _BoardGame;
	vector<int> ret=_BoardGame.trackMoves(die1,die2,numPlayers);
	cout<<"--------------------test 7--------------------"<<endl;
	cout<<"die1 = "<<die1<<endl;
	cout<<"die2 = "<<die2<<endl;
	cout<<"numPlayers = "<<numPlayers<<endl;
	cout<<"expected to return "<<trackMoves<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==trackMoves)
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
