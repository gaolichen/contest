#include<iostream.h>
#include<string.h>
#include<fstream.h>

int p[6][4]={{2,5,3,4},{4,3,5,2},{5,0,4,1},{1,4,0,5},{2,0,3,1},{1,3,0,2}};
int die[800][6],can,cnt;
char mark[800];

inline int check(int a,int b,int c,int k){
	int i,j;
	for(i=0;i<6;i++)
		if(die[k][i]==a)break;
	for(j=0;j<4;j++){
		if(die[k][p[i][j]]==b&&die[k][p[i][(j+1)%4]]==c)
			return 1;
	}
	return 0;
}

void run(int a,int b,int c){
	if(!can)return ;
	int i;
	for(i=0;i<cnt;i++)
		if(!mark[i]&&!check(a,b,c,i)){
			mark[i]=1;
			can--;
		}
}

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


int main(){
	int i,n,j,a,b,c;
//	ofstream cout("die.out");
//	ifstream cin("die.in");
	init();
	while(cin>>n){
		memset(mark,0,sizeof(mark));
		can=cnt;
		for(i=0;i<n;i++){
			cin>>a>>b>>c;
			run(a,b,c);
		}
		if(!can){
			cout<<"T_T"<<endl;
		}
		else if(can>1){
			cout<<"=.-"<<endl;
		}
		else 
			for(i=0;i<cnt;i++)
				if(!mark[i]){
					for(j=0;j<6;j++){
						if(j)cout<<' ';
						cout<<die[i][j];
					}
					cout<<endl;
					break;
				}
	}
	return 0;
}