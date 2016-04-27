#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include"Matrix.h"
using namespace std;
    
    Matrix::Matrix()
	{
		R1=C1=R2=C2;
	}

	void Matrix::set(int r1, int c1 )
	{
		int i,j;
		for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                cin>>MA[i][j];
            }
        }
	}

	void Matrix::set(int r1,int c1,int r2,int c2)
	{
		int i,j;
		cout<<"������"<<r1<<"*"<<c1<<"����MA(ÿ���Իس�����):"<<endl;
		for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                cin>>MA[i][j];
            }
        }
        cout<<"������"<<r2<<"*"<<c2<<"����MB(ÿ���Իس�����):"<<endl;
		for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                cin>>MB[i][j];
            }
        }
	}

	void Matrix::display()
	{
		
		    int c;
    while(1)
    {
		system("cls");
        cout<<"�������£�"<<endl;
        cout<<"���˾��� 1"<<endl;
        cout<<"����ת�� 2"<<endl;
        cout<<"������� 3"<<endl;
        cout<<"������� 4"<<endl;
        cout<<"����˷� 5"<<endl;
        cout<<"����     0"<<endl;
        cout<<"��ѡ������Ҫ�Ĳ���:"<<endl;
        cin>>c;
        switch(c)
        {
            case 1:
                Scalar();
				system("pause");
                break;
            case 2:
                Transposition();
				system("pause");
                break;
            case 3:
                Add();
				system("pause");
                break;
            case 4:
                Subtraction();
				system("pause");
                break;
            case 5:
                Multiplication();
				system("pause");
                break;
            case 0:
                cout<<"����!"<<endl;
                exit(0);
                break;
            default:
                cout<<"�Բ����������벻�Ϸ�!"<<endl;
				system("pause");
                break;
        }
    }
	}

    void Matrix::Scalar()//�������˺���
   {
        int i,j,k;
        cout<<"���������:"<<endl;
        cin>>k;
	    cout<<"�������һ��MA�����������������"<<endl;
	    cin>>R1>>C1;
        cout<<"������"<<R1<<"*"<<C1<<"����MA(ÿ���Իس�����):"<<endl;
        set(R1,C1);
        cout<<k;
        cout<<"�˾���MA���Ϊ:"<<endl;
        for(i=0;i<R1;i++)
        {
            for(j=0;j<C1;j++)
            {
                cout<<setw(8)<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(2)<<k*MA[i][j];
            }
            cout<<endl;
        }
    }

    void Matrix::Transposition()//����ת�ú���
    {
        int i,j;
	    float MD[Max][Max];
        cout<<"������MA�����������������"<<endl;
	    cin>>R1>>C1;
        cout<<"������"<<R1<<"*"<<C1<<"����MA(ÿ���Իس�����):"<<endl;
        set(R1,C1);
        for(i=0;i<R1;i++)//������MA�ĵ�n�е�ֵ��������MD�ĵ�n��
        {
            for(j=0;j<C1;j++)
            {
                MD[j][i]=MA[i][j];
            }
        }
        cout<<"����MAת�ú�Ľ��Ϊ:"<<endl;
        for(i=0;i<C1;i++)
        {
            for(j=0;j<R1;j++)
            {
                cout<<setw(8)<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(2)<<MD[i][j];
            }
            cout<<endl;
        }
    }

    void Matrix::Add()//����ӷ�����
    {
        int i,j;
	    float ME[Max][Max];
        cout<<"������MA��MB�����������������"<<endl;
        cin>>R1>>C1;
        R2=R1;
        C2=C1;
        set(R1,C1,R2,C2);
        for(i=0;i<R1;i++)
        {
            for(j=0;j<C1;j++)
            {
                ME[i][j]=MA[i][j]+MB[i][j];
            }
        }
        cout<<"�����"<<endl;
        for(i=0;i<R1;i++)
        {
            for(j=0;j<C1;j++)
            {
                cout<<setw(8)<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(2)<<ME[i][j];
            }
            cout<<endl;
        }
    }


    void Matrix::Subtraction()//�����������
    {
        int i,j;
	    float MF[Max][Max];//={0};
        cout<<"������MA��MB�����������������"<<endl;
        cin>>R1>>C1;
        R2=R1;
        C2=C1;
        set(R1,C1,R2,C2);
        for(i=0;i<R1;i++)
        {
            for(j=0;j<C1;j++)
            {
                MF[i][j]=MA[i][j]-MB[i][j];
            }
        }
        cout<<"�����"<<endl;
        for(i=0;i<R1;i++)
        {
            for(j=0;j<C1;j++)
            {
                cout<<setw(8)<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(2)<<MF[i][j];
            }
            cout<<endl;
        }
    }

    void Matrix::Multiplication()
    {
        int i,j,k;
        cout<<"�������һ��MA�����������������"<<endl;
        cin>>R1>>C1;
        cout<<"������ڶ�������MB���������þ����������ڵ�һ���������������"<<endl;
        cin>>C2;
	    R2=C1;
        double **a=NULL;
        a=(double**)malloc(R1*sizeof(double*));
        for(i=0;i<R1;i++)
            a[i]=(double*)malloc(C1*sizeof(double));
	    cout<<"������"<<R1<<"*"<<C1<<"����MA(ÿ���Իس�����):"<<endl;
        for(i=0;i<R1;i++)
            for(j=0;j<C1;j++)
                cin>>a[i][j];
        double **b=NULL;
        b=(double**)malloc(C1*sizeof(double *));
        for(i=0;i<C1;i++)
        b[i]=(double*)malloc(C2*sizeof(double));
	    cout<<"������"<<R2<<"*"<<C2<<"����MA(ÿ���Իس�����):"<<endl;
        for(i=0;i<C1;i++)
            for(j=0;j<C2;j++)
                cin>>b[i][j];
        double **MG=NULL;
        MG=(double**)malloc(R1*sizeof(double*));
        for(i=0;i<R1;i++)
            MG[i]=(double*)malloc(C2*sizeof(double));
        for(i=0;i<R1;i++)
            for(j=0;j<C2;j++)
                MG[i][j]=0;
        for(i=0;i<R1;i++)
            for(j=0;j<C2;j++)
                for(k=0;k<C1;k++)
                    MG[i][j]+=a[i][k]*b[k][j];
        cout<<"�����"<<endl;
        for(i=0;i<R1;i++)
        {
            for(j=0;j<C2;j++)
            cout<<setw(8)<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(2)<<MG[i][j];
            cout<<endl;
        }
        for(i=0;i<R1;i++)
        {
            free(a[i]);
            a[i]=NULL;
            free(MG[i]);
            MG[i]=NULL;
        }   
        free(a);
        a=NULL;
        free(MG);
        MG=NULL;
        for(i=0;i<C1;i++)
        {
            free(b[i]);
            b[i]=NULL;
        }
        free(b);
        b=NULL;
   }







