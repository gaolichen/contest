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
#define elem_t i64
struct NODE{
	elem_t w,v;
	bool operator<(const NODE &a)const {
		return (double)v/w>(double)a.v/a.w;
	}
};

vector<NODE> vk,tvk;
elem_t wei[50],val[50];
vector<int> ret,sk;
elem_t best,tot;

void dfs(int k,elem_t w,elem_t v){
	if(v>=best){
		if(v>best||sk.size()<ret.size())
			ret=sk;
		best=v;

	}
	if(k==tvk.size()||w==tot)return ;
	if((double)(tot-w)*tvk[k].v/tvk[k].w+v<best)return;
	if(w+tvk[k].w<=tot){
		sk.push_back(k);
		dfs(k+1,w+tvk[k].w,v+tvk[k].v);
		sk.pop_back();
	}
	dfs(k+1,w,v);
}

vector<int> knap(vector<NODE> vk,elem_t w){
	tvk=vk;
	sort(tvk.begin(),tvk.end());
	ret.clear();
	sk.clear();
	best=0;tot=w;
	dfs(0,0,0);
	vector<int> ans;
	int i,j;
	char mark[50];
	cls(mark);
	for(i=0;i<ret.size();i++)
		for(j=0;j<vk.size();j++)
			if(!mark[j]&&tvk[ret[i]].v==vk[j].v&&tvk[ret[i]].w==vk[j].w){
				ans.push_back(j);
				mark[j]=1;
				break;
			}
	sort(ans.begin(),ans.end());
	cout<<best<<endl;
	return ans;
}

int main(){
	int i,n,w;
	while(cin>>n){
		vk.clear();
		for(i=0;i<n;i++)
			scanf("%I64d",&wei[i]);
		for(i=0;i<n;i++)
			scanf("%I64d",&val[i]);
		for(i=0;i<n;i++){
			NODE tmp;
			tmp.w=wei[i];
			tmp.v=val[i];
			cout<<tmp.w<<' '<<tmp.v<<endl;
			vk.push_back(tmp);
		}
		cin>>w;
		cout<<knap(vk,w)<<endl;
	}
	return 0;
}

/*
415  528  744  555  526  530  274  154  769  428  200  627  470  891  167  974  101  770  2205

2   4   8   16   16   4   8   32   16   16   24   24   8   16   12   1   2   4   8   8   2   4   16   8   8   12   12   4   8   6   100


1   2   1   2   1   2   2   4   2   4   1   1   1   1   2   2   4  
8   4   4   2   8   4   4   4   4   8   1   4   2   1   1   4   1  
15
 

51302   27983   71667   12089   19588   64031   97596   2003   5100   61584   27432   7419   50365   2582   12821   51090   34725   94152   29702   99239   64167   661   40163  
61693   84646   83719   51302   88549   5379   92979   2577   79031   72574   21805   63706   55248   36660   68135   25281   57868   35613   96663   78418   84348   92573   72048   
684929


29
1   2   4   8   16   32   64   128   256   512   1024   2048   4096   8192   16384   32768   65536   131072   262144   524288   1048576   2097152   4194304   8388608   16777216   33554432   67108864   137108864   267108864  
1   2   4   10   18   31   66   129   257   510   1026   2048   4096   8193   16385   32768   65538   131073   262144   524289   1048576   2097154   4194304   8388608   16777216   33554431   67108865   137108862   267108862   
323717290
34
457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823   457823  
238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   238943   
8294839
*/