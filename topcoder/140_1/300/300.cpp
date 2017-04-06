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


class SpriteCollision{
public:
	int in(double tx,double ty,int x,int y,int w,int h){
		if(tx>x&&tx<x+w&&ty>y&&ty<y+h)return 1;
		return 0;
	}
	vector<int> detect(vector<int> x,vector<int> y,vector<int> w,vector<int> h){
		int i,j;
		vector<int> ret;
/*		for(i=0;i<x.size();i++)
			for(j=0;j<x.size();j++)
				if(i!=j){
					if(in(x[i],y[i],x[j],y[j],w[j],h[j])||
						in(x[i],y[i]+h[i],x[j],y[j],w[j],h[j])||
						in(x[i]+w[i],y[i],x[j],y[j],w[j],h[j])||
						in(x[i]+w[i],y[i]+h[i],x[j],y[j],w[j],h[j])||
						in(x[j],y[j],x[i],y[i],w[i],h[i])||
						in(x[j],y[j]+h[j],x[i],y[i],w[i],h[i])||
						in(x[j]+w[j],y[j],x[i],y[i],w[i],h[i])||
						in(x[j]+w[j],y[j]+h[j],x[i],y[i],w[i],h[i])){
						ret.push_back(i);
						break;
					}
					if(x[i]>=x[j]&&x[i]+w[i]<=x[j]+w[j]&&y[i]<=y[j]&&
						y[i]+h[i]>=y[j]+h[j]||x[j]>=x[i]&&x[j]+w[j]<=x[i]+w[i]&&y[i]>=y[j]&&
						y[i]+h[i]<=y[j]+h[j]){
						ret.push_back(i);
						break;
					}

				}
		return ret;*/
		double k,l;
		for(i=0;i<x.size();i++)
			for(j=0;j<x.size();j++)
				if(i!=j){
					for(k=x[i]+0.5;k<=x[i]+w[i];k+=1){
						for(l=y[i]+0.5;l<=y[i]+h[i];l+=1)
							if(in(k,l,x[j],y[j],w[j],h[j])){
								ret.push_back(i);
								break;
							}
						if(l<=y[i]+h[i])break;
					}
					if(k<=x[i]+w[i])break;
				}
		return ret;
	}
};




void test0(){
	int _x[]={1,3,7,1,8,8,6,8,10,11};
	vector<int> x(_x+0,_x+sizeof(_x)/sizeof(int));
	int _y[]={1,3,1,5,3,1,6,7,0,1};
	vector<int> y(_y+0,_y+sizeof(_y)/sizeof(int));
	int _width[]={4,1,2,2,1,1,3,3,2,2};
	vector<int> width(_width+0,_width+sizeof(_width)/sizeof(int));
	int _height[]={3,4,1,2,2,3,1,1,2,2};
	vector<int> height(_height+0,_height+sizeof(_height)/sizeof(int));
	int _detect[]= { 0,  1,  2,  4,  5,  8,  9 };
	vector<int> detect(_detect+0,_detect+sizeof(_detect)/sizeof(int));
	SpriteCollision _SpriteCollision;
	vector<int> ret=_SpriteCollision.detect(x,y,width,height);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
	cout<<"width = "<<width<<endl;
	cout<<"height = "<<height<<endl;
	cout<<"expected to return "<<detect<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==detect)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	int _x[]={10,73,73};
	vector<int> x(_x+0,_x+sizeof(_x)/sizeof(int));
	int _y[]={10,41,41};
	vector<int> y(_y+0,_y+sizeof(_y)/sizeof(int));
	int _width[]={64,16,1};
	vector<int> width(_width+0,_width+sizeof(_width)/sizeof(int));
	int _height[]={32,1,64};
	vector<int> height(_height+0,_height+sizeof(_height)/sizeof(int));
	int _detect[]= { 0,  1,  2 };
	vector<int> detect(_detect+0,_detect+sizeof(_detect)/sizeof(int));
	SpriteCollision _SpriteCollision;
	vector<int> ret=_SpriteCollision.detect(x,y,width,height);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
	cout<<"width = "<<width<<endl;
	cout<<"height = "<<height<<endl;
	cout<<"expected to return "<<detect<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==detect)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	int _x[]={0,64,128,192,0,64,128,192,0,64,128,192,0,64,128,192};
	vector<int> x(_x+0,_x+sizeof(_x)/sizeof(int));
	int _y[]={0,0,0,0,64,64,64,64,128,128,128,128,192,192,192,192};
	vector<int> y(_y+0,_y+sizeof(_y)/sizeof(int));
	int _width[]={64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64};
	vector<int> width(_width+0,_width+sizeof(_width)/sizeof(int));
	int _height[]={64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64};
	vector<int> height(_height+0,_height+sizeof(_height)/sizeof(int));
	vector<int> detect(0);
	SpriteCollision _SpriteCollision;
	vector<int> ret=_SpriteCollision.detect(x,y,width,height);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
	cout<<"width = "<<width<<endl;
	cout<<"height = "<<height<<endl;
	cout<<"expected to return "<<detect<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==detect)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	int _x[]={50,10,0,50,50,100,101};
	vector<int> x(_x+0,_x+sizeof(_x)/sizeof(int));
	int _y[]={50,0,10,50,50,100,101};
	vector<int> y(_y+0,_y+sizeof(_y)/sizeof(int));
	int _width[]={50,1,20,50,50,1,1};
	vector<int> width(_width+0,_width+sizeof(_width)/sizeof(int));
	int _height[]={50,20,1,50,50,1,1};
	vector<int> height(_height+0,_height+sizeof(_height)/sizeof(int));
	int _detect[]= { 0,  1,  2,  3,  4 };
	vector<int> detect(_detect+0,_detect+sizeof(_detect)/sizeof(int));
	SpriteCollision _SpriteCollision;
	vector<int> ret=_SpriteCollision.detect(x,y,width,height);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
	cout<<"width = "<<width<<endl;
	cout<<"height = "<<height<<endl;
	cout<<"expected to return "<<detect<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==detect)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

int main(){
	test0();
	test1();
	test2();
	test3();
	return 0;
}
