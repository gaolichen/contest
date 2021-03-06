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
	for (vector<T>::iterator i=d.begin();i!=d.end();i++)
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


class BossFight{
public:
	vector<int> getHealthRange(vector<string> a,vector<string> b){
		int i,j,at[100],t;
		vector<int>ret;
		for(i=0;i<a.size();i++){
			for(j=0;j<a[i].length();j++)
				if(a[i][j]==' ')break;
			a[i][j]='\0';
			sscanf(a[i].c_str()+j+1,"%d",&t);
			at[i]=t;
		}
		int s,st,k;
		char buf[1000];
		t=s=0;
		string temp;
		ret.push_back(0);
		ret.push_back(2100000000);
		for(i=0;i<b.size();i++){
			t=s=0;
			st=0;
			while(st<b[i].length()&&b[i][st]==' ')st++;
			for(j=st;j<b[i].length();j++)
				if(b[i][j]==' '){
					b[i][j]='\0';
					for(k=st;k<j;k++)
						temp+=b[i][k];
					for(k=0;k<a.size();k++)
						if(a[k]==temp)break;
						t+=at[k];
						s=t;
						st=j+1;
						while(st<b[i].length()&&b[i][st]==' ')st++;
						j=st;
				}
			if(s>ret[0])ret[0]=s;
			if(t<ret[1])ret[1]=t;
		}
		return ret;
	}
};




void test0(){
	string _attacks[]={"PUNCH 5","KICK 10","THROW 12"};
	vector<string> attacks(_attacks+0,_attacks+sizeof(_attacks)/sizeof(string));
	string _battles[]={"KICK KICK PUNCH"};
	vector<string> battles(_battles+0,_battles+sizeof(_battles)/sizeof(string));
	int _getHealthRange[]= { 21,  25 };
	vector<int> getHealthRange(_getHealthRange+0,_getHealthRange+sizeof(_getHealthRange)/sizeof(int));
	BossFight _BossFight;
	vector<int> ret=_BossFight.getHealthRange(attacks,battles);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"attacks = "<<attacks<<endl;
	cout<<"battles = "<<battles<<endl;
	cout<<"expected to return "<<getHealthRange<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getHealthRange)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _attacks[]={"PUNCH 5","KICK 10","THROW 12"};
	vector<string> attacks(_attacks+0,_attacks+sizeof(_attacks)/sizeof(string));
	string _battles[]={"KICK KICK PUNCH","THROW KICK THROW","THROW THROW"};
	vector<string> battles(_battles+0,_battles+sizeof(_battles)/sizeof(string));
	int _getHealthRange[]= { 23,  24 };
	vector<int> getHealthRange(_getHealthRange+0,_getHealthRange+sizeof(_getHealthRange)/sizeof(int));
	BossFight _BossFight;
	vector<int> ret=_BossFight.getHealthRange(attacks,battles);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"attacks = "<<attacks<<endl;
	cout<<"battles = "<<battles<<endl;
	cout<<"expected to return "<<getHealthRange<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getHealthRange)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _attacks[]={"POKE 1"};
	vector<string> attacks(_attacks+0,_attacks+sizeof(_attacks)/sizeof(string));
	string _battles[]={"POKE POKE POKE POKE POKE POKE POKE POKE POKE POKE"};
	vector<string> battles(_battles+0,_battles+sizeof(_battles)/sizeof(string));
	int _getHealthRange[]= { 10,  10 };
	vector<int> getHealthRange(_getHealthRange+0,_getHealthRange+sizeof(_getHealthRange)/sizeof(int));
	BossFight _BossFight;
	vector<int> ret=_BossFight.getHealthRange(attacks,battles);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"attacks = "<<attacks<<endl;
	cout<<"battles = "<<battles<<endl;
	cout<<"expected to return "<<getHealthRange<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getHealthRange)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string _attacks[]={"OVERKILL 9999"};
	vector<string> attacks(_attacks+0,_attacks+sizeof(_attacks)/sizeof(string));
	string _battles[]={"OVERKILL"};
	vector<string> battles(_battles+0,_battles+sizeof(_battles)/sizeof(string));
	int _getHealthRange[]= { 1,  9999 };
	vector<int> getHealthRange(_getHealthRange+0,_getHealthRange+sizeof(_getHealthRange)/sizeof(int));
	BossFight _BossFight;
	vector<int> ret=_BossFight.getHealthRange(attacks,battles);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"attacks = "<<attacks<<endl;
	cout<<"battles = "<<battles<<endl;
	cout<<"expected to return "<<getHealthRange<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getHealthRange)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string _attacks[]={"A 965939","B 642876","C 579290","D 305875","E 206139","F 202795","G 307979","H 144467","I 866386","J 943978","K 168660","L 559739","M 878626","N 383086","O 673845","P 826654","Q 980470","R 619790","S 587024","T 467245","U 168317","V 977394","W 786","X 16241","Y 400479","Z 893457"};
	vector<string> attacks(_attacks+0,_attacks+sizeof(_attacks)/sizeof(string));
	string _battles[]={"R A O B O K P V T S D U K I Z T F Y","F W V J H Y X P P E X V E X S L L A A F R","A C V I X E R T Y M X C W V Q R F S K","G A C D T R W Y J B J N N A I Q Q","U U U N F Q L N O W D Q D T Y Z U S L P Y S","O F N V V Q O B D A U K E U K I P I","I A K M O P F T V W G C M X G Y Q M","S J N Y L J D E I W G F K L J N Z R F X H K I","T E Q C E D L S O Q C P Q N O E G V","F P Z W V A L K P X K D W Q O Q R P C"};
	vector<string> battles(_battles+0,_battles+sizeof(_battles)/sizeof(string));
	int _getHealthRange[]= { 9994870,  10076486 };
	vector<int> getHealthRange(_getHealthRange+0,_getHealthRange+sizeof(_getHealthRange)/sizeof(int));
	BossFight _BossFight;
	vector<int> ret=_BossFight.getHealthRange(attacks,battles);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"attacks = "<<attacks<<endl;
	cout<<"battles = "<<battles<<endl;
	cout<<"expected to return "<<getHealthRange<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==getHealthRange)
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
