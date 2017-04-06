#include<iostream.h>
#include<stdio.h>

int m;

void run(){
	int i,j,ret;
	if(m==0){
		cout<<"0 1"<<endl;
		return ;
	}
	for(i=1;i<10;i++){
		for(j=0,ret=0;j<m;j++){
			ret=(ret*10+i)%m;
			if(!ret)break;
		}
		if(j<m){
			cout<<i<<' '<<j+1<<endl;
			return ;
		}
	}
	cout<<-1<<endl;
}

int main(){
	while(cin>>m)run();
	return 0;
}