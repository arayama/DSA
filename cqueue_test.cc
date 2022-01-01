#include"circularqueue.h"


using namespace std; 


int main()
{
	cqueue<char> cqu(20);
	string test="thebrownfoxjumpedovertheheapofshit";  
	char ch; 
	cout<<test<<endl; 
	
	for (int i = 0;i <test.length();i++) 
	{	if(cqu.enqueue(test[i]) == NULL)
			break; 
	}
			
  	cout<<endl;		
	
	int i=0;

	while(i++<5)
	{
		cqu.dequeue();
	}
	

	for (int i = 0;i <test.length();i++) 
	{	cout<<cqu.getfront()<<"  "<<cqu.getback()<<endl;
		if(cqu.enqueue(test[i]) == NULL)
			break;
	}



	while((ch=cqu.dequeue()) != NULL)
		cout<<ch;
	cout<<endl;
		
	return 1; 


}
