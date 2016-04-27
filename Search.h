#ifndef SEARCH_H
#define SEARCH_H

class Search: public Sort
{
private:
	int K;
	int result;
public:
	Search(int k=0,int resu=0):Sort()
	{
		K=k;
		result=resu;
	}
	int binsearch(int r[],int n,int k);
	int search(int r[],int n,int k);
	void set();  //redefine¸¸Ààº¯Êı
	void display();

};

#endif