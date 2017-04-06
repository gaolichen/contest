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


class TCSchedule{
public:
	int ret,tot;
	int gp[20],s[20];
	void dfs(int k,int h,int res){
		if(k==tot){
			if(res>ret)ret=res;
			return;
		}
		for(int i=15;i<=17;i++)
			if(h+i+8>=(k+1)*24+7&&h+i+8<=(k+1)*24+14&&h+i+8<=gp[k+1]){
			if(s[i]!=-1&&h<=s[k]&&h+i>=s[k]+2)
				dfs(k+1,h+i+8,res+1);
			else dfs(k+1,h+i+8,res);
			}
	}
	int howMany(vector<int> getup,vector<int> srm){
		int i;
		ret=0;
		for(i=0;i<srm.size();i++){
			if(getup[i]==-1)
				getup[i]=14;
			gp[i]=getup[i]+(i)*24;
			if(srm[i]==-1)
				s[i]=-1;
			else
			s[i]=srm[i]+(i+1)*24;
		}
		gp[i]=(i+1)*24;
		tot=srm.size();
		for(i=7;i<=14&&i<=getup[0];i++)
			dfs(0,i,0);
		return ret;
	}
};




void test0(){
	int _getup[]={ 7,-1,12,-1,-1};
	vector<int> getup(_getup+0,_getup+sizeof(_getup)/sizeof(int));
	int _srm[]={ 2, 2, 2, 2,-1};
	vector<int> srm(_srm+0,_srm+sizeof(_srm)/sizeof(int));
	int howMany= 0;
	TCSchedule _TCSchedule;
	int ret=_TCSchedule.howMany(getup,srm);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"getup = "<<getup<<endl;
	cout<<"srm = "<<srm<<endl;
	cout<<"expected to return "<<howMany<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howMany)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int _getup[]={-1,13};
	vector<int> getup(_getup+0,_getup+sizeof(_getup)/sizeof(int));
	int _srm[]={-1,4};
	vector<int> srm(_srm+0,_srm+sizeof(_srm)/sizeof(int));
	int howMany= 1;
	TCSchedule _TCSchedule;
	int ret=_TCSchedule.howMany(getup,srm);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"getup = "<<getup<<endl;
	cout<<"srm = "<<srm<<endl;
	cout<<"expected to return "<<howMany<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howMany)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int _getup[]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	vector<int> getup(_getup+0,_getup+sizeof(_getup)/sizeof(int));
	int _srm[]={ 2, 3, 4, 2, 3, 4, 2, 3, 4, 2, 3, 4, 2, 3};
	vector<int> srm(_srm+0,_srm+sizeof(_srm)/sizeof(int));
	int howMany= 14;
	TCSchedule _TCSchedule;
	int ret=_TCSchedule.howMany(getup,srm);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"getup = "<<getup<<endl;
	cout<<"srm = "<<srm<<endl;
	cout<<"expected to return "<<howMany<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howMany)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int _getup[]={ 9,-1,-1,-1,-1,12,12,-1,-1,-1,-1,-1,10,-1};
	vector<int> getup(_getup+0,_getup+sizeof(_getup)/sizeof(int));
	int _srm[]={-1,-1,-1, 3,-1,-1,-1, 4, 4, 2,-1,-1,-1, 3};
	vector<int> srm(_srm+0,_srm+sizeof(_srm)/sizeof(int));
	int howMany= 3;
	TCSchedule _TCSchedule;
	int ret=_TCSchedule.howMany(getup,srm);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"getup = "<<getup<<endl;
	cout<<"srm = "<<srm<<endl;
	cout<<"expected to return "<<howMany<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howMany)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int _getup[]={-1,13,10,-1,-1};
	vector<int> getup(_getup+0,_getup+sizeof(_getup)/sizeof(int));
	int _srm[]={-1, 2,-1,-1,-1};
	vector<int> srm(_srm+0,_srm+sizeof(_srm)/sizeof(int));
	int howMany= 0;
	TCSchedule _TCSchedule;
	int ret=_TCSchedule.howMany(getup,srm);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"getup = "<<getup<<endl;
	cout<<"srm = "<<srm<<endl;
	cout<<"expected to return "<<howMany<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howMany)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	int _getup[]={-1,-1,12,-1,-1,-1,-1,-1,-1,-1, 7,-1,-1,-1};
	vector<int> getup(_getup+0,_getup+sizeof(_getup)/sizeof(int));
	int _srm[]={ 3, 3, 3,-1, 2,-1, 3, 3, 4, 3, 4, 2, 3, 2};
	vector<int> srm(_srm+0,_srm+sizeof(_srm)/sizeof(int));
	int howMany= 3;
	TCSchedule _TCSchedule;
	int ret=_TCSchedule.howMany(getup,srm);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"getup = "<<getup<<endl;
	cout<<"srm = "<<srm<<endl;
	cout<<"expected to return "<<howMany<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howMany)
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
