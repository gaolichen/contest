
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


class NextRuler{
public:
	char name[200][50];
	struct node{
		int f,m;
	};
	node child[200];
	int count;
	int push(char *buf){
		int i;
		for(i=0;i<count;i++)
			if(strcmp(name[i],buf)==0)return i;
		strcpy(name[count++],buf);
		return count-1;
	}
	string bestClaim(vector<string> r,string o,vector<string> c){
		int i,j,p[200][60],i1,i2,i3,mark[200],flag;
		char buf1[50],buf2[50],buf3[50];
		memset(p,0,sizeof(p));
		count=0;
		for(i=0;i<100;i++){
			child[i].m=0;child[i].f=0;
		}
		for(i=0;i<r.size();i++){
			sscanf(r[i].c_str(),"%s %s %s",buf1,buf2,buf3);
			i1=push(buf1);
			i2=push(buf2);
			i3=push(buf3);
			child[i1].f=i2+1;
			child[i1].m=i3+1;
		}
		memset(mark,0,sizeof(mark));
		for(i=0;i<count;i++)
			if(!child[i].f&&!child[i].m)mark[i]=1;
		for(i=0;i<count;i++)
			if(o==name[i])break;
		mark[i]=1;p[i][0]=1;
		int t;
		while(1){
			flag=0;
			for(i=0;i<count;i++)
				if(!mark[i]&&mark[child[i].f-1]&&mark[child[i].m-1]){
					flag=1;
					for(j=59,t=0;j>0;j--){
						p[i][j]=p[child[i].f-1][j-1]+p[child[i].m-1][j-1];
						p[i][j]+=t;
						t=p[i][j]/2;
						p[i][j]%=2;
					}
					mark[i]=1;
				}
			if(!flag)break;
		}
		int temp[60];
		for(i=0;i<c.size();i++){
			for(j=0;j<count;j++)
				if(c[i]==name[j])break;
			temp[i]=j;
		}
		flag=temp[0];
		for(i=0;i<c.size();i++){
			for(j=0;j<60;j++){
				if(p[temp[i]][j]>p[flag][j]){
					flag=temp[i];break;
				}
				else if(p[temp[i]][j]<p[flag][j])
					break;
			}
		}
		for(i=0;i<c.size();i++)
			if(temp[i]==flag)break;
		string ret;
		ret=name[flag];
		return ret;
	}
};




void test0(){
	string _relation[]={"CharlesI EdwardI Diana", "Philip CharlesI Mistress", "Wilhelm Mary Philip", "Matthew Wilhelm Helen", "EdwardII CharlesI Laura", "Alice Laura CharlesI", "Helen Alice Bernard", "HenriI EdwardII Roxane", "CharlesII Elizabeth HenriI"};
	vector<string> relation(_relation+0,_relation+sizeof(_relation)/sizeof(string));
	string originalruler="EdwardI";
	string _claimants[]={"CharlesII","Matthew"};
	vector<string> claimants(_claimants+0,_claimants+sizeof(_claimants)/sizeof(string));
	string bestClaim= "Matthew";
	NextRuler _NextRuler;
	string ret=_NextRuler.bestClaim(relation,originalruler,claimants);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"relation = "<<relation<<endl;
	cout<<"originalruler = "<<originalruler<<endl;
	cout<<"claimants = "<<claimants<<endl;
	cout<<"expected to return "<<bestClaim<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestClaim)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _relation[]={"A P Q","B Q R","C R P"};
	vector<string> relation(_relation+0,_relation+sizeof(_relation)/sizeof(string));
	string originalruler="Q";
	string _claimants[]={"A","B","C"};
	vector<string> claimants(_claimants+0,_claimants+sizeof(_claimants)/sizeof(string));
	string bestClaim= "A";
	NextRuler _NextRuler;
	string ret=_NextRuler.bestClaim(relation,originalruler,claimants);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"relation = "<<relation<<endl;
	cout<<"originalruler = "<<originalruler<<endl;
	cout<<"claimants = "<<claimants<<endl;
	cout<<"expected to return "<<bestClaim<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestClaim)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _relation[]={"B A x","C A x","D B y","E B y","F C z","G C z","H E F"};
	vector<string> relation(_relation+0,_relation+sizeof(_relation)/sizeof(string));
	string originalruler="A";
	string _claimants[]={"G","H","D"};
	vector<string> claimants(_claimants+0,_claimants+sizeof(_claimants)/sizeof(string));
	string bestClaim= "G";
	NextRuler _NextRuler;
	string ret=_NextRuler.bestClaim(relation,originalruler,claimants);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"relation = "<<relation<<endl;
	cout<<"originalruler = "<<originalruler<<endl;
	cout<<"claimants = "<<claimants<<endl;
	cout<<"expected to return "<<bestClaim<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestClaim)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string _relation[]={"B A x","C B x","D C x","E D x","F E A"};
	vector<string> relation(_relation+0,_relation+sizeof(_relation)/sizeof(string));
	string originalruler="A";
	string _claimants[]={"B","F"};
	vector<string> claimants(_claimants+0,_claimants+sizeof(_claimants)/sizeof(string));
	string bestClaim= "F";
	NextRuler _NextRuler;
	string ret=_NextRuler.bestClaim(relation,originalruler,claimants);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"relation = "<<relation<<endl;
	cout<<"originalruler = "<<originalruler<<endl;
	cout<<"claimants = "<<claimants<<endl;
	cout<<"expected to return "<<bestClaim<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestClaim)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string _relation[]={"b c d", "C D E", "Z a b", "B C D", "G H I", "S T U", "Y Z a", "M N O", "I J K", "d e f", "K L M", "V W X", "N O P", "O P Q", "P Q R", "R S T", "a b c", "U V W", "D E F", "Q R S", "J K L", "W X Y", "A B C", "L M N", "E F G", "H I J", "X Y Z", "T U V", "F G H", "c d e"};
	vector<string> relation(_relation+0,_relation+sizeof(_relation)/sizeof(string));
	string originalruler="f";
	string _claimants[]={"V","D","B","c","K"};
	vector<string> claimants(_claimants+0,_claimants+sizeof(_claimants)/sizeof(string));
	string bestClaim= "V";
	NextRuler _NextRuler;
	string ret=_NextRuler.bestClaim(relation,originalruler,claimants);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"relation = "<<relation<<endl;
	cout<<"originalruler = "<<originalruler<<endl;
	cout<<"claimants = "<<claimants<<endl;
	cout<<"expected to return "<<bestClaim<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestClaim)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test5(){
	string _relation[]={"GYsDbiC pedVJuWgwn tvblYANLn", "ja pedVJuWgwn XCrHQk", "af GYsDbiC ja", "SYP af KGsyREaXx", "RhRezB ja af", "udhX ja kCWtLI", "eLRk af pedVJuWgwn", "VDywf RhRezB SYP", "QDWoRsjR GYsDbiC vKugVgfJy", "kbmgAnQ SYP pedVJuWgwn", "iICNsw ja udhX", "knHPYMfZV QDWoRsjR udhX", "SqDcC SYP af", "VqcZ kbmgAnQ iICNsw", "Vrl pedVJuWgwn ZDoeDmqHaA", "gLIUHspX GYsDbiC VDywf", "JEROn iICNsw VDywf", "I RhRezB LizA", "EA ja kbmgAnQ", "t kbmgAnQ ja", "KomD I ZHMVBrAl", "VBVRPVqOH JEROn eLRk", "WxbeP eLRk I", "xD WxbeP N", "GnaiEpBj QDWoRsjR pedVJuWgwn", "U ja CHzvp", "ZP KomD ng", "zpxtticYl WxbeP ghnCykWWK", "ripXT U OCadB", "fpkMSE U pedVJuWgwn", "Nksgbx xD knHPYMfZV", "QfkikVQdiP VBVRPVqOH SqDcC", "ZZ EA KQ", "qesjbZ GYsDbiC pedVJuWgwn", "vyFURINK SqDcC ZaUz", "FtavXSXi SYP iICNsw", "DXPhbje VqcZ CQ", "XWIwLT VqcZ txTVELdRew", "TgiqhiNHT DXPhbje JEROn", "BIGkoSy vyFURINK G", "kEKpSoxUbj XWIwLT ijQdhry", "vDjDoOGa QfkikVQdiP xD", "RsWUVA JEROn ZIG", "AVPuLo Vrl VqcZ", "RKYJyVBG gLIUHspX WxbeP", "jdrzbg kbmgAnQ U", "AuyhysLBGT DXPhbje JEROn", "Q U WxbeP", "Py EA knHPYMfZV", "bplbwvpO gLIUHspX xD"};
	vector<string> relation(_relation+0,_relation+sizeof(_relation)/sizeof(string));
	string originalruler="pedVJuWgwn";
	string _claimants[]={"ZP", "ZZ", "kEKpSoxUbj", "AVPuLo", "TgiqhiNHT", "Py", "qesjbZ", "VqcZ", "VDywf", "QDWoRsjR", "EA", "AuyhysLBGT", "BIGkoSy", "fpkMSE", "JEROn", "VBVRPVqOH", "zpxtticYl", "Q", "eLRk", "I", "SYP", "KomD", "GYsDbiC", "gLIUHspX", "FtavXSXi"};
	vector<string> claimants(_claimants+0,_claimants+sizeof(_claimants)/sizeof(string));
	string bestClaim= "qesjbZ";
	NextRuler _NextRuler;
	string ret=_NextRuler.bestClaim(relation,originalruler,claimants);
	cout<<"--------------------test 5--------------------"<<endl;
	cout<<"relation = "<<relation<<endl;
	cout<<"originalruler = "<<originalruler<<endl;
	cout<<"claimants = "<<claimants<<endl;
	cout<<"expected to return "<<bestClaim<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==bestClaim)
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
	return 0;
}
