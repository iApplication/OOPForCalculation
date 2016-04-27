#ifndef MATRIX_H
#define MATRIX_H


const int Max=100;

class Matrix
{
private:
	float MA[Max][Max],MB[Max][Max];
    int R1,C1,R2,C2;
public:
	Matrix();
	void set(int r1, int c1 );
	void set(int r1,int c1,int r2,int c2);   //函数重载
	void display();
    void Scalar();    //矩阵数乘函数
    void Transposition();  //矩阵转置函数
    void Add();   //矩阵加法函数    
    void Subtraction();   //矩阵减法函数    
    void Multiplication();   //矩阵乘法运算
};


#endif