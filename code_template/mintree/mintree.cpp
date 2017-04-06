#include<string.h>
#define M 2100000000

int mintree(int map[][300],int n){
	int i,j,ret=0,min,ti,nea[300];
	char mark[300];
	memset(mark,0,sizeof(mark));
	mark[0]=1;
	for(i=0;i<n;i++)
		nea[i]=map[0][i];
	j=1;
	while(j++<n){
		min=M;
		for(i=0;i<n;i++)
			if(!mark[i]&&nea[i]<min){
				min=nea[i];
				ti=i;
			}
		mark[ti]=1;
		for(i=0;i<n;i++)
			if(!mark[i]&&nea[i]>map[i][ti])
				nea[i]=map[i][ti];
		ret+=min;
	}
	return ret;
}