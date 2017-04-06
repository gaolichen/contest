#include<iostream.h>
#include<stdio.h>
#include<string.h>

int len,tot,sk[30];
char buf[30];

int mycmp(){
	int i;
	for(i=0;i<len/2;i++){
		if(sk[i]>buf[i+len/2]-'0')return 1;
		else if(sk[i]<buf[i+len/2]-'0')return -1;
	}
	return 0;
}

int dfs(int k,int s){
	if(k==len/2){
		if(s!=tot)return 0;
		if(mycmp()>=0)return 1;
		return 0;
	}
	int i;
	if(k==0){
		for(i=buf[len/2]-'0';i<=9;i++){
			if(s+i>tot||s+i+(len/2-k-1)*9<tot)continue;
			sk[k]=i;
			if(dfs(k+1,s+i))return 1;
		}
		return 0;
	}
	else{
		for(i=0;i<=9;i++){
			if(s+i>tot||s+i+(len/2-k-1)*9<tot)continue;
			sk[k]=i;
			if(dfs(k+1,s+i))return 1;
		}
		return 0;
	}
	return 0;
}


void run(){
	int i,j;
	char tmp[30];
	strcpy(tmp,buf);
	len=strlen(buf);
	for(i=0,tot=0;i<len/2;i++)
		tot+=buf[i]-'0';
	for(i=len/2,j=0;i<len;i++)
		j+=buf[i]-'0';
	if(j==tot){
		cout<<0<<endl;
		return ;
	}
	if(!dfs(0,0)){
		for(i=len/2-1;i>=0;i--){
			if(buf[i]=='9')buf[i]='0';
			else {
				buf[i]++;
				break;
			}
		}
		for(i=tot=0;i<len/2;i++)
			tot+=buf[i]-'0';
		for(i=len/2;i<len;i++)buf[i]='0';
		dfs(0,0);
	}
	long long ans=0,k;
	for(i=len/2;i<len;i++)
		buf[i]=sk[i-len/2]+'0';
//	cout<<buf<<endl;
	for(i=len-1,j=0,k=1;i>=0;i--){
		if(buf[i]-j<tmp[i]){
			ans+=(buf[i]-j+10-tmp[i])*k;
			j=1;
		}
		else{
			ans+=(buf[i]-j-tmp[i])*k;
			j=0;
		}
		k*=10;
	}
	cout<<ans<<endl;
}
int main(){
	while(cin>>buf)run();
	return 0;
}