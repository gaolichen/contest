#include<iostream.h>
#include<stdio.h>
#include<fstream.h>

int n,m,a[2100],b[2100],r[2100],next[2100],pre[2100];
/*
//FILE *in,*out;
void run(){
	int i,j,head,end;
	for(i=1;i<=n;i++){
		r[i]=i;
		pre[i]=i-1;
		next[i]=i+1;
	}
	pre[1]=n;
	next[n]=1;
	head=1;end=n;
	for(i=1;i<n;i++){
		for(j=0;j<m;j++){
			head=next[head];
		}
		a[i]=r[head];
		end=pre[head];
		head=next[head];
		pre[head]=end;
		next[end]=head;
//		cout<<a[i]<<endl;
	}
	a[i]=r[head];
	for(i=1;i<=n;i++)
		b[a[i]]=i;
	for(i=1;i<=n;i++){
		if(i>1)putchar(' ');
//		if(i>1)out<<' ';
//		if(i>1)fprintf(out," ");
//		out<<b[i];
//		fprintf(out,"%d",b[i]);
		printf("%d",b[i]);
	}
//	out<<endl;
//	fprintf(out,"\n");
	printf("\n");
}*/

void run(){
	int i,j,head,end,curr;
	for(i=0;i<n;i++)r[i]=i;
	head=0;end=n-1;
	for(i=curr=0;i<n;i++){
		curr+=m%(end-head+1);
		if(curr>end)curr=curr%(end+1)+head;
		a[i]=r[curr];
//		printf("%d\n",a[i]);
		if(2*curr>head+end){
			for(j=curr;j<end;j++)
				r[j]=r[j+1];
			end--;
		}
		else{
			for(j=curr;j>head;j--)
				r[j]=r[j-1];
			head++;
		}
		if(curr>end)curr=head;
		curr++;
		if(curr>end)curr=head;
		printf("%d %d %d %d\n",a[i],head,end,curr);
		for(j=head;j<=end;j++)
			printf("%d ",r[j]);
		putchar('\n');
	}
	for(i=0;i<n;i++)
		b[a[i]]=i;
	for(i=0;i<n;i++){
		if(i)putchar(' ');
		printf("%d",b[i]+1);
	}
	putchar('\n');
}
int main(){
//	in=fopen("input.txt","r");
//	out=fopen("output.txt","w");
	while(scanf("%d %d",&n,&m)==2)run();
	return 0;
}