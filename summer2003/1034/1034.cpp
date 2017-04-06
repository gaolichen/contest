#include<iostream>
#include<cstdio>

using namespace std;
double p;
double dfs(int n,int m){
	if(!m)return 1.0;
	if(!n)return 0.0;
	if(n%2)return dfs(n+1,m-1)*p+dfs(n-1,m+1)*(1-p);
	return (p*p*dfs(n+2,m-2)+dfs(n-2,m+2)*(1-p)*(1-p))/(1-2*p*(1-p));
}
int main(){
	int n,m;
	while(cin>>n>>m>>p){
		printf("%.6lf\n",dfs(n,m));
	}
	return 0;
}