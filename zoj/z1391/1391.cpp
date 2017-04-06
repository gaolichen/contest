#include<iostream.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int sy,ey,x;
}segment;
segment seg[9000];
int p[8]={1,2,4,8,16,32,64,128};
int n;
unsigned char map[8001][1001];
int mark[9000],done[9000],x[8000*2+10];

int cmp(const void *t1,const void *t2){
	if(((segment*)t1)->x!=((segment*)t2)->x)
		return ((segment*)t1)->x-((segment*)t2)->x;
	return ((segment*)t1)->sy-((segment*)t2)->sy;
}
void run(){
	int i,k,count=0,tot=0;
	int j;
	for(i=0;i<=8000;i++)
		if(mark[i])x[i]=tot++;
	for(i=0;i<n;i++){
		seg[i].sy=x[seg[i].sy];
		seg[i].ey=x[seg[i].ey];
	}
	for(i=tot=0;i<=8000;i++)
		if(done[i])x[i]=tot++;
	for(i=0;i<n;i++){
		seg[i].x=x[seg[i].x];
	}
	qsort(seg,n,sizeof(segment),cmp);
	memset(map,0,sizeof(map));
	memset(mark,0,sizeof(mark));
	memset(x,0,sizeof(x));
	for(i=seg[0].sy;i<seg[0].ey;i++)
		x[i*2]=x[i*2+1]=1;
	x[2*seg[0].ey]=1;
	for(i=1;i<n;i++){
		tot=0;
		for(j=seg[i].sy;j<=seg[i].ey;j++)
		{
			if(x[2*j]){
				if(!(map[i][(x[2*j]-1)/8]&p[(x[2*j]-1)%8])){
					mark[tot++]=x[2*j]-1;
					map[i][(x[2*j]-1)/8]|=p[(x[2*j]-1)%8];
					map[(x[2*j]-1)][i/8]|=p[i%8];
				}
			}
			x[2*j]=i+1;
			if(j!=seg[i].ey){
				if(x[2*j+1]){
					if(!(map[i][(x[2*j+1]-1)/8]&p[(x[2*j+1]-1)%8])){
					mark[tot++]=x[2*j+1]-1;
					map[i][(x[2*j+1]-1)/8]|=p[(x[2*j+1]-1)%8];
					map[(x[2*j+1]-1)][i/8]|=p[i%8];
					}
				}
				x[2*j+1]=i+1;
			}
		}
		for(j=0;j<tot;j++)
			for(k=j+1;k<tot;k++)
				if(map[mark[j]][mark[k]/8]&p[mark[k]%8])count++;
		}/*
	for(i=0;i<n;i++){
		for(j=seg[i].sy;j<=seg[i].ey;){
			k=i+1;
			while(k<n&&!(seg[k].sy<=j&&seg[k].ey>=j))k++;
			if(k>=n||mark[k]==i+1){
				j+=0.5;
				if(k<n&&seg[k].x==seg[i].x+1)j=seg[k].ey+0.5;
				continue;
			}
			else {
				mark[k]=i+1;
				map[i][k/8]+=p[k%8];
				map[k][i/8]+=p[i%8];
				j+=0.5;
			}
		}
	}*/
/*	for(i=count=0;i<n;i++)
		for(l=i+1;l<n;l++)
			if(map[i][l/8]&p[l%8])
			for(k=l+1;k<n;k++)
				if((map[l][k/8]&p[k%8])&&(map[i][k/8]&p[k%8])){
					count++;
//					cout<<i<<' '<<l<<' '<<k<<endl;
				}*/
	/*
	for(i=count=0;i<n;i++){	
		memset(done,0,sizeof(done));
		for(j=seg[i].sy;j<=seg[i].ey;){
			k=i+1;
			while(k<n&&!(seg[k].sy<=j&&seg[k].ey>=j))k++;
			if(k>=n||mark[k]==i+1){
				j+=0.5;
				if(seg[k].x==seg[i].x+1)j=seg[k].ey+0.5;
				continue;
			}
			else{
				mark[k]=i+1;
				for(h=seg[k].sy;h<=seg[k].ey;){
					l=k+1;
					while(l<n&&!(seg[l].sy<=h&&seg[l].ey>=h))l++;
					if(l>=n||done[l]==k+1){
						h+=0.5;
						if(seg[l].x==seg[k].x+1)h=seg[l].ey+0.5;
						continue;
					}
					else{
						done[l]=k+1;
						for(g=seg[l].sy;g<=seg[l].ey&&g<=seg[i].ey;){
							if(g<seg[i].sy){
								g=seg[i].sy;continue;
							}
							t=l-1;
							while(t>=i&&!(seg[t].sy<=g&&seg[t].ey>=g))t--;
							if(t<i){
								g+=0.5;
								continue;
							}
							else if(t!=i){
								g=seg[t].ey+0.5;
								continue;
							}
							else {
								count++;
								break;
							}
						}
						h+=0.5;
						if(seg[l].x==seg[k].x+1)h=seg[l].ey+0.5;
					}
					
				}
				j+=0.5;
				if(seg[k].x==seg[i].x+1)j=seg[k].ey+0.5;
			}
		}
	}*/
	cout<<count<<endl;
	
}
int main(){
	int t,i;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<n;i++){
			cin>>seg[i].sy>>seg[i].ey>>seg[i].x;
			mark[seg[i].sy]=mark[seg[i].ey]=1;
			done[seg[i].x]=1;
		}
		run();
	}
	return 0;
}