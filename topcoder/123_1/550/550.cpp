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


class TypingJob{
public:
	int tot,size;
	int mm[20],ans;
	int mark[20];
	void dfs(int k,int t[3]){
		if(k==size){
			int res;
			res=t[0];
			if(t[1]>res)res=t[1];
			if(t[2]>res)res=t[2];
			if(res<ans)ans=res;
			return ;
		}
		for(mark[k]=0;mark[k]<3;mark[k]++){
			t[mark[k]]+=mm[k];
			dfs(k+1,t);
			t[mark[k]]-=mm[k];
		}
	}
	int bestTime(vector<int> pages){
		int i,temp[3];
		tot=0;
		for(i=0;i<pages.size();i++){
			mm[i]=pages[i];
			tot+=pages[i];
		}
		size=pages.size();
		memset(mark,0,sizeof(mark));
		ans=10000000;
		temp[0]=temp[1]=temp[2]=0;
		dfs(0,temp);
		return ans;
	}
};




void test0(){
	int _pages[]={38};
	vector<int> pages(_pages+0,_pages+sizeof(_pages)/sizeof(int));
	int bestTime= 38;
	TypingJob _TypingJob;
	int ret=_TypingJob.bestTime(pages);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"pages = "<<pages<<endl;
	cout<<"expected to return "<<bestTime<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestTime)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int _pages[]={15,10,5,7,8};
	vector<int> pages(_pages+0,_pages+sizeof(_pages)/sizeof(int));
	int bestTime= 15;
	TypingJob _TypingJob;
	int ret=_TypingJob.bestTime(pages);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"pages = "<<pages<<endl;
	cout<<"expected to return "<<bestTime<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestTime)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int _pages[]={100,100,100,100,100,100,100,100,100,100};
	vector<int> pages(_pages+0,_pages+sizeof(_pages)/sizeof(int));
	int bestTime= 400;
	TypingJob _TypingJob;
	int ret=_TypingJob.bestTime(pages);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"pages = "<<pages<<endl;
	cout<<"expected to return "<<bestTime<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestTime)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int _pages[]={1,2,3,4,5};
	vector<int> pages(_pages+0,_pages+sizeof(_pages)/sizeof(int));
	int bestTime= 5;
	TypingJob _TypingJob;
	int ret=_TypingJob.bestTime(pages);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"pages = "<<pages<<endl;
	cout<<"expected to return "<<bestTime<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestTime)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int _pages[]={1,2,3,4,5,6,7};
	vector<int> pages(_pages+0,_pages+sizeof(_pages)/sizeof(int));
	int bestTime= 10;
	TypingJob _TypingJob;
	int ret=_TypingJob.bestTime(pages);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"pages = "<<pages<<endl;
	cout<<"expected to return "<<bestTime<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestTime)
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
