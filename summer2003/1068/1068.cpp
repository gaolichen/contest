#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

unsigned int p[40],mark[100000000/32+1];
unsigned char prime[5800000];
int cnt;

void init(){
	int i,j,k;
	p[0]=1;
	for(i=1;i<32;i++)
		p[i]=(p[i-1]<<1);
	memset(mark,0,sizeof(mark));
	for(k=6;k<10000;k+=6){
		i=k-1;
		if(!(mark[i>>5]&p[i&0x1f])){
			j=i*i;
			mark[j>>5]|=p[j&0x1f];
			for(;;){
				j+=i+i;
				if(j>100000000)break;
				mark[j>>5]|=p[j&0x1f];
				j+=4*i;
				if(j>100000000)break;
				mark[j>>5]|=p[j&0x1f];
			}
		}
		i=k+1;
		if(!(mark[i>>5]&p[i&0x1f])){
			j=i*i;
			mark[j>>5]|=p[j&0x1f];
			for(;;){
				j+=4*i;
				if(j>100000000)break;
				mark[j>>5]|=p[j&0x1f];
				j+=i+i;
				if(j>100000000)break;
				mark[j>>5]|=p[j&0x1f];
			}
		}
	}
	prime[0]=2;prime[1]=1;j=3;cnt=2;
	for(k=6;k<100000000;k+=6){
		i=k-1;
		if(!(mark[i>>5]&p[i&0x1f])){
			prime[cnt++]=i-j;
			j=i;
			if(cnt>=5800000)break;
		}
		i=k+1;
		if(!(mark[i>>5]&p[i&0x1f])){
			prime[cnt++]=i-j;
			j=i;
			if(cnt>=5800000)break;
		}
	}
}
int main(){
	init();
	int tot=0,n,j,num;
	while(scanf("%d",&n)==1){
		tot=0;num=2;
		for(j=1;j<cnt;j++){
			num+=prime[j];
			if(num+num>n)break;
			if((n-num)!=3&&(n-num)%6!=1&&(n-num)%6!=5)continue;
			if(!(mark[(n-num)>>5]&p[(n-num)&0x1f])){
				tot++;
				if(tot<=20){
					printf("%d+%d\n",num,n-num);
				}
				else if(tot==21){
					printf("...\n");
				}
			}
		}
		printf("%d\n",tot);
	}
	return 0;
}