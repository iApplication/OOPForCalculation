#ifndef SORT_H
#define SORT_H
const int MAX=100;
class Sort
{
protected:    //以便于继承之后调用这些值
    int num[MAX];
	int length;
    int count;    //可以用static实现一下！！！
public:
	Sort();
    void set();
    void swap(int *a,int *b);

    //排序快速
    void Qksort(int rx[],int l, int h);

    //冒泡排序
    void Bsort(int r[], int n);

    //简单选择排序
    void SelectSort(int r[],int n);

    //堆排序
   void Sift(int r[],int n,int k);
   void BSift(int r[],int n);
   void HeapSort(int r[], int n);

    //插入排序
    void InsertSort(int r[], int n);

    //希尔排序
    void ShellSort(int r[], int n);

    void Sort_1();
	void print();
	void display();
};
//int Sort::count=0;
#endif