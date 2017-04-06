#include<stdio.h>
void copy_col(int p[3],int q[3])
{
	p[0]=q[0];
	p[1]=q[1];
	p[2]=q[2];
}
long move(long bot1[3],long bot2[3],long bot3[3],int col[3])
{
	long count1=0;
	count1+=bot2[col[0]]+bot3[col[0]];
	count1+=bot1[col[1]]+bot3[col[1]];
	count1+=bot1[col[2]]+bot2[col[2]];
	return count1;
}
void main()
{   
	long bot1[3],bot2[3],bot3[3],min,temp;
	int col[3],temp_col[3],i,j,k;
	int count;
	while(scanf("%ld%ld%ld%ld%ld%ld%ld%ld%ld",
		&bot1[0],&bot1[2],&bot1[1],&bot2[0],
		&bot2[2],&bot2[1],&bot3[0],&bot3[2],
		&bot3[1])==9)
	{count=0;min=0l;
    for(i=0;i<3;i++)
	{
	 col[0]=i;
	 for(j=0;j<3;j++)
	  if(j!=i)
		{col[1]=j;
		 for(k=0;k<3;k++)
		  if(k!=j&&k!=i)col[2]=k;
		  {   	
           count++;
		   if(count==1)
		{min=move(bot1,bot2,bot3,col);
		 copy_col(temp_col,col);
		}
		else 
		if((temp=move(bot1,bot2,bot3,col))<min)
		{
			min=temp;
		    copy_col(temp_col,col);
		}
		else if(move(bot1,bot2,bot3,col)==min)
		if(temp_col[0]>col[0]||(temp_col[0]==col[0]
			&&temp_col[1]>col[1]))
		copy_col(temp_col,col);
		}
		}
	}
     for(count=0;count<3;count++)
	 switch(temp_col[count])
	 {
		 case 0:printf("%c",'B');break;
         case 1:printf("%c",'C');break;
         case 2:printf("%c",'G');break;
	 }
	 printf(" %ld\n",min);
	}
}



