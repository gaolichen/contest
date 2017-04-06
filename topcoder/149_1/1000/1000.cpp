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


struct F{
	double a,b,c;
};
class GForce{
public:
	double areo(F f,double t){
		return f.a*t*t+f.b*t+f.c;
	}
	double calc(F f,int s,int t){
		double ret;
		ret=0;
		if(areo(f,(double)s)>ret)ret=areo(f,(double)s);
		if(areo(f,(double)t)>ret)ret=areo(f,(double)t);
		if(-f.b/(2.0*f.a)>=s&&-f.b/(2*f.a)<=t){
			if(areo(f,-f.b/(2.0*f.a))>ret)
				ret=areo(f,-f.b/(2.0*f.a));
		}
		return ret;
	}
	double avgAccel(int p,vector<int> a,vector<int> t){
		int i,j;
		double tmp,A,B;
		F f[11000];
		f[t[0]].a=f[t[0]].b=f[t[0]].c=0;
		for(i=0;i<t.size()-1;i++){
			tmp=f[t[i]].a*t[i]*t[i]+f[t[i]].b*t[i]+f[t[i]].c;
			A=(double)(a[i+1]-a[i])/(t[i+1]-t[i])*0.5;
			B=-(double)t[i]*(a[i+1]-a[i])/(t[i+1]-t[i])+a[i];
			for(j=t[i]+1;j<=t[i+1];j++){
				f[j].a=A;
				f[j].b=B;
				f[j].c=tmp-A*t[i]*t[i]-B*t[i];
			}
		}
//		for(i=0;i<t.size();i++)
//			cout<<f[t[i]].a<<' '<<f[t[i]].b<<' '<<f[t[i]].c<<endl;
		F ff;
		double ret=0;
		for(i=1;i+p<=t[t.size()-1];i++){
			ff.a=f[i+p].a-f[i].a;
			ff.b=f[i+p].b+2*f[i+p].a*p-f[i].b;
			ff.c=f[i+p].b*p+f[i+p].a*p*p+f[i+p].c-f[i].c;
			if(calc(ff,(double)i-1,(double)i)>ret)
				ret=calc(ff,(double)i-1,(double)i);
		}
		cout<<ret<<endl;
		return ret/p;
	}
};




void test0(){
	int period=100;
	int _accel[]={1500,1500,500,2000};
	vector<int> accel(_accel+0,_accel+sizeof(_accel)/sizeof(int));
	int _time[]={0,100,150,225};
	vector<int> time(_time+0,_time+sizeof(_time)/sizeof(int));
	double avgAccel= 1500.0;
	GForce _GForce;
	double ret=_GForce.avgAccel(period,accel,time);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"period = "<<period<<endl;
	cout<<"accel = "<<accel<<endl;
	cout<<"time = "<<time<<endl;
	cout<<"expected to return "<<avgAccel<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==avgAccel)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int period=500;
	int _accel[]={5,30,5};
	vector<int> accel(_accel+0,_accel+sizeof(_accel)/sizeof(int));
	int _time[]={0,1000,2000};
	vector<int> time(_time+0,_time+sizeof(_time)/sizeof(int));
	double avgAccel= 26.875;
	GForce _GForce;
	double ret=_GForce.avgAccel(period,accel,time);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"period = "<<period<<endl;
	cout<<"accel = "<<accel<<endl;
	cout<<"time = "<<time<<endl;
	cout<<"expected to return "<<avgAccel<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==avgAccel)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int period=11;
	int _accel[]={0,5,5,0,6};
	vector<int> accel(_accel+0,_accel+sizeof(_accel)/sizeof(int));
	int _time[]={0,5,15,25,31};
	vector<int> time(_time+0,_time+sizeof(_time)/sizeof(int));
	double avgAccel= 4.984848484848485;
	GForce _GForce;
	double ret=_GForce.avgAccel(period,accel,time);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"period = "<<period<<endl;
	cout<<"accel = "<<accel<<endl;
	cout<<"time = "<<time<<endl;
	cout<<"expected to return "<<avgAccel<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==avgAccel)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}
/*
int main(){
	test0();
	test1();
	test2();
	return 0;
}*/
