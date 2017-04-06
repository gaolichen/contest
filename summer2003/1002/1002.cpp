#include<iostream>
#define i64 unsigned long long
using namespace std;

int main(){
	int t;
	i64 n,m;
	cin>>t;
	while(t--){
		cin>>m>>n;
		cout<<(1+m)*m/2*(n+1)*n/2<<endl;
	}
	return 0;
}