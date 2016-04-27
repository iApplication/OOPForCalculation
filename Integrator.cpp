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
         cout<<"choice 0:结束"<<endl;
         cout<<"请输入你的选择:";
         cin>>sel;
	     choice=sel;
         //double a,b;
         cout<<"***输入积分上下限min,max的值用空格隔开***"<<endl;
         cin>>min>>max;
         cout<<"***下限min="<<min<<endl;
         cout<<"***上限max="<<max<<endl;
         int sel;
	     cout<<"请选择排序方式:"<<endl;
	     cout<<" ---- 梯形法1:1"<<endl;
	     cout<<" ---- 梯形法2:2"<<endl;
	     cout<<" ---- 左矩形法:3"<<endl;
	     cout<<" ---- 中矩形法:4"<<endl;
	     cout<<" ---- 右矩形法:5"<<endl;
	     cout<<" ---- 辛甫生法:6"<<endl;
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
            cout<<"结束!"<<endl;
            exit(0);
            break;
        default:
            cout<<"请输入正确的函数！"<<endl;
            break;
    }
    return y;
}
void Integrator::inte()
{
    int n;
    double trace,sum=0,area,heightl=0,heighth=0,i,a=0;
    cout<<"***在（"<<min<<","<<max<<"）上的定积分"<<endl;
    cout<<"***请输入对区间的分割次数:";
    cin>>n;
    //trace=((double)max-(double)min)/n;
	//trace=(max-min)/n;
	trace=(static_cast<double>(max)-static_cast<double>(min))/n;//求出定义区间上的元素单位
    a=(double)min;
    for(i=0;i<=max;i+=trace)
    {
       heightl=f(a);   //求出梯形左边
       a+=trace;
       heighth=f(a);   //求出梯形右边
       area=(((heightl+heighth)*trace)/2);    //梯形面积元素
       sum+=area;
    }
    cout<<"***结果如下:"<<endl;
    cout<<"***在（"<<min<<","<<max<<"）上的定积分为"<<sum<<endl;

}

void Integrator::leftTangular()
{
    int i,n; //为区间等分的个数，应尽可能大
    double h;
	double sum=0; //h为步长
    cout<<"***在（"<<min<<","<<max<<"）上的定积分"<<endl;
    cout<<"***请输入对区间的分割次数:";
	cin>>n;
	//h=((double)max-(double)min)/n;  
	//h=(max-min)/n;
	h=(static_cast<double>(max)-static_cast<double>(min))/n;  //步长的计算
    sum=f(min)*h;
    for(i=1;i<n;i++)
    {
        sum=sum+f(min+i*h)*h;
    }
    cout<<"***结果如下:"<<endl;
    cout<<"***在（"<<min<<","<<max<<"）上的定积分为"<<sum<<endl;
}

void Integrator::midTangular()
{
	int n,i;
	double h;
    double sum=0;
    cout<<"***在（"<<min<<","<<max<<"）上的定积分"<<endl;
    cout<<"***请输入对区间的分割次数:";
    cin>>n;
    //h=((double)max-(double)min)/n;   
	h=(static_cast<double>(max)-static_cast<double>(min))/n;//求出定义区间上的元素单位
    sum=0.5*(f(min)+f(min+h))*h;
    for(i=1;i<n;i++)
    {
        sum=sum+0.5*(f(min+i*h)+f(min+(i+1)*h))*h;
    }
    cout<<"***结果如下:"<<endl;
    cout<<"***在（"<<min<<","<<max<<"）上的定积分为"<<sum<<endl;
}

void Integrator::rightTangular()
{
	int n,i;
	double h;
    double sum=0;
    cout<<"***在（"<<min<<","<<max<<"）上的定积分"<<endl;
    cout<<"***请输入对区间的分割次数:";
    cin>>n;
    //h=((double)max-(double)min)/n;   
	h=(static_cast<double>(max)-static_cast<double>(min))/n;//求出定义区间上的元素单位
    sum=f(min+h)*h;
    for(i=1;i<n-1;i++)
    {
        sum=sum+f(min+(i+1*h))*h;
    }
    cout<<"***结果如下:"<<endl;
    cout<<"***在（"<<min<<","<<max<<"）上的定积分为"<<sum<<endl;
}

void Integrator::trapezoid()
{
	int n,i;
	double h;
    double sum=0;
    cout<<"***在（"<<min<<","<<max<<"）上的定积分"<<endl;
    cout<<"***请输入对区间的分割次数:";
    cin>>n;
    //h=((double)max-(double)min)/n;   
	h=(static_cast<double>(max)-static_cast<double>(min))/n;//求出定义区间上的元素单位
    sum=0.5*(f(min)+f(min+h))*h;
    for(i=1;i<n;i++)
    {
        sum=sum+0.5*(f(min+i*h)+f(min+(i+1)*h))*h;
    }
    cout<<"***结果如下:"<<endl;
    cout<<"***在（"<<min<<","<<max<<"）上的定积分为"<<sum<<endl;
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
    cout<<"***在（"<<min<<","<<max<<"）上的定积分"<<endl;
    cout<<"***请输入对区间的分割次数:";
    cin>>n;
    sum=(4*T(min,max,2*n)-T(min,max,n))/3; //利用辛甫生公式求解定积分
    cout<<"***结果如下:"<<endl;
    cout<<"***在（"<<min<<","<<max<<"）上的定积分为"<<sum<<endl;
}











