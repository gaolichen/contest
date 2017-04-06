#include<iostream>
#include<cstring>
using namespace std;

char buf[100010],buf2[200020];
int n;
void run(){
	int i,j;
	strcpy(buf2,buf);
	int len=strlen(buf);
	strcpy(buf2+len,buf);
	i=0;j=1;
	int cnt;
	while(i<len&&j<len){
		for(cnt=0;cnt<len&&buf2[cnt+i]==buf2[cnt+j];cnt++);
		if(cnt==len){
			break;
		}
		else if(buf2[cnt+i]<buf2[cnt+j])j+=cnt+1;
		else {
			i=j;j++;
		}
	}
	cout<<i<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>buf;
		run();
	}
	return 0;
}