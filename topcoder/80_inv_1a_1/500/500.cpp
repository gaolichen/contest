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


class Nestings{
public:
	int howDeep(string nested){
		int i,j,flag=0,count,max;
		int sk[100],temp[100];
		for(i=j=0;i<nested.length();i++){
			if(nested[i]=='/'){
				sk[j++]=4;
				if(i+1>=nested.length()||nested[i+1]!='*')
					return -1;
				i++;
			}
			else if(nested[i]=='*'){
				sk[j++]=-4;
				if(i+1>=nested.length()||nested[i+1]!='/')
					return -1;
				i++;
			}
			else if(nested[i]=='(')
				sk[j++]=1;
			else if(nested[i]==')')
				sk[j++]=-1;
			else if(nested[i]=='[')
				sk[j++]=2;
			else if(nested[i]==']')
				sk[j++]=-2;
			else if(nested[i]=='{')
				sk[j++]=3;
			else if(nested[i]=='}')
				sk[j++]=-3;
			else if(nested[i]=='<')
				sk[j++]=5;
			else if(nested[i]=='>')
				sk[j++]=-5;
		}
//		for(i=0;i<j;i++)
//			cout<<sk[i]<<' ';
//		cout<<endl;
		count=j;
		j=0;max=0;
		for(i=0;i<count;i++){
			if(sk[i]>0){
				temp[j++]=sk[i];
				if(j>max)max=j;
			}
			else {
				j--;
				if(j<0||temp[j]+sk[i]!=0)
					return -1;
			}
		}
		if(j)return -1;
		return max;
	}
};




void test0(){
	string nested="";
	int howDeep= 0;
	Nestings _Nestings;
	int ret=_Nestings.howDeep(nested);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"nested = "<<nested<<endl;
	cout<<"expected to return "<<howDeep<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howDeep)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string nested="<(A)(b)>";
	int howDeep= 2;
	Nestings _Nestings;
	int ret=_Nestings.howDeep(nested);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"nested = "<<nested<<endl;
	cout<<"expected to return "<<howDeep<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howDeep)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string nested="(/*/)";
	int howDeep= -1;
	Nestings _Nestings;
	int ret=_Nestings.howDeep(nested);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"nested = "<<nested<<endl;
	cout<<"expected to return "<<howDeep<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howDeep)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string nested="<<<</**/asdf>>>>";
	int howDeep= 5;
	Nestings _Nestings;
	int ret=_Nestings.howDeep(nested);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"nested = "<<nested<<endl;
	cout<<"expected to return "<<howDeep<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howDeep)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string nested="abcd(A(B(C(D)C)B)A)abcd";
	int howDeep= 4;
	Nestings _Nestings;
	int ret=_Nestings.howDeep(nested);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"nested = "<<nested<<endl;
	cout<<"expected to return "<<howDeep<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howDeep)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string nested="([)]";
	int howDeep= -1;
	Nestings _Nestings;
	int ret=_Nestings.howDeep(nested);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"nested = "<<nested<<endl;
	cout<<"expected to return "<<howDeep<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howDeep)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test6(){
	string nested="([{/**/}])";
	int howDeep= 4;
	Nestings _Nestings;
	int ret=_Nestings.howDeep(nested);
	cout<<"--------------------test 6--------------------"<<endl;
	cout<<"nested = "<<nested<<endl;
	cout<<"expected to return "<<howDeep<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howDeep)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test7(){
	string nested="(";
	int howDeep= -1;
	Nestings _Nestings;
	int ret=_Nestings.howDeep(nested);
	cout<<"--------------------test 7--------------------"<<endl;
	cout<<"nested = "<<nested<<endl;
	cout<<"expected to return "<<howDeep<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howDeep)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test8(){
	string nested="][";
	int howDeep= -1;
	Nestings _Nestings;
	int ret=_Nestings.howDeep(nested);
	cout<<"--------------------test 8--------------------"<<endl;
	cout<<"nested = "<<nested<<endl;
	cout<<"expected to return "<<howDeep<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howDeep)
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
	test8();
	return 0;
}
