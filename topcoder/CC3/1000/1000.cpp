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


class NENE{
public:
	vector<string> dic;
	void init(string a,string b,char c,char d){
		if(a.length()==10||b.length()==10){
//			dic.push_back(a);
			dic.push_back(b);
			return;
		}
//		dic.push_back(a);
		string tmp;
		if(a.length()==b.length()){
			if(c=='E'||c=='W')tmp=d+a;
			else tmp=c+b;
		}
		else if(a.length()<b.length()){
			tmp=c+b;
		}
		else{
			tmp=d+a;	
		}
		init(a,tmp,c,d);
		init(tmp,b,c,d);
	}
	int myfind(string a){
		int i;
		for(i=0;i<dic.size();i++)
			if(dic[i]==a)return i;
		return -1;
	}
	string vulnerable(vector<string> cw,vector<string> ccw){
		init("E","N",'E','N');
//		dic.pop_back();
		init("N","W",'N','W');
//		dic.pop_back();
		init("W","S",'W','S');
//		dic.pop_back();
		init("S","E",'S','E');
//		dic.pop_back();
		int i,j,k;
		vector<int> a,b;
//		for(i=0;i<10;i++)
//			cout<<dic[i]<<endl;
		for(i=0;i<cw.size();i++){
			j=myfind(cw[i]);
//			if(j==0)j=dic.size();
			a.push_back(j);
//			cout<<j<<' ';
			j=myfind(ccw[i]);
//			if(j==0)j=dic.size();
			b.push_back(j);
//			cout<<j<<endl;
		}
		for(i=0;i<a.size();i++){
			if(a[i]>b[i]||a[i]==0||b[i]==0)break;
		}
		if(i==a.size())return dic[0];
		int ret=dic.size()+1;
		for(i=0;i<a.size();i++){
			j=a[i]-1;
			if(j<0)j=dic.size()-1;
			if(j>=dic.size())j=0;
//			cout<<j<<endl;
			if(j<ret){
				for(k=0;k<a.size();k++){
					if(a[k]<=b[k]){
						if(a[k]<=j&&j<=b[k])break;
					}
					else {
						if(j>=a[k]||j<=b[k])break;
					}
				}
				if(k==a.size())ret=j;
			}
			j=b[i]+1;
			if(j<0)j=dic.size()-1;
			if(j>=dic.size())j=0;
//			cout<<j<<endl;
			if(j<ret){
				for(k=0;k<a.size();k++){
					if(a[k]<=b[k]){
						if(a[k]<=j&&j<=b[k])break;
					}
					else {
						if(j>=a[k]||j<=b[k])break;
					}
				}
				if(k==a.size())ret=j;
			}
		}
		if(ret==dic.size()+1)return "SAFE";
		if(ret==dic.size())ret=0;
		return dic[ret];
	}
};




void test0(){
	string _cw[]={"E"};
	vector<string> cw(_cw+0,_cw+sizeof(_cw)/sizeof(string));
	string _ccw[]={"W"};
	vector<string> ccw(_ccw+0,_ccw+sizeof(_ccw)/sizeof(string));
	string vulnerable= "WWWWWWWWSW";
	NENE _NENE;
	string ret=_NENE.vulnerable(cw,ccw);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"cw = "<<cw<<endl;
	cout<<"ccw = "<<ccw<<endl;
	cout<<"expected to return "<<vulnerable<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==vulnerable)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _cw[]={"E","E","SE"};
	vector<string> cw(_cw+0,_cw+sizeof(_cw)/sizeof(string));
	string _ccw[]={"W","N","S"};
	vector<string> ccw(_ccw+0,_ccw+sizeof(_ccw)/sizeof(string));
	string vulnerable= "SSSSSSSSSE";
	NENE _NENE;
	string ret=_NENE.vulnerable(cw,ccw);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"cw = "<<cw<<endl;
	cout<<"ccw = "<<ccw<<endl;
	cout<<"expected to return "<<vulnerable<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==vulnerable)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _cw[]={"E","WWWWWWWWSW"};
	vector<string> cw(_cw+0,_cw+sizeof(_cw)/sizeof(string));
	string _ccw[]={"W","NE"};
	vector<string> ccw(_ccw+0,_ccw+sizeof(_ccw)/sizeof(string));
	string vulnerable= "SAFE";
	NENE _NENE;
	string ret=_NENE.vulnerable(cw,ccw);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"cw = "<<cw<<endl;
	cout<<"ccw = "<<ccw<<endl;
	cout<<"expected to return "<<vulnerable<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==vulnerable)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string _cw[]={"EEEENE","WNW","SSWWSW"};
	vector<string> cw(_cw+0,_cw+sizeof(_cw)/sizeof(string));
	string _ccw[]={"NNNNENEENE","WWNW","EEENE"};
	vector<string> ccw(_ccw+0,_ccw+sizeof(_ccw)/sizeof(string));
	string vulnerable= "NEENE";
	NENE _NENE;
	string ret=_NENE.vulnerable(cw,ccw);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"cw = "<<cw<<endl;
	cout<<"ccw = "<<ccw<<endl;
	cout<<"expected to return "<<vulnerable<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==vulnerable)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string _cw[]={"EEEEEEEENE","W"};
	vector<string> cw(_cw+0,_cw+sizeof(_cw)/sizeof(string));
	string _ccw[]=	{"WWWWWWWWNW","EEEEEEEESE"};
	vector<string> ccw(_ccw+0,_ccw+sizeof(_ccw)/sizeof(string));
	string vulnerable="E";
	NENE _NENE;
	string ret=_NENE.vulnerable(cw,ccw);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"cw = "<<cw<<endl;
	cout<<"ccw = "<<ccw<<endl;
	cout<<"expected to return "<<vulnerable<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==vulnerable)
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
