#include<iostream.h>
#include<stdio.h>
#include<string.h>
//#define SIZE (strlen(en))
#define SIZE 1

short en[31000],cap[50];
short output[31000],key[50],mark[50];

void getinput(){
	int i,j;
	for(i=0;i<SIZE;i++){
//		cin>>j;
//		en[i]=j;
	}
	en[i]=0;
/*	cout<<en<<endl;
	int i;
	for(i=0;i<SIZE;i++){
		en[i]=getchar();
	}
	en[i]=0;
	cin.getline(en,31000);*/
}

int check(int k,int s){
	int i;
	unsigned char ch;
	for(i=0;i*s+k<SIZE;i++){
		ch=en[i*s+k]^key[k];
		if(ch!=' '&&!(ch>='a'&&ch<='z')&&!(ch>='A'&&ch<='Z'))return 0;
	}
	return 1;
}

int dfs(int k,int s){
	if(k==s)return 1;
	int i;
	for(i=0;i<36;i++)
		if(!mark[i]){
			key[k]=cap[i];
			mark[i]=1;
			if(check(k,s)){
				if(dfs(k+1,s))
					return 1;
			}
			mark[i]=0;
	}
	return 0;
}

void run(){
	int i,j;
	for(i=1;i<=30;i++){
		memset(mark,0,sizeof(mark));
		if(dfs(0,i))break;
	}
	cout<<i<<endl;
	for(j=0;j<SIZE;j++){
		output[j]=en[j]^key[j%i];
		cout<<(char)output[j];
	}
	cout<<endl;
	output[SIZE]=0;
//	cout<<output<<endl;
}

int main(){
	int i,j;
	for(i=0;i<26;i++)cap[i]='a'+i;
	for(i=0;i<10;i++)cap[26+i]='0'+i;
	for(i=0;i<36;i++)cout<<cap[i]<<' ';
	cout<<endl;
	for(i=0;i<36;i++)
		for(j=128;j<256;j++)
			if((cap[i]^j)<128)
				cout<<cap[i]<<' '<<j<<' '<<(cap[i]^j)<<endl;
	for(i=127;i<256;i++){
		getinput();
		en[0]=i;
//		run();
	}
	return 0;
}

/*
EZT.@GXQZ.S@^E_.W]I.[G\BB.^DT@.FYW.^PHH.U]V
*/