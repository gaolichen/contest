#include<iostream>
#include<string>
using namespace std;

class ConvertBase{
public:
	string getValue(int n,int base){
		string ans;
		if(n<0){
			ans+='-';
			n=-n;
		}
		string temp;
		char ch;
		int i;
		do{
			i=n%base;
			n/=base;
			ch=i<=9? i+'0':(i-10+'A');
			temp=ch+temp;
		}while(n);
		return ans+temp;
	}
};

