#include<iostream.h>
#include<string.h>

int s,d,mark[60];

void run(){
	int c=0;
	memset(mark,0,sizeof(mark));
	mark[s]=1;
	while(1){
		c++;
		s=s+s*d;
		s%=60;
		if(mark[s])break;
		mark[s]=1;
		if(!s)break;
	}
	if(!s)cout<<c<<endl;
	else cout<<"Impossible"<<endl;
}
int main(){
	while(1){
		cin>>s>>d;
		if(!s&&!d)break;
		run();
	}
	return 0;
}