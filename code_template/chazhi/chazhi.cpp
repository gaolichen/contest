//整数插值程序

#include<iostream.h>
#include<stdio.h>
#include<math.h>
#include<fstream.h>

typedef  int T;

T gcd(T a,T b){
	if(b==0)return a;
	return gcd(b,a%b);
}

class fct{
	T a,b;
public:
	friend inline int fctcmp(fct&,fct&);
	friend inline int intcmp(fct&,int);
	inline fct& init(T,T);
	inline int operator>(fct&);
	inline int operator>(T);
	inline int operator<(fct&);
	inline int operator<(T);
	inline int operator>=(fct&);
	inline int operator>=(T);
	inline int operator<=(T);
	inline int operator<=(fct&);
	inline int operator==(fct&);
	inline int operator==(T);
	inline fct& operator=(fct&);
	inline fct& operator=(int);
	inline fct& operator+=(int);
	inline fct& operator+=(fct&);
	inline fct& operator-=(int);
	inline fct& operator-=(fct&);
	inline fct& operator*=(int);
	inline fct& operator*=(fct&);
	inline fct& operator/=(int);
	inline fct& operator/=(fct&);
	friend inline istream& operator>>(istream&,fct&);
	friend inline ostream& operator<<(ostream&,fct&);
};

inline fct& fct::init (T a,T b){
	int t;
	t=gcd(a,b);
	if(t>1){
		a/=t;b/=t;
	}
	if(b<0){
		b=-b;a=-a;
	}
	this->a=a;
	this->b=b;
	return *this;
}
inline fct& fct::operator *=(fct& a){
	T t;
	this->a*=a.a;
	this->b*=a.b;
	t=gcd(this->a,this->b);
	if(t<0)t=-t;
	if(t>1){
		this->a/=t;this->b/=t;
	}
	return *this;
}
inline fct& fct::operator *=(int a){
	T t;
	this->a*=a;
	t=gcd(this->a,this->b);
	if(t<0)t=-t;
	if(t>1){
		this->a/=t;this->b/=t;
	}
	return *this;
}

inline fct& fct::operator /= (int a){
	T t;
	this->b*=a;
	t=gcd(this->a,this->b);
	if(t>1||t<-1){
		this->a/=t;
		this->b/=t;
	}
	if(this->b<0){
		this->b=-this->b;
		this->a=-this->a;
	}
	return *this;
}

inline fct& fct::operator /= (fct& a){
	T t;
	this->a*=a.b;
	this->b*=a.a;
	t=gcd(this->a,this->b);
	if(t>1||t<-1){
		this->a/=t;this->b/=t;
	}
	if(this->b<0){
		this->b=-this->b;
		this->a=-this->a;
	}
	return *this;
}

inline fct& fct::operator += (int a){
	this->a+=a*this->b;
	return *this;
}

inline fct& fct::operator += (fct& a){
	T t;
	t=this->b*a.b;
	this->a=this->a*a.b+this->b*a.a;
	this->b=t;
	t=gcd(this->a,this->b);
	if(t<0)t=-t;
	if(t>1){
		this->a/=t;this->b/=t;
	}
	return *this;
}

inline fct& fct::operator -=(fct& a){
	T t;
	t=this->b*a.b;
	this->a=this->a*a.b-this->b*a.a;
	this->b=t;
	t=gcd(this->a,this->b);
	if(t<0)t=-t;
	if(t>1){
		this->a/=t;
		this->b/=t;
	}
	return *this;
}

inline fct& fct::operator -= (int a){
	this->a-=a*this->b;
	return *this;
}
inline int fctcmp(fct& a,fct& b){
	return (int)(a.a*b.b-a.b*b.a);
}

inline int fct::operator < (fct& a){
	return fctcmp(*this,a)<0;
}

inline int fct::operator >(fct& a){
	return fctcmp(*this,a)>0;
}

inline int fct::operator ==(fct& a){
	return fctcmp(*this,a)==0;
}

inline int fct::operator >=(fct &a){
	return fctcmp(*this,a)>=0;
}

inline int fct::operator <=(fct &a){
	return fctcmp(*this,a)<=0;
}

inline int intcmp(fct& a,T b){
	return (int)(a.a-a.b*b);
}

inline int fct::operator<(T a){
	return intcmp(*this,a)<0;
}

inline int fct::operator>(T a){
	return intcmp(*this,a)>0;
}

inline int fct::operator<=(T a){
	return intcmp(*this,a)<=0;
}

inline int fct::operator>=(T a){
	return intcmp(*this,a)>=0;
}

inline int fct::operator==(T a){
	return intcmp(*this,a)==0;
}

inline ostream& operator<<(ostream& os,fct& a){
	os<<a.a;
	if(a.b>1)os<<'/'<<a.b;
	return os;
}

inline istream& operator>>(istream& is,fct& a){
	char ch;
	T t;
	if(!(is>>a.a))return is;
	is>>ch;
	is>>a.b;
	t=gcd(a.a,a.b);
	if(t>1){
		a.a/=t;a.b/=t;
	}
	if(a.b<0){
		a.a=-a.a;
		a.b=-a.b;
	}
	return is;
}

inline fct& fct::operator = (fct& a){
	this->a =a.a ;
	this->b =a.b ;
	return *this;
}
inline fct& fct::operator=(int a){
	this->a=a;
	this->b=1;
	return *this;
}

int n;
T x[100],y[100],a[100];

void done(int k){
	int i,j;
	T tmp[100];
	for(i=0;i<n;i++)tmp[i]=0;
	tmp[0]=1;
	for(i=0;i<n;i++)
		if(i!=k){
			a[0]=0;
			for(j=0;j<n;j++)
				a[j+1]=tmp[j];
			for(j=0;j<n;j++){
				a[j]-=tmp[j]*x[i];
				tmp[j]=a[j];
			}
		}

}
void run(){
	int i,j;
	fct tmp,ans[100];
	T t;
	for(i=0;i<=n;i++)
		ans[i]=0;
	for(i=0;i<n;i++){
		done(i);
		t=1;
		for(j=0;j<n;j++)
			if(i!=j)t*=x[i]-x[j];
		for(j=0;j<n;j++){
			tmp.init(y[i]*a[j],t);
			ans[j]+=tmp;
		}
	}
	j=0;
	cout<<"y = ";
	for(i=n-1;i>=0;i--)
		if(ans[i]>0||ans[i]<0){
			if(!j)cout<<ans[i];
			else {
				cout<<' ';
				if(ans[i]>0)cout<<"+";
				cout<<ans[i];
			}
			if(i)cout<<"*x";
			if(i>1)cout<<'^'<<i;
			j++;
		}
	cout<<endl;
}
int main(){
	int i;
	while(cin>>n){
		for(i=0;i<n;i++)
			cin>>x[i]>>y[i];
		run();
	}
	return 0;
}