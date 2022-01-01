// this is an implementation of normal queue
//  front points to the front element 
// back points to the last element that can be pulled out
#include<iostream> 
#define MAXX 10
using namespace std;

template <class T>
class cqueue
{
	T *val; 
	int front, back; 	
	int LEN; 
	public: 
	cqueue()
	{
		val=new T [MAXX]; 
		front=-1;
		back=-1; 
		LEN=MAXX; 
	}
	cqueue(int size)
	{
		val=new T [size]; 
		front=-1;
		back=-1; 
		LEN=size; 
	}	

	~cqueue()
	{
		delete [] val; 
	}
	
	void reset()
	{
		front=-1; 
		back=-1; 
	}
	int getfront()
	{	return front;
	}
	int getback()
	{
		return back;
	}
	bool isempty()
	{
		return  front==-1;  
	}
	bool isfull()
	{
		return (front == (back  + 1)%LEN); 
	}

	bool enqueue(T v) 
	{
		if (isfull()==0)
		{	
			front = (front == -1) ? front + 1 : front; //for the first element
			back=(back+1)%LEN;
			val[back]=v;
		}	 
		else 
			return NULL;			
	}

	T dequeue()
	{
		if (isempty()==0)
		{	T out = val[front]; 
			front = (front+1)%LEN;  
			
			if(front == (back + 1)%LEN)
			{
				front=-1;
				back=-1;
			}
			return out; 
		}
		else
			return NULL;	
	}

};

