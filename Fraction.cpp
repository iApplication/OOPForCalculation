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
	cout<<"����������Ҫ�ķ�����"<<endl;
	cout<<"��������ӣ�"<<endl;
	cin>>numerator;
	cout<<"�������ĸ��"<<endl;
	cin>>denominator;
	reduction();
}

void Fraction::reduction()            //Լ�ֺ���
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

void Fraction::reciprocal()         //��������
{
	int temp=numerator;
	numerator=denominator;
	denominator=temp;
	reduction();
}

const Fraction operator+(const Fraction& x,const Fraction& y)     //�˴��������c=a+4,c=4+a,�����������ת���ͼӷ�������
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

const Fraction operator-(const Fraction& x)    //��Ŀ����ʵ�ַ����ĸ���
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

ostream& operator<<(ostream& os, Fraction& com)     //����Ҫ����Լ�����㣬����Fraction& comǰ��û��const
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
	cout<<"��ֱ���������ķ��Ӻͷ�ĸ��";
	is>>com.numerator>>com.denominator;
	com.reduction();
	return is;
}

