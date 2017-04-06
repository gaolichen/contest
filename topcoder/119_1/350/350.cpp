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


class NumberGuess{
public:
	int check(vector<string> qu,vector<string> ans,int k){
		int i,j,t,mark[20],flag,st,mat[20][20];
		char ch;
		for(i=0;i<10;i++)
			mark[i]=-1;
		memset(mat,0,sizeof(mat));
		for(i=0;i<qu.size();i++){
			st=0;
			while(qu[i][st]==' ')st++;
			for(j=st;j<=qu[i].length();j++)
				if(qu[i][j]==' '||qu[i][j]=='\0'){
					ch=qu[i][j];
					qu[i][j]='\0';
					sscanf(qu[i].c_str()+st,"%d",&t);
					mat[i][t]=1;
					qu[i][j]=ch;
					j=st=j+1;
				}
		}
		for(i=0;i<qu.size();i++){
			flag=(ans[i]=="YES");
			if(i==k)flag=!flag;
			for(j=1;j<=8;j++){
				if(mark[j]==-1){
					if(flag)
					mark[j]=(mat[i][j]);
					else mark[j]=!mat[i][j];
				}
				else{
					if(flag)
						t=mat[i][j];
					else t=!mat[i][j];
					if(mark[j]!=t)mark[j]=2;
				}
			}
		}
		int t1,t2,t3,t4;
		t1=t2=t3=t4=0;
		for(i=1;i<=8;i++){
			if(mark[i]==-1)t1++;
			if(mark[i]==0)t2++;
			if(mark[i]==1){
				t3++;
				j=i;
			}
			if(mark[i]==2)t4++;
		}
		if(t3==1)return j;
		if(t3>1)return 0;
		return -1;
	}
	string answer(vector<string> qu,vector<string> ans){
		int i,j,flag=0,flag2=0,t,mark[20],flag1=0;
		memset(mark,0,sizeof(mark));
		for(i=0;i<=ans.size();i++){
			j=check(qu,ans,i-1);
			if(j>0){
				if(mark[j])continue;
				mark[j]=1;
				flag++;
				t=j;
			}
			if(j==0)flag1++;
			if(j<0)flag2++;
		}
		string ret;
		if(flag==1&&!flag1){
			ret+=t+'0';
			return ret;
		}
		else{
			if(flag2==ans.size()+1)
				ret+="CONTRADICTION";
			else
				ret+="NOT ENOUGH INFO"; 
			return ret;
		}
	}
};




void test0(){
	string _questions[]={"1 2 3"};
	vector<string> questions(_questions+0,_questions+sizeof(_questions)/sizeof(string));
	string _answers[]={"YES"};
	vector<string> answers(_answers+0,_answers+sizeof(_answers)/sizeof(string));
	string answer= "NOT ENOUGH INFO";
	NumberGuess _NumberGuess;
	string ret=_NumberGuess.answer(questions,answers);
	cout<<"--------------------test 0--------------------"<<endl;
	cout<<"questions = "<<questions<<endl;
	cout<<"answers = "<<answers<<endl;
	cout<<"expected to return "<<answer<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==answer)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test1(){
	string _questions[]={"1 2 3","1 2 3","1 2 3","1 2 3"};
	vector<string> questions(_questions+0,_questions+sizeof(_questions)/sizeof(string));
	string _answers[]={"YES","NO","YES","NO"};
	vector<string> answers(_answers+0,_answers+sizeof(_answers)/sizeof(string));
	string answer= "CONTRADICTION";
	NumberGuess _NumberGuess;
	string ret=_NumberGuess.answer(questions,answers);
	cout<<"--------------------test 1--------------------"<<endl;
	cout<<"questions = "<<questions<<endl;
	cout<<"answers = "<<answers<<endl;
	cout<<"expected to return "<<answer<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==answer)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test2(){
	string _questions[]={"1","1"};
	vector<string> questions(_questions+0,_questions+sizeof(_questions)/sizeof(string));
	string _answers[]={"YES","YES"};
	vector<string> answers(_answers+0,_answers+sizeof(_answers)/sizeof(string));
	string answer= "1";
	NumberGuess _NumberGuess;
	string ret=_NumberGuess.answer(questions,answers);
	cout<<"--------------------test 2--------------------"<<endl;
	cout<<"questions = "<<questions<<endl;
	cout<<"answers = "<<answers<<endl;
	cout<<"expected to return "<<answer<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==answer)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test3(){
	string _questions[]={"1 2 3 4","1 2","1","1 3"};
	vector<string> questions(_questions+0,_questions+sizeof(_questions)/sizeof(string));
	string _answers[]={"YES","YES","YES","YES"};
	vector<string> answers(_answers+0,_answers+sizeof(_answers)/sizeof(string));
	string answer= "1";
	NumberGuess _NumberGuess;
	string ret=_NumberGuess.answer(questions,answers);
	cout<<"--------------------test 3--------------------"<<endl;
	cout<<"questions = "<<questions<<endl;
	cout<<"answers = "<<answers<<endl;
	cout<<"expected to return "<<answer<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==answer)
		cout<<endl<<"Pass!"<<endl<<endl;
	else
		cout<<endl<<"Fail!!!!!!!!!! aoao~~~~~~~~~~~~"<<endl<<endl;
}

void test4(){
	string _questions[]={"1 2 3 4","1 2","1"};
	vector<string> questions(_questions+0,_questions+sizeof(_questions)/sizeof(string));
	string _answers[]={"YES","YES","YES"};
	vector<string> answers(_answers+0,_answers+sizeof(_answers)/sizeof(string));
	string answer= "NOT ENOUGH INFO";
	NumberGuess _NumberGuess;
	string ret=_NumberGuess.answer(questions,answers);
	cout<<"--------------------test 4--------------------"<<endl;
	cout<<"questions = "<<questions<<endl;
	cout<<"answers = "<<answers<<endl;
	cout<<"expected to return "<<answer<<endl;
	cout<<"your method returns "<<ret<<endl;
	if (ret==answer)
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
