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


class Clusters{
public:
	int a[100],b[100];
	int mat[100][100];
	vector<string> mostClustered(vector<string> l){
		int i,j,t,k,tmp;
		char buf[100];
		int c[100][30],size[100];
		vector<string>name;
		memset(mat,0,sizeof(mat));
		memset(size,0,sizeof(size));
		for( i=0;i<l.size();i++){
			t=0;//cout<<name<<endl;
			for(j=0;j<=l[i].length();j++)
				if(l[i][j]==' '||l[i][j]=='\0'){
					l[i][j]='\0';
					sscanf(l[i].c_str()+t,"%s",buf);
					for(k=0;k<name.size();k++)
						if(name[k]==buf)break;
					if(k==name.size())name.push_back(buf);
					if(t==0)tmp=k;
					else mat[tmp][k]=1;
					c[i][size[i]++]=k;
					l[i][j]=' ';
					t=j;
				}
			l[i][t]='\0';
		}
		
		for(i=0;i<l.size();i++){
			b[i]=(size[i]-2)*(size[i]-1);
			a[i]=0;
			for(j=1;j<size[i];j++)
				for(k=1;k<size[i];k++)
					if(j!=k&&mat[c[i][j]][c[i][k]])a[i]++;
		}
		j=0;k=0;
		for(i=0;i<l.size();i++)
			if((j==0&&k==0)||k*a[i]>b[i]*j){
				j=a[i];k=b[i];
			}
		cout<<j<<' '<<k<<endl;
		vector<string> ret;
		if(k==0)return ret;
		for(i=0;i<l.size();i++){
			if(b[i]&&j*b[i]==k*a[i])ret.push_back(name[c[i][0]]);
		}
		return ret;
	}
};




void test0(){
	string _links[]={"A B C D", "B A E D"};
	vector<string> links(_links+0,_links+sizeof(_links)/sizeof(string));
	string _mostClustered[]= { "A",  "B" };
	vector<string> mostClustered(_mostClustered+0,_mostClustered+sizeof(_mostClustered)/sizeof(string));
	Clusters _Clusters;
	vector<string> ret=_Clusters.mostClustered(links);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"links = "<<links<<endl;
	cout<<"expected to return "<<mostClustered<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==mostClustered)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _links[]={"A", "B"};
	vector<string> links(_links+0,_links+sizeof(_links)/sizeof(string));
	vector<string> mostClustered(0);
	Clusters _Clusters;
	vector<string> ret=_Clusters.mostClustered(links);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"links = "<<links<<endl;
	cout<<"expected to return "<<mostClustered<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==mostClustered)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _links[]={"SEARCH SCHOOL NEWS", "NEWS FINANCE WORLD", "FINANCE WORLD"};
	vector<string> links(_links+0,_links+sizeof(_links)/sizeof(string));
	string _mostClustered[]= { "NEWS" };
	vector<string> mostClustered(_mostClustered+0,_mostClustered+sizeof(_mostClustered)/sizeof(string));
	Clusters _Clusters;
	vector<string> ret=_Clusters.mostClustered(links);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"links = "<<links<<endl;
	cout<<"expected to return "<<mostClustered<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==mostClustered)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string _links[]={"A B C D E F","B A C D E F","C A B D E F","D A B C E F","E A B C D F","F A B C D E"};
	vector<string> links(_links+0,_links+sizeof(_links)/sizeof(string));
	string _mostClustered[]= { "A",  "B",  "C",  "D",  "E",  "F" };
	vector<string> mostClustered(_mostClustered+0,_mostClustered+sizeof(_mostClustered)/sizeof(string));
	Clusters _Clusters;
	vector<string> ret=_Clusters.mostClustered(links);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"links = "<<links<<endl;
	cout<<"expected to return "<<mostClustered<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==mostClustered)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string _links[]={"Z Y X"};
	vector<string> links(_links+0,_links+sizeof(_links)/sizeof(string));
	string _mostClustered[]= { "Z" };
	vector<string> mostClustered(_mostClustered+0,_mostClustered+sizeof(_mostClustered)/sizeof(string));
	Clusters _Clusters;
	vector<string> ret=_Clusters.mostClustered(links);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"links = "<<links<<endl;
	cout<<"expected to return "<<mostClustered<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==mostClustered)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string _links[]={"A", "B C"};
	vector<string> links(_links+0,_links+sizeof(_links)/sizeof(string));
	vector<string> mostClustered(0);
	Clusters _Clusters;
	vector<string> ret=_Clusters.mostClustered(links);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"links = "<<links<<endl;
	cout<<"expected to return "<<mostClustered<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==mostClustered)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test6(){
	string _links[]={"A"};
	vector<string> links(_links+0,_links+sizeof(_links)/sizeof(string));
	vector<string> mostClustered(0);
	Clusters _Clusters;
	vector<string> ret=_Clusters.mostClustered(links);
	cout<<"--------------------test 6--------------------"<<endl;
	cout<<"links = "<<links<<endl;
	cout<<"expected to return "<<mostClustered<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==mostClustered)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test7(){
	string _links[]={"ABRA CA DABRA","DABRA CA","CA DABRA","D A B","A B C"};
	vector<string> links(_links+0,_links+sizeof(_links)/sizeof(string));
	string _mostClustered[]= { "ABRA" };
	vector<string> mostClustered(_mostClustered+0,_mostClustered+sizeof(_mostClustered)/sizeof(string));
	Clusters _Clusters;
	vector<string> ret=_Clusters.mostClustered(links);
	cout<<"--------------------test 7--------------------"<<endl;
	cout<<"links = "<<links<<endl;
	cout<<"expected to return "<<mostClustered<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==mostClustered)
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
	return 0;
}
