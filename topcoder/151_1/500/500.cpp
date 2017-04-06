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


class MergeSort{
public:
	int mer(VI b,VI c){
		int ret=0;
		VI a;
		while(b.size()&&c.size()){
			if(b[0]<c[0]){
				a.push_back(b[0]);
				ret++;
				b=VI(&b[1],&b[b.size()]);
			}
			else if(b[0]>c[0]){
				ret++;
				a.push_back(c[0]);
				c=VI(&c[1],&c[c.size()]);
			}
			else{
				ret++;
				a.push_back(b[0]);
				a.push_back(c[0]);
				c=VI(&c[1],&c[c.size()]);
				b=VI(&b[1],&b[b.size()]);
			}
		}
		if(b.size()){
			int i;
			for(i=0;i<b.size();i++)
				a.push_back(b[i]);
		}
		else if(c.size()){
			int i;
			for(i=0;i<c.size();i++)
				a.push_back(c[i]);
		}
		return ret;
		return 1;
	}
	int mysort(VI n){
		if(n.size()<=1)return 0;
		VI b,c;
		if(n.size()%2==0){
			b=VI(&n[0],&n[n.size()/2]);
			c=VI(&n[n.size()/2],&n[n.size()]);
		}
		else{
			b=VI(&n[0],&n[n.size()/2]);
			c=VI(&n[n.size()/2],&n[n.size()]);
		}
		int ret;
		ret=mysort(b);
		ret+=mysort(c);
		ret+=mer(b,c);
		return ret;
	}
	int howManyComparisons(vector<int> n){
		return mysort(n);
	}
};




void test0(){
	int _numbers[]={1, 2, 3, 4};
	vector<int> numbers(_numbers+0,_numbers+sizeof(_numbers)/sizeof(int));
	int howManyComparisons= 4;
	MergeSort _MergeSort;
	int ret=_MergeSort.howManyComparisons(numbers);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"numbers = "<<numbers<<endl;
	cout<<"expected to return "<<howManyComparisons<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howManyComparisons)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int _numbers[]={2, 3, 2};
	vector<int> numbers(_numbers+0,_numbers+sizeof(_numbers)/sizeof(int));
	int howManyComparisons= 2;
	MergeSort _MergeSort;
	int ret=_MergeSort.howManyComparisons(numbers);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"numbers = "<<numbers<<endl;
	cout<<"expected to return "<<howManyComparisons<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howManyComparisons)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int _numbers[]={-17};
	vector<int> numbers(_numbers+0,_numbers+sizeof(_numbers)/sizeof(int));
	int howManyComparisons= 0;
	MergeSort _MergeSort;
	int ret=_MergeSort.howManyComparisons(numbers);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"numbers = "<<numbers<<endl;
	cout<<"expected to return "<<howManyComparisons<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howManyComparisons)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	vector<int> numbers(0);
	int howManyComparisons= 0;
	MergeSort _MergeSort;
	int ret=_MergeSort.howManyComparisons(numbers);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"numbers = "<<numbers<<endl;
	cout<<"expected to return "<<howManyComparisons<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howManyComparisons)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int _numbers[]={-2000000000,2000000000,0,0,0,-2000000000,2000000000,0,0,0};
	vector<int> numbers(_numbers+0,_numbers+sizeof(_numbers)/sizeof(int));
	int howManyComparisons= 19;
	MergeSort _MergeSort;
	int ret=_MergeSort.howManyComparisons(numbers);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"numbers = "<<numbers<<endl;
	cout<<"expected to return "<<howManyComparisons<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==howManyComparisons)
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

/* [{50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}]
    EXPECTED: 153
    RECEIVED: 133*/