#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"Complex.h"
#include"Fraction.h"
#include"Calculator.h"

  struct Op * Calculator::create_stack(int max, enum Optype type)
{
  struct Op *op;

  op = (Op*)malloc(sizeof(*op));
  if (op == NULL)
    nullerr();

  op->era = (Era*)calloc(sizeof(union Era), max);
  if (op->era == NULL)
    nullerr();

  op->max = max;
  op->top = EMPTY;
  op->type = type;

  return op;
}

void Calculator::push(union Era era, struct Op *op)
{
  if (op->top >= op->max) {
    if (op->type == ND)
      printf("error: stack full, can't push %g\n", era.nd);
    else
      printf("error: stack full, can't push %c\n", era.tor);
  }
  else
    op->era[op->top++] = era;
}

union Era Calculator::pop(struct Op *op)
{
  if (op->top > EMPTY)
    return op->era[--op->top];
  else {
   // printf("error: stack empty\n");////////////////////////////////////////////////////
    if (op->type == ND)
      op->era[EMPTY].nd = 0.0;
    else
      op->era[EMPTY].tor = 0;
    return op->era[EMPTY];
  }
}

void Calculator::nullerr(void)
{
  printf("not enough memory\n");
  exit(1);
}

int Calculator::getop(char s[])    // [K&R] section 4.3
{
  int i, c;

  while ((s[0] = c = getchar()) == ' ' || c == '\t')
    //do nothing
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c;        // not a number
  i = 0;
  if (isdigit(c))    // collect integer part
    while (isdigit(s[++i] = c = getchar()))
      ;
  if (c == '.')        // collect fraction part
    while (isdigit(s[++i] = c = getchar()))
      //do nothing
  s[i] = '\0';
  if (c != EOF)
    ungetc(c, stdin);
  return NUMBER;
}

double Calculator::operate(struct Op *opnd, struct Op *optor)
{
  union Era nd1, nd2, tor;

  nd2 = pop(opnd);
  nd1 = pop(opnd);
  tor = pop(optor);

  switch (tor.tor) {
  case '+':
    return nd1.nd + nd2.nd;
    break;
  case '-':
    return nd1.nd - nd2.nd;
    break;
  case '*':
    return nd1.nd * nd2.nd;
    break;
  case '/':
    return nd1.nd / nd2.nd;
    break;
  default:
    return 0.0;
    break;
  }
}

void Calculator::print_stack(struct Op *op)
{
  int i;
  for (i = op->top; i > 0; i--)
    printf("%g\n", op->era[i].nd);
}

char Calculator::top_tor(struct Op *op)
{
  return op->era[op->top-1].tor;    // after push, top plus one
}

void Calculator::display()
{
  system("CLS");
  opnd = create_stack(MAXOP, ND);
  optor = create_stack(MAXOP, TOR);
  cout<<" 本程序可进行“加减乘除(+ - * /)”四则混合运算。"<<endl;
  cout<<" 输入 q 退出程序。"<<endl;
  cout<<" 输入算式后按回车即可算出答案："<<endl;
  while ((c = getop(s)) != EOF) 
  {
    switch (c) 
	{
    case NUMBER:
        if (opnd->top > optor->top + 1) 
		{    // 如果是逆波兰算式
            cout<<"\tparse error\n";
            while (getchar() != '\n')
                 /*void*/;
            opnd->top = EMPTY;
            era.nd = 0.0;
        }
        else
            era.nd = atof(s);
        push(era, opnd);
        break;
    case '+':        // + 和 - 优先级最低，把除了 '(' 以外的全部操作符弹出后入栈
    case '-':
        if (optor->top == EMPTY) 
		{
            era.tor = c;
            push(era, optor);
        }
        else 
		{
            while (optor->top > EMPTY)
               if (top_tor(optor) == '(')
               break;
               else 
			   {
                   era.nd = operate(opnd, optor);
                   push(era, opnd);
               }
           era.tor = c;
           push(era, optor);
        }
        break;
    case '*':              // 乘除优先级最高，把相同优先级的乘和除弹出后入栈
    case '/':
        if (optor->top == EMPTY) 
		{
            era.tor = c;
            push(era, optor);
        }
        else 
	    {
            while (optor->top > EMPTY)
                if (((era.tor = top_tor(optor)) == '+')
                || (era.tor == '-')
                || (era.tor == '('))
                break;
                else 
			   {
                    era.nd = operate(opnd, optor);
                    push(era, opnd);
                }
            era.tor = c;
            push(era, optor);
       }
       break;
    case '(':        // '(' 不作运算，直接放入optor栈。
        era.tor = c;
        push(era, optor);
        break;
    case ')':        // 把 '(' 之前的全部操作符弹出，计算后把 '(' 也弹出
        while (optor->top > EMPTY)
            if (top_tor(optor) == '(')
            break;
            else 
			{
                era.nd = operate(opnd, optor);
                push(era, opnd);
             }
             pop(optor);
        break;
    case '\n':        // 把余下的操作符全部弹出，计算后输出结果
        if (opnd->top == EMPTY)
          ; //do nothing
        else
            while (optor->top > EMPTY)
                if (top_tor(optor) == '(')
                    pop(optor);
                else 
	            {
                    era.nd = operate(opnd, optor);
                    push(era, opnd);
                }
        era = pop(opnd);
		cout<<"\tans="<<era.nd<<endl;
      break;
    case 'p':
        print_stack(opnd);
        getchar();
        break;
    case 'q':
        exit(0);
        break;
    default:
      cout<<"error: unknown command"<<endl;
      break;
    }
  }
}

/*void Calculator::set_complex()
{
	a.set();
	b.set();
}

void Calculator::display_complex()
{
	system("CLS");
	int sel=-1;
	while(sel!=0)
	{
		system("CLS");
        cout<<"\n\n\n";
	    cout<<"\t\t\t请输入你的选择:\n"<<endl;
	    cout<<"\t\t\t输入1进行复数加\n"<<endl;
	    cout<<"\t\t\t输入2进行复数减\n"<<endl;
    	cout<<"\t\t\t输入3进行复数乘\n"<<endl;
    	cout<<"\t\t\t输入4进行复数除\n"<<endl;
	    cout<<"\t\t\t输入0退出"<<endl;
	    cin>>sel;
	    if(sel!=0)
		{
			set_complex();
		}
	    Complex c;
	    switch (sel)
    	{
	    case 1:
	    	c=a+b;
	    	cout<<"结果为："<<a<<"+"<<b<<"="<<c<<endl;
			system("pause");
	    	cout<<endl;
	    	break;
	    case 2:
	    	c=a-b;
	    	cout<<"结果为："<<a<<"-"<<b<<"="<<c<<endl;
			system("pause");
		    cout<<endl;
		    break;
	    case 3:
	    	c=a*b;
		    cout<<"结果为："<<a<<"*"<<b<<"="<<c<<endl;
			system("pause");
		    cout<<endl;
		    break;
	    case 4:
		    c=a/b;
		    cout<<"结果为："<<a<<"/"<<b<<"="<<c<<endl;
			system("pause");
		    cout<<endl;
		    break;
	    case 0:
		    cout<<"退出"<<endl;
		    exit(0);
		    break;
        default:
            cout<<"请输入正确的函数！"<<endl;
            break;
	    }
	}
}*/

void Calculator::set_fraction()
{
	cout<<"分数a："<<endl;
	a1.set();
	cout<<"分数b："<<endl;
	b1.set();

}
void Calculator::display_fraction()
{
	system("CLS");
	int sel=-1;
	while(sel!=0)
	{
		system("CLS");
        cout<<"\n\n\n";
	    cout<<"\t\t\t请输入你的选择:\n"<<endl;
	    cout<<"\t\t\t输入1进行分数加\n"<<endl;
	    cout<<"\t\t\t输入2进行分数减\n"<<endl;
    	cout<<"\t\t\t输入3进行分数乘\n"<<endl;
    	cout<<"\t\t\t输入4进行分数除\n"<<endl;
	    cout<<"\t\t\t输入0退出"<<endl;
	    cin>>sel;
	    if(sel!=0)
		{
			set_fraction();
		}
	    Fraction c;
	    switch (sel)
    	{
	    case 1:
	        c=a1+b1;
	    	cout<<"结果为："<<"("<<a1<<")"<<"+"<<"("<<b1<<")"<<"="<<c<<endl;
			system("pause");
	    	cout<<endl;
	    	break;
	    case 2:
	    	c=a1-b1;
	    	cout<<"结果为："<<"("<<a1<<")"<<"-"<<"("<<b1<<")"<<"="<<c<<endl;
			system("pause");
		    cout<<endl;
		    break;
	    case 3:
	        c=a1*b1;
		    cout<<"结果为："<<"("<<a1<<")"<<"*"<<"("<<b1<<")"<<"="<<c<<endl;
			system("pause");
		    cout<<endl;
		    break;
	    case 4:
		    c=a1/b1;
		    cout<<"结果为："<<"("<<a1<<")"<<"/"<<"("<<b1<<")"<<"="<<c<<endl;
			system("pause");
		    cout<<endl;
		    break;
	    case 0:
		    cout<<"退出"<<endl;
		    exit(0);
		    break;
        default:
            cout<<"请输入正确的数！"<<endl;
            break;
	    }
	}
}

const Calculator operator+( const Calculator& add1, const Calculator& add2)  
{
	Calculator temp(add1.rpart+add2.rpart,add1.ipart+add2.ipart);
    return temp;
}
const Calculator operator-(const Calculator &sub1, const Calculator &sub2)
{
	Calculator temp(sub1.rpart-sub2.rpart,sub1.ipart-sub2.ipart);
	return temp;
}
const Calculator operator*( const Calculator &c1, const Calculator &c2)
{
	Calculator temp((c1.rpart*c2.rpart-c1.ipart*c2.ipart),(c1.rpart*c2.ipart+c1.ipart*c2.rpart));
	return temp;
}
const Calculator operator/(const Calculator &c1,const Calculator &c2)
{
	Calculator temp( (c1.rpart*c2.rpart+c1.ipart*c2.ipart)/(c2.rpart*c2.rpart+c2.ipart*c2.ipart), (c1.ipart*c2.rpart-c1.rpart*c2.ipart)/(c2.rpart*c2.rpart+c2.ipart*c2.ipart));
	return temp;
}
ostream& operator<<(ostream& os, const Calculator& com)
{
	os << "(" << com.rpart;
	if(com.ipart)
	{
		os << "," << com.ipart << "i";
	}
	os << ")" ;
	return os;
}

istream& operator>>(istream& is, Calculator& com)
{
	is >> com.rpart >>com.ipart;
	return is;
}

void display()
{
	Calculator a,b;
	system("CLS");
	int sel=-1;
	while(sel!=0)
	{
		system("CLS");
        cout<<"\n\n\n";
	    cout<<"\t\t\t请输入你的选择:\n"<<endl;
	    cout<<"\t\t\t输入1进行复数加\n"<<endl;
	    cout<<"\t\t\t输入2进行复数减\n"<<endl;
    	cout<<"\t\t\t输入3进行复数乘\n"<<endl;
    	cout<<"\t\t\t输入4进行复数除\n"<<endl;
	    cout<<"\t\t\t输入0退出"<<endl;
	    cin>>sel;
	    if(sel!=0)
		{
			a.set();
			b.set();
		}
	    Complex c;
	    switch (sel)
    	{
	    case 1:
	    	c=a+b;
	    	cout<<"结果为："<<a<<"+"<<b<<"="<<c<<endl;
			system("pause");
	    	cout<<endl;
	    	break;
	    case 2:
	    	c=a-b;
	    	cout<<"结果为："<<a<<"-"<<b<<"="<<c<<endl;
			system("pause");
		    cout<<endl;
		    break;
	    case 3:
	    	c=a*b;
		    cout<<"结果为："<<a<<"*"<<b<<"="<<c<<endl;
			system("pause");
		    cout<<endl;
		    break;
	    case 4:
		    c=a/b;
		    cout<<"结果为："<<a<<"/"<<b<<"="<<c<<endl;
			system("pause");
		    cout<<endl;
		    break;
	    case 0:
		    cout<<"退出"<<endl;
		    exit(0);
		    break;
        default:
            cout<<"请输入正确的函数！"<<endl;
            break;
	    }
	}
	
}





