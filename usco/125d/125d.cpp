/*
ID:  mygali1
PROG: crypt1
*/
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
#define DEBUG
#define M 2100000000
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("crypt1.in");
ofstream out("crypt1.out");
#endif
int temp[10],c,d,e,mark[10],num[10],n,a[10],ans;
int ok(int n){
	int i=0;
	while(n){
		if(!mark[n%10])return 0;
		temp[i++]=n%10;
		n/=10;
	}
	return 1;
}
int check(){
	int a,b;
	a=num[0]*100+num[1]*10+num[2];
	b=num[3]*10+num[4];
	c=a*num[4];
	d=a*num[3];
	if(c>=1000||d>=1000)return 0;
	e=a*b;
	return ok(c)&&ok(d)&&ok(e);

}
void output(){
	 out<<"      "<<num[0]<<' '<<num[1]<<' '<<num[2]<<endl;
	 out<<"    x   "<<num[3]<<' '<<num[4]<<endl;
	 out<<"     ------"<<endl;
	 ok(c);
	 out<<"      "<<temp[2]<<' '<<temp[1]<<' '<<temp[0]<<endl;
	 ok(d);
	 out<<"    "<<temp[2]<<' '<<temp[1]<<' '<<temp[0]<<endl;
	 out<<"  ---------"<<endl;
	 ok(e);
	 out<<"    "<<temp[3]<<' '<<temp[2]<<' '<<temp[1]<<' '<<temp[0]<<endl;
}
void dfs(int k){
	int i;
	if(k==5){
		if(check())ans++;
		return ;
	}
	for(i=0;i<n;i++){
		num[k]=a[i];
		dfs(k+1);
	}
}
int main(){
	int i;
	while(in>>n){
		memset(mark,0,sizeof(mark));
		for(i=0;i<n;i++){
			in>>a[i];
			mark[a[i]]=1;
		}
		n=0;
		for(i=1;i<10;i++)
			if(mark[i])a[n++]=i;
		ans=0;
		dfs(0);
		out<<ans<<endl;
	}
	return 0;
}