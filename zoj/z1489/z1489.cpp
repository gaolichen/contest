#include<iostream.h>

int main(){
	int i,n,j;
	while(cin>>n){
		if(n%2==0||n==1)
			cout<<"2^? mod ";
		else{
			i=1;j=2;
			while(j!=1){
				i++;
				j=(2*j)%n;
			}
			cout<<"2^"<<i<<" mod ";
		}
		cout<<n<<" = 1"<<endl;
	}
	return 0;
}