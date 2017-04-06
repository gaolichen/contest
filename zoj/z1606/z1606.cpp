#include<iostream.h>
#define abs(a) ((a)>=0?(a):(-a))

int n;
int d[51000],len[51000];

void run(){
	int i;
	long long sa,sb,sc;
	sa=sb=sc=0;
	d[n]=d[0];len[n]=len[0];
	for(i=0;i<n;i++){
		if(d[i]==2&&d[i+1]==3)
			sa-=len[i]*len[i+1];
		else if(d[i]==4&&d[i+1]==5)
			sb-=len[i]*len[i+1];
		else if(d[i]==6&&d[i+1]==1)
			sc-=len[i]*len[i+1];
		else if(d[i]==3&&d[i+1]==2)
			sa+=len[i]*len[i+1];
		else if(d[i]==5&&d[i+1]==4)
			sb+=len[i]*len[i+1];
		else if(d[i]==1&&d[i+1]==6)
			sc+=len[i]*len[i+1];
	}
	cout<<abs(sa)<<' '<<abs(sb)<<' '<<abs(sc)<<endl;
}

int main(){
	int i;
	for(;cin>>n;run())
		for(i=0;i<n;i++)
			cin>>d[i]>>len[i];
	return 0;
}