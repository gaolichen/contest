#include<iostream.h>
#include<stdio.h>
#include<string.h>
#define i64 long long

i64 s[2],r[2],cx[2],cy[2],top[2],low[2],left[2],right[2];

int in(i64 x,i64 y,i64 cx,i64 cy,i64 r){
	return (x-cx)*(x-cx)+(y-cy)*(y-cy)<r*r;
}

i64 abs(i64 a){
	return (a>0? a:-a);
}
void run(){
	i64 i;
	if(!s[0]&&!s[1]){
		i=(cx[0]-cx[1])*(cx[0]-cx[1])+(cy[0]-cy[1])*(cy[0]-cy[1]);
		if(i>(r[0]+r[1])*(r[0]+r[1])||i<(r[0]-r[1])*(r[0]-r[1]))
			cout<<"no"<<endl;
		else cout<<"yes"<<endl;
		return;
	}
	if(s[0]&&s[1]){
		if(top[0]>low[1]||top[1]>low[0]
			||left[0]<right[1]||left[1]<right[0])
			cout<<"no"<<endl;
		else if(top[0]<top[1]&&low[0]>low[1]
			&&left[0]>left[1]&&right[0]<right[1])
			cout<<"no"<<endl;
		else if(top[1]<top[0]&&low[1]>low[0]
			&&left[1]>left[0]&&right[1]<right[0])
			cout<<"no"<<endl;
		else cout<<"yes"<<endl;
		return ;
	}
	if(!s[0]&&s[1]){
		if(in(top[1],left[1],cx[0],cy[0],r[0])&&
			in(top[1],right[1],cx[0],cy[0],r[0])&&
			in(low[1],left[1],cx[0],cy[0],r[0])&&
			in(low[1],right[1],cx[0],cy[0],r[0]))
			cout<<"no"<<endl;
		else if(in(top[1],left[1],cx[0],cy[0],r[0])||
			in(top[1],right[1],cx[0],cy[0],r[0])||
			in(low[1],left[1],cx[0],cy[0],r[0])||
			in(low[1],right[1],cx[0],cy[0],r[0]))
			cout<<"yes"<<endl;
		else {
			if(abs(top[1]-cx[0])<=r[0]||abs(low[1]-cx[0])<=r[0]){
				if((right[1]-cy[0])*(left[1]-cy[0])<=0){
					cout<<"yes"<<endl;
					return;
				}
			}
			if(abs(left[1]-cx[0])<=r[0]||abs(right[1]-cx[0])<=r[0]){
				if((top[1]-cx[0])*(low[1]-cx[0])<=0){
					cout<<"yes"<<endl;
					return;
				}
			}
			cout<<"no"<<endl;
		}
		return ;
	}
	if(!s[1]&&s[0]){
		if(in(top[0],left[0],cx[1],cy[1],r[1])&&
			in(top[0],right[0],cx[1],cy[1],r[1])&&
			in(low[0],left[0],cx[1],cy[1],r[1])&&
			in(low[0],right[0],cx[1],cy[1],r[1]))
			cout<<"no"<<endl;
		else if(in(top[0],left[0],cx[1],cy[1],r[1])||
			in(top[0],right[0],cx[1],cy[1],r[1])||
			in(low[0],left[0],cx[1],cy[1],r[1])||
			in(low[0],right[0],cx[1],cy[1],r[1]))
			cout<<"yes"<<endl;
		else {
			if(abs(top[0]-cx[1])<=r[1]||abs(low[0]-cx[1])<=r[1]){
				if((right[0]-cy[1])*(left[0]-cy[1])<=0){
					cout<<"yes"<<endl;
					return;
				}
			}
			if(abs(left[0]-cx[1])<=r[1]||abs(right[0]-cx[1])<=r[1]){
				if((top[0]-cx[1])*(low[0]-cx[1])<=0){
					cout<<"yes"<<endl;
					return;
				}
			}
			cout<<"no"<<endl;
		}
		return ;
	}
}
int main(){
	int t,i;
	char buf[100];
//	scanf("%d",&t);
	cin>>t;
	while(t--){
		for(i=0;i<2;i++){
//			scanf("%s",buf);
			cin>>buf;
			if(buf[0]=='c'){
				s[i]=0;
//				scanf("%64d %64d %64d",&r[i],&cx[i],&cy[i]);
				cin>>r[i]>>cx[i]>>cy[i];
			}
			else{
				s[i]=1;
				cin>>top[i]>>left[i]>>low[i]>>right[i];
//				scanf("%64d %64d %64d %64d",&top[i],&left[i],&low[i],&right[i]);
			}
		}
		run();
	}
	return 0;
}