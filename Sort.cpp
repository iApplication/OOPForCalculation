#include<iostream>
#include"Sort.h"
#include<cmath>
using namespace std;


Sort::Sort():length(0)
{
	for(int i=0;i<MAX;i++)
		num[i]=0;
	//length=0;
	//count=0;
}
void Sort::set()
{
	int i;
	cout<<"Putin your array length:";
	cin>>length;
	cout<<"Putin your numbers:";
	for(i=0;i<length;i++)
	{
		cin>>num[i];
	}
}

void Sort::swap(int *a,int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

//排序快速
void Sort::Qksort(int rx[],int l, int h)
{
	 static int count2=0;            //由于是本程序是递归调用，所以需要设置局部静态数据来作为中间值，只赋值一次！
     int i,j;
     int x=rx[l];
     i=l;
     j=h;
     while (i<j){
         while ( (i<j) && (rx[j]>=x) )
          {
			  j--;
			  count2++;
		  }
         rx[i] =rx[j];
        while ( (i<j) && (rx[i]<=x) )
          {
			  i++;
			  count2++;
		  }
  	     rx[j]=rx[i];
     }
     rx[i]=x;
     if(l<i-1)
       Qksort(rx,l,i-1);
     if(i+1<h)
       Qksort(rx,i+1,h);
	 count=count2;
   }

//冒泡排序
void Sort::Bsort(int r[], int n)
{
   count=0;
   int  j, k, f=n-1; 
   while(f>=0){ 
     k=f-1;  f=-1;    
     for(j=0;j<=k;j++){
	   count++;
	   if(r[j]>r[j+1])
       {
          swap(&r[j],&r[j+1]);
          f=j;
		  
       }
     }
   }
}

//简单选择排序
void Sort::SelectSort(int r[],int n)
{
  count=0;
  int i,j,k;
  int temp;
  for (i=0;i<n-1;i++){
    j=i;
    for (k=i+1;k<n;k++) 
	{
      if(r[j]>r[k]) 
        j=k;
	  count++;
	}
      if (j>i)
	  {
        swap(&r[i],&r[j]); 
	  }
  }
}

//堆排序
void Sort::Sift(int r[],int n,int k)
{
  int i,j,t;             
  i=k; 
  j=2*i+1; //j为右子树 
  t=r[i];
  while (j<n){
    if (j<n-1&&r[j]<r[j+1]) 
	{
      j++;
	  count++;
	}
    if (t<r[j]){
      r[i]=r[j]; 
      i=j; 
      j=2*i+1; 
	  count++;
    }
  	else break;  
  }
   r[i]=t;
}
void Sort::BSift(int r[],int n)
{
  int p=(n-2)/2,i;
  for (i=p;i>=0;i--)
  {
     Sift(r,n,i);
	 count++;
  }
}
void Sort::HeapSort(int r[], int n)
{
  count=0;
  int i;
  BSift(r,n); 
  for (i=n-1;i>=0;i--){
      swap(&r[0],&r[i]); //最大的放在最后，升序排列;
      Sift(r,i,0);  //调整其余的元素为堆;
	  count++;
  }
}

//插入排序
void Sort::InsertSort(int r[], int n)
{
  int i,j;
  int temp;
  count=0;
  for (i=1;i<n;i++){	 
    temp=r[i]; 
    j=i-1;
	//count++;
    while (temp<r[j]){ 
      r[j+1]=r[j];
      j--;
	  count++;
    }
    r[j+1]=temp;	
  }
}

//希尔排序
void Sort::ShellSort(int r[], int n)
{
    int i,j,k,h;
	int t;
	int m, index;
	int H[50];
	count=0;
	m=(int)(log(n*1.0)/log(2*1.0));
	for(index=0;index<m;index++)
	{
		H[index]=(int)(pow(1.0*2,index));
	}
    while(--index>=0)
    { 
      for(k=0;k<H[index];k++)
       for (i=H[index];i<n;i++){
    	  t=r[i]; 
          j=i-H[index];
		  count++;
           while (t<r[j]&&j>=0)
           { 
             r[j+H[index]]=r[j]; 
             j=j-H[index];
			 count++;
		   }	
             r[j+H[index]]=t;	
       }
    }
   /*方法二
    int i,j,increment;
	int t;
	for(increment=n/2;increment>0;increment/=2)  
       for(i=increment;i<n;i++){
         t=r[i];
         for(j=i;j>=increment;j-=increment)
           if(t<r[j-increment])
             r[j]=r[j-increment];
           else
             break;
           r[j]=t;
       } */ 
    
}

 void Sort::Sort_1()
{
	int sel;
	cout<<"请选择排序方式:"<<endl;
	cout<<" ---- 选择排序:1"<<endl;
	cout<<" ---- 堆排序  :2"<<endl;
	cout<<" ---- 插入排序:3"<<endl;
	cout<<" ---- 希尔排序:4"<<endl;
	cout<<" ---- 冒泡排序:5"<<endl;
	cout<<" ---- 快速排序:6"<<endl;
	cin>>sel;
	//count =0;
	switch(sel)
    {
		case 1:
			SelectSort(num,length);
			cout<<"排序时间长度："<<count<<endl;
			break;
		case 2:
			HeapSort(num,length);
			cout<<"排序时间长度："<<count<<endl;
			break;
		case 3:
			InsertSort(num,length);
			cout<<"排序时间长度："<<count<<endl;
			break;
		case 4:
			ShellSort(num,length);
			cout<<"排序时间长度："<<count<<endl;
			break;
		case 5:
			Bsort(num,length);
			cout<<"排序时间长度："<<count<<endl;
			break;
		case 6:
			Qksort(num, 0,length-1);
			cout<<"排序时间长度："<<count<<endl;
			break;
	}
}
void Sort::print()
{
    int i;
	cout<<"The result after sort is:";
	for(i=0;i<length;i++)
	{
	   cout<<num[i]<<' ';
	}
	cout<<endl;
}


void Sort::display()
{
	int choice=1;
		while(choice!=0)
		{
			system("cls");
	        set();
            Sort_1();
	        print();
			cout<<"结束请按0，继续请按1或其他数字！"<<endl;
			cin>>choice;
			if(choice==0)
			{
				exit(0);
			}
		}
}
