#ifndef SORT_H
#define SORT_H
const int MAX=100;
class Sort
{
protected:    //�Ա��ڼ̳�֮�������Щֵ
    int num[MAX];
	int length;
    int count;    //������staticʵ��һ�£�����
public:
	Sort();
    void set();
    void swap(int *a,int *b);

    //�������
    void Qksort(int rx[],int l, int h);

    //ð������
    void Bsort(int r[], int n);

    //��ѡ������
    void SelectSort(int r[],int n);

    //������
   void Sift(int r[],int n,int k);
   void BSift(int r[],int n);
   void HeapSort(int r[], int n);

    //��������
    void InsertSort(int r[], int n);

    //ϣ������
    void ShellSort(int r[], int n);

    void Sort_1();
	void print();
	void display();
};
//int Sort::count=0;
#endif