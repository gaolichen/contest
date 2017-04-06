#include<iostream.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 200
int n,a[MAXN],b[MAXN],mark[MAXN],w[MAXN];
int isheavy,times;
int s[2];

char buf[80];

int judge(int cnt);
int weight(int ,int );

void pleft(){
	cout<<"Set 1 :";
}

void pright(){
	cout<<"Set 2 :";
}

void pent(){
	cout<<endl;
}

void pstep(int step){
	cout<<"Step "<<step<<" : "<<endl;
}
void question(){
	cout<<"Enter which set is heavier (1 or 2) or 0 if same : ";
	cin>>buf;
	cout<<endl;
//	if(s[0]>s[1])buf[0]='1';
//	else if(s[0]<s[1])buf[0]='2';
//	else buf[0]='0';
//	buf[1]='\0';
//	cout<<buf<<endl;
}
void output(int up,int low,int *array,int side){
	int i;
	for(i=up;i<low;i++)
		cout<<' '<<array[i];
//	for(i=up;i<low;i++)
//		s[side]+=w[array[i]];
}
int cut(){
	int i,left=0,right=0,cnt,j;
	s[0]=s[1];
	times++;
	for(i=1,cnt=0;i<=n;i++)
		if(mark[i]==3)cnt++;
	if(cnt==n)return 0;
	if(cnt==n-1){
		for(i=1;i<=n;i++)
			if(mark[i]!=3)break;
		isheavy=mark[i];
		return i;
	}
	pstep(times+1);
	for(i=1;i<=n;i++)
		if(mark[i]&&mark[i]!=3)break;
	if(i>n){
		for(cnt=0,i=1;i<=n;i++)
			if(!mark[i])a[cnt++]=i;
		if(cnt%3){
			for(i=1;i<=n;i++)
				if(mark[i]==3)break;
			for(j=cnt++;j>0;j--)
				a[j]=a[j-1];
			a[0]=i;
		}
		return judge(cnt);
	}
	for(i=1;i<=n;i++){
		if(mark[i]==1)a[left++]=i;
		if(mark[i]==2)b[right++]=i;
	}
	if(left%3&&right%3&&left%3==right%3){
		for(i=1;i<=n;i++)
			if(mark[i]==3)break;
		for(j=left++;j>0;j--)
			a[j]=a[j-1];
		a[0]=i;
	}
	return weight(left,right);
}

int sameball(int cnt,int *ball,int flag){
	int left,i;
	left=cnt/3+(cnt%3==2);
	pleft();
	output(0,left,ball,0);
	pent();pright();
	output(left,left+left,ball,1);
	pent();
	question();
	if(buf[0]=='1'){
		if(flag==2)
			for(i=0;i<left;i++)
				mark[ball[i]]=3;
		else for(i=left;i<left+left;i++)
			mark[ball[i]]=3;
		for(i=left+left;i<cnt;i++)
			mark[ball[i]]=3;
	}
	else if(buf[0]=='2'){
		if(flag==2)
			for(i=left;i<left+left;i++)
				mark[ball[i]]=3;
		else for(i=0;i<left;i++)
			mark[ball[i]]=3;
		for(i=left+left;i<cnt;i++)
			mark[ball[i]]=3;
	}
	else {
		for(i=0;i<left+left;i++)
			mark[ball[i]]=3;
	}
	return cut();
}

int weight(int left,int right){
	if(left==0){
		return sameball(right,b,2);
	}
	if(right==0){
		return sameball(left,a,1);
	}
	int ll,i,lr,rl,rr;
	ll=lr=left/3+(left%3==2);
	rr=rl=right/3+(right%3==2);
	pleft();
	output(0,ll,a,0);
	output(0,rl,b,0);
	pent();pright();
	output(ll,ll+lr,a,1);
	output(rl,rl+rr,b,1);
	pent();
	question();
	if(buf[0]=='1'){
		for(i=0;i<rl;i++)
			mark[b[i]]=3;
		for(i=ll;i<ll+lr;i++)
			mark[a[i]]=3;
		for(i=ll+lr;i<left;i++)
			mark[a[i]]=3;
		for(i=rl+rr;i<right;i++)
			mark[b[i]]=3;
	}
	else if(buf[0]=='2'){
		for(i=0;i<ll;i++)
			mark[a[i]]=3;
		for(i=rl;i<rl+rr;i++)
			mark[b[i]]=3;
		for(i=ll+lr;i<left;i++)
			mark[a[i]]=3;
		for(i=rl+rr;i<right;i++)
			mark[b[i]]=3;
	}
	else {
		for(i=0;i<ll+lr;i++)
			mark[a[i]]=3;
		for(i=0;i<rl+rr;i++)
			mark[b[i]]=3;
	}
	return cut();
}
int judge(int cnt){
	int i,left,right;
	if(cnt==n)
		pstep(1);
	left=right=cnt/3+(cnt%3==2);
	pleft();
	output(0,left,a,0);
	pent();pright();
	output(left,left+right,a,1);
	pent();
	question();
	if(buf[0]=='1'){
		for(i=0;i<left;i++)
			if(mark[a[i]]!=3)
				mark[a[i]]=1;
		for(i=left;i<left+right;i++)
			if(mark[a[i]]!=3)
				mark[a[i]]=2;
		for(i=left+right;i<cnt;i++)
			mark[a[i]]=3;
	}
	else if(buf[0]=='2'){
		for(i=0;i<left;i++)
			if(mark[a[i]]!=3)
				mark[a[i]]=2;
		for(i=left;i<left+right;i++)
			if(mark[a[i]]!=3)
				mark[a[i]]=1;
		for(i=left+right;i<cnt;i++)
			mark[a[i]]=3;
	}
	else {
		for(i=0;i<left+right;i++)
			mark[a[i]]=3;
	}
	return cut();
}

int run(){
	int i=1,ret=0;
	if(n<3){
		cout<<"Can not judge."<<endl;
		return 0;
	}
	if(n>=MAXN){
		cout<<"Too many balls."<<endl;
		return 0;
	}
	while(i<2*n){
		ret++;i*=3;
	}
	cout<<"The different ball will be found in most ";
	cout<<ret<<" times"<<endl;
	cout<<endl;
	for(i=0;i<n;i++)a[i]=i+1;
	memset(mark,0,sizeof(mark));
	times=0;
	ret=judge(n);
	if(!ret){
		cout<<"Sorry, I cannot find the different ball -_-,";
		cout<<" maybe you told lies."<<endl;
		cout<<endl;
		return 0;
	}
	cout<<"The different ball is NO."<<ret<<". ";
	if(isheavy==1)cout<<"It's heavier than others."<<endl;
	else if(isheavy==2)cout<<"It's lighter than others."<<endl;
	else cout<<endl;
	cout<<"It cost "<<times<<" time(s) to check."<<endl;
	cout<<endl;
	return ret;
}

void printhead(){
	cout<<"Hi! You are now in a funny game. ";
	cout<<"There are n balls.";
	cout<<" One of them is different \n";
	cout<<"from the others -- it can be either heavier or ";
	cout<<"lighter.";
	cout<<"You should select the \nspecial ball and whether";
	cout<<" it's heavier or lighter in mind.";
	cout<<"The computer will ask \nyou some questions. ";
	cout<<"For each question, two sets of balls ";
	cout<<"will be given, and you\nshould answer which ";
	cout<<"set is";
	cout<<" heavier or that they are of the same weight.";
	cout<<endl;
	cout<<"At the end, the computer will tell which ball is ";
	cout<<"special, and whether it is \nheavier or lighter.";
	cout<<"The computer will ask the least number of ";
	cout<<"questions possible\nduring a game session.";
	cout<<"Now, have the special ball number in your";
	cout<<" mind and enter \nthe number of balls: ";
}

int main(){
	printhead();
	while(cin>>n)run();
	return 0;
}
/*
int main(){
	int i,k,max;
	for(n=3;n<MAXN;n++){
		max=0;k=1;
		while(k<2*n){
			k*=3;
			max++;
		}
		memset(w,0,sizeof(w));
		for(i=1;i<=n;i++)
			for(k=-1;k<2;k+=2){
				w[i]=k;
				times=0;
				if(run()!=i||times>max||(k==-1&&isheavy==1)||(k==1&&isheavy==2)){
					cout<<n<<' '<<i<<' '<<k<<endl;
					return 0;
				}
				w[i]=0;
			}
	}
	return 0;
}*/
