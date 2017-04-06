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


class StripePainter{
public:
	string s,ss;
	int ret,cnt,num[30],pl[30][60];
	int inf;
	char mark[26];
	void dfs(int k,int ans,string s){
		if(ans>=ret)return ;
		if(k==ss.length()){
			if(ss==s)ret=ans;
			return ;
		}
		if(s[k]==ss[k]){
			dfs(k+1,ans,s);
			return ;
		}
		int i,j=0,pre;
/*		cls(mark);
		for(i=k;i<ss.length();i++)
			if(s[i]!=ss[i]&&!mark[ss[i]-'A']){
				mark[ss[i]-'A']=1;
				j++;
			}
		if(ans+j>=ret)return ;*/
		string tmp=s;
		pre=k+1;
		cnt++;
		int ch=ss[k]-'A';
		if(cnt>=inf)return;
/*		for(i=0;i<num[ch];i++){
			if(pl[ch][i]<=k)continue;
			if(ss[pl[ch][i]]==s[pl[ch][i]])continue;
			for(j=pre;j<pl[ch][i];j++)
				tmp[j]=ss[k];
			dfs(k+1,ans+1,tmp);
			pre=j+1;
		}*/
		for(i=k;i<ss.length();i++){
			if(ss[i]==ss[k]&&ss[i]!=s[i]){
				while(i<ss.length()&&ss[i]!=s[i]){
					tmp[i++]=ss[k];
				}
				dfs(k+1,ans+1,tmp);
				i--;
//				pre=i;
			}
			else tmp[i]=ss[k];
		}
	}
	int minStrokes(string st){
		int i;
		for(i=0;i<st.length();i++)if(!i||st[i]!=st[i-1]){
			s+=st[i];
		}
		ss=s;
		cls(num);
		for(i=0;i<ss.length();i++)
			pl[ss[i]-'A'][num[ss[i]-'A']++]=i;
		for(i=0;i<s.length();i++)
			s[i]=s[0];
		inf=400000;
		cnt=0;
		ret=s.length();
		dfs(1,1,s);
		cout<<cnt<<endl;
		return ret;
	}
};




void test0(){
	string stripes="RGBGR";
	int minStrokes= 3;
	StripePainter _StripePainter;
	int ret=_StripePainter.minStrokes(stripes);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"stripes = "<<stripes<<endl;
	cout<<"expected to return "<<minStrokes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minStrokes)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string stripes="RGRG";
	int minStrokes= 3;
	StripePainter _StripePainter;
	int ret=_StripePainter.minStrokes(stripes);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"stripes = "<<stripes<<endl;
	cout<<"expected to return "<<minStrokes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minStrokes)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string stripes="ABACADA";
	int minStrokes= 4;
	StripePainter _StripePainter;
	int ret=_StripePainter.minStrokes(stripes);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"stripes = "<<stripes<<endl;
	cout<<"expected to return "<<minStrokes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minStrokes)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string stripes="AABBCCDDCCBBAABBCCDD";
	int minStrokes= 7;
	StripePainter _StripePainter;
	int ret=_StripePainter.minStrokes(stripes);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"stripes = "<<stripes<<endl;
	cout<<"expected to return "<<minStrokes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minStrokes)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string stripes="BECBBDDEEBABDCADEAAEABCACBDBEECDEDEACACCBEDABEDADD";
	int minStrokes= 26;
	StripePainter _StripePainter;
	int ret=_StripePainter.minStrokes(stripes);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"stripes = "<<stripes<<endl;
	cout<<"expected to return "<<minStrokes<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minStrokes)
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
