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

#define K /
#define A *


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


class NumberGuessing{
public:
	void dfs(int k,int n){
		if(k==n){
			return ;
		}
		;
	}
	int bestGuess(int r,vector<int> g,int n){
		return 1;
	}
};




void test0(){
	int range=1000;
	int _guesses[]={500};
	vector<int> guesses(_guesses+0,_guesses+sizeof(_guesses)/sizeof(int));
	int numLeft=1;
	int bestGuess= 501;
	NumberGuessing _NumberGuessing;
	int ret=_NumberGuessing.bestGuess(range,guesses,numLeft);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"range = "<<range<<endl;
	cout<<"guesses = "<<guesses<<endl;
	cout<<"numLeft = "<<numLeft<<endl;
	cout<<"expected to return "<<bestGuess<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestGuess)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int range=1000000;
	vector<int> guesses(0);
	int numLeft=1;
	int bestGuess= 500000;
	NumberGuessing _NumberGuessing;
	int ret=_NumberGuessing.bestGuess(range,guesses,numLeft);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"range = "<<range<<endl;
	cout<<"guesses = "<<guesses<<endl;
	cout<<"numLeft = "<<numLeft<<endl;
	cout<<"expected to return "<<bestGuess<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestGuess)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int range=1000;
	vector<int> guesses(0);
	int numLeft=2;
	int bestGuess= 750;
	NumberGuessing _NumberGuessing;
	int ret=_NumberGuessing.bestGuess(range,guesses,numLeft);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"range = "<<range<<endl;
	cout<<"guesses = "<<guesses<<endl;
	cout<<"numLeft = "<<numLeft<<endl;
	cout<<"expected to return "<<bestGuess<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestGuess)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int range=100;
	int _guesses[]={27,80};
	vector<int> guesses(_guesses+0,_guesses+sizeof(_guesses)/sizeof(int));
	int numLeft=1;
	int bestGuess= 26;
	NumberGuessing _NumberGuessing;
	int ret=_NumberGuessing.bestGuess(range,guesses,numLeft);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"range = "<<range<<endl;
	cout<<"guesses = "<<guesses<<endl;
	cout<<"numLeft = "<<numLeft<<endl;
	cout<<"expected to return "<<bestGuess<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestGuess)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

int main(){
	test0();
	test1();
	test2();
	test3();
	return 0;
}

/*
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [1000, {}, 2]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [20, {8}, 3]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [100, {27, 80}, 1]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [20, {}, 4]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [20, {8, 13, 18}, 1]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [20, {8, 13}, 2]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [20, {8, 13, 18, 3}, 0]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [1000000, {}, 1]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [10, {}, 6]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [10, {9, 6}, 4]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [10, {9, 6, 1}, 3]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [10, {9}, 5]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [10, {9, 6, 1, 2}, 2]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [10, {9, 6, 1, 2, 3, 4}, 0]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [10, {9, 6, 1, 2, 3}, 1]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [99, {}, 3]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [99, {50, 83}, 1]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [99, {50}, 2]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [99, {50, 83, 17}, 0]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [100, {}, 3]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [100, {84}, 2]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [100, {84, 51}, 1]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [298771, {251230, 275984, 79583, 295940}, 0]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [100, {84, 51, 17}, 0]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [202854, {}, 1]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [483114, {317503, 134086, 267077, 66718, 178552, 185571, 349609, 313749}, 1]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [720732, {270364, 706055, 718771, 231002, 572272, 687510, 406934, 477034}, 1]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [12, {}, 5]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [25, {9, 25, 3, 2, 1, 18}, 3]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [47, {22, 1, 36, 6, 45}, 3]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [50, {28, 16, 41, 42}, 3]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [61, {32, 44, 3, 22, 60, 18, 50, 27, 15, 53}, 3]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [29, {9}, 3]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [15, {7, 5, 9, 1}, 4]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [6, {6}, 4]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [53, {40, 24, 15, 18, 12}, 3]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [22, {7}, 4]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [38, {2, 8}, 3]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [86, {23}, 3]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [1, {}, 0]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [1000000, {999999, 45000, 10503, 198388}, 1]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [1000, {233, 877}, 2]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [1000, {232, 877}, 2]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [477, {11, 33, 57, 400, 239}, 2]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [3, {}, 2]
0.00    | 22:40  | Succeeded system test of 1100-point problem with arguments [1000, {501}, 1]

*/
