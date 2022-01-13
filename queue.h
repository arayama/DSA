// this is an implementation of normal queue
//  front points to the front element 
// back points to one element after the current last element 
#include<iostream> 
#define MAXX 40


template <class T>
class queue
{
	T *val; 
	int front, back; 	

	public: 
	queue()
	{
		val=new T [MAXX]; 
		front=-1;
		back=-1; 
	}
	queue(int size)
	{
		val=new T [size]; 
		front=-1;
		back=-1; 
	}	
	
	bool isempty()
	{
		return (front==back); 
	}
	bool isfull()
	{
		return (back >= MAXX);
	}

	bool enqueue(T v) 
	{
		if (isfull()==0)
		{	
			front = (front == -1) ? front + 1 : front; //for the first element
			back  = (back  == -1) ? back  + 1 : back;  // for the first element 
			val[back++]= v;
		}	 
		else 
			return NULL;			
	}

	T dequeue()
	{
		if (isempty()==0)
			return val[front++]; 
		else
			return NULL; 
	}

	T getfront()
	{
		return(val[front]); 
	}
};

