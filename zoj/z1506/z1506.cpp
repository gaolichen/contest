#include<iostream.h>
#include<string.h>

int mx[4]={1,0,-1,0};
int my[4]={0,-1,0,1};
int h,w,dx,dy;
int x[12000],y[12000];
char mat[120][120],mark[120][120];

inline int check1(int x,int y,int i){
	if(x+mx[i]<0||y+my[i]<0||x+mx[i]>=h||y+my[i]>=w)
		return 0;
	if(mark[x+mx[i]][y+my[i]])return 0;
	if(x+mx[i]+1>=h||y+my[i]+1>=w)return 0;
	int j,k,flag=0;
	for(j=0;j<2;j++)
		for(k=0;k<2;k++){
			if(mat[j+x+mx[i]][k+y+my[i]]=='#')return 0;
			if(mat[j+x+mx[i]][k+y+my[i]]=='.')flag=1;
		}
	return flag;
}

inline int check(int x,int y,int i){
	if(x+mx[i]<0||y+my[i]<0||x+mx[i]>=h||y+my[i]>=w)
		return 0;
	return 1;
}

void bfs(){
	int opn,cls,i,j,k;
	x[opn=cls=0]=-1;
	y[0]=0;
	memset(mark,0,sizeof(mark));
	while(opn<=cls){
		for(i=0;i<4;i++)
			if(check1(x[opn],y[opn],i)){
				x[++cls]=x[opn]+mx[i];
				y[cls]=y[opn]+my[i];
				mark[x[cls]][y[cls]]=1;
				for(j=0;j<2;j++)
					for(k=0;k<2;k++)
						mat[x[cls]+j][y[cls]+k]='*';
			}
		opn++;
	}	
}

int moveleft();
void getdoor(){
	int i,j,k,l;
	for(i=0;i<h;i++)
		for(j=0;j<w;j++)
			if(mat[i][j]=='.'){
				for(k=0;k<4;k++)
					if(check(i,j,k)&&mat[i+mx[k]][j+my[k]]=='*')
						break;
				if(k==4)continue;
				for(l=0;l<2;l++)
					if(check(i,j,l)&&check(i,j,l+2)
						&&mat[i+mx[l]][j+my[l]]=='#'&&mat[i+mx[l+2]][j+my[l+2]]=='#'){
						dx=i;dy=j;
						if(moveleft()){
							cout<<"YES"<<endl;
							return ;
						}
					}
			}
	cout<<"NO"<<endl;
}

int ok(int x,int y){
	int i;
	for(i=0;i<4;i++)
		if(check(x,y,i)&&check(x,y,(i+1)%4)){
			if(mat[x+mx[i]][y+my[i]]=='.'&&
				mat[x+mx[(i+1)%4]][y+my[(i+1)%4]]=='.'&&
				mat[x+mx[(i+1)%4]+mx[i]][y+my[(i+1)%4]+my[i]]=='.')
				return 1;
		}
	return 0;
}

int moveleft(){
	int i,j,d;
	memset(mark,0,sizeof(mark));
	mark[dx][dy]=1;
	for(i=0;i<4;i++)
		if(check(dx,dy,i)&&mat[dx+mx[i]][dy+my[i]]=='.')
			break;
	if(i==4)return 0;
	d=i;
	while(1){
		for(i=0;i<4;i++){
			j=(d+3+i)%4;
			if(check(dx,dy,j)&&mat[dx+mx[j]][dy+my[j]]=='.')
				break;
		}
		if(i==4)return 0;
		dx+=mx[j];
		dy+=my[j];
		if(++mark[dx][dy]>4)return 0;
		if(ok(dx,dy)){
			return 1;
		}
		d=j;
	}
}
void run(){
	bfs();
	getdoor();
}

int main(){
	int i;
	while(cin>>h>>w){
		memset(mat,'.',sizeof(mat));
		for(i=2;i<h+2;i++){
			cin>>(mat[i]+2);
			mat[i][2+w]='.';
			mat[i][2+w+2]='\0';
		}
		h+=4;w+=4;
		mat[0][w]=mat[1][w]='\0';
		mat[h-1][w]=mat[h-2][w]='\0';
		run();
	}
	return 0;
}