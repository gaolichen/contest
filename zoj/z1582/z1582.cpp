#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
	int i,t,j,v;
	string s1,s2;
	char buf1[110],buf2[110];
	for(cin>>t,j=0;j<t;j++){
		cin>>v;
		cin.getline(buf1,100);
		cin.getline(buf1,100);
		cin.getline(buf2,100);
		s1=buf1;s2=buf2;
		for(i=0;i<s1.length()&&i<s2.length();i++)
			if(s1[i]!=s2[i])break;
		if(i<s1.length()&&i<s2.length())
			cout<<(s2.length()-i+s1.length()-i)*v<<endl;
		else if(i<s1.length()){
			cout<<(s1.length()-i)*v<<endl;
		}
		else 
			cout<<(s2.length()-i)*v<<endl;
	}
	return 0;
}