/*
ID:  mygali1
PROG: friday
*/
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
//#define DEBUG
#define M 2100000000
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("friday.in");
ofstream out("friday.out");
#endif
int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};  
struct date{                                                                                                            
    int year,month,day;                                                                                                 
};  
int num[10],n;                                                                                                                    
//����ָ�����������ڼ�   
//������                                                                                                                
inline int leap(int year){                                                                                              
    return (year%4==0&&year%100!=0)||year%400==0;                                                                       
}                                                                                                                       
                                                                                               
int weekday(date a){                                                                                                    
    int tm=a.month>=3?(a.month-2):(a.month+10);                                                                         
    int ty=a.month>=3?a.year:(a.year-1);                                                                                
    return (ty+ty/4-ty/100+ty/400+(int)(2.6*tm-0.2)+a.day)%7;                                                           
}

//����ת����ƫ��                                                                                                        
int date2int(date a){                                                                                                   
    int ret=a.year*365+(a.year-1)/4-(a.year-1)/100+(a.year-1)/400,i;                                                    
    days[1]+=leap(a.year);                                                                                              
    for (i=0;i<a.month-1;ret+=days[i++]);                                                                               
    days[1]=28;                                                                                                         
    return ret+a.day;                                                                                                   
}                                                                                                                       
                                                                                                                        
//����ƫ��ת����                                                                                                        
date int2date(int a){                                                                                                   
    date ret;                                                                                                           
    ret.year=a/146097*400;                                                                                              
    for (a%=146097;a>=365+leap(ret.year);a-=365+leap(ret.year),ret.year++);                                             
    days[1]+=leap(ret.year);                                                                                            
    for (ret.month=1;a>=days[ret.month-1];a-=days[ret.month-1],ret.month++);                                            
                                                                                                                        
    days[1]=28;                                                                                                         
    ret.day=a+1;                                                                                                        
    return ret;                                                                                                         
}

void run(){
	date temp;
	int i,j;
	temp.day=13;
	memset(num,0,sizeof(num));
	for(i=1900;i<1900+n;i++){
		temp.year=i;
		for(j=1;j<13;j++){
			temp.month=j;
			num[weekday(temp)]++;
		}
	}
	out<<num[6];
	for(i=0;i<6;i++)
		out<<' '<<num[i];
	out<<endl;
}
int main(){
	while(in>>n)run();
	return 0;
}