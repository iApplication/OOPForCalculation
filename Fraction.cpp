#include<iostream>
using namespace std;
#include"Fraction.h"


Fraction::Fraction(int number1,int number2)
{
	numerator=number1;
	denominator=number2;
}

void Fraction::set()
{
	cout<<"请输入你想要的分数："<<endl;
	cout<<"请输入分子："<<endl;
	cin>>numerator;
	cout<<"请输入分母："<<endl;
	cin>>denominator;
	reduction();
}

void Fraction::reduction()            //约分函数
{
	int i;
	int nume,deno;
	int k=1,j=1;
	if(numerator<0)
	{
		nume=-1*numerator;
		k=-1;
	}
	else 
		nume=numerator;

	if(denominator<0)
	{
		deno=-1*denominator;
		j=-1;
	}
	else 
		deno=denominator;

	if(nume<deno)
	{
		for(i=2;i<=nume;i++)
		{
			if( (nume%i==0) && (deno%i==0) )
			{
				nume/=i;
				deno/=i;
				i--;
			}
		}
	}
	else if(nume>=deno)
	{
		for(i=2;i<=deno;i++)
		{
			if( (nume%i==0) && (deno%i==0) )
			{
				nume/=i;
				deno/=i;
				i--;
			}
		}
	}
	numerator=k*j*nume;
	denominator=deno;
}

void Fraction::reciprocal()         //倒数函数
{
	int temp=numerator;
	numerator=denominator;
	denominator=temp;
	reduction();
}

const Fraction operator+(const Fraction& x,const Fraction& y)     //此处可以完成c=a+4,c=4+a,即完成了类型转换和加法交换律
{
	Fraction c(x.numerator*y.denominator+y.numerator*x.denominator,x.denominator*y.denominator);
	c.reduction();
	return c;
}

const Fraction operator-(const Fraction& x,const Fraction& y)     
{
	Fraction c(x.numerator*y.denominator-y.numerator*x.denominator,x.denominator*y.denominator);
	c.reduction();
	return c;
}

const Fraction operator*(const Fraction& x,const Fraction& y)     
{
	Fraction c(x.numerator*y.numerator,x.denominator*y.denominator);
	c.reduction();
	return c;
}

const Fraction operator/(const Fraction& x,const Fraction& y)     
{
	Fraction c(x.numerator*y.denominator,x.denominator*y.numerator);
	c.reduction();
	return c;
}

const Fraction operator+(const Fraction& x)
{
	Fraction c(+x.numerator,+x.denominator);
	c.reduction();
	return c;
}

const Fraction operator-(const Fraction& x)    //单目负号实现分数的负数
{
	Fraction c(-1*x.numerator,x.denominator);
	c.reduction();
	return c;
}

const bool Fraction::operator<(const Fraction& x)
{
	if(numerator*x.denominator<x.numerator*denominator)
		return true;
	else 
		return false;
}
const bool Fraction::operator<=(const Fraction& x)
{
	if(numerator*x.denominator<=x.numerator*denominator)
		return true;
	else 
		return false;
}

const bool Fraction::operator>(const Fraction& x)
{
	if(numerator*x.denominator>x.numerator*denominator)
		return true;
	else 
		return false;
}

const bool Fraction::operator>=(const Fraction& x)
{
	if(numerator*x.denominator>=x.numerator*denominator)
		return true;
	else 
		return false;
}

const bool Fraction::operator==(const Fraction& x)
{
	if(numerator*x.denominator==x.numerator*denominator)
		return true;
	else 
		return false;
}

const bool Fraction::operator!=(const Fraction& x)
{
	if(numerator*x.denominator!=x.numerator*denominator)
		return true;
	else 
		return false;
}

ostream& operator<<(ostream& os, Fraction& com)     //由于要进行约分运算，所以Fraction& com前面没有const
{
	com.reduction();
	if(com.denominator!=1)
		cout<<com.numerator<<"/"<<com.denominator<<" ";
	else
		cout<<com.numerator<<" ";
	return os;
}

istream& operator>>(istream& is, Fraction& com)
{
	cout<<"请分别输入分数的分子和分母：";
	is>>com.numerator>>com.denominator;
	com.reduction();
	return is;
}

