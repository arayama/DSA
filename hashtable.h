// implementation of hash table 
// using array of doubly linked list to represent each node in a hash table. 
// using chain rule to break collision 

#include"linkedlist.h"
#include<iostream>
#define N 1024
template<class T>
class hashtable
{
    	doublylinkedlist<T> **table; // list of lists
    	unsigned int k;  // index identifies the location of value 
    
    	public:
	hastable()
	{
		**table=new doublylinkedlist<T>* [N]; 
		for(int i=0;i<N;i++)
			table[i] = new doublylinkedlist<T>; 
		k=0; 
	}


	hashtable(int size)
	{
		**table=new doublylinkedlist<T>* [size]; 
		for(int i=0;i<size;i++)
			table[i] = new doublylinkedlist<T>; 
		k=0; 
	}

	void insertKey(unsigned int k);
	void deleteKey(unsigned int k); 
	T getKey(unsigned int k);
};


template <class T>
void insertkey(unsigned int k)
{
	
	


}

