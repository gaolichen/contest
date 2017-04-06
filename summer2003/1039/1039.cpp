#include<iostream.h>
//求sum{[0..n-1]}
//维护和查询复杂度均为O(logn)
//用于动态求子段和,数组内容保存在sum.a[]中
//可以改成其他数据类型
#include <string.h>
#include<stdio.h>
#define lowbit(x) ((x)&((x)^((x)-1)))
#define MAXN 1000010
typedef int elem_t;

struct sum{
	elem_t a[MAXN],c[MAXN],ret;
	int n;
	void init(int i){memset(a,0,sizeof(elem_t)*(i+1));memset(c,0,sizeof(elem_t)*(i+1));n=i;}
	void update(int i,elem_t v){for (a[i++]+=v;i<=n;c[i-1]+=v,i+=lowbit(i));}
	elem_t query(int i){for (ret=0;i;ret+=c[i-1],i^=lowbit(i));return ret;}
};

int main(){
	int i,j,n;
	char tmp[10];
	sum s;
	while(scanf("%d",&n)==1){
		s.init(n+5);
		while(scanf("%s",tmp)==1){
			if(tmp[0]=='e')break;
			scanf("%d%d",&i,&j);
			if(tmp[0]=='p')
				s.update(i,(elem_t)(j));
			else{
				printf("%d\n",(int)(s.query(j+1)-s.query(i+1)));
				//<<<<endl;
			}
		}
//		cout<<endl;
		putchar('\n');
	}
	return 0;
}