/*
ID:  mygali1
PROG: sprime
*/

#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("sprime.in");
ofstream out("sprime.out");
#endif

int n;
int isprime(int ans){
	if(ans==1)return 0;
	if(ans==2)return 1;
	if(ans%2==0)return 0;
	for(int i=3;i*i<=ans;i+=2)
		if(ans%i==0)return 0;
	return 1;
}
void dfs(int k,int ans){
	if(k==n){
		out<<ans<<endl;
		return ;
	}
	for(int i=1;i<10;i++)
	if(isprime(ans*10+i))
		dfs(k+1,ans*10+i);
}
int main(){
	while(in>>n)dfs(0,0);
	return 0;
}