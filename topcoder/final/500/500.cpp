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

int mx[8]={1,1,1,-1,-1,-1,0,0};
int my[8]={1,-1,0,1,0,-1,1,-1};

int c,l;
vector<string> ff;
int check(int x,int y,int k){
	if(x+mx[k]<0||x+mx[k]>=l||y+my[k]<0||y+my[k]>=c)
		return 0;
	if(ff[x+mx[k]][y+my[k]]=='X'||ff[x][y+my[k]]=='X'||ff[x+mx[k]][y]=='X')return 0;
	return 1;
}

class Robot{
public:
	int getProb(vector<string> f,int x,int y,int t){
		int i,j,k,cnt;
		double p[60][60],tmp[60][60];
		memset(p,0,sizeof(p));
		for(i=0;i<f.size();i++)
			for(j=0;j<f[0].length();j++)
				if(f[i][j]=='R')p[i][j]=1000.0;
		l=f.size();
		ff=f;
		c=f[0].length();
		while(t--){
			memset(tmp,0,sizeof(tmp));
			for(i=0;i<f.size();i++)
				for(j=0;j<f[0].length();j++){
					for(k=cnt=0;k<8;k++){
						if(check(i,j,k))
//							cnt++;
//					for(k=0;k<8;k++)
//						if(check(i,j,k))
							tmp[i+mx[k]][j+my[k]]+=p[i][j]*0.125;
						else tmp[i][j]+=p[i][j]*0.125;
					}
				}
			memcpy(p,tmp,sizeof(tmp));
		}
		cout<<p[y][x]<<endl;
		return (int)(p[y][x]);
	}
};




void test0(){
	string _floor[]={"R.XX", "..XX", "..XX", "...."};
	vector<string> floor(_floor+0,_floor+sizeof(_floor)/sizeof(string));
	int x=3;
	int y=3;
	int time=7;
	int getProb= 1;
	Robot _Robot;
	int ret=_Robot.getProb(floor,x,y,time);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"floor = "<<floor<<endl;
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
	cout<<"time = "<<time<<endl;
	cout<<"expected to return "<<getProb<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getProb)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

int main(){
	test0();
	return 0;
}
