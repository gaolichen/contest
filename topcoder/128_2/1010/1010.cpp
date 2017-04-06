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


class Indentation{
public:
	int countBlocks(vector<string> lines){
		int i,j,flag[100],t;
		string temp;
		char ch;
		for(i=0;i<lines.size();i++){
			for(j=0;j<lines[i].length();j++)
				if(lines[i][j]=='#')break;
			if(j==lines[i].length())continue;
			if(j<lines[i].length()-1&&lines[i][j+1]=='#')
				flag[i]=1;
			else flag[i]=0;
			temp="";
			for(t=0;t<j;t++){
				temp+=lines[i][j];
			}
			lines[i]=temp;
		}
		i=0;
		int count=-1;
		t=0;
		vector<string> ll;
		for(j=i=0;j<lines.size();j++){
			if(t)
				ll[count]+=lines[j];
			else {
				ll.push_back(lines[j]);
				count++;
			}
			if(flag[j]==0){
				t=0;
				continue;
			}
			else if(flag[j]&&!t){t=1;}
		}
		for(i=0;i<count;i++)
			cout<<lines[i]<<endl;
		i=-1;
		vector<string> tt;
		for(j=0;j<count;j++){
			for(t=0;t<ll[j].length();t++)
				if(ll[j][t]!=' ')break;
			if(t!=ll[j].length()){
				i++;
				tt.push_back(ll[j]);
			}
		}
//		for(i=0;i<ll.size();i++)
//			cout<<ll[i]<<endl;
		int pop=0,sk[100],ret=0,a=0;
		sk[0]=-1;
		for(i=0;i<tt.size();i++){
			for(j=0;j<tt[i].length();j++)
				if(tt[i][j]!=' ')break;
				if(j>sk[pop]){
					ret++;
					sk[++pop]=j;
				}
				else if(j==sk[pop]){
					continue;
				}
				else if(j<sk[pop]){
					pop--;
					a=1;
				}
		}
		return ret;
	}
};




void test0(){
	string _lines[]={ "function fact n is",  "  if n equals 0 then",  "    return 0",  "  else",  "    return n times fact n minus 1" };
	vector<string> lines(_lines+0,_lines+sizeof(_lines)/sizeof(string));
	int countBlocks= 4;
	Indentation _Indentation;
	int ret=_Indentation.countBlocks(lines);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"lines = "<<lines<<endl;
	cout<<"expected to return "<<countBlocks<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==countBlocks)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _lines[]={ "function gcd of a and b is",  "    # greatest common divisor",  "  if b is 0 then ## base case",  "    return a",  "  else return gcd b and a mod b" };
	vector<string> lines(_lines+0,_lines+sizeof(_lines)/sizeof(string));
	int countBlocks= 2;
	Indentation _Indentation;
	int ret=_Indentation.countBlocks(lines);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"lines = "<<lines<<endl;
	cout<<"expected to return "<<countBlocks<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==countBlocks)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _lines[]={ "  while neither current nor parent is null",  "      grandparent is parent of parent",  "      set parent of current to grandparent",  "     set current to grandparent" };
	vector<string> lines(_lines+0,_lines+sizeof(_lines)/sizeof(string));
	int countBlocks= -1;
	Indentation _Indentation;
	int ret=_Indentation.countBlocks(lines);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"lines = "<<lines<<endl;
	cout<<"expected to return "<<countBlocks<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==countBlocks)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string _lines[]={ "  test multiline comments",  " ## space 1",  " ## space 2",  "second line in block" };
	vector<string> lines(_lines+0,_lines+sizeof(_lines)/sizeof(string));
	int countBlocks= 1;
	Indentation _Indentation;
	int ret=_Indentation.countBlocks(lines);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"lines = "<<lines<<endl;
	cout<<"expected to return "<<countBlocks<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==countBlocks)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string _lines[]={ "# this program",  "## is completely",  "# empty" };
	vector<string> lines(_lines+0,_lines+sizeof(_lines)/sizeof(string));
	int countBlocks= 0;
	Indentation _Indentation;
	int ret=_Indentation.countBlocks(lines);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"lines = "<<lines<<endl;
	cout<<"expected to return "<<countBlocks<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==countBlocks)
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
