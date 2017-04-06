#include<iostream.h>
#include<string.h>

char mat[12][12][12],mark[12][12][12];
int n,x[1100],y[1100],z[1100],step[1100];
int sx,sy,sz,ex,ey,ez;

int mx[6]={1,-1,0,0,0,0};
int my[6]={0,0,1,-1,0,0};
int mz[6]={0,0,0,0,1,-1};

int  check(int i,int j,int k,int p){
	int ti,tj,tk;
	ti=i+mx[p];tj=j+my[p];
	tk=k+mz[p];
	if(ti>=n||ti<0||tj>=n||tj<0||tk>=n||tk<0)return 0;
	if(mark[ti][tj][tk]||mat[ti][tj][tk]=='X')return 0;
	return 1;
}

void run(){
	int i,opn,cls;
	memset(mark,0,sizeof(mark));
	x[opn=cls=0]=sx;
	y[0]=sy;z[0]=sz;
	mark[sx][sy][sz]=1;
	step[opn]=0;
	while(opn<=cls&&!mark[ex][ey][ez]){
		for(i=0;i<6;i++)
			if(check(x[opn],y[opn],z[opn],i)){
				x[++cls]=x[opn]+mx[i];
				y[cls]=y[opn]+my[i];
				z[cls]=z[opn]+mz[i];
				step[cls]=step[opn]+1;
				mark[x[cls]][y[cls]][z[cls]]=1;
			}
		opn++;
	}
	if(mark[ex][ey][ez])
		cout<<n<<' '<<step[cls]<<endl;
	else cout<<"NO ROUTE"<<endl;
}

int main(){
	int i,j;
	char buf[100];
	while(cin>>buf>>n){
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cin>>mat[i][j];
		cin>>sz>>sy>>sx;
		cin>>ez>>ey>>ex;
		cin>>buf;
		run();
	}
	return 0;
}