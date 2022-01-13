// implement a binary tree using linked list like data structure 
#include<iostream>
#include"queue.h"
using namespace std; 

template <class T>
class binaryTree
{
	T data; 
    	binaryTree<T> *left;
    	binaryTree<T> *right;
	
	public:
	binaryTree()
	{
	 	this->left=NULL;
		this->right=NULL; 
	}

	binaryTree(T val)
	{	
		this->data=val;
		this->left=NULL;
		this->right=NULL;
	}
	void putVal(T val) { this-> data = val; }
	T getVal() { return this->data; }
	binaryTree* getLeft(){ return this->left; }
	void setLeft(binaryTree* n) { this->left = n; }
	binaryTree* getRight(){ return this->right; } 
	void setRight(binaryTree *n) { this-> right = n; }
};

template <class T>
int findDepth(binaryTree<T>* node)
{	
	int d=0;
	binaryTree<T>* temp = node; 
	while(node != NULL)
	{
		d++;
		node=node->getLeft();
	}
	return d; 
}

template <class T>
bool isPerfect(binaryTree<T> *node,int h)
{
	// this function will look for lett and right side of this node. 
	// It will check if the two sides are perfect 
	// if they are not perfect, it will return the pointer that is not perfect 
	int child =0; 
	
	binaryTree<T> temp = node;
	child += (node->getLeft() == NULL) ? 0:1; 
	child += (node->getRight() == NULL) ? 0:1; 

//	if
}

template <class T>
binaryTree<T>* insertBST(binaryTree<T> *root, T val)
{
	if (root == nullptr)
	{
		binaryTree<T> *node = new binaryTree <T>; 
		node->putVal(val); 
		return node; 
	}

	if(root->getVal() > val)
		root->setLeft(insertBST(root->getLeft(),val));
	else if(root->getVal() < val)
		root->setRight(insertBST(root->getRight(),val));

	return root; 
}

template <class T>
binaryTree<T>* searchBST(binaryTree<T>* root,T val)
{
	if (root==NULL || root->getVal()==val)
		return root; 

	else if(root->getVal() > val)
		return searchBST(root->getLeft(),val); 
	else 
		return searchBST(root->getRight(),val);
}


template <class T> 
binaryTree<T>* insert(binaryTree<T> *root,T arr[], int i, int n) 
{
	if(i<n) 
	{
		binaryTree<T> *node = new binaryTree <T>; 
		node->putVal(arr[i]); 
		root=node; 

		root->setLeft(insert(root->getLeft(), arr,2*i+1, n));
		root->setRight(insert(root->getRight(),arr,2*i+2,n));
	
	}
	return root; 
}



template <class T>
void PrintLevelTraverse(binaryTree<T>* root)
{ // using queue to pring leveltraverse 

	queue <binaryTree<T>*> que;
   	binaryTree<T> *item;
   	que.enqueue(root); 
   	while(!que.isempty()){
		   
      		item = que.getfront(); 
      		cout << item->getVal() << " ";
      		if(item->getLeft() != NULL)
         		que.enqueue(item->getLeft());
      		if(item->getRight() != NULL)
         		que.enqueue(item->getRight());
      		que.dequeue(); //remove the item from queue
   	} 
}

template <class T>
void PrintInOrder(binaryTree<T> *root)
{
    if (root != NULL)
    {
        PrintInOrder(root->getLeft());
        cout << root->getVal() <<" ";
        PrintInOrder(root->getRight());
    }
}

template <class T>
void PrintPreOrder(binaryTree<T> *root)
{
    if (root != NULL)
    {
		cout<< root->getVal() << " "; 
        PrintPreOrder(root->getLeft());
        PrintPreOrder(root->getRight());
    }
}

template <class T>
void PrintPostOrder(binaryTree<T> *root)
{
    if (root != NULL)
    {
        PrintPostOrder(root->getLeft());
        PrintPostOrder(root->getRight());
		cout<< root->getVal() << " "; 
    }
}

template <class T>
binaryTree<T>* findInorderMinValue(binaryTree<T> *node) 
{
	binaryTree<T> *current = node;
	while (current != NULL && current->getLeft() != NULL)
    	current = current->getLeft();
	
	return current;
}

template <class T>
binaryTree<T>* deleteBST(binaryTree<T>* root, T val)
{
	if (root == NULL) return root;

 	if (val < root->getVal())
    	root->setLeft(deleteBST(root->getLeft(), val));
  	else if (val > root->getVal())
    	root->setRight(deleteBST(root->getRight(), val));
  	else  //the val has been found
	{
    	if (root->getLeft() == NULL) 
		{
      		binaryTree<T>* temp = root->getRight();
      		free(root);
      		return temp;
		} 
		else if (root->getRight() == NULL) 
		{
      		binaryTree<T> *temp = root->getLeft();
      		free(root);
      		return temp;
    	}
    binaryTree<T> *temp = findInorderMinValue(root->getRight());
    root->putVal(temp->getVal());
    root->setRight(deleteBST(root->getRight(), temp->getVal()));
  }
  return root;

}


