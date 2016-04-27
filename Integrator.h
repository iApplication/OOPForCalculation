#ifndef INTEGRATOR_H
#define INTEGRATOR_H
class Integrator
{
private:
    int choice;
    int min;
    int max;
public:
    void display();
    double  f(double x);
    void inte();           //梯形法1
	void leftTangular();    //左矩形法
	void midTangular();    //中矩形法
	void rightTangular();   //右矩形法
	void trapezoid();    //梯形法2

	void simpson();       //辛甫生法
	double T(double x,double y,int z);
	
};


#endif