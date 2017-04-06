#include<stdio.h>
int p[10]={0},i;
int a[5][5]={{0,1,1,0,1},
{1,0,1,0,1},{1,1,0,1,1},{0,0,1,0,1},
{1,1,1,1,0}};
int pop;
void print()
{
	int j;
	for(j=0;j<=8;j++)
		printf("%d",p[j]+1);
	printf("\n");
	a[p[pop-1]][p[pop]]=1;
	a[p[pop]][p[pop-1]]=1;
	i=p[pop]+1;
	pop--;
}
void main(){
	i=0;
	pop=0;
	p[0]=0;
	while(pop>=0){
		if(pop==8)
			print();
		else if(i==5){
			if(pop)
			{
			a[p[pop]][p[pop-1]]=1;
			a[p[pop-1]][p[pop]]=1;
			i=p[pop]+1;
			}
			pop--;
		}
		else{
			if(a[p[pop]][i])
			{
				a[p[pop]][i]=0;
				a[i][p[pop]]=0;
				p[++pop]=i;
				i=0;
			}
		    else i++;
		}
	}
}
