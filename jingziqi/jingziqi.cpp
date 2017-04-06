#include<iostream.h>
#include<string.h>
#define ROW 3
#define LINE 3
#define DEPTH 4
#define LOSE -100000
#define WIN 100000

int p[DEPTH+1]={1,9,81,729,6561};

char mark[ROW+1][LINE+1],done[ROW+1][LINE+1];

class chess{
private:
	char mat[ROW+1][LINE+1];
	int value;
	int step;
	int whogo;
public:
	chess(int whofirst=1){
		memset(mat,'.',sizeof(mat));
		value=step=0;
		whogo=whofirst;
	}
	void gonext();
	void yougo();
	void computergo();
	void print();
	int youwin();
	int computerwin();
	inline int get_value();
	inline int show_value(){
		return value;
	}
	inline int show_step(){
		return step;
	}
	inline int show_whogo(){
		return whogo;
	}
};


int found(char ch){
	int i,j,ret=0;
	for(i=0;i<ROW;i++){
		for(j=0;j<ROW;j++)
			if(done[i][j]!=ch)break;
		if(j==ROW)ret++;
	}
	for(i=0;i<ROW;i++){
		for(j=0;j<ROW;j++)
			if(done[j][i]!=ch)break;
		if(j==ROW)ret++;
	}
	for(i=0;i<ROW;i++)
		if(done[i][i]!=ch)break;
	ret+=(i==ROW);
	for(i=0;i<ROW;i++)
		if(done[i][ROW-i]!=ch)break;
	ret+=(i==ROW);
	return ret;
}
int chess::youwin(){
	memcpy(done,mat,sizeof(mat));
	return found('*');
}

int chess::computerwin(){
	memcpy(done,mat,sizeof(mat));
	return found('#');
}


void chess::yougo(){
	int x,y;
	while(1){
		cout<<"Input the position you go : ";
		cin>>x>>y;
		if(x>=0&&x<ROW&&y>=0&&y<LINE&&mat[x][y]=='.')
			break;
		else {
			cout<<"Error positone , please input a ";
			cout<<"availability position ! "<<endl;
		}
	}
	this->mat[x][y]='*';
	step++;
	whogo=!whogo;
	value=get_value();
}


int calc(){
	memcpy(done,mark,sizeof(mark));
	if(found('*'))return LOSE;
	if(found('#'))return WIN;
	int i,j,ret;
	for(i=0;i<ROW;i++)
		for(j=0;j<LINE;j++)
			if(done[i][j]=='.')done[i][j]='#';
	ret=found('#');
	memcpy(done,mark,sizeof(mark));
	for(i=0;i<ROW;i++)
		for(j=0;j<LINE;j++)
			if(done[i][j]=='.')done[i][j]='*';
	ret-=found('*');
	return ret;
}
int dfs(int whogo,int step,int depth){
	int i;
	i=calc();
	if(step==ROW*LINE||depth==0){
		return i*p[DEPTH-depth];
	}
	if(i==WIN||i==LOSE)return i;
	int j,tmp,tmp1;
	if(whogo){
		tmp=LOSE-1;
		for(i=0;i<ROW;i++)
			for(j=0;j<LINE;j++)
				if(mark[i][j]=='.'){
					mark[i][j]='#';
					tmp1=dfs(!whogo,step+1,depth-1);
					if(tmp1>tmp)tmp=tmp1;
					mark[i][j]='.';
				}
	}
	else{
		tmp=WIN+1;
		for(i=0;i<ROW;i++)
			for(j=0;j<LINE;j++)
				if(mark[i][j]=='.'){
					mark[i][j]='*';
					tmp1=dfs(!whogo,step+1,depth-1);
					if(tmp1<tmp)
						tmp=tmp1;
					mark[i][j]='.';
				}
	}
	return tmp+calc()*p[DEPTH-depth];
}


inline int chess::get_value(){
	int ret;
	memcpy(mark,mat,sizeof(mat));
	ret=dfs(whogo,step,DEPTH);
	return ret;
}

void chess::computergo(){
	int i,j,x,y,max,tmp;
	step++;
	whogo=!whogo;
	max=LOSE-1;
	for(i=0;i<ROW;i++)
		for(j=0;j<LINE;j++)
			if(mat[i][j]=='.'){
				mat[i][j]='#';
				tmp=get_value();
				if(tmp>max){
					x=i;y=j;
					max=tmp;
				}
				mat[i][j]='.';
			}
	mat[x][y]='#';
	value=max;
}

void chess::gonext(){
	if(!whogo){
		yougo();
	}
	else{
		computergo();
	}
	this->print();
}

void chess::print(){
	int i,j;
	for(i=0;i<ROW;i++,cout<<endl)
		for(j=0;j<LINE;j++)
			cout<<(this->mat[i][j]);
	cout<<endl;
	
}


void run(int first){
	chess a(first);
	int whowin=2;
	while(a.show_step()!=ROW*LINE){
		if(a.youwin()){
			whowin=0;break;
		}
		else if(a.computerwin()){
			whowin=1;break;
		}
		else {
			cout<<"It's "<<(a.show_whogo()?"computer's":"your");
			cout<<" turn!"<<endl;
			a.gonext();
		}
	}
	if(whowin==2){
		cout<<"Tie !"<<endl;
	}
	else cout<<(whowin?"Computer":"You")<<" win !"<<endl;
}

int main(){
	int cnt=0,first;
	char ch;
	while(1){
		if(cnt++){
			cout<<"Continue (Y/N)? ";
			cin>>ch;
			if(ch!='y'&&ch!='Y')break;
		}
		cout<<"Who first,you (0) or computer (1)? ";
		cin>>first;
		if(first)first=1;
		run(first);
	}
	return 0;
}