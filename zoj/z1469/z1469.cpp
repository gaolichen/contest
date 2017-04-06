#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;

vector<int> p;
char buf1[100][20],buf2[100][20];
int cnt,n;

void calc(int n,int h,int k){
	int i,a;
	for(i=0;i<10;i++)
		if((10*n+i)%11==0){
			a=(10*n+i)/11;
			if(a%10!=i)continue;
			sprintf(buf1[cnt],"%d",a*p[k]+h);
			sprintf(buf2[cnt++],"%d",(a/10)*p[k]+h);
		}
}

void check(int n,int k){
	int i,j,h;
	i=n%p[k];
	n=(n-i)/p[k];
	if(i%2)return ;
	for(j=0;j<2;j++){
		h=(i+j*p[k])/2;
		calc(n-j,h,k);
	}
}

void run(){
	int i,j=n,np=0;
	while(j>=1){
		j/=10;np++;
	}
	for(i=cnt=0;i<np;i++)
		check(n,i);
	cout<<cnt<<endl;
	for(i=0;i<cnt;i++)
		cout<<buf1[i]<<" + "<<buf2[i]<<" = "<<n<<endl;
}

int main(){
	int i,t;
	p.push_back(1);
	for(i=0;i<9;i++)
		p.push_back(p[i]*10);
	for(i=0,cin>>t;i<t;i++){
		cin>>n;
		run();
	}
	return 0;
}