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


class Tothello{
public:
	int calc(VS &chess,int r,int l,char whoseturn){
		int i,j,ret=0,k;
//		chess[r][l]=whoseturn;
		char ch;
		if(whoseturn=='R')ch='B';
		else ch='R';
		for(i=0;i<8;i++){
			j=1;
			while(inmat(r+j*mx[i],l+j*my[i],8,8)&&chess[r+j*mx[i]][l+j*my[i]]==ch)
				j++;
			if(!inmat(r+j*mx[i],l+j*my[i],8,8)||chess[r+j*mx[i]][l+j*my[i]]==' ')
				continue;
			ret+=j-1;
			for(k=1;k<j;k++)
				chess[r+k*mx[i]][l+k*my[i]]=whoseturn;
			for(k=1;k<j;k++)
				ret+=calc(chess,r+k*mx[i],l+k*my[i],whoseturn);
		}
		return ret;
	}
	int bestMove(VS red,VS black,string whoseturn){
		int i;
		string tmp="        ";
		vector<string> chess(8,tmp);
		VS tch;
		for(i=0;i<red.size();i++){
			chess[red[i][1]-'1'][red[i][0]-'A']='R';
		}
		for(i=0;i<black.size();i++)
			chess[black[i][1]-'1'][black[i][0]-'A']='B';
		int ret=0,j;
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
				if(chess[i][j]==' '){
					tch=chess;
					tch[i][j]=whoseturn[0];
					int t=calc(tch,i,j,whoseturn[0])+1;
					if(t>ret){
						ret=t;
					}
				}
		if(whoseturn=="Red")return ret+red.size();
		return ret+black.size();
	}
};

int main(){
	string buf1[]={"E1", "F2", "G2", "H2"};
	string buf2[]={"A2", "B2", "C2", "D2", "E2"};
	VS red(buf1,buf1+4);
	VS black(buf2,buf2+5);
	string whoseturn="Black";
	Tothello a;
	cout<<a.bestMove(red,black,whoseturn)<<endl;
	return 0;
}

/*
[{"E1", "F2", "G2", "H2"}, {"A2", "B2", "C2", "D2", "E2"}, "Black"]
    EXPECTED: 6
    RECEIVED: 7
*/