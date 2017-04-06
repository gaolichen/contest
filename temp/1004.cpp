#include<stdio.h>
#include<string.h>
#include<math.h>
double s[15],aa[15],bb[16];
double p[20],a,b,c[15][15];
int n;
//FILE *in,*out,*in1,*out1;
void run()
{
	int i,j;
//	char res[10],res1[10];
	double sum;
	s[0]=b-a+1;
	for(i=1;i<=n;i++)
	{
		s[i]=0.0;
		if(a+b!=0||i%2==0){
	for(j=0;j<i;j++)
		s[i]+=c[i+1][j]*s[j];
	s[i]=(bb[i+1]-aa[i+1])-s[i];
	s[i]/=i+1;
		}
	}
	for(i=0,sum=0.0;i<=n;i++)
		sum+=p[i]*s[i];
	if(fabs(sum)<1e-6)
		sum=0.0;
//	fscanf(out,"%s",res);
//	fprintf(out1,"%.6e\n",sum);
	printf("%.6e\n",sum);
//	fscanf(in1,"%s",res1);
//	if(res1!=res)
//	{
//		printf("%s %s\n",res1,res);
//		for(i=n;i>=0;i--)
//			printf("%.0lf ",p[i]);
//		printf("\n%.0lf %.0lf\n",a,b);
//		getchar();
//	}
}
void init()
{
	int i,j;
	for(i=0;i<=12;i++)
		c[i][i]=c[i][0]=1.0;
	for(i=1;i<=12;i++)
		for(j=1;j<i;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
/*	for(i=0;i<=11;i++)
		for(j=0,putchar('\n');j<=i;j++)
			printf("%.0lf ",c[i][j]);
	putchar('\n');*/
}
void init1()
{
öööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööööö==1)
	while(scanf("%d",&n)==1)
	{
		for(i=n;i>=0;i--)
			scanf("%lf",&p[i]);
//			fscanf(in,"%lf",&p[i]);
//		fscanf(in,"%lf%lf",&a,&b);
		scanf("%lf %lf",&a,&b);
		init1();
		run();
	}
}/*
void main()
{
	char buf1[50],buf2[50];
	int len,i;
	if((in=fopen("input.txt","r"))==0)
	{
		printf("error\n");
		return ;
	}
	if((out=fopen("output.txt","r"))==0)
	{
		printf("error\n");return ;
	}
	if((in1=fopen("out1.txt","r"))==0)
	{
		printf("error2\n");return ;
	}
	while(fscanf(out,"%s",buf1)==1)
	{
		fscanf(in1,"%s",buf2);
		len=strlen(buf2);
		for(i=len-3;i<len;i++)
			buf2[i]=buf2[i+1];
		fscanf(in,"%d",&n);
		for(i=n;i>=0;i--)
			fscanf(in,"%lf",&p[i]);
		fscanf(in,"%lf%lf",&a,&b);
		if(strcmp(buf1,buf2)!=0)
//		if(buf1!=buf2)
		{
			getchar();
			printf("%d\n",n);
			for(i=n;i>=0;i--)
				printf("%.0lf ",p[i]);
			putchar('\n');
			printf("%.0lf %.0lf\n",a,b);
			printf("%s %s\n",buf1,buf2);
		}
	}
}*/