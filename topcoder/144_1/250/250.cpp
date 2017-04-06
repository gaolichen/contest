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
#include <strstream>
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
#define fo(a,b) for((a)=0;(a)<(b);(a)++)
#define inmat(i,j,m,n) ((i)>=0&&(i)<(m)&&(j)>=0&&(j)<(n))
#define cls(a) memset((a),0,sizeof(a))
#define VI vector<int>
#define V64 vector<i64>
#define VS vector<string>
#define VD vector<double>
int mx[8]={0,1,0,-1,1,1,-1,-1};
int my[8]={1,0,-1,0,1,-1,-1,1};
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


class BinaryCode{
public:
	vector<string> decode(string m){
		int i,j;
		VS ret;
		string tmp;
		if(m.size()==1){
			if(m=="0"){
				ret.push_back("0");
			}
			else if(m=="1")
				ret.push_back("1");
			return ret;
		}
		tmp="0";
		tmp+=m[0];
//		m+='0';
		if(tmp[1]<'0'||tmp[1]>'1'){
			ret.push_back("NONE");
		}
		else{
		for(i=1;i<m.size()-1;i++){
			tmp+=m[i]-(tmp[i]-'0')-(tmp[i-1]-'0');
			if(tmp[i+1]<'0'||tmp[i+1]>'1')break;
		}
//		tmp+=m[i]-tmp[i-1]+'0';
		if(i<m.size()-1)
			ret.push_back("NONE");
		else if(tmp[i]+tmp[i-1]-'0'!=m[m.size()-1]){
			ret.push_back("NONE");
		}
		else ret.push_back(tmp);
		}
		
		tmp="1";
		tmp+=m[0]-tmp[0]+'0';
//		m+='0';
		if(tmp[1]<'0'||tmp[1]>'1'){
			ret.push_back("NONE");
		}
		else{
		for(i=1;i<m.size()-1;i++){
			tmp+=m[i]-(tmp[i]-'0')-(tmp[i-1]-'0');
			if(tmp[i+1]<'0'||tmp[i+1]>'1')break;
		}
		if(i<m.size()-1)
			ret.push_back("NONE");
		
		else if(tmp[i]+tmp[i-1]-'0'!=m[m.size()-1]){
			ret.push_back("NONE");
		}
		else ret.push_back(tmp);
		}
		return ret;
	}
};




void test0(){
	string message="123210122";
	string _decode[]= { "011100011",  "NONE" };
	vector<string> decode(_decode+0,_decode+sizeof(_decode)/sizeof(string));
	BinaryCode _BinaryCode;
	vector<string> ret=_BinaryCode.decode(message);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"message = "<<message<<endl;
	cout<<"expected to return "<<decode<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==decode)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string message="11";
	string _decode[]= { "01",  "10" };
	vector<string> decode(_decode+0,_decode+sizeof(_decode)/sizeof(string));
	BinaryCode _BinaryCode;
	vector<string> ret=_BinaryCode.decode(message);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"message = "<<message<<endl;
	cout<<"expected to return "<<decode<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==decode)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string message="22111";
	string _decode[]= { "NONE",  "11001" };
	vector<string> decode(_decode+0,_decode+sizeof(_decode)/sizeof(string));
	BinaryCode _BinaryCode;
	vector<string> ret=_BinaryCode.decode(message);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"message = "<<message<<endl;
	cout<<"expected to return "<<decode<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==decode)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string message="123210120";
	string _decode[]= { "NONE",  "NONE" };
	vector<string> decode(_decode+0,_decode+sizeof(_decode)/sizeof(string));
	BinaryCode _BinaryCode;
	vector<string> ret=_BinaryCode.decode(message);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"message = "<<message<<endl;
	cout<<"expected to return "<<decode<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==decode)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string message="3";
	string _decode[]= { "NONE",  "NONE" };
	vector<string> decode(_decode+0,_decode+sizeof(_decode)/sizeof(string));
	BinaryCode _BinaryCode;
	vector<string> ret=_BinaryCode.decode(message);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"message = "<<message<<endl;
	cout<<"expected to return "<<decode<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==decode)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string message="12221112222221112221111111112221111";
	string _decode[]={ "01101001101101001101001001001101001", "10110010110110010110010010010110010" };
	vector<string> decode(_decode+0,_decode+sizeof(_decode)/sizeof(string));
	BinaryCode _BinaryCode;
	vector<string> ret=_BinaryCode.decode(message);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"message = "<<message<<endl;
	cout<<"expected to return "<<decode<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==decode)
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
