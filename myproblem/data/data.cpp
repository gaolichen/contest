#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>
#include<time.h>

int p[6][4]={{2,5,3,4},{4,3,5,2},{5,0,4,1},{1,4,0,5},{2,0,3,1},{1,3,0,2}};

int cnt,sk[300][3],die[300][6];
/*
void init(){
	int i,j,k;
	cnt=0;
	for(i=1;i<=6;i++)
		for(j=1;j<=6;j++)if(i!=j)
			for(k=1;k<=6;k++)if(k!=i&&k!=j){
				sk[cnt][0]=i;
				sk[cnt][1]=j;
				sk[cnt++][2]=k;
			}
}*/

void init(){
	int i,j,a,b,c;
	cnt=0;
	for(i=2;i<=6;i++)
		for(j=2;j<=3;j++)if(i!=j)
			for(a=j+1;a<=6;a++)if(a!=i)
				for(b=j+1;b<=6;b++)if(b!=i&&b!=a)
					for(c=j+1;c<=6;c++)if(c!=i&&c!=a&&c!=b){
						die[cnt][0]=1;
						die[cnt][1]=i;
						die[cnt][2]=j;
						die[cnt][3]=a;
						die[cnt][4]=b;
						die[cnt++][5]=c;
					}
}
ofstream out("die.in");

void output(int k){
	int j,h;
	j=rand()%6;
	h=rand()%4;
	out<<die[k][j]<<' '<<die[k][p[j][h]]<<' '<<die[k][p[j][(h+1)%4]]<<endl;
}
int main(){
	int i,j,k,t;
	int n;
	init();
	
	while(1){
		cin>>t;
		if(!t)break;
		srand(time(NULL));
		for(i=0;i<t;i++){
			n=rand()%10+1;
			out<<n<<endl;
			k=rand()%cnt;
			for(j=0;j<n;j++){	
				output(k);
			}
		}
	}
	return 0;
}