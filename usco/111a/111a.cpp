
/*
ID:  mygali1
PROG: ride
*/

#include<iostream.h>
#include<fstream.h>
#include<string.h>
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("ride.in");
ofstream out("ride.out");
#endif
char buf[2][1000];
void run(){
	int i,j,ans[2],len;
	for(i=0;i<2;i++){
		len=strlen(buf[i]);
		ans[i]=1;
		for(j=0;j<len;j++)
			ans[i]*=buf[i][j]-'A'+1;
		ans[i]%=47;
	}
	if(ans[0]==ans[1])out<<"GO"<<endl;
	else out<<"STAY"<<endl;
}
int main(){
	while(in>>buf[0]>>buf[1])run();
	return 0;
}
