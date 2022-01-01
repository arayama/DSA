// Implementation of priority queue with max heap 


#include<iostream> 
#include<vector>
using namespace std; 

template <class T>
class priorityqueue
{
	vector<T> val; // implemented as a vector 
			// allows runtime flexible vector resizing
	public:
	priorityqueue()
	{
		
	}

	priorityqueue(T *arr)
	{
		typename vector<T>::iterator itr=val.begin(); 
		
		while(itr != val.end())
			*(itr++)=*(arr++); 
		
		heapify(); 
	}
	
 	void heapify();
	bool swap(int i, int j)
	{
		T temp=val[i]; 
		val[i]=val[j];
		val[j]=temp; 
	}

	T peek()
	{
		return val.front(); 
	}
 
	T extract()
	{
		int end= val.size()-1; 
		swap(0,end);
		T temp= val.back(); 
		val.pop_back();
		heapify();
		return temp;  
	}
	void insert(T v)
	{	
		if(val.size()==0)
			val.push_back(v); 
		else
		{	val.push_back(v); 	
			heapify(); 
		}
	}
	void print()
	{
		typename vector<T>::iterator itr=val.begin();
		while(itr != val.end())
			cout<<*(itr++)<<" "; 

		cout<<endl; 
	}


	void traverse(int loc); 

};

template <class T>
void priorityqueue<T>:: traverse(int loc)
{
	int largest=loc;
	int left= loc*2+1; 
	int right = loc*2+2; 

	if(val[loc]<val[left] && (left < val.size()))
	{	swap(loc,left); 
		largest=left; 
	}
	if((val[loc] < val[right]) && (right < val.size())) // check if its a complete binary tree
	{	swap(loc,right); 
		largest=right; 
	}

	if(largest != loc)
	{	
		//swap(loc,largest); 
		traverse(largest); 
	}		
}

template <class T>
void priorityqueue<T>:: heapify()
{
	int ind = (val.size()-1)/2; 
	while(ind >=0)
	{
		traverse(ind--); 
	}
}
