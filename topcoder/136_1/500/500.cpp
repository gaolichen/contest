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


class Cribbage{
public:
	int score(string hand){
		int i,j,t,k;
		char card[10][10];
		int c[10][2],tmp1[10];
		sscanf(hand.c_str(),"%2s,%2s,%2s,%2s,%2s",card[0],card[1],card[2],card[3],card[4]);
//		cout<<card[0]<<' '<<card[1]<<' '<<card[2]<<endl;
		for(i=0;i<5;i++){
			switch(card[i][0]){
			case 'A':c[i][0]=1;break;
			case 'T':c[i][0]=10;break;
			case 'J':c[i][0]=11;break;
			case 'Q':c[i][0]=12;break;
			case 'K':c[i][0]=13;break;
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':c[i][0]=card[i][0]-'0';
			}
//			cout<<c[i][0]<<' ';
			switch(card[i][1]){
			case 'C':c[i][1]=1;break;
			case 'D':c[i][1]=2;break;
			case 'H':c[i][1]=3;break;
			case 'S':c[i][1]=4;break;
			}
		}
//		cout<<endl;
		int ret=0;
		char a[10];
		memset(a,0,sizeof(a));
		while(!a[5]){
			t=0;
			for(i=0;i<5;i++)
				if(a[i])t+=(c[i][0]>10?10:c[i][0]);
			if(t==15)ret+=2;
			i=0;
			while(a[i])a[i++]=0;
			a[i]=1;
		}
		for(i=0;i<5;i++)
			for(j=i+1;j<5;j++){
				if(c[i][0]==c[j][0])ret+=2;
			}
//		cout<<ret<<endl;
		for(i=0;i<5;i++)
			if(c[i][1]!=c[0][1])break;
		if(i==5)ret+=5;
		if(i==1){
			for(j=1;j<5;j++)
				if(c[j][1]!=c[1][1])break;
			if(j==5)ret+=4;
		}
//		cout<<ret<<endl;
		if(c[0][0]!=11)
		for(i=1;i<5;i++)
			if(c[i][0]==11&&c[i][1]==c[0][1])
				ret+=1;
		int tmp[10];
		for(i=0;i<5;i++)
			tmp[i]=c[i][0];
		for(i=1;i<5;i++)
			for(j=0;j<5-i;j++)
				if(tmp[j]>tmp[j+1]){
					t=tmp[j];
					tmp[j]=tmp[j+1];
					tmp[j+1]=t;
				}
		for(i=0;i<5;i++)
			cout<<tmp[i]<<' ';
		cout<<endl;
		for(i=0;i<4;i++)
			if(tmp[i]+1!=tmp[i+1])break;
		if(i==4){
			ret+=5;
			cout<<ret<<endl;
		}
		else{
			int flag=0;
		for(i=0;i<5;i++){
			for(j=t=0;j<5;j++)
				if(i!=j)tmp1[t++]=tmp[j];
			for(j=0;j<3;j++)
				if(tmp1[j]+1!=tmp1[j+1])break;
				if(j==3){
					ret+=4;
					flag=1;
				}
		}
		cout<<ret<<endl;
		if(!flag){
			for(i=0;i<5;i++)
				for(j=i+1;j<5;j++)
					if(tmp[j]==tmp[i]+1)
						for(k=j+1;k<5;k++)
							if(tmp[k]==tmp[j]+1)
								ret+=3;
		}
		}
		return ret;
	}
};




void test0(){
	string hand="4H,6D,5S,JH,6C";
	int score= 15;
	Cribbage _Cribbage;
	int ret=_Cribbage.score(hand);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"hand = "<<hand<<endl;
	cout<<"expected to return "<<score<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==score)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string hand="2D,6H,4C,5C,3C";
	int score= 9;
	Cribbage _Cribbage;
	int ret=_Cribbage.score(hand);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"hand = "<<hand<<endl;
	cout<<"expected to return "<<score<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==score)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string hand="JS,TH,JH,9H,QH";
	int score= 14;
	Cribbage _Cribbage;
	int ret=_Cribbage.score(hand);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"hand = "<<hand<<endl;
	cout<<"expected to return "<<score<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==score)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string hand="7S,6H,7D,8C,8S";
	int score= 24;
	Cribbage _Cribbage;
	int ret=_Cribbage.score(hand);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"hand = "<<hand<<endl;
	cout<<"expected to return "<<score<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==score)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string hand="AH,2H,6C,QH,KH";
	int score= 0;
	Cribbage _Cribbage;
	int ret=_Cribbage.score(hand);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"hand = "<<hand<<endl;
	cout<<"expected to return "<<score<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==score)
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
