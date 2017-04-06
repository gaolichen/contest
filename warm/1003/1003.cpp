#include<string>
#include<map>
#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>

using namespace std;
int n,curr,pre,end;

struct NODE{
	char name[5];
	short g;
};



NODE vn[1000*1000+1];
int vnnum,vsnum,vnamenum;
short vs[3*(1000*1000)+1],r[1000*1000+1];

char vname[1000*1000+1][5];

int cmp1(const void *a,const void *b){
	return strcmp((char*)a,(char*)b);
}

int cmp2(const void *a,const void *b){
	if(((NODE*)a)->g!=((NODE*)b)->g)
		return ((NODE*)a)->g-((NODE*)b)->g;
	return strcmp(((NODE*)a)->name,((NODE*)b)->name);
}

int mybsearch(char * a){
	int top,low,mid,k;
	top=vnamenum-1;low=0;
	mid=(top+low)/2;
	while(low<mid){
		k=strcmp(vname[mid],a);
		if(!k)return mid;
		else if(k<0)
			low=mid;
		else top=mid;
		mid=(low+top)/2;
	}
	if(!strcmp(vname[low],a))return low;
	if(!strcmp(vname[top],a))return top;
	while(1);
	return -1;
}

void run(){
	int i;
	if(curr==vsnum)return ;
	printf("%s\n",vname[vs[curr]]);
	end=vsnum;
	for(i=curr+1;i<end;i++)
		if(vs[i]!=-1&&r[vs[i]]==r[vs[curr]]){
			vs[curr]=-1;
			curr=i;
			break;
		}
	if(i==end){
		vs[curr]=-1;
		while(pre<vsnum&&vs[pre]==-1)pre++;
		curr=pre;
		end=curr;
	}
}

int main(){
	int i,j,k,cnt=0;
	char tmp[1000];
	char name[100];
	while(1){
		scanf("%d",&n);
		if(n<1)break;
		if(cnt)putchar('\n');
		printf("Scenario #%d\n",++cnt);
		vnamenum=vsnum=vnnum=0;
		for(i=0;i<n;i++){
			scanf("%d",&k);
			for(j=0;j<k;j++){
				scanf("%s",vname[vnamenum]);
				strcpy(vn[vnnum].name,vname[vnamenum]);
				vn[vnnum++].g=i+1;
				vnamenum++;
			}
		}
		qsort(vname,vnamenum,sizeof(char)*5,cmp1);
		qsort(vn,vnnum,sizeof(NODE),cmp2);
		for(i=0;i<vnnum;i++){
			k=mybsearch(vn[i].name);
			r[k]=vn[i].g;
		}
		curr=pre=0;
		end=0;
		while(1){
			scanf("%s",tmp);
			if(tmp[0]=='S')break;
			if(tmp[0]=='E'){
				scanf("%s",name);
				vs[vsnum++]=mybsearch(name);
				if(vsnum>(3*(1000*1000)+1))
					while(1);
			}
			else {
				if(end==curr)end=vsnum;
				run();
			}
		}
	}
	return 0;
}