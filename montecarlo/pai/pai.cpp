#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include<time.h>

const int maxn=3;

double pi=acos(-1.0);

inline double random(){
	return (double)rand()/RAND_MAX;
}

void calc_pi(){
	int n,cnt,tot,i;
	int x1,y1,x2,y2,max;
	double y,pai=0;
	for(i=0;i<maxn;i++){
		cout<<i<<endl;
		n=10000000;
		max=0;
		cnt=0,tot=n;srand(time(NULL));
		while(n--){		
			x1=rand();
			y1=rand();
			x2=rand();
			y2=rand();
			y=500.0/sqrt(((double)(x1-x2))*(x1-x2)+((double)(y1-y2))*(y1-y2))*(y2-y1);
			if(y<0)y=-y;
			y1%=500;
			y+=y1;
			if(y1==0||y>500)cnt++;
		}
		pai+=2*tot/(double)cnt;
	}
	cout<<pai/maxn<<endl;
	return ;
}

int main(){
	int n,cnt[10],tot,i;
	double r;
	int a,b;
	a=-2100000000;
	b=-a+1;
	a=a-b;
	b=a+b;
	a=a-b;
	cout<<a<<' '<<b<<endl;
	while(cin>>n){
		srand(time(NULL));
		memset(cnt,0,sizeof(cnt));
		tot=n;
		while(n--){
			r=random();
			r=-log(r);
			for(i=0;i<10;i++)
				if(i+1>=r)cnt[i]++;
		}
		for(i=0;i<10;i++)
			cout<<cnt[i]/(double)tot<<' '<<1-exp(-i-1.0)<<endl;
	}
	return 0;
}