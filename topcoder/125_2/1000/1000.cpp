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


class TurnFinder{
public:
	string turnAngle(string p1,string p2,string p3){
		int i;
		float x1,x2,x3,y1,y2,y3;
		sscanf(p1.c_str(),"%f:%f",&x1,&y1);
		sscanf(p2.c_str(),"%f:%f",&x2,&y2);
		sscanf(p3.c_str(),"%f:%f",&x3,&y3);
		float ang=0.0;
		ang=(x2-x1)*(x3-x2)+(y2-y1)*(y3-y2);
		ang/=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))*sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
		float t;
		t=(x2-x1)*(y3-y2)-(y2-y1)*(x3-x2);
		string ret;
		i=(int)(acos(ang)*180.0/acos(-1.0)+0.5);
		string dir="RIGHT";
		char buf[100];
		if(t>0)dir="LEFT";
		i=abs(i);
		if(i<10){
			ret="CONTINUE";
			return ret;
		}
		sprintf(buf,"%d",i);
		if(i>=10&&i<60){
			ret+="TURN SLIGHT ";
			ret+=dir;
			ret+=':';
			ret+=buf;
			return ret;
		}
		if(i>=60&&i<120){
			ret+="TURN ";
			ret+=dir;
			ret+=':';
			ret+=buf;
			return ret;
		}
		if(i>=120&&i<170){
			ret+="TURN SHARP ";
			ret+=dir;
			ret+=':';
			ret+=buf;
			return ret;
		}
		ret+="U-TURN";
		return ret;
	}
};




void test0(){
	string p1="0:0";
	string p2="0:3";
	string p3="3:3";
	string turnAngle= "TURN RIGHT:90";
	TurnFinder _TurnFinder;
	string ret=_TurnFinder.turnAngle(p1,p2,p3);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"p1 = "<<p1<<endl;
	cout<<"p2 = "<<p2<<endl;
	cout<<"p3 = "<<p3<<endl;
	cout<<"expected to return "<<turnAngle<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==turnAngle)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string p1="47:32";
	string p2="20:80";
	string p3="-5:0";
	string turnAngle= "TURN SHARP LEFT:133";
	TurnFinder _TurnFinder;
	string ret=_TurnFinder.turnAngle(p1,p2,p3);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"p1 = "<<p1<<endl;
	cout<<"p2 = "<<p2<<endl;
	cout<<"p3 = "<<p3<<endl;
	cout<<"expected to return "<<turnAngle<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==turnAngle)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string p1="0:0";
	string p2="20:20";
	string p3="50:50";
	string turnAngle= "CONTINUE";
	TurnFinder _TurnFinder;
	string ret=_TurnFinder.turnAngle(p1,p2,p3);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"p1 = "<<p1<<endl;
	cout<<"p2 = "<<p2<<endl;
	cout<<"p3 = "<<p3<<endl;
	cout<<"expected to return "<<turnAngle<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==turnAngle)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string p1="0:0";
	string p2="50:50";
	string p3="0:0";
	string turnAngle= "U-TURN";
	TurnFinder _TurnFinder;
	string ret=_TurnFinder.turnAngle(p1,p2,p3);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"p1 = "<<p1<<endl;
	cout<<"p2 = "<<p2<<endl;
	cout<<"p3 = "<<p3<<endl;
	cout<<"expected to return "<<turnAngle<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==turnAngle)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string p1="50:50";
	string p2="30:30";
	string p3="20:-5";
	string turnAngle= "TURN SLIGHT LEFT:29";
	TurnFinder _TurnFinder;
	string ret=_TurnFinder.turnAngle(p1,p2,p3);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"p1 = "<<p1<<endl;
	cout<<"p2 = "<<p2<<endl;
	cout<<"p3 = "<<p3<<endl;
	cout<<"expected to return "<<turnAngle<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==turnAngle)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string p1="0:0";
	string p2="0:10";
	string p3="-19:9";
	string turnAngle= "TURN LEFT:93";
	TurnFinder _TurnFinder;
	string ret=_TurnFinder.turnAngle(p1,p2,p3);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"p1 = "<<p1<<endl;
	cout<<"p2 = "<<p2<<endl;
	cout<<"p3 = "<<p3<<endl;
	cout<<"expected to return "<<turnAngle<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==turnAngle)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test6(){
	string p1="0:0";
	string p2="0:10";
	string p3="1:6";
	string turnAngle= "TURN SHARP RIGHT:166";
	TurnFinder _TurnFinder;
	string ret=_TurnFinder.turnAngle(p1,p2,p3);
	cout<<"--------------------test 6--------------------"<<endl;
	cout<<"p1 = "<<p1<<endl;
	cout<<"p2 = "<<p2<<endl;
	cout<<"p3 = "<<p3<<endl;
	cout<<"expected to return "<<turnAngle<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==turnAngle)
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
	return 0;
}
