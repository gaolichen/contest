#include<iostream.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int mx[4]={1,-1,0,0};
int my[4]={0,0,1,-1};
int a[10],b[10];
int h;
inline int check(int x,int y){
	if(x<=0||y<=0||x>8||y>8)return 0;
	return 1;
}

inline int ok(){
	int i,j,k,ret,max,min;
	for(i=ret=k=max=0;i<8;i+=2){
		min=100;
		for(j=0;j<8;j+=2){
			if(a[i]==b[j]&&b[j+1]==a[i+1])break;
			if(min*2>abs(b[j]-a[i])+abs(b[j+1]-a[i+1]))
				min=(abs(b[j]-a[i])+abs(b[j+1]-a[i+1])+1)/2;
		}
		if(j<8)
			ret++;
		else {
			if(min>max)max=min;
			if(min>1)k++;
		}
	}
	if(ret==4)return 0;
	if(k==0)k++;
	return 3-ret+max+k-1;
}

int dfs(int step){
	int i;
	i=ok();
	if(!i)return 1;
	if(step+i>8)return 0;
	int j,k;
	for(i=0;i<8;i+=2){
		for(j=0;j<4;j++){
			for(k=0;k<8;k+=2)
				if(k!=i&&a[i]+mx[j]==a[k]&&a[i+1]+my[j]==a[k+1])
					break;
			if(k==8){
				if(!check(a[i]+mx[j],a[i+1]+my[j]))continue;
				a[i]+=mx[j];
				a[i+1]+=my[j];
				if(dfs(step+1))return 1;
				a[i]-=mx[j];a[i+1]-=my[j];
			}
			else if(check(a[k]+mx[j],a[k+1]+my[j])){
				for(h=0;h<8;h+=2)
					if(a[k]+mx[j]==a[h]&&a[k+1]+my[j]==a[h+1])
						break;
				if(h<8)continue;
				a[i]=a[k]+mx[j];
				a[i+1]=a[k+1]+my[j];
				if(dfs(step+1))return 1;
				a[i]=a[k]-mx[j];
				a[i+1]=a[k+1]-my[j];
			}
		}
	}
	return 0;
}

void run(){
	if(dfs(0))cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

int main(){
	int i;
	while(cin>>a[0]){
		for(i=1;i<8;i++)
			cin>>a[i];
		for(i=0;i<8;i++)cin>>b[i];
		run();
	}
	return 0;
}