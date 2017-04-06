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


class TeaCoffee{
public:
	int mat[30][30];
	int a[30];
	int stabilizes(vector<string> friends,vector<string> d){
		int i,j,size,b[30],k,t;
		char ch;
		memset(mat,0,sizeof(mat));
		for(i=0;i<friends.size();i++){
			for(j=0;j<friends[i].length();j++)
				if(friends[i][j]!=' '){
					for(k=j+1;k<=friends[i].length();k++)
						if(friends[i][k]==' '||friends[i][k]=='\0'){
							ch=friends[i][k];
							friends[i][k]='\0';
							sscanf(friends[i].c_str()+j,"%d",&t);
							mat[i][t]=1;
							friends[i][k]=ch;
							break;
						}
					j=k;
				}
		}
			for(i=0;i<d.size();i++){
				if(strcmp(d[i].c_str(),"TEA"))
					a[i]=0;
				else a[i]=1;
			}
				int ret=1,tmp[2];
				size=friends.size();
//				for(i=0;i<size;i++,cout<<endl)
//					for(j=0;j<size;j++)
//						cout<<mat[i][j]<<' ';
				while(ret<=51){
					for(i=0;i<size;i++)
						if(a[i]!=a[0])break;
					if(i==size)return ret;
					for(i=0;i<size;i++){
						tmp[0]=tmp[1]=0;
						for(j=0;j<size;j++)
							if(mat[i][j])
								tmp[a[j]]++;
						if(tmp[0]>tmp[1])
							b[i]=0;
						else if(tmp[0]<tmp[1])
							b[i]=1;
						else b[i]=a[i];
					}
					memcpy(a,b,sizeof(int)*size);
					ret++;
				}
			return -1;
		}
};




void test0(){
	string _friends[]={" "," "};
	vector<string> friends(_friends+0,_friends+sizeof(_friends)/sizeof(string));
	string _favoriteDrinks[]={"TEA","TEA"};
	vector<string> favoriteDrinks(_favoriteDrinks+0,_favoriteDrinks+sizeof(_favoriteDrinks)/sizeof(string));
	int stabilizes= 1;
	TeaCoffee _TeaCoffee;
	int ret=_TeaCoffee.stabilizes(friends,favoriteDrinks);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"friends = "<<friends<<endl;
	cout<<"favoriteDrinks = "<<favoriteDrinks<<endl;
	cout<<"expected to return "<<stabilizes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==stabilizes)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _friends[]={"  1 2","0   2","0 1   "};
	vector<string> friends(_friends+0,_friends+sizeof(_friends)/sizeof(string));
	string _favoriteDrinks[]={"TEA","TEA","COFFEE"};
	vector<string> favoriteDrinks(_favoriteDrinks+0,_favoriteDrinks+sizeof(_favoriteDrinks)/sizeof(string));
	int stabilizes= 2;
	TeaCoffee _TeaCoffee;
	int ret=_TeaCoffee.stabilizes(friends,favoriteDrinks);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"friends = "<<friends<<endl;
	cout<<"favoriteDrinks = "<<favoriteDrinks<<endl;
	cout<<"expected to return "<<stabilizes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==stabilizes)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _friends[]={"1 2 3","0 2 3","0 1 3","0 1 2"};
	vector<string> friends(_friends+0,_friends+sizeof(_friends)/sizeof(string));
	string _favoriteDrinks[]={"TEA","TEA","COFFEE","COFFEE"};
	vector<string> favoriteDrinks(_favoriteDrinks+0,_favoriteDrinks+sizeof(_favoriteDrinks)/sizeof(string));
	int stabilizes= -1;
	TeaCoffee _TeaCoffee;
	int ret=_TeaCoffee.stabilizes(friends,favoriteDrinks);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"friends = "<<friends<<endl;
	cout<<"favoriteDrinks = "<<favoriteDrinks<<endl;
	cout<<"expected to return "<<stabilizes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==stabilizes)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string _friends[]={"1","0 2","1 3","2 4","3 5","4 6","5 7","6 8","7 9","8 10","9 11","10 12","11 13","12 14","13 15","14 16","15 17","16 18","17 19","18 20","19 21","20 22","21 23","22 24","23"};
	vector<string> friends(_friends+0,_friends+sizeof(_friends)/sizeof(string));
	string _favoriteDrinks[]={"TEA", "COFFEE", "TEA", "COFFEE", "TEA", "COFFEE", "TEA", "COFFEE", "TEA", "COFFEE", "TEA", "COFFEE", "TEA", "COFFEE", "TEA", "COFFEE", "TEA", "COFFEE", "TEA", "COFFEE", "TEA", "COFFEE", "TEA", "TEA", "TEA"};
	vector<string> favoriteDrinks(_favoriteDrinks+0,_favoriteDrinks+sizeof(_favoriteDrinks)/sizeof(string));
	int stabilizes= 23;
	TeaCoffee _TeaCoffee;
	int ret=_TeaCoffee.stabilizes(friends,favoriteDrinks);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"friends = "<<friends<<endl;
	cout<<"favoriteDrinks = "<<favoriteDrinks<<endl;
	cout<<"expected to return "<<stabilizes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==stabilizes)
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
