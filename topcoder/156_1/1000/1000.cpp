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
int mx[9]={0,1,0,-1,1,1,-1,-1,0};
int my[9]={1,0,-1,0,1,-1,-1,1,0};
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

#define MAXN 400*400
class PathFinding{
public:
	VS bb;
	int bfs(int sa,int sb){
		int opn,cls,i,step[MAXN+1];
		int j;
		char mark[401][401];
		int sk[MAXN+1];
		cls(mark);
		mark[sa][sb]=1;
		sk[opn=cls=0]=sa*400+sb;
		step[0]=0;
		while(opn<=cls){
			int x1,y1,x2,y2;
			x2=sk[opn]%400;
			y2=x2%bb[0].length();
			x2/=bb[0].length();
			x1=sk[opn]/400;
			y1=x1%bb[0].length();
			x1/=bb[0].length();
//			cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
			for(i=0;i<9;i++)
				if(inmat(x1+mx[i],y1+my[i],bb.size(),bb[0].length())&&
					bb[x1+mx[i]][y1+my[i]]!='X')
				for(j=0;j<9;j++)
					if(inmat(x2+mx[j],y2+my[j],bb.size(),bb[0].length())&&
						bb[x2+mx[j]][y2+my[j]]!='X'){
						if((x1+mx[i]!=x2||y1+my[i]!=y2)||(x2+mx[j]!=x1||y2+my[j]!=y1)){
							int tx1,ty1,tx2,ty2;
//							cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
//							cout<<x1+mx[i]<<' '<<y1+my[i]<<' '<<x2+mx[j]<<' '<<y2+my[j]<<endl<<endl;
							tx1=(x1+mx[i])*bb[0].length();
							ty1=y1+my[i];
							tx2=(x2+mx[j])*bb[0].length();
							ty2=y2+my[j];
							if(tx1==tx2&&ty1==ty2||mark[tx1+ty1][tx2+ty2])continue;
							mark[tx1+ty1][tx2+ty2]=1;
							sk[++cls]=(tx1+ty1)*400+tx2+ty2;
							step[cls]=step[opn]+1;
							if(tx1+ty1==sb&&tx2+ty2==sa)return step[cls];
						}
					}
			opn++;
		}
		return -1;
	}
	int minTurns(vector<string> b){
		int i,j;
		int sa,sb;
		bb=b;
		for(i=0;i<b.size();i++)
			for(j=0;j<b[0].length();j++){
				if(b[i][j]=='A')
					sa=i*b[0].length()+j;
				if(b[i][j]=='B')
					sb=i*b[0].length()+j;
			}
//		cout<<sa<<' '<<sb<<endl;
		return bfs(sa,sb);
	}
};




void test0(){
	string _board[]={"....", ".A..", "..B.", "...."};
	vector<string> board(_board+0,_board+sizeof(_board)/sizeof(string));
	int minTurns= 2;
	PathFinding _PathFinding;
	int ret=_PathFinding.minTurns(board);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"board = "<<board<<endl;
	cout<<"expected to return "<<minTurns<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minTurns)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _board[]={"XXXXXXXXX", "A...X...B", "XXXXXXXXX"};
	vector<string> board(_board+0,_board+sizeof(_board)/sizeof(string));
	int minTurns= -1;
	PathFinding _PathFinding;
	int ret=_PathFinding.minTurns(board);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"board = "<<board<<endl;
	cout<<"expected to return "<<minTurns<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minTurns)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _board[]={"XXXXXXXXX", "A.......B", "XXXXXXXXX"};
	vector<string> board(_board+0,_board+sizeof(_board)/sizeof(string));
	int minTurns= -1;
	PathFinding _PathFinding;
	int ret=_PathFinding.minTurns(board);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"board = "<<board<<endl;
	cout<<"expected to return "<<minTurns<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minTurns)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string _board[]={"XXXXXXXXX", "A.......B", "XXXX.XXXX"};
	vector<string> board(_board+0,_board+sizeof(_board)/sizeof(string));
	int minTurns= 8;
	PathFinding _PathFinding;
	int ret=_PathFinding.minTurns(board);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"board = "<<board<<endl;
	cout<<"expected to return "<<minTurns<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minTurns)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string _board[]={"...A.XXXXX.....", ".....XXXXX.....", "...............", ".....XXXXX.B...", ".....XXXXX....."};
	vector<string> board(_board+0,_board+sizeof(_board)/sizeof(string));
	int minTurns= 13;
	PathFinding _PathFinding;
	int ret=_PathFinding.minTurns(board);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"board = "<<board<<endl;
	cout<<"expected to return "<<minTurns<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minTurns)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string _board[]={"AB.................X", "XXXXXXXXXXXXXXXXXXX.", "X..................X", ".XXXXXXXXXXXXXXXXXXX", "X..................X", "XXXXXXXXXXXXXXXXXXX.", "X..................X", ".XXXXXXXXXXXXXXXXXXX", "X..................X", "XXXXXXXXXXXXXXXXXXX.", "X..................X", ".XXXXXXXXXXXXXXXXXXX", "X..................X", "XXXXXXXXXXXXXXXXXXX.", "X..................X", ".XXXXXXXXXXXXXXXXXXX", "X..................X", "XXXXXXXXXXXXXXXXXXX.", "...................X", ".XXXXXXXXXXXXXXXXXXX"};
	vector<string> board(_board+0,_board+sizeof(_board)/sizeof(string));
	int minTurns= 379;
	PathFinding _PathFinding;
	int ret=_PathFinding.minTurns(board);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"board = "<<board<<endl;
	cout<<"expected to return "<<minTurns<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==minTurns)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

int main(){
//	test0();
//	test1();
//	test2();
//	test3();
//	test4();
	test5();
	return 0;
}
