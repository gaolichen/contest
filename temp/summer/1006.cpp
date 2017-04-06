#include<stdio.h>
#include<string.h>
int a[20][3],sk[30][3],tot,num[20],kind[50];
int n,c,count;
//FILE *in;
int search(int j,int t)
{
	int i;
	if(t==tot)
	{
		if(sk[t-1][2]==sk[0][0])
			return 1;
		return 0;
	}
	for(i=0;i<count;i++)
		if(num[i])
		{
			if(j==2)
			{
				if(sk[t-1][1]==a[i][0]&&sk[t-1][2]==a[i][1]||
					sk[t-1][1]==a[i][1]&&sk[t-1][2]==a[i][0])
				{
					num[i]--;
					sk[t][0]=a[i][0];sk[t][1]=a[i][1];
					sk[t][2]=a[i][2];
					if(search(1,t+1))return 1;
					num[i]++;
				}
				if((sk[t-1][1]==a[i][0]&&sk[t-1][2]==a[i][2]||
					sk[t-1][1]==a[i][2]&&sk[t-1][2]==a[i][0])&&
					a[i][2]!=a[i][1])
				{
					num[i]--;
					sk[t][0]=a[i][0];sk[t][1]=a[i][2];
					sk[t][2]=a[i][1];
					if(search(1,t+1))return 1;
					num[i]++;
				}
				if((sk[t-1][1]==a[i][1]&&sk[t-1][2]==a[i][2]||
					sk[t-1][1]==a[i][2]&&sk[t-1][2]==a[i][1])&&
					a[i][0]!=a[i][1]&&a[i][0]!=a[i][2])
				{
					num[i]--;
					sk[t][0]=a[i][1];sk[t][1]=a[i][2];
					sk[t][2]=a[i][0];
					if(search(1,t+1))return 1;
					num[i]++;
				}
			}
			if(j==1)
			{
				if(sk[t-1][2]==a[i][0])
				{
					num[i]--;
					sk[t][0]=a[i][0];sk[t][1]=a[i][1];
					sk[t][2]=a[i][2];
					if(search(2,t+1))return 1;
					num[i]++;
				}
				if(sk[t-1][2]==a[i][1]&&a[i][1]!=a[i][0])
				{
					num[i]--;
					sk[t][0]=a[i][1];sk[t][1]=a[i][0];
					sk[t][2]=a[i][2];
					if(search(2,t+1))return 1;
					num[i]++;
				}
				if(sk[t-1][2]==a[i][2]&&a[i][2]!=a[i][0]&&
					a[i][2]!=a[i][1])
				{
					num[i]--;
					sk[t][0]=a[i][2];sk[t][1]=a[i][0];
					sk[t][2]=a[i][1];
					if(search(2,t+1))return 1;
					num[i]++;
				}
			}
		}
	return 0;
}
void run()
{
	int i,j;
	if(tot%2)
	{
		printf("~~~><~~~\n");
		return ;
	}
	for(i=1;i<=c;i++)
		if(kind[i]%2)
		{
			printf("~~~><~~~\n");
			return ;
		}
	for(i=0;i<n;i++)
	{
		for(j=0;j<count;j++)
			if(memcmp(a[i],a[j],sizeof(int)*3)==0)
			{
				num[j]+=num[i];
				break;
			}
		if(j==count)
		{
			memcpy(a[count],a[i],sizeof(int)*3);
			num[count++]=num[i];
		}
	}
	num[0]--;
	memcpy(sk[0],a[0],sizeof(int)*3);
	if(search(2,1))
	{
		printf("^_^\n");
		return ;
	}
	sk[0][0]=a[0][1];
	sk[0][1]=a[0][2];
	sk[0][2]=a[0][0];
	if(a[0][0]!=a[0][1]&&search(2,1))
	{
		printf("^_^\n");
		return ;
	}
	sk[0][0]=a[0][2];
	sk[0][1]=a[0][0];
	sk[0][2]=a[0][1];
	if(a[0][2]!=a[0][1]&&a[0][2]!=a[0][1]&&search(2,1))
	{
		printf("^_^\n");
		return ;
	}
	else printf("~~~><~~~\n");
}
void myswap(int *a,int *b,int *c)
{
	int i;
	if(*a>*b)
	{
		i=*a;*a=*b;*b=i;
	}
	if(*c>=*b)return;
	if(*a<*c)
	{
		i=*b;*b=*c;*c=i;
		return;
	}
	i=*a;*a=*c;*c=i;
}
int main()
{
	int i,t,j;
/*	if((in=fopen("input.txt","r"))==0)
	{
		printf("error\n");
		return 0;
	}*/
	scanf("%d",&t);
//	fscanf(in,"%d",&t);
	for(j=0;j<t;j++)
	{
		if(j)putchar('\n');
		printf("Case #%d\n",j+1);
		scanf("%d%d",&n,&c);
//		fscanf(in,"%d%d",&n,&c);
		tot=0;count=0;
		memset(kind,0,sizeof(kind));
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&num[i]);
//			fscanf(in,"%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&num[i]);
			myswap(a[i],a[i]+1,a[i]+2);
			kind[a[i][0]]+=num[i];
			kind[a[i][1]]+=num[i];
			kind[a[i][2]]+=num[i];
			tot+=num[i];
		}
		run();
	}
	return 0;
}