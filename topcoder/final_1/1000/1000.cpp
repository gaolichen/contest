//program framework generated with WishingBone's parser :)-

//common header
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <strstream>
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


char mark[20][20];
int done[(1<<16)+1][2];
int can[(1<<16)+1][2],cnt,tot,n,res,sk[(1<<17)+1],step[(1<<17)+1];
vector<int> ww;

int check(int k,int m){
	int i;
	for(i=0;i<m;i++)
		if(mark[sk[i]][k])return 0;
	return 1;
}

void dfs(int k,int m,int w,int p){
	if(k==n)return;
	if(ww[k]+w>tot){
		dfs(k+1,m,w,p);
		return ;
	}
	if(check(k,m)){
		can[cnt++][0]=p+(1<<k);
		can[cnt-1][1]=m+1;
		sk[m]=k;
		dfs(k+1,m+1,w+ww[k],p+(1<<k));
	}
	dfs(k+1,m,w,p);
}

int cmp(const void *a,const void *b){
	return *((int*)a+1)-*((int*)b+1);
}

void dfs2(int p,int step,int flag){
	if(res!=-1&&step>=res)return;
	if(p==0){
		if(res==-1||res>step)
			res=step;
		return;
	}
	int i;
	if(flag){
		for(i=0;i<n;i++)
			if(!((1<<i)&p)){
				if(done[p+(1<<i)][0]&&done[p+(1<<i)][0]<=step+1)continue;
				done[p+(1<<i)][0]=step+1;
				dfs2(p+(1<<i),step+1,0);
			}
		return;
	}
	else{
		for(i=cnt-1;i>=0;i--)
			if((can[i][0]&p)==can[i][0]){
				if(done[p-can[i][0]][1]&&done[p-can[i][0]][1]<=step+1)continue;
				done[p-can[i][0]][1]=step+1;
				dfs2(p-can[i][0],step+1,1);
			}
	}
}

int check1(int i,int p){
	int flag=(p>=0?0:1);
	if(!((can[i][0]&abs(p))==(!flag)*can[i][0]))return 0;
	if(done[abs(can[i][0]-p)][!flag])return 0;
	return 1;
}

int bfs(){
	int i,opn,cls;
	sk[opn=cls=0]=(1<<n)-1;
	step[0]=0;
	done[(1<<n)-1][0]=1;
	while(opn<=cls){
//		cout<<sk[opn]<<' ';
		for(i=0;i<cnt;i++)
			if(check1(i,sk[opn])){
				step[++cls]=step[opn]+1;
				sk[cls]=can[i][0]-sk[opn];
				done[abs(sk[cls])][sk[cls]>=0?0:1]=1;
				if(sk[cls]==0){
					return step[cls];
				}
			}
		opn++;
	}
	cout<<endl;
	return -1;
}
class Boats{
public:
	int minCrossings(vector<string> en,vector<int> w,int mw){
		int i,j;
		memset(mark,0,sizeof(mark));
		for(i=0;i<en.size();i++){
			istrstream msin(en[i].c_str());
			while(msin>>j){
				mark[i][j]=1;
				mark[j][i]=1;
			}
		}
		
		cnt=0;
		ww=w;tot=mw;
		n=w.size();
		dfs(0,0,0,0);
		qsort(can,cnt,sizeof(int)*2,cmp);
		cout<<cnt<<endl;
		memset(done,0,sizeof(done));
		res=-1;
		done[(1<<n)-1][0]=-1;
		dfs2((1<<n)-1,0,0);
		return res;
//		return bfs();
	}
};




void test0(){
	string _enemies[]={"1 3","0 2","1 3","0 2"};
	vector<string> enemies(_enemies+0,_enemies+sizeof(_enemies)/sizeof(string));
	int _weights[]={1,1,1,1};
	vector<int> weights(_weights+0,_weights+sizeof(_weights)/sizeof(int));
	int maxWeight=10;
	int minCrossings= 5;
	Boats _Boats;
	int ret=_Boats.minCrossings(enemies,weights,maxWeight);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"enemies = "<<enemies<<endl;
	cout<<"weights = "<<weights<<endl;
	cout<<"maxWeight = "<<maxWeight<<endl;
	cout<<"expected to return "<<minCrossings<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minCrossings)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _enemies[]={"1 3","4 2","","0 1 4","3"};
	vector<string> enemies(_enemies+0,_enemies+sizeof(_enemies)/sizeof(string));
	int _weights[]={20,4,12,8,9};
	vector<int> weights(_weights+0,_weights+sizeof(_weights)/sizeof(int));
	int maxWeight=30;
	int minCrossings= 9;
	Boats _Boats;
	int ret=_Boats.minCrossings(enemies,weights,maxWeight);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"enemies = "<<enemies<<endl;
	cout<<"weights = "<<weights<<endl;
	cout<<"maxWeight = "<<maxWeight<<endl;
	cout<<"expected to return "<<minCrossings<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minCrossings)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _enemies[]={"1 3","4 2","","0 1 4","3"};
	vector<string> enemies(_enemies+0,_enemies+sizeof(_enemies)/sizeof(string));
	int _weights[]={20,4,12,8,9};
	vector<int> weights(_weights+0,_weights+sizeof(_weights)/sizeof(int));
	int maxWeight=50;
	int minCrossings= 7;
	Boats _Boats;
	int ret=_Boats.minCrossings(enemies,weights,maxWeight);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"enemies = "<<enemies<<endl;
	cout<<"weights = "<<weights<<endl;
	cout<<"maxWeight = "<<maxWeight<<endl;
	cout<<"expected to return "<<minCrossings<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minCrossings)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string _enemies[]={"","","","","","","","","","","","","","","",""};
	vector<string> enemies(_enemies+0,_enemies+sizeof(_enemies)/sizeof(string));
	int _weights[]={10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
	vector<int> weights(_weights+0,_weights+sizeof(_weights)/sizeof(int));
	int maxWeight=70;
	int minCrossings= 5;
	Boats _Boats;
	int ret=_Boats.minCrossings(enemies,weights,maxWeight);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"enemies = "<<enemies<<endl;
	cout<<"weights = "<<weights<<endl;
	cout<<"maxWeight = "<<maxWeight<<endl;
	cout<<"expected to return "<<minCrossings<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minCrossings)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string _enemies[]={"","","",""};
	vector<string> enemies(_enemies+0,_enemies+sizeof(_enemies)/sizeof(string));
	int _weights[]={1,1,1,10};
	vector<int> weights(_weights+0,_weights+sizeof(_weights)/sizeof(int));
	int maxWeight=9;
	int minCrossings= -1;
	Boats _Boats;
	int ret=_Boats.minCrossings(enemies,weights,maxWeight);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"enemies = "<<enemies<<endl;
	cout<<"weights = "<<weights<<endl;
	cout<<"maxWeight = "<<maxWeight<<endl;
	cout<<"expected to return "<<minCrossings<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minCrossings)
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
