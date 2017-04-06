#include<iostream>

using namespace std;

#define i64 long long
i64 gcd(i64 a,i64 b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int main(){
	i64 n,m;
	while(cin>>n>>m){
		if(gcd(n,m)==1){
			cout<<"Poor rabbit   I can't help you :("<<endl;
		}
		else {
			cout<<"Poor wildleopard   there are "<<n-(n/gcd(n,m))<<" holes save!"<<endl;
		}
	}
	return 0;
}