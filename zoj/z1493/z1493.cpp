#include<iostream.h>
#include<stdio.h>


int a[10010],b[10010],n;

void run(){
	int i,tmp;
	printf("%d\n",n/2);
	a[0]=b[0]=0;
	tmp=a[0];
	for(i=1;i<=n;i++){
		b[i]=a[i];
		b[i]-=tmp;
		if(b[i]<-8)b[i]=-8;
		if(b[i]>7)b[i]=7;
		tmp+=b[i];
	}
	for(i=1;i<=n;i++){
		if(b[i]<0)b[i]=16+b[i];
	}
	for(i=1;i*2<=n;i++){
		b[i]=b[2*i-1]<<4;
		b[i]+=b[2*i];
	}
	for(i=1;i*2<=n;i++){
		if(i!=1&&i%8==1)
			printf("\n");
		if(i%8!=1)printf(" ");
//		printf("%x",(unsigned char)(b[i]));
		printf("%02x",(b[i]));
	}
	printf("\n");
}
int main(){
	int i;
	while(scanf("%d",&n)==1){
		for(i=1;i<=n;i++)
			scanf("%X",&a[i]);
		run();
	}
	return 0;
}