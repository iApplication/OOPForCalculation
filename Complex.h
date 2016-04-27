#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;
#include <math.h>
#include<stdlib.h>


class Complex{
protected:   
	double rpart;
    double ipart;
public: 
	Complex(double rp=0.0,double ip=0.0)
	{  
		rpart=rp;   
		ipart=ip; 
	}	
	void set()
	{
		cout<<"请输入你想要的复数（格式为a b，不用写i）："<<endl;
		cin>>rpart>>ipart;
	}
    friend const Complex operator+(const Complex &add1, const Complex &add2);
	friend const Complex operator-(const Complex &sub1, const Complex &sub2);
	friend const Complex operator*(const Complex &c1, const Complex &c2);
	friend const Complex operator/(const Complex &c1,const Complex &c2);
	friend ostream& operator<<(ostream& os, const Complex& com);
    friend istream& operator>>(istream& is, Complex& com);

};

#endif
