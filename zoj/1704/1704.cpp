#include<iostream>
#include<cmath>
#include<string>
using namespace std;

struct NODE{
	int x, y;
};

NODE vn[40];
int n;


int xmult(NODE a,NODE b){
	return a.x*b.y-a.y*b.x;
}
int s(int a,int b,int c){
	NODE t1,t2;
	t1.x=vn[a].x-vn[c].x;
	t1.y=vn[a].y-vn[c].y;
	t2.x=vn[b].x-vn[c].x;
	t2.y=vn[b].y-vn[c].y;
	return abs(xmult(t1,t2));
}

int in(int k,int a,int b,int c){
	if(s(k,a,b)+s(k,b,c)+s(k,c,a)==s(a,b,c))return 1;
	return 0;
}
int check(int a,int b,int c){
	for(int i=0;i<n;i++)if(i!=a&&i!=b&&i!=c&&in(i,a,b,c))return 0;
	return 1;
}

void run(){
	string out;
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
				if(check(i,j,k)&&s(i,j,k)>ans){
					ans=s(i,j,k);
					string tmp;
					tmp+='A'+i;
					tmp+='A'+j;
					tmp+='A'+k;
					out=tmp;
				}
	cout<<out<<endl;
}
int main(){
	char ch;
	while(cin>>n){
		if(!n)break;
		for(int i=0;i<n;i++)cin>>ch>>vn[i].x>>vn[i].y;
		run();
	}
	return 0;
}