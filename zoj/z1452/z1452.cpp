#include<iostream.h>
#include<string.h>
#define MAXN 10000

int sk[MAXN],a[2][MAXN],opn[2],cls[2],s;
void run(){
	int i,j,cnt=0,curr=0;
	opn[0]=opn[1]=0;
	while(s--){
		if((opn[0]==cls[0])||(opn[1]==cls[1]))break;
		for(i=0;i<cnt;i++)
			if(sk[i]==a[curr][opn[curr]])break;
		if(i<cnt){
			a[curr][cls[curr]]=a[curr][opn[curr]];
			cls[curr]=(cls[curr]+1)%MAXN;
			for(j=cnt-1;j>=i;j--){
				a[curr][cls[curr]]=sk[j];
				cls[curr]=(cls[curr]+1)%MAXN;
			}
			cnt=i;
		}
		else sk[cnt++]=a[curr][opn[curr]];
		opn[curr]=(opn[curr]+1)%MAXN;
		curr=(curr+1)%2;
/*		for(i=0;i<2;i++,cout<<endl)
			for(j=opn[i];j<cls[i];j++){
				if(j!=opn[i])cout<<' ';
				cout<<a[i][j];
			}
		if(!cnt)cout<<"NULL";
		else
			for(i=0;i<cnt;i++){
				if(i)cout<<' ';
				cout<<sk[i];
			}
		cout<<endl;
		cin>>i;*/
	}
	if((opn[0]==cls[0])&&!(opn[1]==cls[1]))
		cout<<"B"<<endl;
	else if(!(opn[0]==cls[0])&&(opn[1]==cls[1]))
		cout<<"A"<<endl;
	else{
		for(i=0;i<2;i++,cout<<endl)
			for(j=opn[i];j<cls[i];j++){
				if(j!=opn[i])cout<<' ';
				cout<<a[i][j];
			}
		if(!cnt)cout<<"NULL";
		else
			for(i=0;i<cnt;i++){
				if(i)cout<<' ';
				cout<<sk[i];
			}
		cout<<endl;
	}
}

int main(){
	int cnt=0,i;
	while(1){
		cin>>s;
		if(s<1)break;
		for(i=0;i<2;i++){
			cls[i]=0;
			while(1){
				cin>>a[i][cls[i]];
				if(!a[i][cls[i]])break;
				cls[i]++;
			}
		}
		cout<<"Case "<<++cnt<<":"<<endl;
		run();
	}
	return 0;
}