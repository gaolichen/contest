#include<iostream.h>
#include<stdio.h>
#include<string.h>

char buf[200];

void run(){
	int i,pop,sk[100],len,j,t;
	pop=0;
	len=strlen(buf);
	for(i=0;i<len;i++)
		if(buf[i]=='('||buf[i]==')'){
			if(buf[i]=='(')
				sk[pop++]=i;
			else {
				pop--;
				j=sk[pop]-1;
				while(j>=0&&buf[j]==' ')j--;
				if(j<0||buf[j]!='-')
					buf[sk[pop]]=buf[i]=' ';
				else{
					t=0;
					for(j=sk[pop]+1;j<i;j++)
						if(buf[j]!=' ')t++;
					if(t==1)
						buf[sk[pop]]=buf[i]=' ';
				}
			}
		}
	for(i=0;i<len;i++)
		if(buf[i]!=' ')cout<<buf[i];
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	cin.getline(buf,100);
	while(t--){
		cin.getline(buf,100);
		run();
	}
	return 0;
}