#include"binarytree.h"



int main()
{
	int arr[]={1,20,3,14,15,6,70,80,90,110,11,120}; 
	binaryTree<int> *root = new binaryTree<int>;
 
	binaryTree<int> *rootbst = new binaryTree<int>;

	int len = sizeof(arr)/sizeof(arr[0]); 
	root=insert(root,arr,0,len);


	for(int i=0;i<len;i++)
		rootbst=insertBST(rootbst,arr[i]);

	cout<<"\nPrint In order : ";
	PrintInOrder(root);	

	cout<<"\nPrint Pre Prder :";
	PrintPreOrder(root); 
	
	cout<<"\nPrint Post Order :";
	PrintPostOrder(root);

	cout<<"\nLevelOrderTravers: ";
	PrintLevelTraverse(root);


	cout<<"\nBST LevelOrderTravers: ";
	PrintLevelTraverse(rootbst);

	cout<<"\nBST Inorder Traverse: ";
	PrintInOrder(rootbst);

	cout<<"\nPrint Pre Prder :";
	PrintPreOrder(rootbst); 

	cout<<"\nBST Postorder Traverse: ";
	PrintPostOrder(rootbst);
	cout<<"\n";

	int findnum=55; 
	binaryTree<int>* res=searchBST(rootbst,findnum);
	if(res==NULL)
		cout<<"Search Failed\n";

	else if(res->getVal() == findnum)
		cout<<"Search Success!!\n";


	rootbst=insertBST(rootbst,55);
	rootbst=insertBST(rootbst,66);

	findnum=55; 
	res=searchBST(rootbst,findnum);
	if(res==NULL)
		cout<<"Search Failed\n";

	else if(res->getVal() == findnum)
		cout<<"Search Success!!\n";


	rootbst=deleteBST(rootbst,0);

	findnum=55; 
	res=searchBST(rootbst,findnum);
	if(res==NULL)
		cout<<"Search Failed\n";

	else if(res->getVal() == findnum)
		cout<<"Search Success!!\n";

	cout<<"\nPrint Pre Prder :";
	PrintPreOrder(rootbst);
	cout<<"\n";
	return 1;	 
}



