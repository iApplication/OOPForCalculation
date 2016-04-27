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
    void inte();           //���η�1
	void leftTangular();    //����η�
	void midTangular();    //�о��η�
	void rightTangular();   //�Ҿ��η�
	void trapezoid();    //���η�2

	void simpson();       //��������
	double T(double x,double y,int z);
	
};


#endif