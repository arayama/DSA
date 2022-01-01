/*	 Stack implementation with templates  
	 Allows reset, push, pop, reverse, isfull, isempty 
*/


#include"stack.h"
#include<fstream>
#define MAXX 800000


using namespace std; 


int main()
{
	stack<char> st; 
	ifstream inputf; 
	ofstream outf; 
	std::string str;

	inputf.open("pandp.txt");
	outf.open("pandpr.txt");
	char newline='\n';  
	
	while(getline(inputf,str)) 
	{	for(int i = 0; i< str.length();i++)
			st.push(str[i]);
		st.push(newline);
	}
		
	char c;
	cout<<"Reverse"<<endl;  
	while((c=st.pop()) != NULL) 
		outf<<c; 
	outf<<endl;
 	
	return 1; 
	
 
 	
}

