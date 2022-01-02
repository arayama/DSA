// implementing linkedlist singly ended 


#include<iostream>


using namespace std; 


template <class T>
class linkedlist
{
	T data; 
	linkedlist *next; 

	public:
	linkedlist()
	{
		this->next = NULL;
	}
	linkedlist(T d)
	{
		this->data=d; 
		this->next = NULL;
	}

	~linkedlist()
	{
		delete next; 
	}
	
	linkedlist<T>* getNext()
	{
		return this->next;
	}
	void setNext(linkedlist<T> *there)
	{
		this->next = there; 
	}

	linkedlist<T>& getAddress()
	{
		return(this); 
	}

	T getData()
	{
		return(this->data); 
	}
	void putData(T v)
	{
		this->data=v; 
	}
}; 

template <class T>
void addFront (linkedlist <T> **start, T val)
{
	linkedlist<T> *temp=new linkedlist<T>;
	temp->putData(val); 
	temp->setNext(*start);
	*start=temp; 
}

template <class T>
string addPosition(linkedlist <T> **start, int position, T val)
{
	linkedlist<T> *temp = *start; 
	
	for(int i=0;i!=position;i++)
	{
		if(temp == NULL) 
			return("Error finding valid node at the position\n"); 
		temp=temp->getNext(); 
	}

	linkedlist<T> *node = new linkedlist <T>; 
	node->putData(val); 
	node->setNext(temp->getNext()); 
	temp->setNext(node); 
	return(""); 
}

template <class T>
void addBack(linkedlist <T> *start, T val)
{
	linkedlist <T> *list = start; 
	linkedlist <T> *temp=new linkedlist<T>;
	temp->putData(val); 
	while(list->getNext() != NULL)
		list=list->getNext(); 
	list->setNext(temp); 
}

template <class T>
void deleteFront(linkedlist <T> **start) 
{	linkedlist <T> *temp = (*start); 

	*start=temp->getNext(); 

	free(temp); 
}

template <class T>
void deleteBack(linkedlist <T> *start)
{
	linkedlist <T> *list= start; 
	while(list->getNext()->getNext() != NULL)
		list=list->getNext(); 
	free(list->getNext()); 
	list->setNext(NULL); 
}

template <class T>
string deletePosition(linkedlist <T> **start, int position)
{
	linkedlist <T> *list = *start; 
	
	for(int i=0;i!=position;i++)
	{
		if(list == NULL) 
			return("Error finding valid node at position\n"); 
		list=list->getNext(); 
	}
	
	if(list->getNext() == NULL) 
	{	return("Unable to find valid nodes after the position\n");  
	}
	else 
	{
		linkedlist<T> *temp=list->getNext()->getNext();
		free(list->getNext()); 
		list->setNext(temp); 
		return("");
	}
}

template <class T> 
void reverse(linkedlist <T> **start)
{
	linkedlist <T> *rev=new linkedlist<T>;
	linkedlist <T> *list= *start; 
	rev->putData(list->getData());
	list=list->getNext();
		
	while(list != NULL) 
	{
		addFront(&rev,list->getData());
		list=list->getNext();  
	}
	
	*start=rev; 

}

template <class T>
void sort(linkedlist <T> **start) // increasing order 
{
	linkedlist <T> *i=*start; 
 
	while(i != NULL)
	{	linkedlist <T> *j = i->getNext(); 
		while(j != NULL)
		{
			if(i->getData() > j->getData())
			{
				T temp = i->getData();
				i->putData(j->getData());
				j->putData(temp); 
			}
			j=j->getNext();
		}
		i=i->getNext(); 
	}

}



template <class T>
void printList(linkedlist <T> *start)
{
	linkedlist <T> *list = start; 
	do
	{ 
		cout<<list->getData()<<"  ";
		list = list->getNext();
	}while(list != NULL); 
	cout<<endl;
}



