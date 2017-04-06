#include<iostream.h>

int dfs(int n){
	if(n<3)return 0;
	if(n==3)return 1;
	if(n%2)return dfs(n/2)+dfs(n/2+1);
	return 2*dfs(n/2);
}

int main(){
	int n;
	while(cin>>n)cout<<dfs(n)<<endl;
	return 0;
}