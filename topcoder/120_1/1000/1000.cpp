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


class GradedOrder{
public:
	char x[30];
	int size;
	i64 c[40][40];
	string ret;
	void init(){
		int i,j;
		memset(c,0,sizeof(c));
		for(i=0;i<36;i++){
			c[0][i]=0;
			c[i][0]=1;
		}
		for(i=1;i<=36;i++)
			for(j=1;j<=i;j++)
				c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	void dfs(int n,int k,int s){
		if(s==0||k<0)return ;
		if(n==0){
			dfs(n,k,s-1);
			return;
		}
		if(s==1){
			ret+=x[size-1];
			if(n>1){
				ret+='^';
				if(n<10)ret+=n+'0';
				else {
					ret+=n/10+'0';
					ret+=n%10+'0';
				}
			}
			return ;
		}
		int sum=0,i,pre;
		for(i=n;i>=0;i--){
			pre=sum;
			sum+=c[n-i+s-2][s-2];
			if(sum>=k+1)break;
		}
		sum-=pre+1;
		if(i){
			ret+=x[size-s];
			if(i>1){
			ret+='^';
			if(i<10)ret+=i+'0';
			else {
				ret+=i/10+'0';
				ret+=i%10+'0';
			}
			}
		}
		dfs(n-i,k-sum,s-1);
	}
	string getTerm(string vars,int n,int k){
		int i,j;
		for(i=0;i<vars.length();i++)
			x[i]=vars[i];
		size=vars.length();
		init();
		j=0;int t=0;
		for(i=n;i>=0;i--){
			t=j;
			j+=c[i+size-1][size-1];
			if(j>=k+1)break;
		}
		k=k-t;
		cout<<i<<' '<<k<<' '<<size<<endl;
		dfs(i,k,size);
		if(ret.length()==0)ret+='1';
		return ret;
	}
};




void test0(){
	string vars="xy";
	int n=3;
	int k=2;
	string getTerm= "xy^2";
	GradedOrder _GradedOrder;
	string ret=_GradedOrder.getTerm(vars,n,k);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"vars = "<<vars<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"k = "<<k<<endl;
	cout<<"expected to return "<<getTerm<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getTerm)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string vars="xy";
	int n=3;
	int k=0;
	string getTerm= "x^3";
	GradedOrder _GradedOrder;
	string ret=_GradedOrder.getTerm(vars,n,k);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"vars = "<<vars<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"k = "<<k<<endl;
	cout<<"expected to return "<<getTerm<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getTerm)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string vars="xy";
	int n=3;
	int k=9;
	string getTerm= "1";
	GradedOrder _GradedOrder;
	string ret=_GradedOrder.getTerm(vars,n,k);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"vars = "<<vars<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"k = "<<k<<endl;
	cout<<"expected to return "<<getTerm<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getTerm)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string vars="x";
	int n=6;
	int k=4;
	string getTerm= "x^2";
	GradedOrder _GradedOrder;
	string ret=_GradedOrder.getTerm(vars,n,k);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"vars = "<<vars<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"k = "<<k<<endl;
	cout<<"expected to return "<<getTerm<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getTerm)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string vars="abcdefghijklmn";
	int n=10;
	int k=1000000;
	string getTerm= "d^2gk^2n^5";
	GradedOrder _GradedOrder;
	string ret=_GradedOrder.getTerm(vars,n,k);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"vars = "<<vars<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"k = "<<k<<endl;
	cout<<"expected to return "<<getTerm<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getTerm)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string vars="abcdefghijklmnopqrstuvwxyz";
	int n=10;
	int k=0;
	string getTerm= "a^10";
	GradedOrder _GradedOrder;
	string ret=_GradedOrder.getTerm(vars,n,k);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"vars = "<<vars<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"k = "<<k<<endl;
	cout<<"expected to return "<<getTerm<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getTerm)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test6(){
	string vars="nopqrstuvwxyz";
	int n=10;
	int k=1000000;
	string getTerm= "o^2qtuwxy";
	GradedOrder _GradedOrder;
	string ret=_GradedOrder.getTerm(vars,n,k);
	cout<<"--------------------test 6--------------------"<<endl;
	cout<<"vars = "<<vars<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"k = "<<k<<endl;
	cout<<"expected to return "<<getTerm<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getTerm)
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
