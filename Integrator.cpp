#include<iostream>
using namespace std;
#include<cmath>
#include<stdlib.h>
#include<stdio.h>
#include"Integrator.h"

 void Integrator::display()
 {
	 system("cls");
	 int sel=-1;
	 while(sel!=0)
	 {
		 system("cls");
	     cout<<"choice 1:sin(x)"<<endl;
         cout<<"choice 2:cos(x)"<<endl;
         cout<<"choice 3:x*sin(x)"<<endl;
         cout<<"choice 4:x*cos(x)"<<endl;
         cout<<"choice 0:����"<<endl;
         cout<<"���������ѡ��:";
         cin>>sel;
	     choice=sel;
         //double a,b;
         cout<<"***�������������min,max��ֵ�ÿո����***"<<endl;
         cin>>min>>max;
         cout<<"***����min="<<min<<endl;
         cout<<"***����max="<<max<<endl;
         int sel;
	     cout<<"��ѡ������ʽ:"<<endl;
	     cout<<" ---- ���η�1:1"<<endl;
	     cout<<" ---- ���η�2:2"<<endl;
	     cout<<" ---- ����η�:3"<<endl;
	     cout<<" ---- �о��η�:4"<<endl;
	     cout<<" ---- �Ҿ��η�:5"<<endl;
	     cout<<" ---- ��������:6"<<endl;
	     cin>>sel;
	     switch(sel)
         {
		 case 1:
			inte();
			break;
		 case 2:
			trapezoid();
			break;
		 case 3:
			leftTangular();
			break;
		 case 4:
			midTangular();
			break;
		 case 5:
			rightTangular();
			break;
		 case 6:
			simpson();
			break;
	     }
	     system("pause");
	 }
 }



double  Integrator::f(double x)
{
    double y;

    switch(choice)
    {
        case 1:
            y=sin(x);
            break;
        case 2:
            y=cos(x);
            break;
        case 3:
            y=x*sin(x);
            break;
        case 4:
            y=x*cos(x);
            break;
        case 0:
            cout<<"����!"<<endl;
            exit(0);
            break;
        default:
            cout<<"��������ȷ�ĺ�����"<<endl;
            break;
    }
    return y;
}
void Integrator::inte()
{
    int n;
    double trace,sum=0,area,heightl=0,heighth=0,i,a=0;
    cout<<"***�ڣ�"<<min<<","<<max<<"���ϵĶ�����"<<endl;
    cout<<"***�����������ķָ����:";
    cin>>n;
    //trace=((double)max-(double)min)/n;
	//trace=(max-min)/n;
	trace=(static_cast<double>(max)-static_cast<double>(min))/n;//������������ϵ�Ԫ�ص�λ
    a=(double)min;
    for(i=0;i<=max;i+=trace)
    {
       heightl=f(a);   //����������
       a+=trace;
       heighth=f(a);   //��������ұ�
       area=(((heightl+heighth)*trace)/2);    //�������Ԫ��
       sum+=area;
    }
    cout<<"***�������:"<<endl;
    cout<<"***�ڣ�"<<min<<","<<max<<"���ϵĶ�����Ϊ"<<sum<<endl;

}

void Integrator::leftTangular()
{
    int i,n; //Ϊ����ȷֵĸ�����Ӧ�����ܴ�
    double h;
	double sum=0; //hΪ����
    cout<<"***�ڣ�"<<min<<","<<max<<"���ϵĶ�����"<<endl;
    cout<<"***�����������ķָ����:";
	cin>>n;
	//h=((double)max-(double)min)/n;  
	//h=(max-min)/n;
	h=(static_cast<double>(max)-static_cast<double>(min))/n;  //�����ļ���
    sum=f(min)*h;
    for(i=1;i<n;i++)
    {
        sum=sum+f(min+i*h)*h;
    }
    cout<<"***�������:"<<endl;
    cout<<"***�ڣ�"<<min<<","<<max<<"���ϵĶ�����Ϊ"<<sum<<endl;
}

void Integrator::midTangular()
{
	int n,i;
	double h;
    double sum=0;
    cout<<"***�ڣ�"<<min<<","<<max<<"���ϵĶ�����"<<endl;
    cout<<"***�����������ķָ����:";
    cin>>n;
    //h=((double)max-(double)min)/n;   
	h=(static_cast<double>(max)-static_cast<double>(min))/n;//������������ϵ�Ԫ�ص�λ
    sum=0.5*(f(min)+f(min+h))*h;
    for(i=1;i<n;i++)
    {
        sum=sum+0.5*(f(min+i*h)+f(min+(i+1)*h))*h;
    }
    cout<<"***�������:"<<endl;
    cout<<"***�ڣ�"<<min<<","<<max<<"���ϵĶ�����Ϊ"<<sum<<endl;
}

void Integrator::rightTangular()
{
	int n,i;
	double h;
    double sum=0;
    cout<<"***�ڣ�"<<min<<","<<max<<"���ϵĶ�����"<<endl;
    cout<<"***�����������ķָ����:";
    cin>>n;
    //h=((double)max-(double)min)/n;   
	h=(static_cast<double>(max)-static_cast<double>(min))/n;//������������ϵ�Ԫ�ص�λ
    sum=f(min+h)*h;
    for(i=1;i<n-1;i++)
    {
        sum=sum+f(min+(i+1*h))*h;
    }
    cout<<"***�������:"<<endl;
    cout<<"***�ڣ�"<<min<<","<<max<<"���ϵĶ�����Ϊ"<<sum<<endl;
}

void Integrator::trapezoid()
{
	int n,i;
	double h;
    double sum=0;
    cout<<"***�ڣ�"<<min<<","<<max<<"���ϵĶ�����"<<endl;
    cout<<"***�����������ķָ����:";
    cin>>n;
    //h=((double)max-(double)min)/n;   
	h=(static_cast<double>(max)-static_cast<double>(min))/n;//������������ϵ�Ԫ�ص�λ
    sum=0.5*(f(min)+f(min+h))*h;
    for(i=1;i<n;i++)
    {
        sum=sum+0.5*(f(min+i*h)+f(min+(i+1)*h))*h;
    }
    cout<<"***�������:"<<endl;
    cout<<"***�ڣ�"<<min<<","<<max<<"���ϵĶ�����Ϊ"<<sum<<endl;
}

double Integrator::T(double x,double y,int z)
{
    double h,Tn;
    int i;
    //h=(y-x)/(double)z;
	h=(y-x)/(static_cast<double>(z));
    Tn=(f(x)+f(y))/2;
    for(i=1;i<z;i++)
      Tn=Tn+f(x+i*h);
    Tn=Tn*h;
    return (Tn);
} 

void Integrator::simpson()
{
    double sum;
    int n;
    cout<<"***�ڣ�"<<min<<","<<max<<"���ϵĶ�����"<<endl;
    cout<<"***�����������ķָ����:";
    cin>>n;
    sum=(4*T(min,max,2*n)-T(min,max,n))/3; //������������ʽ��ⶨ����
    cout<<"***�������:"<<endl;
    cout<<"***�ڣ�"<<min<<","<<max<<"���ϵĶ�����Ϊ"<<sum<<endl;
}











