#include<iostream>
using namespace std;
#define u64 unsigned long long

u64 calc(u64 n,int flag){
	if(n==1)return 1;
	if(flag==0){
		if(n%2==0)return 2*calc(n/2,0)-1;
		return 2*calc((n+1)/2,1)-1;
	}
	else {
		if(n%2==0)return 2*calc(n/2,1);
		return 2*calc(n/2,0);
	}
}
int main(){
	u64 n,m,pre;
	while(cin>>n>>m){
		pre=n;
		while(m--){
			n=calc(n,0);
			if(n==pre)break;
			pre=n;
		}
		cout<<n<<endl;
	}
	return 0;
}