#include<iostream.h>
#include<string.h>

int x,y;
void run(){
	if(x==y){
		if(x%2)
			cout<<(x/2)*4+1<<endl;
		else cout<<x*2<<endl;
	}
	else if(x==y+2){
		if(x%2)
			cout<<(x-3)*2+3<<endl;
		else cout<<(x-2)*2+2<<endl;
	}
	else cout<<"No Number"<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>x>>y;
		run();
	}
	return 0;
}