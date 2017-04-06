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


class NameSort{
public:
	string last(string s){
		int i,j=-1;
		for(i=0;i<s.length();i++)
			if(s[i]==' ')j=i;
		string ret;
		for(i=j+1;i<s.length();i++){
			if(s[i]>='a')
			ret+=s[i];
			else ret+=s[i]-'A'+'a';
		}
		return ret;
	}
	vector<string> newList(vector<string> list){
		int i,j,k;
		vector<string> ret;
		string tmp,ans;
		char mark[100];
		memset(mark,0,sizeof(mark));
		for(i=0;i<list.size();i++){
			for(j=list.size()-1,k=-1;j>=0;j--)
				if(!mark[j]){
					if(k==-1){
						k=j;
						ans=last(list[j]);
					}
					else{
						tmp=last(list[j]);
						if(tmp<ans){
							ans=tmp;
							k=j;
						}
					}
				}
				ret.push_back(list[k]);
				mark[k]=1;
		}
		return ret;
	}
};




void test0(){
	string _list[]={"Tom Jones","ADAMS","BOB ADAMS","Tom Jones","STEVE jONeS"};
	vector<string> list(_list+0,_list+sizeof(_list)/sizeof(string));
	string _newList[]= { "BOB ADAMS",  "ADAMS",  "STEVE jONeS",  "Tom Jones",  "Tom Jones" };
	vector<string> newList(_newList+0,_newList+sizeof(_newList)/sizeof(string));
	NameSort _NameSort;
	vector<string> ret=_NameSort.newList(list);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"list = "<<list<<endl;
	cout<<"expected to return "<<newList<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==newList)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _list[]={"C A R Hoare","Kenny G","A DeForest Hoar","Kenny Gee"};
	vector<string> list(_list+0,_list+sizeof(_list)/sizeof(string));
	string _newList[]= { "Kenny G",  "Kenny Gee",  "A DeForest Hoar",  "C A R Hoare" };
	vector<string> newList(_newList+0,_newList+sizeof(_newList)/sizeof(string));
	NameSort _NameSort;
	vector<string> ret=_NameSort.newList(list);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"list = "<<list<<endl;
	cout<<"expected to return "<<newList<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==newList)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _list[]={"Trudy","Trudy","TRUDY"};
	vector<string> list(_list+0,_list+sizeof(_list)/sizeof(string));
	string _newList[]= { "TRUDY",  "Trudy",  "Trudy" };
	vector<string> newList(_newList+0,_newList+sizeof(_newList)/sizeof(string));
	NameSort _NameSort;
	vector<string> ret=_NameSort.newList(list);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"list = "<<list<<endl;
	cout<<"expected to return "<<newList<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==newList)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string _list[]={"tIm JoNeS", "Tim Jones", "tom JoNes", "tim joness", "tiM joneS"};
	vector<string> list(_list+0,_list+sizeof(_list)/sizeof(string));
	string _newList[]= { "tiM joneS",  "tom JoNes",  "Tim Jones",  "tIm JoNeS",  "tim joness" };
	vector<string> newList(_newList+0,_newList+sizeof(_newList)/sizeof(string));
	NameSort _NameSort;
	vector<string> ret=_NameSort.newList(list);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"list = "<<list<<endl;
	cout<<"expected to return "<<newList<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==newList)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string _list[]={"Alan","aLan","alAn","alaN","ALan","AlAn","AlaN","aLAn","aLaN","alAN"};
	vector<string> list(_list+0,_list+sizeof(_list)/sizeof(string));
	string _newList[]={ "alAN", "aLaN", "aLAn", "AlaN", "AlAn", "ALan", "alaN", "alAn", "aLan", "Alan" };
	vector<string> newList(_newList+0,_newList+sizeof(_newList)/sizeof(string));
	NameSort _NameSort;
	vector<string> ret=_NameSort.newList(list);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"list = "<<list<<endl;
	cout<<"expected to return "<<newList<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==newList)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string _list[]={"Al Thompson","Bob Johnson", "John Thompson", "John D Thompson","Bob D Johnson"};
	vector<string> list(_list+0,_list+sizeof(_list)/sizeof(string));
	string _newList[]={ "Bob D Johnson", "Bob Johnson", "John D Thompson", "John Thompson", "Al Thompson" };
	vector<string> newList(_newList+0,_newList+sizeof(_newList)/sizeof(string));
	NameSort _NameSort;
	vector<string> ret=_NameSort.newList(list);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"list = "<<list<<endl;
	cout<<"expected to return "<<newList<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==newList)
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
