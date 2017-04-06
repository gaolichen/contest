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


class Dominoes{
public:
	int ret;
	int cnt;
	int count[7],mat[7][7],mark[7][7],p[50][2];
	int ok(){
		int i,j,k;
		memset(count,0,sizeof(count));
		for(i=0,k=0;i<=6;i++){
			for(j=0;j<=6;j++)
				count[i]+=mark[i][j];
			if(count[i]%2)k++;
		}
		if(k>2)return 0;
		memcpy(mat,mark,sizeof(mark));
		for(k=0;k<7;k++)
			for(i=0;i<7;i++)
				if(i!=k)
				for(j=0;j<7;j++)
					if(j!=k&&j!=i)
					if(mat[i][k]&&mat[k][j])
						mat[i][j]=mat[j][i]=1;
		for(k=0;k<7;k++)
			if(count[k])
				for(i=0;i<7;i++)
					if(k!=i&&count[i]&&!mat[i][k])return 0;
		return 1;
	}

	void dfs(int k,int ans){
		if(ret==0)return ;
		if(ans>=ret)return ;
		if(k==cnt){
			if(ok())
			ret=ans;
			return ;
		}
//		if(ans>=ret)return ;
		dfs(k+1,ans);
		mark[p[k][0]][p[k][1]]++;
		mark[p[k][1]][p[k][0]]++;
		dfs(k+1,ans+1);
		mark[p[k][0]][p[k][1]]--;
		mark[p[k][1]][p[k][0]]--;
	}
	int fewestNeeded(vector<string> b){
		int i,j,k;
		int kaka[10];
		memset(kaka,0,sizeof(kaka));
		memset(mark,0,sizeof(mark));
		for(i=0;i<b.size();i++){
			sscanf(b[i].c_str(),"(%d,%d)",&j,&k);
			mark[j][k]++;
			mark[k][j]++;
			kaka[j]++;
			kaka[k]++;
		}
//		cout<<ok()<<endl;
		cnt=0;
		ret=10000;
		for(i=0;i<7;i++)
			for(j=i+1;j<7;j++)
				if(!mark[i][j]){
					p[cnt][0]=i;
					p[cnt++][1]=j;
				}
		dfs(0,0);
		for(i=0;i<cnt;i++){
			mark[p[i][0]][p[i][1]]++;
			mark[p[i][1]][p[i][0]]++;
			if(ok())cout<<p[i][0]<<' '<<p[i][1]<<endl;
			break;
			mark[p[i][0]][p[i][1]]--;
			mark[p[i][1]][p[i][0]]--;
		}
		return ret;
	}
};




void test0(){
	string _bones[]={"(3,6)","(2,4)","(4,6)","(1,1)"};
	vector<string> bones(_bones+0,_bones+sizeof(_bones)/sizeof(string));
	int fewestNeeded= 1;
	Dominoes _Dominoes;
	int ret=_Dominoes.fewestNeeded(bones);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"bones = "<<bones<<endl;
	cout<<"expected to return "<<fewestNeeded<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==fewestNeeded)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _bones[]={"(0,1)","(0,2)","(0,3)","(1,2)","(1,3)","(2,3)"};
	vector<string> bones(_bones+0,_bones+sizeof(_bones)/sizeof(string));
	int fewestNeeded= 2;
	Dominoes _Dominoes;
	int ret=_Dominoes.fewestNeeded(bones);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"bones = "<<bones<<endl;
	cout<<"expected to return "<<fewestNeeded<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==fewestNeeded)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _bones[]={"(4,4)","(3,0)","(5,3)","(2,3)","(6,1)","(5,5)"};
	vector<string> bones(_bones+0,_bones+sizeof(_bones)/sizeof(string));
	int fewestNeeded= 3;
	Dominoes _Dominoes;
	int ret=_Dominoes.fewestNeeded(bones);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"bones = "<<bones<<endl;
	cout<<"expected to return "<<fewestNeeded<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==fewestNeeded)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string _bones[]={"(0,0)","(1,1)","(2,2)","(3,3)","(4,4)","(5,5)","(6,6)"};
	vector<string> bones(_bones+0,_bones+sizeof(_bones)/sizeof(string));
	int fewestNeeded= 6;
	Dominoes _Dominoes;
	int ret=_Dominoes.fewestNeeded(bones);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"bones = "<<bones<<endl;
	cout<<"expected to return "<<fewestNeeded<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==fewestNeeded)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string _bones[]={"(1,1)","(4,1)","(3,3)","(1,6)","(0,2)","(0,0)","(2,4)", "(6,6)","(6,4)","(5,3)","(5,6)","(4,3)","(3,0)","(5,5)","(2,6)"};
	vector<string> bones(_bones+0,_bones+sizeof(_bones)/sizeof(string));
	int fewestNeeded= 0;
	Dominoes _Dominoes;
	int ret=_Dominoes.fewestNeeded(bones);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"bones = "<<bones<<endl;
	cout<<"expected to return "<<fewestNeeded<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==fewestNeeded)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string _bones[]={"(1,2)","(2,3)","(3,1)","(4,5)","(5,6)","(6,4)"};
	vector<string> bones(_bones+0,_bones+sizeof(_bones)/sizeof(string));
	int fewestNeeded= 1;
	Dominoes _Dominoes;
	int ret=_Dominoes.fewestNeeded(bones);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"bones = "<<bones<<endl;
	cout<<"expected to return "<<fewestNeeded<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==fewestNeeded)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test6(){
	string _bones[]={"(3,2)","(2,4)","(4,3)"};
	vector<string> bones(_bones+0,_bones+sizeof(_bones)/sizeof(string));
	int fewestNeeded= 0;
	Dominoes _Dominoes;
	int ret=_Dominoes.fewestNeeded(bones);
	cout<<"--------------------test 6--------------------"<<endl;
	cout<<"bones = "<<bones<<endl;
	cout<<"expected to return "<<fewestNeeded<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==fewestNeeded)
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
	return 0;
}
