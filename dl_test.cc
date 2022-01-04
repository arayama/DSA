#include"doublylinkedlist.h"

int main() 
{
	doublylinkedlist<int> *start=new doublylinkedlist<int>;
	start->putData(10);

	printList(start);
	
	addBack(start,20);
	addBack(start,30);
	addBack(start,40);
	addBack(start,50);
	addFront(&start,500);
	printList(start);
	printReverse(start);

	cout<<addPosition(&start,1,200);
	printList(start);

	cout<<deletePosition(&start,2);
	printList(start);
	
	deleteFront(&start);
	printList(start);
	printReverse(start);
	deleteBack(start);
	printList(start);
	printReverse(start);

	reverse(&start);
	printList(start); 

	cout<<"Search: "<<search(start, 200)<<endl;
	cout<<"Search: "<<search(start, 1000)<<endl;
	
	return 1;	





}
