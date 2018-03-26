#include <iostream>		//For input output
#include <string>		//For strings
#include <vector>		//For Vectors
#include <algorithm>	//To sort vectors and arrays, refer lec 8 of CS213
#include <map>			//To use maps
#include <fstream>

using namespace std;

///////////////////////////////Initialising a tree///////////////////////////////

struct Node
{
	char op; 								// operator associated with node if any
	string value; 							// value associated with node, if any
	Node* L; 								// pointer to left subformula, if any
	Node* R; 								// pointer to right subformula, if any
	Node(char op1, Node* L1, Node* R1);
	Node(string v);
	Node(fstream &infile);
};

///////////////////////////////Constructors///////////////////////////////

Node::Node(char op1, Node* L1, Node* R1)
{
	op = op1;
	L = L1;
	R = R1;
}

Node::Node(string v)
{
	value = v;
	op = 'P'; 							// 'P' denotes primitive formula
	L = R = NULL ;						// No subformulae.
}

Node::Node(fstream &infile)
{
	char c=infile.get();
	if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		L=R=NULL;
		op='P';
		value = c;
	}
	else if(c == '(')
	{
		L = new Node(infile);
		op = infile.get();
		R = new Node(infile);
		if(infile.get() != ')')
		cout << "No matching parenthesis.\n";
	}
	else
		cout << "Error in input.\n";
}

///////////////////////////////Functions///////////////////////////////

//To check if the 2 formulae are same or not
bool compare(Node* a, Node* b)
{
	if (a==NULL || b==NULL)
	{
		return false;
	}
	else if (a->op=='P' && b->op=='P')
	{
		if (a->value==b->value)
		{
			return true;
		}
		else
			return false;
	}
	else if (a->op=='/' && b->op=='/')
	{
		return ( compare(a->R,b->R) && compare(a->L,b->L) );
	}
	else if (a->op=='+' && b->op=='+')
	{
		return( (compare(a->R,b->R) && compare(a->L,b->L)) || (compare(a->L,b->R) && compare(a->R,b->L)) );
	}
	else
		return false;
}


///////////////////////////////Main///////////////////////////////

int main()
{
	fstream file;
	file.open("tc1.in",fstream::in);			//Reading the input file
	Node *formula1 = new Node(file);
	Node *formula2 = new Node(file);
	cout<<compare(formula1,formula2)<<endl;		//Comparing the 2 formulae

}
