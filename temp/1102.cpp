#include<stdio.h>
#define N 1200
#define M 2100000000
int p[13]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096};
char gen[N][N];
char f[14][N];
int sc[14][N];
int n,l;
void run()
{
	int i,j=1,k,h,t,count=0,tot=0,min;
	char res[N];
	while(j<n)
	{
		j*=2;count++;
	}
	for(i=0;i<l;i++)
	{
		for(k=0;k<=count;k++)
		for(j=0;j<n;j++)
		{
			f[k][j]=gen[j][i];
			if(k)sc[k][j]=M;
			else sc[k][j]=0;
		}
		for(j=0;j<count;j++)
		for(k=0;k<p[count-j];k+=2)
		for(h=k*p[j];h<(k+1)*p[j];h++)
		for(t=(k+1)*p[j];t<(k+2)*p[j];t++)
		{
			if(f[j][t]==f[j][h])
			{
			if(sc[j][t]+sc[j][h]<sc[j+1][h])
			sc[j+1][h]=sc[j][t]+sc[j][h];
			if(sc[j][h]+sc[j][t]<sc[j+1][t])
			sc[j+1][t]=sc[j][h]+sc[j][t];
			}
			else 
			{
		if(sc[j][t]+1+sc[j][h]<sc[j+1][h])
			sc[j+1][h]=sc[j][t]+1+sc[j][h];
		if(sc[j][h]+1+sc[j][t]<sc[j+1][t])
			sc[j+1][t]=sc[j][h]+1+sc[j][t];
			}
		}
		min=-1;
		for(k=0;k<n;k++)
	if(min==-1||sc[count][k]<sc[count][min])
			min=k;
		res[i]=f[count][min];
		tot+=sc[count][min];
		printf("%d\n",tot);
	}
	res[l]='\0';
	printf("%s %d\n",res,tot);
}
void main()
{
	int i;
	char buf[80];
	scanf("%d%d",&n,&l);
	while(n&&l)
	{
		gets(buf);
		for(i=0;i<n;i++)
			gets(gen[i]);
		run();
		scanf("%d%d",&n,&l);
	}
}