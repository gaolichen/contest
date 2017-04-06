#include<iostream.h>
#include<stdio.h>
#include<math.h>
#include<fstream.h>
#define abs(a) ((a)>=0?(a):-(a));

typedef  int T;

T gcd(T a,T b){
	if(b==0)return abs(a);
	return gcd(b,a%b);
}

T lcm(T a,T b){
	return abs(a/gcd(a,b)*b);
}

class fct{
	T a,b;
public:
	friend inline int fctcmp(fct&,fct&);
	friend inline int intcmp(fct&,int);
	inline fct& init(T,T);
	inline int operator!=(fct&);
	inline int operator!=(int);
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

inline int fctcmp(fct& a,fct& b){
	return (int)(a.a*b.b-a.b*b.a);
}

inline int intcmp(fct& a,T b){
	return (int)(a.a-a.b*b);
}

inline int fct::operator != (fct& a){
	return fctcmp(*this,a)!=0;
}

inline int fct::operator !=(int a){
	return intcmp(*this,a)!=0;
}
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
}

/////////////////////////////////////
inline fct& fct::operator *=(fct& a){
	T t1,t2;
	t1=gcd(a.a,this->b);
	t2=gcd(a.b,this->a);
	this->a*=a.a/t1;
	this->b*=a.b/t2;
	t1=gcd(this->a,this->b);
	if(t1>1){
		this->a/=t1;this->b/=t1;
	}
	return *this;
}
inline fct& fct::operator *=(int a){
	T t;
	this->a*=a/gcd(this->b,a);
	this->b/=gcd(this->b,a);
	t=gcd(this->a,this->b);
	if(t>1){
		this->a/=t;this->b/=t;
	}
	return *this;
}

inline fct& fct::operator /= (int a){
	T t;
	this->b*=a/gcd(this->a,a);
	this->a/=gcd(this->a,a);
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
	T t1,t2;
	t1=gcd(this->a,a.a);
	t2=gcd(this->b,a.b);
	this->a*=a.b/t1;
	this->b*=a.a/t2;
	t1=gcd(this->a,this->b);
	if(t1>1||t1<-1){
		this->a/=t1;this->b/=t1;
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
//	t=this->b*a.b;
//	this->a=this->a*a.b+this->b*a.a;
	t=lcm(a.b,this->b);
	this->a=t/a.b*a.a+t/this->b*this->a;
	this->b=t;
	t=gcd(this->a,this->b);
	if(t>1){
		this->a/=t;this->b/=t;
	}
	return *this;
}

inline fct& fct::operator -=(fct& a){
	T t;
//	t=this->b*a.b;
	t=lcm(a.b,this->b);
	this->a=t/this->b*this->a-t/a.b*a.a;
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

