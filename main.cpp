#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include"Sort.h"
#include"Calculator.h"
#include"Equation.h"
#include"Matrix.h"
#include"Integrator.h"
#include"Search.h"
//#include"Complex.h"

using namespace std;



int main()
{
	char choice=' '; 
	while(choice!='0') 
	{ 
		Calculator a;
		Integrator b;
		Matrix c;
		Sort d;
		Search e;

		cout <<endl<<endl<<"\t\t\t��ӭ�����ҵ�matlab\n\n\n"; 
		cout <<"\t\t\t1 �������\n\n\t\t\t2 �������� \n\n\t\t\t3 ��������\n\n\t\t\t4 ��������\n\n\t\t\t5 ��������\n\n\t\t\t0 �� ��"<<endl; 
		cin >> choice; 

		switch (choice) 
		{ 
		case '1': 
			//Calculator a;
			char choice1;
			//while(choice!=0)
			//{
				cout<<"1 ����������"<<endl;
				cout<<"2 ������������"<<endl;
				cout<<"3 ������������"<<endl;
				cout<<"0 �� ��"<<endl;
				cin>>choice1;
				switch(choice1)
				{
				case '1':
					a.display();
					break;
				case '2':
					//a.display_complex();
					display();
					break;
				case '3':
					a.display_fraction();
					break;
				case '0':
					cout<<"�������������"<<endl;
					exit(0);
					break;
		        default:
			        if(choice1 != '0')
					{
				        cout<<"����������������룺"<<endl; 
				        break;
				    }
			    //}
			}
			break; 
		case '2': 
			//Integrator b;
			b.display();
			break; 
		case '3': 
			//Matrix c;
			c.display();
			break; 
		case '4':
			//Sort d;
			d.display();
			/*int choice_2=1;
			while(choice_2!=0)
			{
			system("cls");
	        d.set();
            d.Sort_1();
	        d.print();
			cout<<"�����밴0�������밴1"<<endl;
			cin>>choice_2;
			}*/
			break;
		case '5':
			//Search e;
	        e.display();
			break;
		default:
			if(choice != '0')
			{
				cout<<"����������������룺"<<endl; 
				break;
			}
		}
	}






   /* Sort a;
	a.set();
    a.Sort_1();
	a.print();
	Calculator b;
	b.display();
	Equation a;
	a.set();
    a.get_equation();
	a.print();
	Matrix a;
	a.display();
	a.Scalar();
    a.Subtraction();
	a.Add();
	a.Transposition();
	a.Multiplication();
	Integrator c;
    c.display();*/
	/*Search a;
	a.display();
	Complex a(1,1);
	Complex b(2,2);
	Complex c;
	c=a+b;
	c.display();*/
	/*Complex a(1,1),b(2,2);
    Complex c=a+b;
	cout<<c<<endl;
	Complex d=a-b;
	cout<<d<<endl;
	Complex e=a*b;
	cout<<e<<endl;
	Complex f=a/b;
	cout<<f<<endl;
	
	Complex g;
	g.set();
	cout<<g;
	
	Calculator a;
	a.set_complex();
	a.display_complex();*/

    system("pause");
    return 0;
}



