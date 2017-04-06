#include<iostream.h>
#include<string.h>
#define MAXN 310
int map[MAXN][MAXN],cx[MAXN],cy[MAXN];
int m,n;

//二分图最大匹配,hungary算法,邻接阵形式,复杂度O(m*m*n)
//返回最大匹配数,传入二分图大小m,n和邻接阵mat,非零元素表示有边
//match1,match2返回一个最大匹配,未匹配顶点match值为-1

#define _clr(x) memset(x,0xff,sizeof(int)*MAXN)

int hungary(int m,int n,int mat[][MAXN],int* match1,int* match2){
    int s[MAXN],t[MAXN],p,q,ret=0,i,j,k;
    for (_clr(match1),_clr(match2),i=0;i<m;ret+=(match1[i++]>=0))
        for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
            for (k=s[p],j=0;j<n&&match1[i]<0;j++)
                if (mat[k][j]&&t[j]<0){
                    s[++q]=match2[j],t[j]=k;
                    if (s[q]<0)
                        for (p=j;p>=0;j=p)
                            match2[j]=k=t[j],p=match1[k],match1[k]=j;
                }
    return ret;
}

/*
int path(int x)
{
	int i,j;
	for(i=0;i<m;i++)
		if(done[i]==0&&map[x][i])
		{
			done[i]=1;
			if(cy[i]==0)
			{
				map[x][i]=-map[x][i];
				cy[i]=1;
				cx[x]=1;
				return 1;
			}
			j=0;
			while(j<n&&(mark[j]==1||map[j][i]>=0))j++;
			if(j<n)
			{
				mark[j]=1;
				if(path(j))
				{
					map[x][i]=-map[x][i];
					map[j][i]=-map[j][i];
					cx[x]=1;
					return 1;
				}
			}
		}
	return 0;
}
void run()
{
	int i;
	memset(cx,0,sizeof(cx));
	memset(cy,0,sizeof(cy));
	i=0;
	while(i<n)
	{
		if(!cx[i])
		{
			memset(mark,0,sizeof(mark));
			memset(done,0,sizeof(done));
			mark[i]=1;
			{
				if(!path(i))
				{
					cout<<"NO"<<endl;
					return ;
				}
			}
			i=-1;
		}
		i++;
	}
	cout<<"YES"<<endl;
}*/
int main()
{
	int i,j,t,l,k,num;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>m>>n;
		memset(map,0,sizeof(map));
		for(j=0;j<m;j++)
		{
			cin>>l;
			for(k=0;k<l;k++)
			{
				cin>>num;
				map[num-1][j]=1;
			}
		}
		if(n==0)
			cout<<"NO"<<endl;
		else
		{
		if(hungary(n,m,map,cx,cy)==n)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		}
//		cout<<hungary(n,m,map,cx,cy);
	}
	return 0;
}