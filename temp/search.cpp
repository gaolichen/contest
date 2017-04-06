#include <stdio.h>
#include <string.h>
#define N 1000
char words[N][20];
int sque[N],record[N][N],numw[N];
int title[200][15],lent[200];
int wordcount;
void print()
{
	int i,j,temp=-1,t,r,k,l,m,n,time,ptime;
	for(i=0;i<=wordcount;i++)
	{
		k=sque[i];l=numw[k];
		for(j=0;j<l;j++)
		{
			if(temp==record[k][j])
				time++;
			else time=1;
			t=record[k][j];ptime=0;
			for(m=0;m<=lent[t];m++)
			{
                r=title[t][m];
				if(r==k)
					ptime++;
				if(r!=k||ptime<time)
				{
					for(n=0;words[r][n]!='\0';n++)
						printf("%c",words[r][n]);
				}
				else
					for(n=0;words[r][n]!='\0';n++)
						printf("%c",words[r][n]+'A'-'a');
				printf(" ");
			}
			temp=t;
		}
	}
}
void main()
{
	char ch='#',temp,wordtemp[20],buf[80];
	int i=0,j,k=0,ignor,titlecount=-1,wordflag=0;
	int titleflag=0,result,min,max,mid;
	wordcount=-1;
	do
	{
		temp=ch;
		ch=getchar();
		if(ch==' '||ch=='\n')
		{
			if(i)words[wordcount][i]='\0';
			wordflag=0;i=0;
		}
        else if(ch<='z'&&ch>='a')
		{
			if(!wordflag)
			{
				wordflag=1;
				words[++wordcount][i++]=ch;
			}
			else words[wordcount][i++]=ch;
		}
	}while(ch!=':'||temp!=':');
	ignor=wordcount;
//	printf("%d",strcmp(words[ignor],words[ignor-1]));
	//for(i=0;i<=ignor;i++)
	//	puts(words[i]);
	gets(buf);
	ch='#';i=0;
	do
	{
		temp=ch;
		ch=getchar();
		if(ch==' '||ch=='\n')
		{
			if(i)
			wordtemp[i++]='\0';
			//puts(wordtemp);}
			wordflag=0;i=0;
			for(j=0;j<=ignor;j++)
			{
				result=strcmp(words[j],wordtemp);
				if(!result)
				{title[titlecount][k++]=j;
				//puts(words[j]);
				//printf("%d",k);
				break;}
			}
			if(result!=0)
			{
				min=ignor+1;
				max=wordcount;
			  if(max>=min)
			  {do
			  {
				  mid=(min+max)/2;
				  result=strcmp(words[mid],wordtemp);
				  if(!result)
				  {
					  numw[mid]++;
					  record[mid][numw[mid]]=titlecount;
					  title[titlecount][k++]=mid;
					  //printf("%d",k);
				  }
				  else if(result>0)max=mid;
				  else if(result<0)min=mid;
			  }while(result!=0&&max!=min);
			  if(result!=0)
			  {
				  wordcount++;
				  for(j=0;wordtemp[j]!='\0';j++)
					  words[wordcount][j]=wordtemp[j];
				  words[wordcount][j]=wordtemp[j];
				  numw[wordcount]=0;
				  record[wordcount][0]=titlecount;
				  if(result>0)
                     for(j=wordcount;j>mid;j--)
						 sque[j]=sque[j-1];
				  else 
					  for(j=wordcount;j>mid+1;j--)
						  sque[j]=sque[j-1];
				  sque[j]=wordcount;
				  title[titlecount][k++]=wordcount;
				  printf("%d",k);
			  }
			  }
			  else
			  {
				  strcpy(words[++wordcount],wordtemp);
				  sque[wordcount]=wordcount;
				  numw[wordcount]=0;
				  record[wordcount][0]=0;
				  puts(words[wordcount]);
			  }
			}
			if(ch=='\n')
			{
				titleflag=0;
			//	for(j=0;j<=k;j++)
			//		puts(words[title[titlecount][j]]);
				lent[titlecount]=k;
				 k=0;
			}
		}
		else 
			if((ch<='z'&&ch>='a')||(ch>='A'&&ch<='Z'))
			{
				if(ch>='A'&&ch<='Z')
                   ch-='A'-'a';
				if(!wordflag)
					wordflag=1;
					wordtemp[i++]=ch;
				if(titleflag==0)
					titleflag=1;
			}

	}while(ch!=':'||temp!=':');
//	print();
	for(;(ch=getchar())!='e';);
}