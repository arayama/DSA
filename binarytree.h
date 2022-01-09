// implement a binary tree using linked list like data structure 

#include<iostream>

using namespace std; 

template <class T>
class binarytree
{
	T data; 
    	binarytree<T> *left;
    	binarytree<T> *right;
	
	public:
	binarytree()
	{
	 	this->left=NULL:
		this->right=NULL; 
	}

	binarytree(T val)
	{	
		this->data=val;
		this->left=NULL:
		this->right=NULL:
	}
	void putVal(T val) { this-> data = val; }
	T getVal() { return this->data; }
	binarytree* getLeft(){ return this->left; }
	void putLeft(binarytree* n) { this->left = n; }
	binarytree* getRight(){ return this->right; } 
	void putRight(binarytree *n) { this-> right = n; }
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
	int child =0; 
	
	binaryTree<T> temp = node;
	child += (node->getLeft() == NULL) ? 0:1; 
	child += (node->getRight() == NULL) ? 0:1; 

	if 

}

template <class T> 
binaryTree<T>* insert(binarytree<T> *node, T val,int height) 
{
	// check if node is null -> val 
	// check if left is null, 
		// if left is not null, check if right is null, 
		// if right is null -> val to left 
		
	if (*node == NULL)
	{
		binarytree<T> *n = new binarytree <T>; 
		n->putval(val); 
		return n;
	}
	
	
	// check if the left and right side of the node are perfect trees. 
	// using height to find number of nodes on each side of the node
	// perfect left and right tree should have 2^(height-1) nodes 
	if (isPerfect((*node)->getLeft(),height) == false)
		insert((*node)->getLeft(),val, height+1);
	else if (isPerfect((*node)->getRight(),height) == false)
		insert((*node)->getRight(),val, height+1);
	else 
		insert((*node)->getLeft(),val, height+1);
		
}

