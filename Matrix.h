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
	void set(int r1,int c1,int r2,int c2);   //��������
	void display();
    void Scalar();    //�������˺���
    void Transposition();  //����ת�ú���
    void Add();   //����ӷ�����    
    void Subtraction();   //�����������    
    void Multiplication();   //����˷�����
};


#endif