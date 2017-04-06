#include<stdio.h>
#include<string.h>
#define N 11000
void main()
{
	int i,j,k,n,now,point,len,s,t,min,a[N];
	char str[N],ch;
	scanf("%d",&n);
	for(now=0;now<n;now++)
	{
		i=j=0;min=0;
		do
		{
			ch=getchar();
			if(ch<='z'&&ch>='a')
			{
				str[i++]=ch;
				if(ch<str[min])
				{
					min=i-1;
					j=0;
					a[j++]=i-1;
				}
				else if(ch==str[min])
					a[j++]=i-1;
			}
		}while(ch!='\n'||i==0);
		str[i]='\0';
		len=strlen(str);
		point=a[0];k=j;
		for(i=1;i<k;i++)
		{
			for(j=1;j<len;j++)
			{
				if(a[i]+j>=len)t=a[i]+j-len;
				else t=a[i]+j;
				if(point+j>=len)
					s=point+j-len;
				else s=point+j;
				if(str[t]>str[s])
					break;
				else 
				if(str[t]<str[s])
				{point=a[i];break;}
			}
		}
		printf("%d\n",point+1);
	}
}