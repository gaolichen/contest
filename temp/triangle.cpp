#include<stdio.h>
#include<math.h>
#define pai 3.1415926536
double angle[6],side[6],d;
int flag,toan,tosi,j;
int comp(double i,double j)
{
	int k=1;
	if(j==-1)
		k=1;
	else if(fabs(i-j)>1e-5)
	{flag=0;k=0;}
	return k;
}
void fcos(int i,int j,int k)
{
side[i]=side[j]*side[j]+side[k]*side[k];
side[i]-=2*side[j]*side[k]*cos(angle[i]);
side[i]=sqrt(side[i]);
}
void mfcos(int i,int j,int k)
{
	double t;
if(side[i]<=0||side[k]<=0||side[k]<=0)
	return;
	t=side[j]*side[j]+side[k]*side[k];
	t-=side[i]*side[i];
	t/=2*side[j]*side[k];
	t=acos(t);
	if(comp(t,angle[i]))
		angle[i]=t;
}
void init()
{
	int i;
	scanf("%lf%lf",&side[0],&angle[0]);
	scanf("%lf%lf",&side[1],&angle[1]);
	scanf("%lf%lf",&side[2],&angle[2]);
	for(i=3;i<6;i++)
	{
		side[i]=side[i-3];
		angle[i]=angle[i-3];
	}
	flag=1;d=-1;toan=tosi=0;
}
void print()
{
int i;
switch(flag)
{
case 0:printf("Invalid input.\n");break;
case 2:printf("More than one solution.\n");
	break;
case 1:for(i=0;i<3;i++)
		printf("%.10lf %.10lf ",side[i],angle[i]);
	printf("\n");
}
}
void main()
{
	int i,n,k,m;
	double temp;
	scanf("%d",&n);
	for(j=0;j<n;j++)
	{
		init();
		temp=0;
		for(i=0;i<3;i++)
		{
		if(angle[i]>=pai)
			flag=0;
		else if(angle[i]!=-1)toan++;
		if(side[i]!=-1)tosi++;
		}
		if(flag&&toan==2)
		{
		for(i=0;i<3;i++)
		{
			if(angle[i]==-1)
				k=i;
			else temp+=angle[i];
		}
		angle[k]=angle[k+3]=pai-temp;toan=3;
		}
if(toan==3)
if(fabs(angle[0]+angle[1]+angle[2]-pai)>1e-5)
	flag=0;
if(flag==1&&tosi==1)
	{
			if(toan<=1)flag=0;
			else if(toan==3)
			{
				for(i=0;i<3;i++)
					if(side[i]!=-1)
						k=i;
				d=side[k]/sin(angle[k]);
				for(i=0;i<3;i++)
				if(i!=k)
			side[i+3]=side[i]=d*sin(angle[i]);
				tosi=3;
			}
		}
		if(flag==1&&tosi==2)
		{
			if(toan==0)flag=0;
			else 
			{
				for(i=0;i<3;i++)
					if(side[i]==-1)
						k=i;
				if(toan==3)
				{
				for(i=0;i<3;i++)
				if(i!=k)
				d=side[i]/sin(angle[i]);
			side[k]=d*sin(angle[k]);tosi=3;
				}
				else if(toan==1)
				{
if(angle[k]!=-1)
{
side[k]=side[k+1]*side[k+1];
side[k]+=side[k+2]*side[k+2];
side[k]-=2*side[k+1]*side[k+2]*cos(angle[k]);
side[k]=sqrt(side[k]);
tosi=3;
}
		else
		{
			for(i=0;i<3;i++)
			if(angle[i]!=-1)
				break;
			if(fabs(angle[i]-pai/2)<1e-5)
			{
				if(side[i+1]!=-1)
					temp=side[i+1];
				else temp=side[i+2];
				temp*=temp;
				temp=side[i]*side[i]-temp;
				temp=sqrt(temp);
				side[k]=temp;
				tosi=3;
			}
		else 
		{
		for(m=0;m<3;m++)
		if(m!=k&&m!=i)
			break;
		temp=side[i]/side[m];
		if(fabs(temp-sin(angle[i]))<1e-5)
		{
			side[k]=side[m]*cos(angle[i]);
			tosi=3;
		}
		else if(side[i]>=side[m])
		{
			d=side[i]/sin(angle[i]);
			temp=side[m]/d;
			angle[m]=asin(temp);
			angle[k]=pai-angle[m]-angle[i];
			fcos(k,i,m);
			tosi=3;
		}
		else flag=2;
		}
		}
		}
	}
	}
		if(flag==1&&tosi==3)
		{
			mfcos(0,1,2);
			mfcos(1,0,2);
			mfcos(2,0,1);
		}
		print();
	}
}
