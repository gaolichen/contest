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


struct NODE{
	string name;
	int r;
	double scor;
	bool operator<(const NODE &b)const {
		if(r!=b.r)return r<b.r;
		if(fabs(scor-b.scor)>0.05)return scor>b.scor;
		return name<b.name;
	}

};
	
class ContestScore{
public:
	vector<int> proc(vector<double> b){
		int i,j,max=-1;
		char mark[100];
		vector<int> c;
		cls(mark);
		c.clear();
		c.resize(b.size());
		for(i=0;i<b.size();i++){
			max=-1;
			for(j=0;j<b.size();j++)
				if(!mark[j]&&(max==-1||b[j]>b[max]))max=j;
			mark[max]=1;
			c[i]=max;
		}
		vector<int> d;
		d.resize(b.size());
		for(i=0,j=0;i<c.size();i++){
			if(i==0||b[c[i]]!=b[c[i-1]])j=i+1;
			d[c[i]]=j;
		}
		return d;
	}
	vector<string> sortResults(vector<string> data){
		vector<NODE> a;
		vector< vector< double > > v;
		VS ret;
		if(data.size()==0)return ret;
		int i,j;
		a.resize(data.size());
		v.resize(data.size());
		for(i=0;i<data.size();i++){
			s2in(data[i],in);
			in>>a[i].name;
			a[i].r=0;
			a[i].scor=0;
			double tmp;
			while(in>>tmp){
				v[i].push_back(tmp);
				a[i].scor+=tmp;
			}
		}
		vector<double> b;
		vector<int> c;
		int k;
		for(i=0;i<v[0].size();i++){
			for(j=0,b.clear();j<v.size();j++){
				b.push_back(v[j][i]);	
			}
			c=proc(b);
			for(k=0;k<c.size();k++)
				a[k].r+=c[k];
		}
		sort(a.begin(),a.end());	
		for(i=0;i<a.size();i++){
			char buf[10000];
			sprintf(buf,"%s %d %.1lf",a[i].name.c_str(),a[i].r,a[i].scor);
			ret.push_back(buf);
		}
		return ret;
	}
};




void test0(){
	string _data[]={"AAA 85.7 98.1 86.4 46.9 01.8 88.2 04.6 54.5", "AAAAAA 37.3 15.5 96.1 67.1 75.8 42.4 32.7 20.7", "AAAAAAA 71.4 18.4 09.8 39.3 54.2 57.5 73.4 63.6", "AAAAA 31.7 30.0 39.0 68.5 42.1 88.2 54.6 41.0", "AA 76.5 98.1 15.3 88.7 01.8 54.7 94.1 54.5", "AAAAAAAA 35.3 33.1 86.4 18.5 65.8 47.3 00.7 84.4", "AAAAAAAAAA 65.4 19.4 22.2 46.9 39.6 37.4 63.5 54.2", "AAAA 71.2 80.0 50.2 72.5 70.8 31.1 02.3 17.0", "A 72.5 38.9 12.0 98.5 85.1 94.6 95.0 98.2", "AAAAAAAAA 31.1 45.8 24.4 68.4 23.1 12.0 04.6 94.9"};
	vector<string> data(_data+0,_data+sizeof(_data)/sizeof(string));
	string _sortResults[]= {"A 22 594.8", "AA 34 483.7", "AAA 34 466.2", "AAAA 46 395.1", "AAAAA 46 395.1", "AAAAAA 48 387.6", "AAAAAAA 48 387.6", "AAAAAAAA 49 371.5", "AAAAAAAAA 52 304.3", "AAAAAAAAAA 54 348.6"};
	vector<string> sortResults(_sortResults+0,_sortResults+sizeof(_sortResults)/sizeof(string));
	ContestScore _ContestScore;
	vector<string> ret=_ContestScore.sortResults(data);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"data = "<<data<<endl;
	cout<<"expected to return "<<sortResults<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==sortResults)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _data[]={"STANFORD 85.3 90.1 82.6 84.6 96.6 94.5 87.3 90.3", "MIT 95.5 83.9 80.4 85.5 98.7 98.3 96.7 82.7", "PRINCETON 99.2 79.1 87.6 85.1 93.6 96.4 86.0 90.6", "HARVARD 83.6 92.0 85.5 94.3 97.5 91.5 92.5 83.0", "YALE 99.5 92.6 86.2 82.0 96.4 92.6 84.5 78.6", "COLUMBIA 97.2 87.6 81.7 93.7 88.0 86.3 95.9 89.6", "BROWN 92.2 95.8 92.1 81.5 89.5 87.0 95.5 86.4", "PENN 96.3 80.7 81.2 91.6 85.8 92.2 83.9 87.8", "CORNELL 88.0 83.7 85.0 83.8 99.8 92.1 91.0 88.9"};
	vector<string> data(_data+0,_data+sizeof(_data)/sizeof(string));
	string _sortResults[]={ "PRINCETON 34 717.6", "MIT 36 721.7", "HARVARD 38 719.9", "COLUMBIA 39 720.0", "STANFORD 39 711.3", "YALE 40 712.4", "BROWN 41 720.0", "CORNELL 42 712.3", "PENN 51 699.5" };
	vector<string> sortResults(_sortResults+0,_sortResults+sizeof(_sortResults)/sizeof(string));
	ContestScore _ContestScore;
	vector<string> ret=_ContestScore.sortResults(data);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"data = "<<data<<endl;
	cout<<"expected to return "<<sortResults<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==sortResults)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	vector<string> data(0);
	vector<string> sortResults(0);
	ContestScore _ContestScore;
	vector<string> ret=_ContestScore.sortResults(data);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"data = "<<data<<endl;
	cout<<"expected to return "<<sortResults<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==sortResults)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string _data[]={"AA 90.0 80.0 70.0 60.0 50.0 40.0", "BBB 80.0 70.0 60.0 50.0 40.0 90.0", "EEE 70.0 60.0 50.0 40.0 90.0 80.0", "AAA 60.0 50.0 40.0 90.0 80.0 70.0", "DDD 50.0 40.0 90.0 80.0 70.0 60.0", "CCC 40.0 90.0 80.0 70.0 60.0 50.0"};
	vector<string> data(_data+0,_data+sizeof(_data)/sizeof(string));
	string _sortResults[]={ "AA 21 390.0", "AAA 21 390.0", "BBB 21 390.0", "CCC 21 390.0", "DDD 21 390.0", "EEE 21 390.0" };
	vector<string> sortResults(_sortResults+0,_sortResults+sizeof(_sortResults)/sizeof(string));
	ContestScore _ContestScore;
	vector<string> ret=_ContestScore.sortResults(data);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"data = "<<data<<endl;
	cout<<"expected to return "<<sortResults<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==sortResults)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string _data[]={"A 00.1", "B 05.2", "C 29.0","D 00.0"};
	vector<string> data(_data+0,_data+sizeof(_data)/sizeof(string));
	string _sortResults[]= { "C 1 29.0",  "B 2 5.2",  "A 3 0.1",  "D 4 0.0" };
	vector<string> sortResults(_sortResults+0,_sortResults+sizeof(_sortResults)/sizeof(string));
	ContestScore _ContestScore;
	vector<string> ret=_ContestScore.sortResults(data);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"data = "<<data<<endl;
	cout<<"expected to return "<<sortResults<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==sortResults)
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

/*
{"AAA 85.7 98.1 86.4 46.9 01.8 88.2 04.6 54.5", "AAAAAA 37.3 15.5 96.1 67.1 75.8 42.4 32.7 20.7", "AAAAAAA 71.4 18.4 09.8 39.3 54.2 57.5 73.4 63.6", "AAAAA 31.7 30.0 39.0 68.5 42.1 88.2 54.6 41.0", "AA 76.5 98.1 15.3 88.7 01.8 54.7 94.1 54.5", "AAAAAAAA 35.3 33.1 86.4 18.5 65.8 47.3 00.7 84.4", "AAAAAAAAAA 65.4 19.4 22.2 46.9 39.6 37.4 63.5 54.2", "AAAA 71.2 80.0 50.2 72.5 70.8 31.1 02.3 17.0", "A 72.5 38.9 12.0 98.5 85.1 94.6 95.0 98.2", "AAAAAAAAA 31.1 45.8 24.4 68.4 23.1 12.0 04.6 94.9"}]
    EXPECTED: {"A 22 594.8", "AA 34 483.7", "AAA 34 466.2", "AAAA 46 395.1", "AAAAA 46 395.1", "AAAAAA 48 387.6", "AAAAAAA 48 387.6", "AAAAAAAA 49 371.5", "AAAAAAAAA 52 304.3", "AAAAAAAAAA 54 348.6"}
    RECEIVED: {"A 22 594.8", "AA 34 483.7", "AAA 34 466.2", "AAAA 46 395.1", "AAAAA 46 395.1", "AAAAAAA 48 387.6", "AAAAAA 48 387.6", "AAAAAAAA 49 371.5", "AAAAAAAAA 52 304.3", "AAAAAAAAAA 54 348.6"}

*/