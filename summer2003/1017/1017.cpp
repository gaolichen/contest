#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream.h>
#include<math.h>
#define UNIT 1000
#define DEPTH 3
//#define LONG_LONG
#define N 20000
#define elem_t int
typedef elem_t bignum_t[N];

//此大数模块，大数一位可以储存DEPTH位，且一般处于低位在前，高位在后
//状态，每个函数尽量不调用其他函数，如无注明，不调用其他函数。
//函数的参数可以相同，如bmadd(a,b,a)第一个参数和第三
//个参数相同，但是不影响结果。另外UNIT＝10^DEPTH 所以要修改UNIT的值时
//要同时修改DEPTH的值，并且要稍微修改bmprint。——by gali

int bmget(bignum_t num,char *buf)//输入字符串，转化成大数，一存DEPTH位，倒置
{
	elem_t i,j,k;
	k=strlen(buf);
	num[0]=(k-1)/DEPTH+1;
	i=k-(num[0]-1)*DEPTH;
	for(j=0,num[num[0]]=0;j<i;j++)
		num[num[0]]=num[num[0]]*10+buf[j]-'0';
	for(i=num[0]-1;i>=1;i--)
		for(k=0,num[i]=0;k<DEPTH;k++)
			num[i]=10*num[i]+buf[j++]-'0';
	return 1;
}
//int k 转化成 bignum_t m
int bmget(bignum_t num,elem_t k){
	num[0]=0;
	while(k){
		num[++num[0]]=k%UNIT;
		k/=UNIT;
	}
	return 1;
}
void bmprint(bignum_t num)//输出倒置的大数，每位输出DEPTH位
{
	elem_t i;
	if(!num[0]){
		printf("0\n");
		return ;
	}
	printf("%d",num[num[0]]);
	for(i=num[0]-1;i>=1;i--)
		printf("%03d",num[i]);//%DEPTH d
	printf("\n");
}


int bmcmp(bignum_t a,bignum_t b)//campare bignum_t
{
	elem_t i;
	if(a[0]>b[0])return 1;
	if(a[0]<b[0])return -1;
	for(i=a[0];i>=1;i--){
		if(a[i]>b[i])return 1;
		if(a[i]<b[i])return -1;
	}
	return 0;
}

//传入大数num和整数k，求和。结果存在res内

void bmaddint(bignum_t num,elem_t k,bignum_t res) 
{
	int i;
	if(!num[0]){
		res[0]=0;
		while(k){
			res[++res[0]]=k%UNIT;
			k/=UNIT;
		}
		return ;
	}
	bignum_t tmp;
	memcpy(tmp,num,sizeof(elem_t)*(num[0]+1));
	tmp[i=1]+=k;
	while(tmp[i]>=UNIT){
		if(++i<=tmp[0])
			tmp[i]+=tmp[i-1]/UNIT;
		else tmp[i]=tmp[i-1]/UNIT;
		tmp[i-1]%=UNIT;
	}
	if(i>tmp[0])tmp[0]=i;
	memcpy(res,tmp,sizeof(elem_t)*(tmp[0]+1));
}

//传入大数a,b,求和，结果存在res中

void bmadd(bignum_t a,bignum_t b,bignum_t res)
{
	int i,j;
	bignum_t tmp;
	for(i=1;i<=a[0]||i<=b[0];i++)
	{
		if(i>a[0])tmp[i]=b[i];
		else if(i>b[0])tmp[i]=a[i];
		else tmp[i]=a[i]+b[i];
	}
	tmp[0]=i-1;
	memcpy(res,tmp,sizeof(elem_t)*(tmp[0]+1));
	for(i=1,j=0;i<=res[0];i++){
		res[i]+=j;
		if(res[i]>=UNIT){
			j=res[i]/UNIT;
			res[i]%=UNIT;
		}
		else j=0;
	}
	if(j)res[++res[0]]=j;
}


//大数减法，调用bmcmp()函数。a-b=res，返回-1为a<b情况
//返回1为可正常计算情况

int bmsub(bignum_t a,bignum_t b,bignum_t res)
{
	int i,j;
	bignum_t tmp;
	if(bmcmp(a,b)<0)return -1;
	memcpy(tmp,a,sizeof(elem_t)*(a[0]+1));
	for(i=1,j=0;i<=b[0]||j;i++)
	{
		tmp[i]-=j;
		if(i<=b[0])tmp[i]-=b[i];
		if(tmp[i]<0){
			tmp[i]+=UNIT;
			j=1;
		}
		else j=0;
	}
	while(tmp[0]>0&&tmp[tmp[0]]==0)tmp[0]--;
	memcpy(res,tmp,sizeof(elem_t)*(tmp[0]+1));
	return 1;
}

void bmsubint(bignum_t a,int t,bignum_t ret){
	bignum_t tmp;
	bmget(tmp,t);
	bmsub(a,tmp,ret);
}

//传入大数num和int k，res=num*k

void bmmutiint(bignum_t num,int k,bignum_t res)
{
	int i;
	elem_t j;
	if(!k||!num[0]){
		res[0]=0;
		return;
	}
	if(k==1){
		memcpy(res,num,sizeof(elem_t)*(num[0]+1));
		return;
	}
	for(i=1;i<=num[0];i++)
		res[i]=num[i]*k;
	res[0]=num[0];
	for(i=1,j=0;i<=res[0]||j;i++){
		if(i>res[0])res[i]=0;
		res[i]+=j;
		if(res[i]>=UNIT){
			j=res[i]/UNIT;
			res[i]%=UNIT;
		}
		else j=0;
	}
	res[0]=i-1;
	while(res[0]>1&&!res[res[0]])res[0]--;
}


//传入大数a和b，计算res＝a*b

void bmmutibm(bignum_t a,bignum_t b,bignum_t res)
{
	int i,j;
	elem_t k;
	bignum_t tmp;
	memset(tmp,0,sizeof(tmp));
	tmp[0]=b[0];
	for(i=1;i<=a[0];i++){
		for(j=1;j<=b[0];j++)
			tmp[i+j-1]+=a[i]*b[j];
		tmp[0]=i+b[0]-1;
		for(j=1,k=0;j<=tmp[0]||k;j++){
			tmp[j]+=k;
			if(tmp[j]>=UNIT){
				k=tmp[j]/UNIT;
				tmp[j]%=UNIT;
			}
			else k=0;
		}
		tmp[0]=j-1;
	}
	while(tmp[0]>1&&!tmp[tmp[0]])tmp[0]--;
	memcpy(res,tmp,sizeof(elem_t)*(tmp[0]+1));
}


//传入a,和int k，res=a/k
//返回值为余数,除数为0就返回-1

int bmdiveint(bignum_t num,elem_t k,bignum_t res)
{
	int i=0,h;
	elem_t j=0;
	bignum_t tmp;
	if(!k)return -1;
	i=num[0]+1;
	while(i>1&&j<k)
		j=j*UNIT+num[--i];
	if(j<k)return j;
	h=tmp[0]=num[0];
	while(1){
		tmp[h--]=j/k;
		j%=k;
		if(--i<1)break;
		j=j*UNIT+num[i];
	}
	if(h>=1){
		for(i=h++;h<=num[0];h++)
			res[h-i]=tmp[h];
		res[0]=num[0]-i;
	}
	else memcpy(res,tmp,sizeof(elem_t)*(tmp[0]+1));
	return j;
}

//大数移位，相当于乘以UNIT^k

void bmmoveleft(bignum_t num,int k)
{
	int i;
	num[0]+=k;
	for(i=num[0];i>k;i--)
		num[i]=num[i-k];
	for(i=1;i<=k;i++)
		num[i]=0;
}

//大数移位，相当于除以UNIT^k

int bmmoveright(bignum_t num,int k)
{
	int i;
	if(num[0]<k){
		num[0]=0;
		return 0;
	}
	for(i=1;i<=num[0]-k;i++)
		num[i]=num[i+k];
	num[0]-=k;
	return 1;
}


//大数倒转，使高位和低位互换

void bminverse(bignum_t num){
	if(num[0]<=1)return;
	int i;
	bignum_t tmp;
	for(i=1;i<=num[0];i++)
		tmp[num[0]-i+1]=num[i];
	memcpy(num+1,tmp+1,sizeof(elem_t)*num[0]);
}

//tryres 试商，若返回值为j，则 j*b<=a<(j+1)*b，算法为二分法
//调用 bmmutiint和bmcmp

elem_t tryres(bignum_t a,bignum_t b){
	int top,low,mid,i;
	bignum_t tmp;
	top=UNIT;low=0;mid=(top+low)/2;
	while(mid>low){
		bmmutiint(b,mid,tmp);
		i=bmcmp(tmp,a);
		if(i==0)
			return mid;
		else if(i>0)
			top=mid;
		else low=mid;
		mid=(top+low)/2;
	}
	return low;
}


//大数除法，a=res*b+mod 如果b==0返回-1，否则能进行除法返回1
//调用函数有bmcmp bmmutiint bmsub tryres bmmoveleft bminverse

int bmdivebm(bignum_t a,bignum_t b,bignum_t res,bignum_t mod){
	bignum_t tmp;
	if(!b[0]||(b[0]==1&&!b[1]))return -1;
	if(bmcmp(a,b)<0){
		res[0]=0;
		memcpy(tmp,a,sizeof(elem_t)*(a[0]+1));
		memcpy(mod,tmp,sizeof(elem_t)*(tmp[0]+1));
		return 1;
	}
	int i,k;
	elem_t j;
	bignum_t tmp1,tmp3;
	tmp[0]=b[0];
	i=a[0]-tmp[0]+1;
	memcpy(tmp+1,a+a[0]-tmp[0]+1,sizeof(elem_t)*tmp[0]);
	while(bmcmp(tmp,b)<0&&i>1){
		bmmoveleft(tmp,1);
		tmp[1]=a[--i];
	}
	k=1;
	while(1){
		j=tryres(tmp,b);
		bmmutiint(b,j,tmp1);
		bmsub(tmp,tmp1,tmp);
		tmp3[k++]=j;
		if(--i<1)break;
		bmmoveleft(tmp,1);
		tmp[1]=a[i];
	}
	tmp3[0]=k-1;
	bminverse(tmp3);
	memcpy(res,tmp3,sizeof(elem_t)*(tmp3[0]+1));
	memcpy(mod,tmp,sizeof(elem_t)*(tmp[0]+1));
	return 1;
}


//试商函数 若返回值为j，
//则b*2*UNIT*j+j*j<=a<b*2*UNIT*(j+1)+(j+1)*(j+1)

elem_t tryres1(bignum_t a,bignum_t b){
	int top,low,mid,i;
	bignum_t tmp;
	top=UNIT;low=0;mid=(top+low)/2;
	while(mid>low){
		bmmutiint(b,2*UNIT*mid,tmp);
		bmaddint(tmp,mid*mid,tmp);
		i=bmcmp(tmp,a);
		if(i==0)return mid;
		else if(i>0)top=mid;
		else low=mid;
		mid=(top+low)/2;
	}
	return low;
}

//大数开方 num=res*res+rem 调用函数 tryres1 bm_muti_int 
//bm_plus_int bm_sub bm_moveleft bm_inverse 
//使用此函数时要使UNIT＝1000 DEPTH＝3，bm_print函数里
//printf("%03d",num[i]);

void bmsqrt(bignum_t num,bignum_t res,bignum_t rem){
	int i;
	elem_t k;
	bignum_t tmp1,tmp2,tmp;
	if(!num[0]||(num[0]==1&&num[1]==0)){
		res[0]=rem[0]=0;
		return ;
	}
	if(num[0]%2){
		tmp1[0]=1;
		tmp1[1]=num[num[0]];i=num[0];
	}
	else {
		tmp1[0]=2;
		tmp1[2]=num[num[0]];
		tmp1[1]=num[num[0]-1];
		i=num[0]-1;
	}
	tmp[0]=0;
	while(1){
		k=tryres1(tmp1,tmp);
		bmmutiint(tmp,k*2*UNIT,tmp2);
		bmaddint(tmp2,k*k,tmp2);
		bmsub(tmp1,tmp2,tmp1);
		bmmoveleft(tmp,1);
		tmp[1]=k;
		i-=2;
		if(i<1)break;
		bmmoveleft(tmp1,2);
		tmp1[1]=num[i];
		tmp1[2]=num[i+1];
	}
	memcpy(res,tmp,sizeof(elem_t)*(tmp[0]+1));
	memcpy(rem,tmp1,sizeof(elem_t)*(tmp1[0]+1));
} 


//求n阶乘

void bmfactor(int n,bignum_t fac){
	int i,j;
	elem_t k;
	fac[0]=fac[1]=1;
	for(i=2;i<=n;i++){
		for(j=1;j<=fac[0];j++)
			fac[j]=fac[j]*i;
		for(j=1,k=0;j<=fac[0]||k;j++){
			if(j>fac[0])fac[j]=0;
			fac[j]+=k;
			if(fac[j]>=UNIT){
				k=fac[j]/UNIT;fac[j]%=UNIT;
			}
			else k=0;
		}
		fac[0]=j-1;
	}
}

//a的b次方
 
void bmpower(int a,int b,bignum_t res){
	int i,zero=0,j;
	elem_t k;
	if(a==0){
		res[0]=0;
		return ;
	}
	if(b==0){
		res[0]=res[1]=1;
		return ;
	}
	while(a%10==0){
		a/=10;zero++;
	}
	zero*=b;
	j=zero/DEPTH;
	memset(res+1,0,sizeof(elem_t)*j);
	zero=zero-j*DEPTH;res[j+1]=1;
	for(i=0;i<zero;i++)
		res[j+1]*=10;
	res[0]=j+1;
	if(a==1)
		return ;
	zero=j+1;
	for(i=0;i<b;i++){
		for(j=zero,k=0;j<=res[0];j++){
			res[j]=res[j]*a+k;
			if(res[j]>=UNIT){
				k=res[j]/UNIT;
				res[j]%=UNIT;
			}
			else k=0;
		}
		while(k){
			res[j++]=k%UNIT;
			k/=UNIT;
		}
		res[0]=j-1;
	}
}


int pri[10000],pri_count;
void make_pri(int n)
{
	int i,j,mark[N];
	pri_count=0;
	memset(mark,0,sizeof(int)*(n+1));
	for(i=2;i<=n;i++)
		if(mark[i]==0)
		{
			for(j=i;i*j<=n;j++)
				mark[i*j]=1;
			mark[i]=1;
			pri[pri_count++]=i;
		}
}

//求组合数c(m,n)，m>=n ，调用函数make_pri,以及全局变量pri[]和
//pri_count;如果m<n返回0否则返回1

int comb(int m,int n,bignum_t res)
{
	int i,j,h,k,t;
	bignum_t tmp;
	if(m<n)return 0;
	if(2*n>m)n=m-n;
	if(n==0){
		res[0]=1;res[1]=1;
		return 1;
	}
	make_pri(m);
	memset(tmp,0,sizeof(tmp));
	for(i=m-n+1;i<=m;i++){
		for(j=0,k=i;j<pri_count&&pri[j]<=k;j++){		
			h=0;
			while(k%pri[j]==0){
				k/=pri[j];
				h++;
			}
			tmp[j]+=h;
		}
	}	
	for(i=2;i<=n;i++){
		for(j=0,k=i;j<pri_count&&pri[j]<=k;j++){
			h=0;		
			while(k%pri[j]==0){
				k/=pri[j];
				h++;
			}
			tmp[j]-=h;
		}
	}
	res[0]=res[1]=1;
	for(i=0,t=1;i<pri_count;i++)
		for(j=0;j<tmp[i];j++){
			t*=pri[i];
			if(t<400)continue;
			for(k=1,h=0;k<=res[0]||h;k++){
				if(k>res[0])res[k]=0;
				res[k]=res[k]*t+h;
				if(res[k]>=UNIT){
					h=res[k]/UNIT;
					res[k]%=UNIT;
				}
				else h=0;
			}
			res[0]=k-1;
			t=1;
		}
	if(t>1){
		for(k=1,h=0;k<=res[0]||h;k++){
			if(k>res[0])res[k]=0;
				res[k]=res[k]*t+h;
				if(res[k]>=UNIT){
					h=res[k]/UNIT;
					res[k]%=UNIT;
				}
				else h=0;
			}
		res[0]=k-1;
	}
	return 1;
}


class bignum{
	bignum_t num;
public:
	inline bignum(){num[0]=0;}
	inline ~bignum(){}
	inline int size(){return num[0];}
	inline int length();
	inline int begin(){return num[0]==0?0:num[num[0]];}
	inline int operator!=(bignum& a){return bmcmp(num,a.num);}
	inline bignum& operator=(bignum& a);
	inline bignum& operator=(char *);
	inline bignum& operator=(int);
	inline int operator==(bignum& a){return bmcmp(num,a.num)==0;}
	inline int operator>(bignum& a){return bmcmp(num,a.num)>0;}
	inline int operator<(bignum& a){return bmcmp(num,a.num)<0;}
	inline int operator>=(bignum& a){return bmcmp(num,a.num)>=0;}
	inline int operator<=(bignum& a){return bmcmp(num,a.num)<=0;}
	inline bignum operator+(elem_t);
	inline bignum operator+(bignum&);
	inline bignum operator-(elem_t);
	inline bignum operator-(bignum&);
	inline bignum operator*(elem_t);
	inline bignum operator*(bignum&);
	inline bignum operator/(elem_t);
	inline bignum operator/(bignum&);
	inline int operator%(int);
	inline bignum operator%(bignum&);
	inline bignum& operator++();
	inline bignum& operator--();
	inline bignum& operator+=(bignum&);
	inline bignum& operator+=(elem_t);
	inline bignum& operator-=(elem_t);
	inline bignum& operator-=(bignum&);
	inline bignum& operator*=(elem_t);
	inline bignum& operator*=(bignum&);
	inline bignum& operator/=(elem_t);
	inline bignum& operator/=(bignum&);
	inline bignum& operator%=(elem_t);
	inline bignum& operator%=(bignum&);
	inline int operator[](int t){return num[t];}
	friend inline bignum sqrt(bignum&,bignum&);
	friend inline bignum factor(int t);
	friend inline bignum power(int a,int b);
	friend inline void print(bignum &a){bmprint(a.num);}
	friend inline istream& operator>>(istream&,bignum&);
	friend inline ostream& operator<<(ostream&,bignum&);
};

inline istream& operator>>(istream& is,bignum& a){
	char buf[N];
	is>>buf;
	bmget(a.num,buf);
	return is;
}

inline ostream& operator<<(ostream& os,bignum& a){
	if(a[0]==0)
		os<<0;
	else {
		int i,k;
		os<<a[a[0]];
		for(i=a.size()-1;i>=1;i--){
			k=UNIT/10;
			while(k>a[i]){
				os<<0;
				k/=10;
			}
			if(a[i])os<<a[i];
		}
	}
	return os;
}

inline int bignum::length(){
	if(this->size()==0)return 1;
	int ret=0;
	elem_t k;
	while(k<=this->begin()){
		k*=10;
		ret++;
	}
	return ret+(this->size()-1)*DEPTH;
}
inline bignum& bignum::operator=(bignum &a){
	memcpy(num,a.num,sizeof(int)*(a.size()+1));
	return *this;
}

inline bignum& bignum::operator=(char* buf){
	bmget(num,buf);
	return *this;
}

inline bignum& bignum::operator=(int t){
	bmget(num,t);
	return *this;
}

inline bignum bignum::operator+(bignum &a){
	bignum ret;
	bmadd(num,a.num,ret.num);
	return ret;
}

inline bignum bignum::operator+(int t){
	bignum ret;
	bmaddint(num,t,ret.num);
	return ret;
}

inline bignum bignum::operator-(int t){
	bignum ret;
	bmsubint(num,t,ret.num);
	return ret;
}

inline bignum bignum::operator-(bignum &a){
	bignum ret;
	bmsub(num,a.num,ret.num);
	return ret;
}

inline bignum bignum::operator *(bignum& a){
	bignum ret;
	bmmutibm(num,a.num,ret.num);
	return ret;
}

inline bignum bignum::operator *(int t){
	bignum ret;
	bmmutiint(num,t,ret.num);
	return ret;
}

inline bignum bignum::operator/(int t){
	bignum ret;
	bmdiveint(num,t,ret.num);
	return ret;
}

inline bignum bignum::operator/(bignum& a){
	bignum ret,tmp;
	bmdivebm(num,a.num,ret.num,tmp.num);
	return ret;
}

inline int bignum::operator%(int t){
	bignum tmp;
	return bmdiveint(num,t,tmp.num);
}

inline bignum bignum::operator %(bignum& a){
	bignum tmp,ret;
	bmdivebm(num,a.num,tmp.num,ret.num);
	return ret;
}

inline bignum& bignum::operator+=(int t){
	bmaddint(num,t,num);
	return *this;
}

inline bignum& bignum::operator+=(bignum& a){
	bmadd(num,a.num,num);
	return *this;
}

inline bignum& bignum::operator -=(int t){
	bmsubint(num,t,num);
	return *this;
}

inline bignum& bignum::operator-=(bignum& a){
	bmsub(num,a.num,num);
	return *this;
}

inline bignum& bignum::operator*=(int t){
	bmmutiint(num,t,num);
	return *this;
}

inline bignum& bignum::operator*=(bignum& a){
	bmmutibm(num,a.num,num);
	return *this;
}

inline bignum& bignum::operator/=(int t){
	bmdiveint(num,t,num);
	return *this;
}

inline bignum& bignum::operator/=(bignum& a){
	bignum tmp;
	bmdivebm(num,a.num,num,tmp.num);
	return *this;
}

inline bignum& bignum::operator %=(int t){
	int tmp;
	tmp=bmdiveint(num,t,num);
	return *this=tmp;
}

inline bignum& bignum::operator %=(bignum& a){
	bignum tmp;
	bmdivebm(num,a.num,tmp.num,num);
	return *this;
}

inline bignum& bignum::operator ++(){
	int i=1;
	while(i<=this->size()&&this->num[i]==UNIT-1)
		this->num[i++]=0;
	if(i>this->size())
		num[++num[0]]=1;
	else num[i]++;
	return *this;
}

inline bignum& bignum::operator --(){
	int i=1;
	while(i<=this->size()&&num[i]==0)
		num[i++]=UNIT-1;
	if(--num[i]==0)num[0]--;
	return *this;
}

inline bignum sqrt(bignum& a,bignum& b){
	bignum ret;
	bmsqrt(a.num,ret.num,b.num);
	return ret;
}

inline bignum factor(int t){
	bignum ret;
	bmfactor(t,ret.num);
	return ret;
}

inline bignum power(int a,int b){
	bignum ret;
	bmpower(a,b,ret.num);
	return ret;
}

int main(){
	bignum n,t,p,zero;
	t=2;p=1;zero=0;
	while(cin>>n){
		if(n==t||n==p){
			cout<<1<<endl;
			continue;
		}
		if(n==zero){
			cout<<0<<endl;
			continue;
		}
		--n;
		n/=2;
		cout<<n<<endl;
	}
	return 0;
}