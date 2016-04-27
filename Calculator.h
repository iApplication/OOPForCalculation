#ifndef CALCULATOR_H
#define CALCULATOR_H
#include"Complex.h"   //注意这个错误
#include"Fraction.h"
#define MAXOP    100
#define NUMBER    '0'    // signal that a number was found
#define EMPTY    0
enum Optype { ND, TOR };    // ND for operand, TOR for operator
union Era
{
  double nd;    // op.era.nd
  char tor;    // op.era.tor
};

struct Op
{
  int max;
  int top;
  enum Optype type;
  union Era *era;
};

class Calculator:public Complex
{
private:
  int c;
  char s[MAXOP];
  union Era era;
  struct Op *opnd;
  struct Op *optor;
  //Complex a;
  //Complex b;
  Fraction a1;
  Fraction b1;
public:
  Calculator(double rp=0.0,double ip=0.0):Complex(rp,ip)
  {  }
  struct Op *create_stack(int max, enum Optype);
  void push(union Era, struct Op *);
  union Era pop(struct Op *);
  void nullerr(void);
  int getop(char []);
  double operate(struct Op *opnd, struct Op *optor);
  void print_stack(struct Op *op);
  char top_tor(struct Op *);
  void display();    //四则运算
  void set_complex();
  void display_complex();
  void set_fraction();
  void display_fraction();
  friend const Calculator operator+(const Calculator &add1, const Calculator &add2);   //redefine
  friend const Calculator operator-(const Calculator &sub1, const Calculator &sub2);   //redefine
  friend const Calculator operator*(const Calculator &c1, const Calculator &c2);       //redefine
  friend const Calculator operator/(const Calculator &c1,const Calculator &c2);        //redefine
  friend ostream& operator<<(ostream& os, const Calculator& com);                     //redefine
  friend istream& operator>>(istream& is, Calculator& com);                          //redefine
  friend void display();

};



#endif