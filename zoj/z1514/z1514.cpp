#include<iostream.h>
#include<string.h>
int mark[21000];
int main(){
	int n,m,cnt,i,j;
	while(1){
		cin>>n>>m;
		if(!n&&!m)break;
		cnt=0;
		memset(mark,0,sizeof(mark));
		for(i=0;i<m;i++){
			cin>>j;
			if(mark[j]==1)cnt++;
			mark[j]++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}