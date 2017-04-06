/*
ID:  mygali1
PROG: rect1
*/
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("rect1.in");
ofstream out("rect1.out");
#endif
/*
struct rectangle{
	short llx,lly,urx,ury,color;
};
rectangle rect[1100];
char markx[10001],marky[10001],mark[1100];
int x[5000],y[5000],n,a,b,countx,county,s[3000];

int cmp(const void *t1,const void *t2){
	return *(int *)t1-*(int*)t2;
}
int checkin(int llx,int lly,int urx,int ury,rectangle rec){
	if(llx<rec.llx||lly<rec.lly)return 0;
	if(urx>rec.urx||ury>rec.ury)return 0;
	return 1;
}
void run(){
	int i,j,k;
	memset(mark,0,sizeof(mark));
	for(i=n-1;i>=0;i--)
		if(!mark[i])
			for(j=i-1;j>=0;j--)
				if(!mark[j]&&checkin(rect[j].llx,rect[j].lly,rect[j].urx,rect[j].ury,rect[i]))
					mark[j]=1;
	j=n;n=0;
	for(i=0;i<j;i++)
		if(!mark[i])rect[n++]=rect[i];
	memset(markx,0,sizeof(markx));
	memset(marky,0,sizeof(marky));
	markx[0]=markx[a]=1;
	marky[0]=marky[b]=1;
	x[0]=0;x[1]=a;y[0]=0;y[1]=b;
	countx=county=2;
	for(i=0;i<n;i++){
		if(!markx[rect[i].llx]){
			x[countx++]=rect[i].llx;
			markx[x[countx-1]]=1;
		}
		if(!markx[rect[i].urx]){
			x[countx++]=rect[i].urx;
			markx[x[countx-1]]=1;
		}
		if(!marky[rect[i].lly]){
			y[county++]=rect[i].lly;
			marky[y[county-1]]=1;
		}
		if(!marky[rect[i].ury]){
			y[county++]=rect[i].ury;
			marky[y[county-1]]=1;
		}
	}
	qsort(x,countx,sizeof(int),cmp);
	qsort(y,county,sizeof(int),cmp);
	memset(s,0,sizeof(s));
	for(i=0;i<countx-1;i++)
		for(j=0;j<county-1;j++){
			for(k=n-1;k>=0;k--)
				if(checkin(x[i],y[j],x[i+1],y[j+1],rect[k]))break;
			if(k>=0)s[rect[k].color]+=(x[i+1]-x[i])*(y[j+1]-y[j]);
			else s[1]+=(x[i+1]-x[i])*(y[j+1]-y[j]);
		}
	for(i=1;i<=2500;i++)
		if(s[i])out<<i<<' '<<s[i]<<endl;
}
int main(){
	int i;
	while(in>>a>>b>>n){
		for(i=0;i<n;i++)
			in>>rect[i].llx>>rect[i].lly>>rect[i].urx>>rect[i].ury>>rect[i].color;
		run();
	}
	return 0;
}*/

//用长方形交来求的版本
int n,a,b,nn,s[3000];
struct rectangle{
	int c;
	int x1,y1,x2,y2;
};
rectangle rec[1100],nrec[3000];
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
				j--;rr--;nr--;
				continue;
			}
			end[j]=cut[--k];
			while(k>0)end[rr++]=cut[--k];
		}
	}
	*nn=rr;
}

void run(){
	int i;
	cutrectangle(rec,n,nrec,&nn);
	memset(s,0,sizeof(s));
	for(i=0;i<nn;i++)
		s[nrec[i].c]+=(nrec[i].x2-nrec[i].x1)*(nrec[i].y2-nrec[i].y1);
	for(i=1;i<=2500;i++)
		if(s[i])out<<i<<' '<<s[i]<<endl;
}
int main(){
	int i;
	while(in>>a>>b>>n){
		rec[0].c=1;
		rec[0].x1=rec[0].y1=0;
		rec[0].x2=a;rec[0].y2=b;
		for(i=1;i<=n;i++)
			in>>rec[i].x1>>rec[i].y1>>rec[i].x2>>rec[i].y2>>rec[i].c;
		n++;
		run();
	}
	return 0;
}
