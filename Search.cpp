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

void Search::set()    //继承之后又重载
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
	    cout<<"\t\t\t请输入你的选择:\n"<<endl;
	    cout<<"\t\t\t输入1直接查找\n"<<endl;
	    cout<<"\t\t\t输入2先排序再查找\n"<<endl;
	    cout<<"\t\t\t输入0退出"<<endl;
	    cin>>sel;
	    switch (sel)
    	{
	    case 1:
			system("cls");
	        cout<<"直接查找！"<<endl;
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
		    cout<<"先排序，然后利用对分查找算法进行查找！"<<endl;
		    system("pause");
	        Sort_1();              //基类中的函数
	        print();              //基类中的函数
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
		    cout<<"退出"<<endl;
		    exit(0);
		    break;
        default:
            cout<<"请输入正确的数！"<<endl;
            break;
	    }
	}
	/*int choice=1;
	while(choice!=0)
	{
		system("cls");
	    set();
		cout<<"先排序，然后利用对分查找算法进行查找！"<<endl;
		system("pause");
	    Sort_1();
	    print();
	    result=binsearch(num,length,K);
	    if(result==1)
	    {
	    	cout<<"I can find the K="<<K<<endl;
	    }
		cout<<"结束请按0，继续请按1或其他数字！"<<endl;
		cin>>choice;
		if(choice==0)
		{
			exit(0);
		}
	}*/
}