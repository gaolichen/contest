#include<stdio.h>
char s[20],v[20];
int w[2];
int fh(int a)
{
	int i,tot,j,t[2];
	for(i=a;i<a+3;i++)
	{
		if(v[i]==v[i+1]&&v[i]==v[i+2])
			break;
	}
	if(i==a+3)return 0;
	tot=0;
	for(j=a;j<a+5;j++)
		if(v[j]!=v[i])t[tot++]=v[j];
	if(t[0]!=t[1])return 0;
	return v[i];
}
int fk(int a)
{
	int i;
	for(i=a;i<a+2;i++)
		if(v[i]==v[i+1]&&v[i]==v[i+2]&&v[i]==v[i+3])
		return v[i];
	return 0;
}
int sf(int a)
{
	int i;
	for(i=a+1;i<a+5;i++)
		if(v[i]!=v[i-1]-1||s[i]!=s[a])
			return 0;
	return v[a];
}
int hc(int a)
{
	int i,k=1,tot=0;
	for(i=a+4;i>=a;i--)
	{
		tot+=v[i]*k;
		k*=15;
	}
	return tot;
}
int fl(int a)
{
	int i;
	for(i=a+1;i<a+5;i++)
		if(s[i]!=s[a])return 0;
	return hc(a);
}
int sh(int a)
{
	int i;
	for(i=a+1;i<a+5;i++)
		if(v[i]!=v[i-1]-1)
			return 0;
	return v[a];
}
int tk(int a)
{
	int i;
	for(i=a;i<a+3;i++)
		if(v[i]==v[i+1]&&v[i+1]==v[i+2])
			return v[i];
	return 0;
}
int tp(int a)
{
	int i,tot=0,t[2];
	for(i=a;i<a+4;i++)
		if(v[i]==v[i+1])
			t[tot++]=v[i];
	if(tot<2)return 0;
	for(i=a;i<a+5;i++)
		if(v[i]!=t[0]&&v[i]!=t[1])
			break;
	return t[0]*225+t[1]*15+v[i];
}
int pa(int a)
{
	int i,k,j,tot=0;
	for(i=a;i<a+4;i++)
		if(v[i]==v[i+1])
			break;
	if(i==a+4)return 0;
	k=1;
	for(j=a+4;j>=a;j--)
		if(v[j]!=v[i])
		{
			tot+=v[j]*k;
			k*=15;
		}
	return tot+=v[i]*k;
}

void result(int a,int b)
{
	if(a>b)
		printf("Black wins.\n");
	else if(a<b)
		printf("White wins.\n");
	else printf("Tie.\n");
}
void mysort(int a)
{
	int i,j;
	char ch;
	for(i=a;i<a+5;i++)
	{
		if(v[i]>='2'&&v[i]<='9')
			v[i]-='0';
		else switch(v[i])
		{
			case 'T':v[i]=10;break;
			case 'J':v[i]=11;break;
			case 'Q':v[i]=12;break;
			case 'K':v[i]=13;break;
			case 'A':v[i]=14;break;
		}
	}
	for(i=1;i<5;i++)
		for(j=0;j<5-i;j++)
			if(v[a+j]<v[a+j+1])
			{
				ch=v[a+j];
				v[a+j]=v[a+j+1];
				v[a+j+1]=ch;
				ch=s[a+j];
				s[a+j]=s[a+j+1];
				s[a+j+1]=ch;
			}
}
void run()
{
	mysort(0);mysort(5);
	w[0]=sf(0);w[1]=sf(5);
	if(w[0]||w[1])
	{
		result(w[0],w[1]);
		return;
	}
	w[0]=fk(0);w[1]=fk(5);
	if(w[0]||w[1])
	{
		result(w[0],w[1]);
		return;
	}
	w[0]=fh(0);w[1]=fh(5);
	if(w[0]||w[1])
	{
		result(w[0],w[1]);
		return;
	}
	w[0]=fl(0);w[1]=fl(5);
	if(w[0]||w[1])
	{
		result(w[0],w[1]);
		return;
	}
	w[0]=sh(0);w[1]=sh(5);
	if(w[0]||w[1])
	{
		result(w[0],w[1]);
		return;
	}
	w[0]=tk(0);w[1]=tk(5);
	if(w[0]||w[1])
	{
		result(w[0],w[1]);
		return;
	}
	w[0]=tp(0);w[1]=tp(5);
	if(w[0]||w[1])
	{
		result(w[0],w[1]);
		return;
	}
	w[0]=pa(0);w[1]=pa(5);
	if(w[0]||w[1])
	{
		result(w[0],w[1]);
		return;
	}
	w[0]=hc(0);w[1]=hc(5);
	result(w[0],w[1]);
}
void main()
{
	int i;
	while(scanf("%c%c",&v[0],&s[0])!=-1)
	{
		for(i=1;getchar(),i<10;i++)
			scanf("%c%c",&v[i],&s[i]);
		run();
	}
}
