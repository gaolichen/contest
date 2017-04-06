#include<stdio.h>
float table[21][21];
int count,n;
/*void find_path(int i,int path[21],int step)
{
	int j;
    if(count==1){
	path[0]=path[step]=i;
	count++;
	for(j=1;j<step;j++)
		path[j]=j;
	}
	else
	{path[step-1]++;j=step-1;
	while(path[j]>n&&j>1)
	{path[j]-=n;
	   path[--j]++;
	};
	}	
}*/
void main()
{
	int i,j,len,path[21],flag;
	float profit;
	while(scanf("%d",&n)==1)
	{
	   for(i=1;i<=n;i++)
		 for(j=1;j<=n;j++)
		 {if(i!=j)scanf("%f",&table[i][j]);
		  else table[i][j]=1;
		 } 
		 flag=0;
	   for(len=2;len<=n;len++)
	   {
		   for(i=1;i<=n;i++)
	{   
        path[0]=path[len]=i;
	    for(j=1;j<len;j++)
		path[j]=j;
		//count=1;
        //find_path(i,path,len);
		while(!flag&&path[1]<=n)
		{
		for(profit=1.0,j=0;j<len;j++)
			profit*=table[path[j]][path[j+1]];
		if(profit>=1.01)flag=1;
		//else find_path(i,path,len);
		else
			{
			path[len-1]++;j=len-1;
	          while(path[j]>n&&j>1)
			  {path[j]-=n;
	            path[--j]++;
			  };
		}
		}
		if(flag)break;
	}
		   if(i<=n)break;
	}
	   if(len<=n){
      for(i=0;i<=len;i++)
	     printf("%d ",path[i]);
	     printf("\n");
	   }
	  else
		  printf("no arbitrage sequence exists\n");
	}
}