#include"queue.h"


using namespace std; 


int main()
{
	queue<char> qu;
	string test="the brownfox jumped over the heap of shit";  
	char ch; 
	cout<<test<<endl; 

	for (int i = 0;i <test.length();i++) 
		if(qu.enqueue(test[i])==NULL)
			cout<<"Queue is full\n";
	
	int i=0;

	while(i++<9)
	{
		if(qu.dequeue()==NULL)
			cout<<"Queue is empty\n"; 
	}


	while((ch=qu.dequeue()) != NULL)
		cout<<ch;
	cout<<endl;


	return 1; 


}
