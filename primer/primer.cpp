#include<iostream.h>
#include<string.h>
#define MAXN 11000000
char mark[MAXN+1];
//int p[MAXN/3];
void markprimer(){
	int i,j;
	memset(mark,0,sizeof(mark));
	for(i=2;i<=MAXN;i++)
		if(!mark[i]){
			for(j=i;j*i>0&&j*i<MAXN;j++)
				mark[i*j]=1;
		}
}

int main(){
	int i,n;
	markprimer();
	while(cin>>n){
		for(i=n;;i++)
			if(!mark[i]){
				cout<<i<<endl;
				break;
			}
	}
	return 0;
}