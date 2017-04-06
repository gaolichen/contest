#include<iostream.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

char name[30][20];
int time[30][10],geo[30],tot[30],sol[30],n,r[30];

int cmp(const void *a,const void *b){
	int i,j;
	i=*(int*)a;j=*(int*)b;
	if(sol[i]!=sol[j])return sol[j]-sol[i];
	if(tot[i]!=tot[j])return tot[i]-tot[j];
	if(geo[i]!=geo[j])return geo[i]-geo[j];
	return strcmp(name[i],name[j]);
}
void run(){
	int i,j;
	double t=0;
	for(i=0;i<n;i++){
		sol[i]=tot[i]=geo[i]=0;
		for(j=0;j<7;j++)
			if(time[i][j]){
				sol[i]++;
				tot[i]+=time[i][j];
			}
		if(sol[i]){
			t=0;
			for(j=0;j<7;j++)
				if(time[i][j])
					t+=log(time[i][j]);
			t/=sol[i];
			geo[i]=(int)(exp(t)+0.5);
		}
	}
	for(i=0;i<n;i++)
		r[i]=i;
	qsort(r,n,sizeof(int),cmp);
//	printf("%d\n",strcmp(name[r[1]],name[r[2]]));
	int rank,pre=1;
	for(i=0;i<n;i++){
		if(!i||sol[r[i]]!=sol[r[i-1]]||tot[r[i]]!=tot[r[i-1]]||geo[r[i]]!=geo[r[i-1]])
			rank=i+1;
		else rank=pre;
		pre=rank;
		printf("%02d %-10s %d %4d %3d",rank,name[r[i]],sol[r[i]],tot[r[i]],geo[r[i]]);
		for(j=0;j<7;j++)
			printf(" %3d",time[r[i]][j]);
		printf("\n");
	}
}

int main(){
	int i,cnt=0,j;
	while(1){
		cin>>n;
		if(n<1)break;
		for(i=0;i<n;i++){
			cin>>name[i];
			for(j=0;j<7;j++)
				cin>>time[i][j];
		}
		printf("CONTEST %d\n",++cnt);
		run();
	}
	return 0;
}