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


class StringFold{
public:
	string foldString(string o){
		int i,j,r[100],c[100];
		for(i=0;i<o.length();i++)
			r[i]=i;
		int flag=1;
		memset(c,0,sizeof(c));
		for(i=1;i<o.length();i++)
			if(o[i]==o[i-1]){
				flag*=-1;
				for(j=i;j<o.length();j++){
					r[j]=r[i-1]+(j-i)*flag;
					c[j]++;
				}
			}
		string ret;
		int l=o.length();
		for(i=-l;i<l;i++)
			for(j=l-1;j>=0;j--)
				if(r[j]==i){
//					cout<<"kaka"<<endl;
					if(c[j]%2){
						if(o[j]>='A'&&o[j]<='Z')
							o[j]=o[j]-'A'+'a';
						else o[j]=o[j]-'a'+'A';
					}
					ret+=o[j];
					break;
				}
		return ret;
	}
};




void test0(){
	string original="ABBCD";
	string foldString= "dcb";
	StringFold _StringFold;
	string ret=_StringFold.foldString(original);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"original = "<<original<<endl;
	cout<<"expected to return "<<foldString<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==foldString)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string original="acccdee";
	string foldString= "acdE";
	StringFold _StringFold;
	string ret=_StringFold.foldString(original);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"original = "<<original<<endl;
	cout<<"expected to return "<<foldString<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==foldString)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string original="bcccddbb";
	string foldString= "bbD";
	StringFold _StringFold;
	string ret=_StringFold.foldString(original);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"original = "<<original<<endl;
	cout<<"expected to return "<<foldString<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==foldString)
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
