
#include"linkedlist.h"



int main()
{
	linkedlist<int> *start= new linkedlist<int>;
	start->putData(10); 
	printList(start);

	addBack(start,20); 
	addBack(start,30);
	addBack(start,40);
	addBack(start,50);
	printList(start);	

	reverse(&start);
	printList(start); 
	

	addFront(&start,100);
	addFront(&start,200);
	printList(start);

	cout<<addPosition(&start, 0, 500);
	printList(start);

	sort(&start);
	printList(start); 
	
	deleteFront(&start); 
	printList(start);

	deleteBack(start);
	printList(start);

	deleteFront(&start); 
	printList(start);

	deleteBack(start);
	printList(start);

	cout<<deletePosition(&start, 2);
	printList(start);
	
	reverse(&start);
	printList(start); 
	
	sort(&start); 
	printList(start);
	
	return 1;

}
