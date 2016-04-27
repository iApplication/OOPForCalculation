#ifndef FRACTION_H
#define FRACTION_H	
class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction(int number1=1,int number2=1);  //default argument
	void set();   
	void reduction();  //约分函数
	void reciprocal();  //倒数函数
	friend const Fraction operator+(const Fraction& x,const Fraction& y);
	friend const Fraction operator-(const Fraction& x,const Fraction& y);
	friend const Fraction operator*(const Fraction& x,const Fraction& y);
	friend const Fraction operator/(const Fraction& x,const Fraction& y);
	friend const Fraction operator+(const Fraction& x);
	friend const Fraction operator-(const Fraction& x);
	const bool operator<(const Fraction& x);
	const bool operator<=(const Fraction& x);
	const bool operator>(const Fraction& x);
	const bool operator>=(const Fraction& x);
	const bool operator==(const Fraction& x);
	const bool operator!=(const Fraction& x);
	friend ostream& operator<<(ostream& os, Fraction& com);
    friend istream& operator>>(istream& os, Fraction& com);
	
};

#endif