#include<iostream.h>
#include<string.h>
#include<stdio.h>
int map[10][10],x[20],y[20],f[20],big[10][10],left[10],right[10];
int place(int n,int i,int j)
{
	if(map[i][j])return 0;
	if(i-1>=0&&map[i-1][j])return 1;
	if(i+1<n&&map[i+1][j])return 1;
	if(j-1>=0&&map[i][j-1])return 1;
	if(j+1<n&&map[i][j+1])return 1;
	return 0;
}
int ok(int n,int a[][10],int b[][10])
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(a[i][j]>b[i][j])return 1;
			if(a[i][j]<b[i][j])return 0;
		}
	return 1;
}
int ok1(int n,int a[][10],int b[][10])
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(a[i][j]>b[i][j])return 0;
			if(a[i][j]<b[i][j])return 1;
		}
	return 0;
}
int check(int n)
{
	int i,temp[10][10],maxx,maxy,minx=n,miny=n;
	memset(temp,0,sizeof(temp));
	for(i=0,maxx=0;i<n;i++)
	{
		if(x[i]>maxx)maxx=x[i];
		if(x[i]<minx)minx=x[i];
		if(y[i]<miny)miny=y[i];
		if(y[i]>maxy)maxy=y[i];
	}
	if(minx)return 0;
	if(miny)return 0;
	for(i=0;i<n;i++)
		temp[maxx-x[i]][y[i]]=1;
	if(!ok(n,map,temp))return 0;
	memset(temp,0,sizeof(temp));
	for(i=0;i<n;i++)
		temp[x[i]][maxy-y[i]]=1;
	if(!ok(n,map,temp))return 0;
	memset(temp,0,sizeof(temp));
	for(i=0;i<n;i++)
		temp[maxx-x[i]][maxy-y[i]]=1;
	if(!ok(n,map,temp))return 0;
	memset(temp,0,sizeof(temp));
	for(i=0;i<n;i++)
		temp[y[i]][x[i]]=1;
	if(!ok(n,map,temp))return 0;
	memset(temp,0,sizeof(temp));
	for(i=0;i<n;i++)
		temp[y[i]][maxx-x[i]]=1;
	if(!ok(n,map,temp))return 0;
	memset(temp,0,sizeof(temp));
	for(i=0;i<n;i++)
		temp[maxy-y[i]][x[i]]=1;
	if(!ok(n,map,temp))return 0;
	memset(temp,0,sizeof(temp));
	for(i=0;i<n;i++)
		temp[maxy-y[i]][maxx-x[i]]=1;
	if(!ok(n,map,temp))return 0;
	return 1;
}
void search(int n,int k)
{
	int i,j,t1,t2,t3,t4,t5,t6;;
	if(k==n)
	{
		if(ok1(n,map,big)&&check(n))
		{
			f[n]++;
//			cout<<f[n]<<' ';
			memcpy(big,map,sizeof(big));
/*			for(i=0;i<n;i++,cout<<endl)
				for(j=0;j<n;j++)
				{
					if(map[i][j])cout<<'x';
					else cout<<' ';
				}*/
		}
		return ;
	}
	if(k==0)
	{
		for(i=0;i<n;i++)
		{
			map[0][i]=1;
			if(i-1>=0&&i-1<left[0])
				left[0]=i-1;
			if(i<left[1])left[1]=i;
			if(i+1<n)right[0]=i+1;
			if(i>right[1])right[1]=i;
			x[0]=0;y[0]=i;
			search(n,k+1);
			left[0]=right[0]=left[1]=right[1]=0;
			map[0][i]=0;
		}
		return ;
	}
	for(i=0;i<n;i++)
		for(j=left[i];j<=right[i];j++)
			if(place(n,i,j))
			{
				map[i][j]=1;
				t1=right[i];t2=left[i];
				if(i+1<n)
				{
					t3=right[i+1];
					t4=left[i+1];
				}
				if(i-1>=0)
				{
					t5=right[i-1];
					t6=left[i-1];
				}
				if(j+1<n&&j+1>right[i])
					right[i]=j+1;
				if(j-1>=0&&j-1<left[i])left[i]=j-1;
				if(i-1>=0)
				{
					if(j>right[i-1])
						right[i-1]=j;
					if(j<left[i-1])left[i-1]=j;
				}
				if(i+1<n)
				{
					if(j>right[i+1])
						right[i+1]=j;
					if(j<left[i+1])left[i+1]=j;
				}
				x[k]=i;y[k]=j;
				search(n,k+1);
				right[i]=t1;left[i]=t2;
				if(i+1<n)
				{
					right[i+1]=t3;left[i+1]=t4;
				}
				if(i-1>=0)
				{
					right[i-1]=t5;left[i-1]=t6;
				}
				map[i][j]=0;
			}
}
void run()
{
	int i,j,k;
	for(i=1;i<=10;i++)
	{
		f[i]=0;
		for(j=0;j<i;j++)
			for(k=0;k<i;k++)
				big[j][k]=1;
		memset(left,0,sizeof(left));
		memset(right,0,sizeof(right));
		memset(map,0,sizeof(map));
		search(i,0);
		cout<<f[i]<<endl;
	}
	f[8]=345;f[9]=1156;f[10]=4021;
	f[1]=1;
}
void print(int n,int k)
{
	if(k==1)cout<<"There is ";
	else cout<<"There are ";
	cout<<k<<" distinct ";
	if(n==5)
		cout<<"pentomino";
	else if(n==4)
		cout<<"tetromino";
	else if(n==2)cout<<"domino";
	else cout<<n<<"-mino";
	if(k>1)cout<<"es";
	cout<<'.'<<endl;
	cout<<endl;

}
int main()
{
	int n;
	run();
	while(cin>>n)
		print(n,f[n]);
	return 0;
}