/*
ID:  mygali1
PROG: gift1
*/

#include<iostream.h>
#include<string.h>
#include<fstream.h>
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("gift1.in");
ofstream out("gift1.out");
#endif
int n,give[20],total[20][2];
char name[20][20];
int main(){
	int i,j,k,h,t;
	char buf[20];
	while(in>>n){
		memset(total,0,sizeof(total));
		for(i=0;i<n;i++)
			in>>name[i];		
		for(i=0;i<n;i++){
			in>>buf;
			for(j=0;j<n;j++)
				if(strcmp(buf,name[j])==0)break;
			in>>t>>give[j];
			total[j][0]=t;
			if(give[j])total[j][1]+=total[j][0]%give[j];
			else total[j][1]+=t;
			for(k=0;k<give[j];k++){
				in>>buf;
				for(h=0;h<n;h++)
					if(strcmp(buf,name[h])==0)break;
				total[h][1]+=total[j][0]/give[j];
			}
		}
		for(i=0;i<n;i++)
			out<<name[i]<<' '<<total[i][1]-total[i][0]<<endl;
	}
	return 0;
}