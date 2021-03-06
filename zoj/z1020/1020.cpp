#define WIN32
#ifdef WIN32
#	pragma warning(disable:4786)
#define for if(0);else for
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
#define mit(a,b) map<a,b>::iterator
#define fr(a,b) for(int a=0;a<(b);a++)
#define foreach(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i) 
#define all(a) a.begin(),a.end()
#define inmat(i,j,m,n) ((i)>=0&&(i)<(m)&&(j)>=0&&(j)<(n))
#define cls(a) memset((a),0,sizeof(a))
#define isCap(a) ((a)>='A'&&(a)<='Z')
#define isLow(a) ((a)>='a'&&(a)<='z')
#define inf 2100000000
#define eps 1e-8
typedef istringstream iss;
typedef ostringstream oss;
typedef vector<int> VI; typedef vector<vector<int> > VVI;
typedef vector<i64> V64; typedef vector<vector<i64> > VV64;
typedef vector<string> VS; typedef vector<vector<string> > VVS;
typedef vector<double> VD; typedef vector<vector<double> > VVD;
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
template <class T>
ostream& operator<<(ostream& s,vector<T> d){
	s<<"{";
	for (typename vector<T>::iterator i=d.begin();i!=d.end();i++)
		s<<(i!=d.begin()?",":"")<<*i;
	s<<"}";
	return s;
}

//parsing routine
vector<string > parse(const string &s,const string &delim){
	vector<string > ret(0);
	for (int b,e=0;;ret.push_back(s.substr(b,e-b)))
		if ((b=s.find_first_not_of(delim,e))==(e=s.find_first_of(delim,b)))
			return ret;
}

VVS dic;
VS vs;
int ret;
string output;
int unknow[1100];
int searchcnt;

void check(string &a,string &b,string &c,string &d){
	fr(i,a.length()){
		if(d[b[i]-'A']!='*'&&d[b[i]-'A']!=a[i]){
			c="";return ;
		}
		else d[b[i]-'A']=a[i];
		if(c[a[i]-'A']!='*'&&c[a[i]-'A']!=b[i]){
			c="";return ;
		}
		else c[a[i]-'A']=b[i];
	}
}

void dfs(int k,string &s1,string &s2){
//	if(searchcnt>1000)return ;
//	return ;
	if(ret>1)return ;
	if(k==vs.size()){
//		cout<<s2<<endl;
		if(!ret||output!=s2)ret++;output=s2;return ;
	}
	if(unknow[k]==0){
		string tmp;tmp.resize(vs[k].length());
		fr(i,vs[k].length())tmp[i]=s1[vs[k][i]-'A'];
		if(binary_search(all(dic[vs[k].length()]),tmp))
		dfs(k+1,s1,s2);
		return ;
	}
	searchcnt++;
	for(int i=0;i<dic[vs[k].size()].size();i++){
		string tmp1,tmp2;
		tmp1=s1;tmp2=s2;
		check(vs[k],dic[vs[k].size()][i],tmp1,tmp2);
		if(tmp1=="")continue;
		dfs(k+1,tmp1,tmp2);
	}
}


void init(VS &vs){
	VS tmp;
	char mark[30],done[1100];cls(mark);cls(done);
	int first=0,fmax=0;
	fr(i,vs.size()){
		cls(mark);int cnt=0;
		fr(j,vs[i].length())mark[vs[i][j]-'A']=1;
		fr(i,26)if(mark[i])cnt++;
		if(cnt>fmax||(cnt==fmax&&vs[i].length()>vs[first].length())){
			fmax=cnt;first=i;	
		}
	}
	tmp.push_back(vs[first]);done[first]=1;
	unknow[0]=fmax;cls(mark);
	fr(i,tmp[0].length())mark[tmp[0][i]-'A']=1;
	for(int i=1;i<vs.size();i++){
		int flag=-1,mknow=0,munknow=0;
		fr(j,vs.size())if(!done[j]){
			int cnt=0,know=0,unknow=0;
			char have[26];cls(have);
			fr(k,vs[j].length())have[vs[j][k]-'A']=1;
			fr(k,26)if(have[k]){
				if(!mark[k])unknow++;
				else know++;
			}
//			if(flag==-1||(mknow<know)||(mknow==know&&munknow<unknow)||(mknow==know&&munknow==unknow&&vs[j].length()>vs[flag].length())){
			if(flag==-1||(munknow>unknow)||(munknow==unknow&&mknow<unknow)||(mknow==know&&munknow==unknow&&vs[j].length()>vs[flag].length())){
				munknow=unknow;flag=j;mknow=know;
			}
		}
		done[flag]=1;
		tmp.push_back(vs[flag]);
		unknow[i]=munknow;
		fr(j,vs[flag].length())mark[vs[flag][j]-'A']=1;
	}
	vs=tmp;
}
void run(){
	string s1(26,'*'),s2(26,'*');
	ret=0;output="";sort(all(vs));
	vs.resize(unique(all(vs))-vs.begin());
	init(vs);
	cout<<vs<<endl;
	fr(i,vs.size())cout<<unknow[i]<<' ';
	cout<<endl;
	fr(i,dic.size())sort(all(dic[i]));searchcnt=0;
	dfs(0,s1,s2);
	if(!ret){
		cout<<"#No solution#"<<endl;
	}
	else if(ret>1){
		cout<<"#More than one solution#"<<endl;
	}
	else {
		cout<<output<<endl;
	}
}
int main(){
	int n;
	dic.resize(21);
	cin>>n;
	fr(i,n){
		string tmp;
		cin>>tmp;
		dic[tmp.size()].push_back(tmp);
	}
	int t;
	cin>>t;
	string tmp;
	getline(cin,tmp);
	getline(cin,tmp);
	while(t--){
		vs.clear();
		while(getline(cin,tmp)){
			if(tmp=="")break;
			iss in(tmp);
			string a;
			while(in>>a){
				vs.push_back(a);	
			}	
		}
		run();
	}
	return 0;
}