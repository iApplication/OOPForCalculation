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
  cout<<" ������ɽ��С��Ӽ��˳�(+ - * /)�����������㡣"<<endl;
  cout<<" ���� q �˳�����"<<endl;
  cout<<" ������ʽ�󰴻س���������𰸣�"<<endl;
  while ((c = getop(s)) != EOF) 
  {
    switch (c) 
	{
    case NUMBER:
        if (opnd->top > optor->top + 1) 
		{    // ������沨����ʽ
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
    case '+':        // + �� - ���ȼ���ͣ��ѳ��� '(' �����ȫ����������������ջ
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
    case '*':              // �˳����ȼ���ߣ�����ͬ���ȼ��ĳ˺ͳ���������ջ
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
    case '(':        // '(' �������㣬ֱ�ӷ���optorջ��
        era.tor = c;
        push(era, optor);
        break;
    case ')':        // �� '(' ֮ǰ��ȫ�������������������� '(' Ҳ����
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
    case '\n':        // �����µĲ�����ȫ�������������������
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
	    cout<<"\t\t\t���������ѡ��:\n"<<endl;
	    cout<<"\t\t\t����1���и�����\n"<<endl;
	    cout<<"\t\t\t����2���и�����\n"<<endl;
    	cout<<"\t\t\t����3���и�����\n"<<endl;
    	cout<<"\t\t\t����4���и�����\n"<<endl;
	    cout<<"\t\t\t����0�˳�"<<endl;
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
	    	cout<<"���Ϊ��"<<a<<"+"<<b<<"="<<c<<endl;
			system("pause");
	    	cout<<endl;
	    	break;
	    case 2:
	    	c=a-b;
	    	cout<<"���Ϊ��"<<a<<"-"<<b<<"="<<c<<endl;
			system("pause");
		    cout<<endl;
		    break;
	    case 3:
	    	c=a*b;
		    cout<<"���Ϊ��"<<a<<"*"<<b<<"="<<c<<endl;
			system("pause");
		    cout<<endl;
		    break;
	    case 4:
		    c=a/b;
		    cout<<"���Ϊ��"<<a<<"/"<<b<<"="<<c<<endl;
			system("pause");
		    cout<<endl;
		    break;
	    case 0:
		    cout<<"�˳�"<<endl;
		    exit(0);
		    break;
        default:
            cout<<"��������ȷ�ĺ�����"<<endl;
            break;
	    }
	}
}*/

void Calculator::set_fraction()
{
	cout<<"����a��"<<endl;
	a1.set();
	cout<<"����b��"<<endl;
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
	    cout<<"\t\t\t���������ѡ��:\n"<<endl;
	    cout<<"\t\t\t����1���з�����\n"<<endl;
	    cout<<"\t\t\t����2���з�����\n"<<endl;
    	cout<<"\t\t\t����3���з�����\n"<<endl;
    	cout<<"\t\t\t����4���з�����\n"<<endl;
	    cout<<"\t\t\t����0�˳�"<<endl;
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
	    	cout<<"���Ϊ��"<<"("<<a1<<")"<<"+"<<"("<<b1<<")"<<"="<<c<<endl;
			system("pause");
	    	cout<<endl;
	    	break;
	    case 2:
	    	c=a1-b1;
	    	cout<<"���Ϊ��"<<"("<<a1<<")"<<"-"<<"("<<b1<<")"<<"="<<c<<endl;
			system("pause");
		    cout<<endl;
		    break;
	    case 3:
	        c=a1*b1;
		    cout<<"���Ϊ��"<<"("<<a1<<")"<<"*"<<"("<<b1<<")"<<"="<<c<<endl;
			system("pause");
		    cout<<endl;
		    break;
	    case 4:
		    c=a1/b1;
		    cout<<"���Ϊ��"<<"("<<a1<<")"<<"/"<<"("<<b1<<")"<<"="<<c<<endl;
			system("pause");
		    cout<<endl;
		    break;
	    case 0:
		    cout<<"�˳�"<<endl;
		    exit(0);
		    break;
        default:
            cout<<"��������ȷ������"<<endl;
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
	    cout<<"\t\t\t���������ѡ��:\n"<<endl;
	    cout<<"\t\t\t����1���и�����\n"<<endl;
	    cout<<"\t\t\t����2���и�����\n"<<endl;
    	cout<<"\t\t\t����3���и�����\n"<<endl;
    	cout<<"\t\t\t����4���и�����\n"<<endl;
	    cout<<"\t\t\t����0�˳�"<<endl;
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
	    	cout<<"���Ϊ��"<<a<<"+"<<b<<"="<<c<<endl;
			system("pause");
	    	cout<<endl;
	    	break;
	    case 2:
	    	c=a-b;
	    	cout<<"���Ϊ��"<<a<<"-"<<b<<"="<<c<<endl;
			system("pause");
		    cout<<endl;
		    break;
	    case 3:
	    	c=a*b;
		    cout<<"���Ϊ��"<<a<<"*"<<b<<"="<<c<<endl;
			system("pause");
		    cout<<endl;
		    break;
	    case 4:
		    c=a/b;
		    cout<<"���Ϊ��"<<a<<"/"<<b<<"="<<c<<endl;
			system("pause");
		    cout<<endl;
		    break;
	    case 0:
		    cout<<"�˳�"<<endl;
		    exit(0);
		    break;
        default:
            cout<<"��������ȷ�ĺ�����"<<endl;
            break;
	    }
	}
	
}





