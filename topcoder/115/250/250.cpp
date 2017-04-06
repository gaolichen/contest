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


class Mail{
public:
	int calc(string s1,string s2){
		int ret=0,j;
		for(j=0;j<s1.size();j++){
			if(s1[j]==s2[j]){
				ret+=6;
				continue;
			}
			if(j+1<s1.size()&&s1[j+1]==s2[j]&&s2[j+1]==s1[j]){
				ret+=5;
				j++;
				continue;
			}
			if((s1[j]=='7')&&(s2[j]=='2')||
				(s1[j]=='2')&&(s2[j]=='7')||
				(s1[j]=='7')&&(s2[j]=='1')||
				(s1[j]=='1')&&(s2[j]=='7')||
				(s1[j]=='9')&&(s2[j]=='6')||
				(s1[j]=='6')&&(s2[j]=='9')||
				(s1[j]=='0')&&(s2[j]=='9')||
				(s1[j]=='9')&&(s2[j]=='0')){
				ret+=2;
				continue;
			}
			if(s1[j]==s2[j]+1||s2[j]==s1[j]+1){
				ret++;
				continue;
			}
		}
		return ret;
	}
	vector<int> handleBadZips(vector<string> of,vector<string> le){
		int i,j,t;
		VI ret;
		ret.resize(of.size());
		for(i=0;i<le.size();i++){
			t=-1;
			for(j=0;j<of.size();j++)
				if(calc(of[j],le[i])>=10){
					if(t==-1||calc(of[t],le[i])<calc(of[j],le[i]))
						t=j;
				}
			if(t!=-1)ret[t]++;
		}
		return ret;
	}
};




void test0(){
	string _offices[]={"90211", "09210", "12345", "88888", "69779"};
	vector<string> offices(_offices+0,_offices+sizeof(_offices)/sizeof(string));
	string _letters[]={"90210"};
	vector<string> letters(_letters+0,_letters+sizeof(_letters)/sizeof(string));
	int _handleBadZips[]= { 1,  0,  0,  0,  0 };
	vector<int> handleBadZips(_handleBadZips+0,_handleBadZips+sizeof(_handleBadZips)/sizeof(int));
	Mail _Mail;
	vector<int> ret=_Mail.handleBadZips(offices,letters);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"offices = "<<offices<<endl;
	cout<<"letters = "<<letters<<endl;
	cout<<"expected to return "<<handleBadZips<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==handleBadZips)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _offices[]={"88888", "66666", "22222"};
	vector<string> offices(_offices+0,_offices+sizeof(_offices)/sizeof(string));
	string _letters[]={"84444", "77771", "99999"};
	vector<string> letters(_letters+0,_letters+sizeof(_letters)/sizeof(string));
	int _handleBadZips[]= { 0,  1,  0 };
	vector<int> handleBadZips(_handleBadZips+0,_handleBadZips+sizeof(_handleBadZips)/sizeof(int));
	Mail _Mail;
	vector<int> ret=_Mail.handleBadZips(offices,letters);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"offices = "<<offices<<endl;
	cout<<"letters = "<<letters<<endl;
	cout<<"expected to return "<<handleBadZips<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==handleBadZips)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _offices[]={"14736", "23741", "09284", "27481", "56456", "89148"};
	vector<string> offices(_offices+0,_offices+sizeof(_offices)/sizeof(string));
	string _letters[]={"12375", "99642", "12763", "84564"};
	vector<string> letters(_letters+0,_letters+sizeof(_letters)/sizeof(string));
	int _handleBadZips[]= { 2,  0,  0,  0,  0,  1 };
	vector<int> handleBadZips(_handleBadZips+0,_handleBadZips+sizeof(_handleBadZips)/sizeof(int));
	Mail _Mail;
	vector<int> ret=_Mail.handleBadZips(offices,letters);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"offices = "<<offices<<endl;
	cout<<"letters = "<<letters<<endl;
	cout<<"expected to return "<<handleBadZips<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==handleBadZips)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

int main(){
	test0();
	test1();
	test2();
	return 0;
}
