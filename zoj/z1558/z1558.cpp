#include<iostream.h>
#include<stdio.h>

int a[10],f[1100];
void run(){
	int i,j,k;
	for(i=1;i<=500;i++)
		f[i]=i;
	for(i=0;i<6;i++)f[a[i]]=1;
	for(i=1;i<=50;i++)
		for(j=1;j<=500;j++)
			if(f[j]==i)
				for(k=0;k<6;k++){
					if(a[k]+j<=500&&f[a[k]+j]>i+1)
						f[a[k]+j]=i+1;
					if(j-a[k]>0&&f[j-a[k]]>i+1)
						f[j-a[k]]=i+1;
				}
	int av=0;
	for(i=1,j=0;i<=100;i++){
		if(f[i]>j)j=f[i];
		av+=f[i];
	}
	printf("%.2lf %d\n",av/100.0,j);
}
int main(){
	int i,j,t;
	for(i=0,cin>>t;i<t;i++){
		for(j=0;j<6;j++)
			cin>>a[j];
		run();
	}
	return 0;
}