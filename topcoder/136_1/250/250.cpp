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


class MemberCheck{
public:
	vector<string> whosDishonest(vector<string> c1,vector<string> c2,vector<string> c3){
		int i,j;
		vector<string> tmp,ret;
		for(i=0;i<c1.size();i++){
			for(j=0;j<tmp.size();j++)
				if(c1[i]==tmp[j])break;
			if(j==tmp.size())tmp.push_back(c1[i]);
		}
		for(i=0;i<c2.size();i++){
			for(j=0;j<tmp.size();j++)
				if(c2[i]==tmp[j])break;
			if(j==tmp.size())tmp.push_back(c2[i]);
		}
		for(i=0;i<c3.size();i++){
			for(j=0;j<tmp.size();j++)
				if(c3[i]==tmp[j])break;
			if(j==tmp.size())tmp.push_back(c3[i]);
		}
		for(i=0;i<tmp.size();i++){
			int t=0;
			for(j=0;j<c1.size();j++)
				if(c1[j]==tmp[i]){
					t++;
					break;
				}
			for(j=0;j<c2.size();j++)
				if(c2[j]==tmp[i]){t++;break;}
			for(j=0;j<c3.size();j++)
				if(c3[j]==tmp[i]){t++;break;}
			if(t>1)ret.push_back(tmp[i]);
		}
		sort(ret.begin(),ret.end());
		return ret;
	}
};




void test0(){
	string _club1[]={"JOHN","JOHN","FRED","PEG"};
	vector<string> club1(_club1+0,_club1+sizeof(_club1)/sizeof(string));
	string _club2[]={"PEG","GEORGE"};
	vector<string> club2(_club2+0,_club2+sizeof(_club2)/sizeof(string));
	string _club3[]={"GEORGE","DAVID"};
	vector<string> club3(_club3+0,_club3+sizeof(_club3)/sizeof(string));
	string _whosDishonest[]= { "GEORGE",  "PEG" };
	vector<string> whosDishonest(_whosDishonest+0,_whosDishonest+sizeof(_whosDishonest)/sizeof(string));
	MemberCheck _MemberCheck;
	vector<string> ret=_MemberCheck.whosDishonest(club1,club2,club3);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"club1 = "<<club1<<endl;
	cout<<"club2 = "<<club2<<endl;
	cout<<"club3 = "<<club3<<endl;
	cout<<"expected to return "<<whosDishonest<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==whosDishonest)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _club1[]={"DOUG","DOUG","DOUG","DOUG","DOUG"};
	vector<string> club1(_club1+0,_club1+sizeof(_club1)/sizeof(string));
	string _club2[]={"BOBBY","BOBBY"};
	vector<string> club2(_club2+0,_club2+sizeof(_club2)/sizeof(string));
	string _club3[]={"JAMES"};
	vector<string> club3(_club3+0,_club3+sizeof(_club3)/sizeof(string));
	vector<string> whosDishonest(0);
	MemberCheck _MemberCheck;
	vector<string> ret=_MemberCheck.whosDishonest(club1,club2,club3);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"club1 = "<<club1<<endl;
	cout<<"club2 = "<<club2<<endl;
	cout<<"club3 = "<<club3<<endl;
	cout<<"expected to return "<<whosDishonest<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==whosDishonest)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _club1[]={"BOBBY"};
	vector<string> club1(_club1+0,_club1+sizeof(_club1)/sizeof(string));
	string _club2[]={"BOB","BOBBY"};
	vector<string> club2(_club2+0,_club2+sizeof(_club2)/sizeof(string));
	string _club3[]={"BOB"};
	vector<string> club3(_club3+0,_club3+sizeof(_club3)/sizeof(string));
	string _whosDishonest[]= { "BOB",  "BOBBY" };
	vector<string> whosDishonest(_whosDishonest+0,_whosDishonest+sizeof(_whosDishonest)/sizeof(string));
	MemberCheck _MemberCheck;
	vector<string> ret=_MemberCheck.whosDishonest(club1,club2,club3);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"club1 = "<<club1<<endl;
	cout<<"club2 = "<<club2<<endl;
	cout<<"club3 = "<<club3<<endl;
	cout<<"expected to return "<<whosDishonest<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==whosDishonest)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string _club1[]={"BOBBY","HUGH","LIZ","GEORGE"};
	vector<string> club1(_club1+0,_club1+sizeof(_club1)/sizeof(string));
	string _club2[]={"ELIZABETH","WILL"};
	vector<string> club2(_club2+0,_club2+sizeof(_club2)/sizeof(string));
	string _club3[]={"BOB","BOBBY","BOBBY","PAM","LIZ","BOBBY","BOBBY","WILL"};
	vector<string> club3(_club3+0,_club3+sizeof(_club3)/sizeof(string));
	string _whosDishonest[]= { "BOBBY",  "LIZ",  "WILL" };
	vector<string> whosDishonest(_whosDishonest+0,_whosDishonest+sizeof(_whosDishonest)/sizeof(string));
	MemberCheck _MemberCheck;
	vector<string> ret=_MemberCheck.whosDishonest(club1,club2,club3);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"club1 = "<<club1<<endl;
	cout<<"club2 = "<<club2<<endl;
	cout<<"club3 = "<<club3<<endl;
	cout<<"expected to return "<<whosDishonest<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==whosDishonest)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string _club1[]={"JAMES","HUGH","HUGH","GEORGE","ELIZABETH","ELIZABETH","HUGH","DAVID","ROBERT","DAVID","BOB","BOBBY","PAM","JAMES","JAMES"};
	vector<string> club1(_club1+0,_club1+sizeof(_club1)/sizeof(string));
	string _club2[]={"BOBBY","ROBERT","GEORGE","JAMES","PEG","JAMES","DAVID","JOHN","LIZ","SANDRA","GEORGE","JOHN","GEORGE","ELIZABETH","LIZ","JAMES"};
	vector<string> club2(_club2+0,_club2+sizeof(_club2)/sizeof(string));
	string _club3[]={"ROBERT","ROBERT","ROBERT","SANDRA","PAM","BOB","LIZ","GEORGE"};
	vector<string> club3(_club3+0,_club3+sizeof(_club3)/sizeof(string));
	string _whosDishonest[]={ "BOB", "BOBBY", "DAVID", "ELIZABETH", "GEORGE", "JAMES", "LIZ", "PAM", "ROBERT", "SANDRA" };
	vector<string> whosDishonest(_whosDishonest+0,_whosDishonest+sizeof(_whosDishonest)/sizeof(string));
	MemberCheck _MemberCheck;
	vector<string> ret=_MemberCheck.whosDishonest(club1,club2,club3);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"club1 = "<<club1<<endl;
	cout<<"club2 = "<<club2<<endl;
	cout<<"club3 = "<<club3<<endl;
	cout<<"expected to return "<<whosDishonest<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==whosDishonest)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string _club1[]={"LIZ","WILL","JAMES"};
	vector<string> club1(_club1+0,_club1+sizeof(_club1)/sizeof(string));
	string _club2[]={"JOHN","ROBERT","GEORGE","LIZ","PEG","HUGH","BOB","BOBBY","ROBERT","ELIZABETH","DAVID"};
	vector<string> club2(_club2+0,_club2+sizeof(_club2)/sizeof(string));
	string _club3[]={"PAM","DAVID","SANDRA","GEORGE","JOHN","ROBERT","SANDRA","GEORGE"};
	vector<string> club3(_club3+0,_club3+sizeof(_club3)/sizeof(string));
	string _whosDishonest[]= { "DAVID",  "GEORGE",  "JOHN",  "LIZ",  "ROBERT" };
	vector<string> whosDishonest(_whosDishonest+0,_whosDishonest+sizeof(_whosDishonest)/sizeof(string));
	MemberCheck _MemberCheck;
	vector<string> ret=_MemberCheck.whosDishonest(club1,club2,club3);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"club1 = "<<club1<<endl;
	cout<<"club2 = "<<club2<<endl;
	cout<<"club3 = "<<club3<<endl;
	cout<<"expected to return "<<whosDishonest<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==whosDishonest)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test6(){
	string _club1[]={"PEG","ROBERT","PAM","JOHN","DAVID","JOHN","ROBERT","GEORGE","HUGH","WILL","JAMES","JAMES","BOBBY","BOBBY","SANDRA"};
	vector<string> club1(_club1+0,_club1+sizeof(_club1)/sizeof(string));
	string _club2[]={"SANDRA","BOB","PAM","JAMES","WILL","DAVID","BOBBY","GEORGE","WILL","LIZ","BOBBY","ROBERT","WILL","BOB","BOBBY","ELIZABETH","HUGH"};
	vector<string> club2(_club2+0,_club2+sizeof(_club2)/sizeof(string));
	string _club3[]={"WILL","PEG","ELIZABETH","DAVID","HUGH","BOBBY","JOHN","SANDRA","ELIZABETH","ELIZABETH","SANDRA","GEORGE","PAM","ELIZABETH","BOBBY","DAVID","PAM"};
	vector<string> club3(_club3+0,_club3+sizeof(_club3)/sizeof(string));
	string _whosDishonest[]={ "BOBBY", "DAVID", "ELIZABETH", "GEORGE", "HUGH", "JAMES", "JOHN", "PAM", "PEG", "ROBERT", "SANDRA", "WILL" };
	vector<string> whosDishonest(_whosDishonest+0,_whosDishonest+sizeof(_whosDishonest)/sizeof(string));
	MemberCheck _MemberCheck;
	vector<string> ret=_MemberCheck.whosDishonest(club1,club2,club3);
	cout<<"--------------------test 6--------------------"<<endl;
	cout<<"club1 = "<<club1<<endl;
	cout<<"club2 = "<<club2<<endl;
	cout<<"club3 = "<<club3<<endl;
	cout<<"expected to return "<<whosDishonest<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==whosDishonest)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test7(){
	string _club1[]={"AHHOZY","AHHAPLL","ASNV"};
	vector<string> club1(_club1+0,_club1+sizeof(_club1)/sizeof(string));
	string _club2[]={"AHDLTOE","AHUKPJ","AHDENCTPP","AHDENCJ","AHDLNZC","AHDLTOGG","AHHAPMBG","ALE","AHBHA","AHUKP","AHDQMILLP","AHDENEDY","AHDENEE","AHHOHVCX","AHISK","AHW","AQDB","AHUP","AQDBNPU","AGWZUV","AHHOSUW","AHXS","AHDENCP","AHDQM","AHDLTURV","AHBHVV","AHDQMILL","AHDQMD","AHH","AHDLTU","AHISFNO","AHURF","AH","AHHAPNQ","AQPL","AHDXL","AHDLTUGX","AHDLT","AHUKRC","AHDLTUGX","AQDTXYX","AGWZS"};
	vector<string> club2(_club2+0,_club2+sizeof(_club2)/sizeof(string));
	string _club3[]={"AHHAPMFF","AHURA","AHHOZ","AHISKH","AHUPR","AHHAPM","AHUKRHIN","AHHAP","AHDLTMO","AHDLTUJ","AHDQY","AHUK","AHDENEDY","AHWK","AHHOZGJJ","AHXS","AHDLTUREL","AHHOZQNL","AHHOSUWOS"};
	vector<string> club3(_club3+0,_club3+sizeof(_club3)/sizeof(string));
	string _whosDishonest[]= { "AHDENEDY",  "AHXS" };
	vector<string> whosDishonest(_whosDishonest+0,_whosDishonest+sizeof(_whosDishonest)/sizeof(string));
	MemberCheck _MemberCheck;
	vector<string> ret=_MemberCheck.whosDishonest(club1,club2,club3);
	cout<<"--------------------test 7--------------------"<<endl;
	cout<<"club1 = "<<club1<<endl;
	cout<<"club2 = "<<club2<<endl;
	cout<<"club3 = "<<club3<<endl;
	cout<<"expected to return "<<whosDishonest<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==whosDishonest)
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
	test7();
	return 0;
}
