// implementing a doubly linked list 
#include<iostream>


using namespace std; 

template <class T>
class doublylinkedlist
{
    T data;
    doublylinkedlist *next; 
    doublylinkedlist *prev; 

    public:
    
    doublylinkedlist()
    {
        this->next=NULL; 
        this->prev=NULL; 
    }
    doublylinkedlist(T val)
    {
        this->data=val; 
        this->next=NULL; 
        this->prev=NULL; 
    }
    void setNext(doublylinkedlist <T>* next)
    {
        this->next=next; 
    }

    void setPrev(doublylinkedlist <T>* prev)
    {
        this->prev=prev;
    }

    doublylinkedlist<T>* getNext()
    {
        return(this->next);
    }

    doublylinkedlist<T>* getPrev()
    {
        return this->prev; 
    }

    T getData()
    {
        return(this->data); 
    }

    void putData(T val)
    {
        this->data=val; 
    }
};


template <class T>
void addFront(doublylinkedlist<T> **start,T val)
{
    doublylinkedlist<T> *temp = new doublylinkedlist<T>;
    temp->putData(val); 
    
    temp->setNext(*start); 
    (*start)->setPrev(temp); 
    *start=temp;    
}


template <class T>
string addPosition(doublylinkedlist <T> **start, int position, T val)
{
    doublylinkedlist<T> *temp=*start;

    for(int i=0;i!=position;i++)
    {
        if (temp== NULL)
            return("Error finding valid node at the position\n"); 
        temp=temp->getNext();
    }
    doublylinkedlist<T> *node=new doublylinkedlist<T>;
    node->putData(val);

    node->setNext(temp); 
    node->setPrev(temp->getPrev()); 
    temp->getPrev()->setNext(node);	
    temp->setPrev(node); 

    return(""); 
}

template <class T>
void addBack(doublylinkedlist <T> *start,T val)
{
	doublylinkedlist <T> *list = start; 
	doublylinkedlist <T> *temp=new doublylinkedlist<T>;
	temp->putData(val);	
	
	while(list->getNext() !=NULL)
	{
		list=list->getNext(); 
	}	

	list->setNext(temp); 
	temp->setPrev(list); 
}

template <class T>
void deleteFront(doublylinkedlist <T> **start)
{
	*start = (*start)->getNext(); 
	(*start)->setPrev(NULL);
}


template <class T> 
void deleteBack(doublylinkedlist <T> *start)
{
	doublylinkedlist <T> *temp=start; 
	
	while(temp->getNext() != NULL)
		temp=temp->getNext(); 
	temp->getPrev()->setNext(NULL); 
	free(temp); 
}

template <class T>
string deletePosition(doublylinkedlist <T> **start, int position)
{
	doublylinkedlist <T> *temp = *start; 
	
	for(int i=0;i!=position;i++)
	{
		if(temp==NULL)
			return("Error finding valid node at position\n");
		temp=temp->getNext();
	}
	
	temp->getNext()->setPrev(temp->getPrev()); 
	temp->getPrev()->setNext(temp->getNext());
	free(temp); 
	return("");
}

template <class T>
void reverse(doublylinkedlist <T> **start)
{
	doublylinkedlist <T> *node = *start; 
	
	while(node->getNext() != NULL)
	{
		
		doublylinkedlist <T> *temp = node->getNext();
		node->setNext(node->getPrev());
		node->setPrev(temp); 
		node=temp; 
	}
	node->setNext(node->getPrev());
	node->setPrev(NULL);	
	*start=node;
}

template <class T> 
bool  search(doublylinkedlist<T> *start, T val)
{
	doublylinkedlist<T> *node = start;

	while(node != NULL)
	{
		if(node->getData() == val)
			return true;
		node=node->getNext();
	}
	return false;
}


template <class T>
void printList(doublylinkedlist<T> *start)
{
        doublylinkedlist <T> *list = start;
        do
        {
                cout<<list->getData()<<"  ";
                list = list->getNext();
        }while(list != NULL);
        cout<<endl;
}

template <class T>
void printReverse(doublylinkedlist<T> *start)
{
        doublylinkedlist <T> *list = start;
        while(list->getNext() != NULL)
	{
		list=list->getNext();
	}
        
	while(list != NULL)
	{
		cout<<list->getData()<<"  ";
		list=list->getPrev(); 
	}
	cout<<endl; 
}
