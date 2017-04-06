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


int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
class MineMapper{
public:
	int size,len;
	int check(int x,int y,int k){
		if(x+dx[k]<0|||x+dx[k]>=size||y+dy[k]<0||y+dy[k]>=len)
			return 0;
	}
	int numClear(vector<string> lay){
		int i,j;
		size=lay.size();
		len=lay.len();
		memset(mark,0,sizeof(mark));
		memset(done,0,sizeof(done));
		for(i=0;i<lay.size();i++)
			for(j=0;j<lay[i].length();j++)
				if(lay[i][j]=='-'){
					tot[i][j]=0;
					for(k=0;k<4;k++)
						if(check(i,j,k)){
							if(lay[i+dx[k]][j+dy[k]]=='M')
								tot[i][j]++;
							done[i][j]++;
						}
					if(done[i][j]==4)lay[i][j]='M';
				}
		int ret=0;
	}
};




void test0(){
	string _layout[]={"-M-","---","---"};
	vector<string> layout(_layout+0,_layout+sizeof(_layout)/sizeof(string));
	int numClear= 1;
	MineMapper _MineMapper;
	int ret=_MineMapper.numClear(layout);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"layout = "<<layout<<endl;
	cout<<"expected to return "<<numClear<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numClear)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _layout[]={"--M-","-MM-","----","----"};
	vector<string> layout(_layout+0,_layout+sizeof(_layout)/sizeof(string));
	int numClear= 13;
	MineMapper _MineMapper;
	int ret=_MineMapper.numClear(layout);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"layout = "<<layout<<endl;
	cout<<"expected to return "<<numClear<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numClear)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _layout[]={"-----","-----","--M-M","-M---","---M-"};
	vector<string> layout(_layout+0,_layout+sizeof(_layout)/sizeof(string));
	int numClear= 18;
	MineMapper _MineMapper;
	int ret=_MineMapper.numClear(layout);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"layout = "<<layout<<endl;
	cout<<"expected to return "<<numClear<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==numClear)
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
