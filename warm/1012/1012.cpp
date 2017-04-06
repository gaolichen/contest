#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<sstream>

using namespace std;

string ss;

void dfs(string s){
	int i;
	if(s.length()==0)return ;
	int j=0,flag=0;
	for(i=0;i<s.length();i++){
		switch(s[i]){
		case '(':j++;break;
		case ')':j--;break;
		case '-':
		case '+':if(!j)flag=2;break;
		case '*':
		case '/':if(!j&&flag!=2)flag=1;break;
		}
	}
	if(!flag){
		if(s[0]=='('){
			ss+="(";
			dfs(s.substr(1,s.length()-2));
			ss+=")";
		}
		else if(s[0]=='x'){
			ss+="1";
		}
		else if(s[0]>='0'&&s[0]<='9'){
			ss+="0";
		}
		else if(s.size()>=2&&s[0]=='l'){
			ss+="(";
			dfs(s.substr(3,s.length()-4));
			ss+=")/(";
			ss+=s.substr(3,s.length()-4);
//			cout<<s.substr(3)<<endl;
			ss+=")";
		}
		return ;
	}
	int k;
	for(i=j=0;i<s.length();i++){
		if(s[i]=='(')j++;
		else if(s[i]==')')j--;
		else if(!j){
			if(flag==1&&(s[i]=='*'||s[i]=='/')){
				k=i;
			}
			else if(flag==2&&(s[i]=='+'||s[i]=='-'))
				k=i;
		}
	}
	if(flag==2&&k==0){
		if(s[k+1]>='0'&&s[k+1]<='9'){
			k=-1;
			for(i=j=0;i<s.length();i++){
				if(s[i]=='(')j++;
				else if(s[i]==')')j--;
				if(!j&&(s[i]=='*'||s[i]=='/'))
					k=i;
			}
		}
		else{
			ss+=s[0];
			dfs(s.substr(1));
			return ;
		}
		if(k==-1){
			ss+="0";
			return ;
		}
		flag=1;
	}
	if(flag==1){
		if(s[k]=='*'){
			ss+="(";
			dfs(s.substr(0,k));
			ss+="*"+s.substr(k+1)+"+"+s.substr(0,k)+"*";
			dfs(s.substr(k+1));
			ss+=")";
		}
		else {
			ss+="(";
			dfs(s.substr(0,k));
			ss+="*"+s.substr(k+1)+"-"+s.substr(0,k)+"*";
			dfs(s.substr(k+1));
			ss+=")/"+s.substr(k+1)+"^2";
		}
	}
	else{
		dfs(s.substr(0,k));
		ss+=s[k];
		dfs(s.substr(k+1));
		return;
	}
}

int main(){
	string s;
	while(cin>>s){
		ss="";
		dfs(s);
		for(int i=0;i<ss.length()-1;i++)
			if(ss[i]=='+'&&ss[i+1]=='-'||ss[i]=='-'&&ss[i+1]=='+'){
				ss=ss.substr(0,i)+ss.substr(i+1);
				ss[i]='-';
			}
		cout<<ss<<endl;
	}
	return 0;
}