#include<iostream.h>

int n;
int a[62000];

void run(){
	int i,ans=0;
	for(i=0;i<n;i++)
		ans=(ans+a[ans])%n;
	cout<<a[ans]<<endl;
}
int main(){
	int i;
	while(cin>>n){
		for(i=0;i<n;i++)cin>>a[i];
		run();
	}
	return 0;
}