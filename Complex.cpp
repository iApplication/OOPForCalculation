#include "complex.h"

const Complex operator+( const Complex& add1, const Complex& add2)  
{
	Complex temp(add1.rpart+add2.rpart,add1.ipart+add2.ipart);
    return temp;
}
const Complex operator-(const Complex &sub1, const Complex &sub2)
{
	Complex temp(sub1.rpart-sub2.rpart,sub1.ipart-sub2.ipart);
	return temp;
}
const Complex operator*( const Complex &c1, const Complex &c2)
{
	Complex temp((c1.rpart*c2.rpart-c1.ipart*c2.ipart),(c1.rpart*c2.ipart+c1.ipart*c2.rpart));
	return temp;
}
const Complex operator/(const Complex &c1,const Complex &c2)
{
	Complex temp( (c1.rpart*c2.rpart+c1.ipart*c2.ipart)/(c2.rpart*c2.rpart+c2.ipart*c2.ipart), (c1.ipart*c2.rpart-c1.rpart*c2.ipart)/(c2.rpart*c2.rpart+c2.ipart*c2.ipart));
	return temp;
}

ostream& operator<<(ostream& os, const Complex& com)
{
    os << "(" << com.rpart;
	if(com.ipart)
	{
		os << "," << com.ipart << "i";
	}
	os << ")" ;
	return os;
}

istream& operator>>(istream& is, Complex& com)
{
	is >> com.rpart >>com.ipart;
	return is;
}


