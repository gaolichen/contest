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


class Sequences{
public:
	int check(int a,int b,int t,int *s){
		if(t==0){
			if(a)return b/a;
			return 0;
		}
		if(t==1)return b-a;
		if(abs(a)==1){
			ddd
		}
	}
	int cmp(const void *a,const void *b){
		return *(int*)a-*(int *)b;
	}
	int size(vector<int> sequence){
		int i,j,temp[100],size;
		for(i=0;i<sequence.size();i++)
			temp[i]=sequence[i];
		qsort(temp,sequence.size(),sizeof(int),cmp);
		size=sequence.size();
		memset(num,0,sizeof(num));
		count=1;num[0]=1;
/*		for(i=1;i<size;i++){
			for(j=0;j<count;j++)
				if(temp[j]==temp[i])break;
			if(j<count)num[j]++;
			else {
				num[count]=1;
				temp[count++]=temp[i];
			}
		}
		size=count;*/
		int t,ret=0,a;
		for(i=0;i<size;i++)
			for(j=0;j<size;j++)
				if(i!=j){
					for(k=0;k<2;k++)
						if(t=check(i,j,k)){
							t=myfind(i,t);
							if(t>ret)ret=t;
						}
				}
		return ret;
	}
};




void test0(){
	int _sequence[]={100,3,2,4,1};
	vector<int> sequence(_sequence+0,_sequence+sizeof(_sequence)/sizeof(int));
	int size= 4;
	Sequences _Sequences;
	int ret=_Sequences.size(sequence);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"sequence = "<<sequence<<endl;
	cout<<"expected to return "<<size<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==size)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int _sequence[]={25,10,1,5};
	vector<int> sequence(_sequence+0,_sequence+sizeof(_sequence)/sizeof(int));
	int size= 3;
	Sequences _Sequences;
	int ret=_Sequences.size(sequence);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"sequence = "<<sequence<<endl;
	cout<<"expected to return "<<size<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==size)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int _sequence[]={1,1,1,1,2};
	vector<int> sequence(_sequence+0,_sequence+sizeof(_sequence)/sizeof(int));
	int size= 4;
	Sequences _Sequences;
	int ret=_Sequences.size(sequence);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"sequence = "<<sequence<<endl;
	cout<<"expected to return "<<size<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==size)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int _sequence[]={-1,-1,-1,1,1,1,1};
	vector<int> sequence(_sequence+0,_sequence+sizeof(_sequence)/sizeof(int));
	int size= 7;
	Sequences _Sequences;
	int ret=_Sequences.size(sequence);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"sequence = "<<sequence<<endl;
	cout<<"expected to return "<<size<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==size)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	int _sequence[]={1,1,1,-1,1,1};
	vector<int> sequence(_sequence+0,_sequence+sizeof(_sequence)/sizeof(int));
	int size= 6;
	Sequences _Sequences;
	int ret=_Sequences.size(sequence);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"sequence = "<<sequence<<endl;
	cout<<"expected to return "<<size<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==size)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	int _sequence[]={-3,9,81,6561};
	vector<int> sequence(_sequence+0,_sequence+sizeof(_sequence)/sizeof(int));
	int size= 4;
	Sequences _Sequences;
	int ret=_Sequences.size(sequence);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"sequence = "<<sequence<<endl;
	cout<<"expected to return "<<size<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==size)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test6(){
	int _sequence[]={0,1,1,1,1};
	vector<int> sequence(_sequence+0,_sequence+sizeof(_sequence)/sizeof(int));
	int size= 4;
	Sequences _Sequences;
	int ret=_Sequences.size(sequence);
	cout<<"--------------------test 6--------------------"<<endl;
	cout<<"sequence = "<<sequence<<endl;
	cout<<"expected to return "<<size<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==size)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test7(){
	int _sequence[]={900000000,1000000000,810000000,729000000};
	vector<int> sequence(_sequence+0,_sequence+sizeof(_sequence)/sizeof(int));
	int size= 4;
	Sequences _Sequences;
	int ret=_Sequences.size(sequence);
	cout<<"--------------------test 7--------------------"<<endl;
	cout<<"sequence = "<<sequence<<endl;
	cout<<"expected to return "<<size<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==size)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test8(){
	int _sequence[]={0,0,0,0,0};
	vector<int> sequence(_sequence+0,_sequence+sizeof(_sequence)/sizeof(int));
	int size= 5;
	Sequences _Sequences;
	int ret=_Sequences.size(sequence);
	cout<<"--------------------test 8--------------------"<<endl;
	cout<<"sequence = "<<sequence<<endl;
	cout<<"expected to return "<<size<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==size)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test9(){
	int _sequence[]={1,500000000,-371654656};
	vector<int> sequence(_sequence+0,_sequence+sizeof(_sequence)/sizeof(int));
	int size= 2;
	Sequences _Sequences;
	int ret=_Sequences.size(sequence);
	cout<<"--------------------test 9--------------------"<<endl;
	cout<<"sequence = "<<sequence<<endl;
	cout<<"expected to return "<<size<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==size)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test10(){
	int _sequence[]={9,6,4};
	vector<int> sequence(_sequence+0,_sequence+sizeof(_sequence)/sizeof(int));
	int size= 3;
	Sequences _Sequences;
	int ret=_Sequences.size(sequence);
	cout<<"--------------------test 10--------------------"<<endl;
	cout<<"sequence = "<<sequence<<endl;
	cout<<"expected to return "<<size<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==size)
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
	test9();
	test10();
	return 0;
}
