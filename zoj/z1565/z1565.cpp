#include<iostream.h>

int xl[110],yl[110],xh[110],yh[110];
int n,w,h;

void run(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(xl[i]>=xh[j]||xl[j]>=xh[i])continue;
			if(yl[i]>=yh[j]||yl[j]>=yh[i])continue;
			cout<<"NONDISJOINT"<<endl;
			return;
		}
	}
	for(i=0;i<n;i++)
		if(xl[i]<0||xh[i]>w||yl[i]<0||yh[i]>h){
			cout<<"NONCONTAINED"<<endl;
			return;
		}
	int ans=0;
	for(i=0;i<n;i++)
		ans+=(xh[i]-xl[i])*(yh[i]-yl[i]);
	cout<<(ans==w*h?"OK":"NONCOVERING")<<endl;
}

int main(){
	int t,i;
	cin>>t;
	while(t--){
		cin>>w>>h>>n;
		for(i=0;i<n;i++)
			cin>>xl[i]>>yl[i]>>xh[i]>>yh[i];
		run();
	}
	return 0;
}