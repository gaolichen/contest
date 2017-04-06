#include<stdio.h>
#include<string.h>
#include<math.h>
char name[30],sub[400][30],lx[400][20];
int cj[400],mark[400],n;
double xf[400],hcj[400],gap,zxf,zcj;
void run()
{
	int i,ti,tot=0;
	double zxf=0.0,zcj=0.0,gap,max;
	memset(mark,0,sizeof(mark));
	for(i=0;i<n;i++)
	{
		if(cj[i]>=90)
			hcj[i]=4.0;
		else hcj[i]=1.0+(cj[i]-60)*0.1;
		if(strcmp(lx[i],"normal")==0)
		{
			zxf+=xf[i];
			zcj+=xf[i]*hcj[i];
			mark[i]=1;
			tot++;
		}
	}
	gap=zcj/zxf;
	while(1)
	{
		for(i=0,max=0.0;i<n;i++)
			if(!mark[i])
			{
				if(hcj[i]-max>1e-6)
				{
					max=hcj[i];
					ti=i;
				}
				else if(fabs(hcj[i]-max)<1e-6&&xf[i]>xf[ti])
					ti=i;
			}
		if(max>1e-6&&hcj[ti]-gap>1e-6)
		{
			mark[ti]=1;
			zxf+=xf[ti];
			zcj+=xf[ti]*hcj[ti];
			gap=zcj/zxf;
			tot++;
		}
		else break;
	}
	if(zxf-(int)zxf>0.1)
		printf("%s %.2lf %d.5 %d\n",name,gap,(int)zxf,tot);
	else printf("%s %.2lf %d %d\n",name,gap,(int)zxf,tot);
	for(i=0;i<n;i++)
	{
		if(mark[i])
			printf("* ");
		else printf("  ");
		if(xf[i]-(int)xf[i]>0.1)
			printf("%s %d.5 %d %s\n",sub[i],(int)xf[i],cj[i],lx[i]);
		else 
			printf("%s %d %d %s\n",sub[i],(int)xf[i],cj[i],lx[i]);
	}
	putchar('\n');
}
void main()
{
	int i;
	while(scanf("%s",name)==1)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%s %lf %d %s",sub[i],&xf[i],&cj[i],lx[i]);
		run();
	}
}