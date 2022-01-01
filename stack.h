/*	 Stack implementation with templates  
	 Allows reset, push, pop, reverse, isfull, isempty 
*/


#include<iostream>
#include<stdlib.h>
#include<string.h>
#define MAXX 800000


using namespace std; 


template <class T>
class stack 
{
	private:
		T *val;
		int top;
	public:

	stack()
	{
		top=-1; 
		val=new T [MAXX]; 
		cout<<"inside default\n"; 
	}

	stack(int size)
	{
		top=-1; 
		val=new T [size]; 	
		cout<<"inside second \n"; 
	}

	~stack()
	{
		delete[] val; 
	}
	
	bool isfull()
	{
		return (top>=MAXX-1);
	}

	bool isempty()
	{
		return (top<=-1); 
	}
 
	void reset()
	{
		top=-1; 	
	}

	bool push(T v)
	{
		if (isfull()==0)
		{
			val[++top]=v; 
			return true;
		}
		else 
		{	//std::cout<<"stack Full!!\n"; 
			return false; 
		} 
	}
	
	T pop()
	{
		if(isempty()==0)
		{
			return val[top--]; 
		}
		else
		{
			//std::cout<<"stack Empty!!\n"; 
			return NULL;
		}		
	}

}; 


