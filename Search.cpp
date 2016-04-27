#include<iostream>
using namespace std;
#include"Sort.h"
#include"Search.h"

int Search::binsearch(int r[],int n,int k)
{
	
	int low=0;
	int high=n-1;
	int mid;
	int result1=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(k==r[mid])
		{
			result1=1;
		}
		if(k>r[mid])
		{
			low=mid+1;
		}
		if(k<r[mid])
		{
			high=mid-1;
		}
	}
	return result1;
	/*int i;
	for(i=0;i<n;i++)
	{
		if(r[i]==k);
		return 1;
	}
	return 0;*/
}

int Search::search(int r[],int n, int k)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(r[i]==k);
		return 1;
	}
	return 0;
}

void Search::set()    //�̳�֮��������
{
	int i;
	cout<<"Putin your array length:";
	cin>>length;
	cout<<"Putin your numbers:";
	for(i=0;i<length;i++)
	{
		cin>>num[i];
	}
	cout<<"Putin the number K which you want to search:";
	cout<<"K=";
	cin>>K;
	result=0;
}

void Search::display()
{
	system("CLS");
	int sel=-1;
	while(sel!=0)
	{
		system("CLS");
        cout<<"\n\n\n";
	    cout<<"\t\t\t���������ѡ��:\n"<<endl;
	    cout<<"\t\t\t����1ֱ�Ӳ���\n"<<endl;
	    cout<<"\t\t\t����2�������ٲ���\n"<<endl;
	    cout<<"\t\t\t����0�˳�"<<endl;
	    cin>>sel;
	    switch (sel)
    	{
	    case 1:
			system("cls");
	        cout<<"ֱ�Ӳ��ң�"<<endl;
			set();
			search(num,length,K);
			if(result==1)
	        {
	    	    cout<<"I can find the K="<<K<<endl;
	        }
			else 
				cout<<"I cannot find the K="<<K<<endl;
			system("pause");
	    	break;
	    case 2:
	    	system("cls");
	        set();
		    cout<<"������Ȼ�����öԷֲ����㷨���в��ң�"<<endl;
		    system("pause");
	        Sort_1();              //�����еĺ���
	        print();              //�����еĺ���
	        result=binsearch(num,length,K);
	        if(result==1)
	        {
	    	    cout<<"I can find the K="<<K<<endl;
	        }
			else 
				cout<<"I cannot find the K="<<K<<endl;
			system("pause");
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
	/*int choice=1;
	while(choice!=0)
	{
		system("cls");
	    set();
		cout<<"������Ȼ�����öԷֲ����㷨���в��ң�"<<endl;
		system("pause");
	    Sort_1();
	    print();
	    result=binsearch(num,length,K);
	    if(result==1)
	    {
	    	cout<<"I can find the K="<<K<<endl;
	    }
		cout<<"�����밴0�������밴1���������֣�"<<endl;
		cin>>choice;
		if(choice==0)
		{
			exit(0);
		}
	}*/
}