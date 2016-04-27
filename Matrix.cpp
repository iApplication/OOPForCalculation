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
		cout<<"请输入"<<r1<<"*"<<c1<<"矩阵MA(每行以回车结束):"<<endl;
		for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                cin>>MA[i][j];
            }
        }
        cout<<"请输入"<<r2<<"*"<<c2<<"矩阵MB(每行以回车结束):"<<endl;
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
        cout<<"功能如下："<<endl;
        cout<<"数乘矩阵 1"<<endl;
        cout<<"矩阵转换 2"<<endl;
        cout<<"矩阵相加 3"<<endl;
        cout<<"矩阵相减 4"<<endl;
        cout<<"矩阵乘法 5"<<endl;
        cout<<"结束     0"<<endl;
        cout<<"请选定您需要的操作:"<<endl;
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
                cout<<"结束!"<<endl;
                exit(0);
                break;
            default:
                cout<<"对不起，您的输入不合法!"<<endl;
				system("pause");
                break;
        }
    }
	}

    void Matrix::Scalar()//矩阵数乘函数
   {
        int i,j,k;
        cout<<"请输入乘数:"<<endl;
        cin>>k;
	    cout<<"请输入第一个MA矩阵的行数和列数："<<endl;
	    cin>>R1>>C1;
        cout<<"请输入"<<R1<<"*"<<C1<<"矩阵MA(每行以回车结束):"<<endl;
        set(R1,C1);
        cout<<k;
        cout<<"乘矩阵MA结果为:"<<endl;
        for(i=0;i<R1;i++)
        {
            for(j=0;j<C1;j++)
            {
                cout<<setw(8)<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(2)<<k*MA[i][j];
            }
            cout<<endl;
        }
    }

    void Matrix::Transposition()//矩阵转置函数
    {
        int i,j;
	    float MD[Max][Max];
        cout<<"请输入MA矩阵的行数和列数："<<endl;
	    cin>>R1>>C1;
        cout<<"请输入"<<R1<<"*"<<C1<<"矩阵MA(每行以回车结束):"<<endl;
        set(R1,C1);
        for(i=0;i<R1;i++)//将矩阵MA的第n行的值赋给矩阵MD的第n列
        {
            for(j=0;j<C1;j++)
            {
                MD[j][i]=MA[i][j];
            }
        }
        cout<<"矩阵MA转置后的结果为:"<<endl;
        for(i=0;i<C1;i++)
        {
            for(j=0;j<R1;j++)
            {
                cout<<setw(8)<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(2)<<MD[i][j];
            }
            cout<<endl;
        }
    }

    void Matrix::Add()//矩阵加法函数
    {
        int i,j;
	    float ME[Max][Max];
        cout<<"请输入MA和MB矩阵的行数和列数："<<endl;
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
        cout<<"结果："<<endl;
        for(i=0;i<R1;i++)
        {
            for(j=0;j<C1;j++)
            {
                cout<<setw(8)<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(2)<<ME[i][j];
            }
            cout<<endl;
        }
    }


    void Matrix::Subtraction()//矩阵减法函数
    {
        int i,j;
	    float MF[Max][Max];//={0};
        cout<<"请输入MA和MB矩阵的行数和列数："<<endl;
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
        cout<<"结果："<<endl;
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
        cout<<"请输入第一个MA矩阵的行数和列数："<<endl;
        cin>>R1>>C1;
        cout<<"请输入第二个矩阵MB的列数（该矩阵行数等于第一个矩阵的列数）："<<endl;
        cin>>C2;
	    R2=C1;
        double **a=NULL;
        a=(double**)malloc(R1*sizeof(double*));
        for(i=0;i<R1;i++)
            a[i]=(double*)malloc(C1*sizeof(double));
	    cout<<"请输入"<<R1<<"*"<<C1<<"矩阵MA(每行以回车结束):"<<endl;
        for(i=0;i<R1;i++)
            for(j=0;j<C1;j++)
                cin>>a[i][j];
        double **b=NULL;
        b=(double**)malloc(C1*sizeof(double *));
        for(i=0;i<C1;i++)
        b[i]=(double*)malloc(C2*sizeof(double));
	    cout<<"请输入"<<R2<<"*"<<C2<<"矩阵MA(每行以回车结束):"<<endl;
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
        cout<<"结果："<<endl;
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







