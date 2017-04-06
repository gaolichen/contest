#include<iostream.h>
#include<math.h>

int main(){
	int i,t,n;
	double ans;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(i=1;i<=n;i++)
			ans+=log10(i);
		cout<<(int)ans+1<<endl;
	}
	return 0;
}