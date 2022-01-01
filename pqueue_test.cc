#include"priorityqueue.h"




int main()
{
	priorityqueue<int> pqu; 
	int num=100; 
	for(int i=0;i<20;i++)
		pqu.insert(i); 

	pqu.print();  

	pqu.extract();
	pqu.print(); 
	
	pqu.extract();
	pqu.print(); 

	pqu.extract();
	pqu.print(); 

	pqu.extract();
	pqu.print(); 



	return 1; 
}
