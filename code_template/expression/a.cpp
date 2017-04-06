#pragma warning (disable:4786)
#define for if(0);else for
#include<string>
#include<vector>
#include<iostream>
#include<stack>
#include<queue>
#include<sstream>
using namespace std;
//#define __DOUBLE
#ifdef __DOUBLE
typedef double T;
#define isDig(a) ((a)>='0'&&(a)<='9'||(a)=='.')
#else
typedef int T;
#define isDig(a) ((a)>='0'&&(a)<='9')
#endif
string xpr,num;
string prt;

T calc1(T a,T b,char ch,bool &ok){
	if(ch=='+')return a+b;
	if(ch=='-')return a-b;
	if(ch=='*')return a*b;
	if(ch=='/'){
		if(b==0){
			ok=false;return 0;
		}
		return a/b;
	}
	return T(0);
}
T s2d(string s){
	T ret;istringstream in(s);in>>ret;
	return ret;
}
T calc(int i,stack<T> &skn,stack<char> &s,bool &ok){
	if(i==xpr.length()){
		if(!num.empty())skn.push(s2d(num));
		while(!skn.empty()&&!s.empty()){
			T a,b;
			b=skn.top();skn.pop();
			a=skn.top();skn.pop();
			char ch=s.top();s.pop();
			skn.push(calc1(a,b,ch,ok));
		}
		return skn.top();
	}
	if(xpr[i]=='-'&&num.empty()&&(!i||xpr[i-1]!=')')||isDig(xpr[i])){
		num+=xpr[i];return calc(i+1,skn,s,ok);
	}
	if(!num.empty()){
		skn.push(s2d(num));
		num="";
	}
	if(xpr[i]==')'){
		while(!s.empty()){
			char ch=s.top();s.pop();
			if(ch=='(')break;
			T a,b;b=skn.top();skn.pop();a=skn.top();skn.pop();
			skn.push(calc1(a,b,ch,ok));
		}
		return calc(i+1,skn,s,ok);
	}
	if(xpr[i]!='('){
		int a=prt.find(xpr[i])/2;
		while(!s.empty()&&s.top()!='('&&prt.find(s.top())/2>=a){
			char ch=s.top();s.pop();
			T a,b;b=skn.top();skn.pop();a=skn.top();skn.pop();
			skn.push(calc1(a,b,ch,ok));
		}	
	}
	s.push(xpr[i]);
	return calc(i+1,skn,s,ok);
}

T expression(string s,bool &ok){
	stack<T> skn;
	stack<char> op;
	xpr=s;num="";
	prt="+-*/";
	return calc(0,skn,op,ok);
}

int main(){
	return 0;
}

