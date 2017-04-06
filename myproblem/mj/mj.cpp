#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
#define MAXN 1100

int ist[3][3]={{11,11,0},{11,1,11},{-1,11,11}};
vector<int> output;
int n;
int p[2],a[MAXN],b[MAXN];

//#define DEBUG
#ifdef DEBUG
#define cin in
#define cout out
ifstream in("input.txt");
ofstream out("output.txt");
#endif

int check(){
	int i,t;
	p[0]=p[1]=0;
	for(i=1;i+1<=n;i++){
		if(b[i]<p[0]+p[1])return 0;
		t=p[0];
		p[0]=(b[i]-p[0]-p[1])%3;
		p[1]=t;
	}
	if(b[n]>=p[0]+p[1]&&b[n+1]>=p[0]&&
		(b[n]-p[0]-p[1])%3==0&&(b[n+1]-p[0])%3==0)return 1;
	return 0;
}

void run(){
	int i,j,flag=1;
	if(n==1){
		if(a[1]%3==0){
			cout<<"good"<<endl;
			return ;
		}
		else if(a[1]%3==2){
			cout<<"not bad\n"<<1<<endl;
			return ;
		}
	}
	memcpy(b,a,sizeof(a));
	for(i=1;i+2<=n;i++){
		if(b[i]<0)flag=0;
		j=b[i]%3;
		b[i]-=j;
		b[i+1]-=j;
		b[i+2]-=j;
	}
	if(b[n]<0||b[n-1]<0)flag=0;
	if(flag&&b[n]%3==0&&b[n-1]%3==0){
		cout<<"good"<<endl;
		return ;
	}
	i=ist[(b[n-1]+9)%3][(b[n]+9)%3];
	if(i>10){
		cout<<"bad"<<endl;
		return ;
	}
	memcpy(b,a,sizeof(a));
	j=n+10;
	output.clear();
	for(i+=n;i>0;i-=3){
		b[j]--;
		b[i]++;
		j=i;
		if(check())output.push_back(i);
	}
	sort(output.begin(),output.end());
	if(output.size()==0){
		cout<<"bad"<<endl;
		return ;
	}
	cout<<"not bad"<<endl;
	for(i=0;i<output.size();i++){
		if(i)cout<<' ';
		cout<<output[i];
	}
	cout<<endl;
}
int main(){
	int i;
	while(cin>>n){
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
			cin>>a[i];
		run();
	}
	return 0;
}