#include<iostream.h>
#include<string.h>
struct rectangle{
	int c;
	int x1,y1,x2,y2;
};

int rectintersect(rectangle a,rectangle b,rectangle *cut){
	if(a.x1>=b.x2||a.x2<=b.x1)return 0;
	if(a.y2<=b.y1||a.y1>=b.y2)return 0;
	if(a.x1>=b.x1&&a.x2<=b.x2&&a.y1>=b.y1&&a.y2<=b.y2)
		return -1;
	int ret=0;
	if(a.x1<b.x1){
		cut[ret]=a;
		cut[ret++].x2=b.x1;
		a.x1=b.x1;
	}
	if(a.x2>b.x2){
		cut[ret]=a;
		cut[ret++].x1=b.x2;
		a.x2=b.x2;
	}
	if(a.y1<b.y1){
		cut[ret]=a;
		cut[ret++].y2=a.y1=b.y1;
	}
	if(a.y2>b.y2){
		cut[ret]=a;
		cut[ret++].y1=a.y2=b.y2;
	}
	return ret;
}
//求长方形的交
void cutrectangle(rectangle *init,int n,rectangle *end,int *nn){
	int i,j,rr=0,nr,k;
	rectangle cut[4];
	for(i=0;i<n;i++){
		end[rr]=init[i];
		nr=rr++;
		for(j=0;j<nr;j++){
			k=rectintersect(end[j],end[nr],cut);
			if(k==0)continue;
			if(k==-1){
				memmove(end+j,end+j+1,sizeof(rectangle)*(rr-j-1));
				j--;
				rr--;
				nr--;
				continue;
			}
			end[j]=cut[--k];
			while(k>0)end[rr++]=cut[--k];
		}
	}
	*nn=rr;
}

