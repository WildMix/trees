#ifndef _BIN_TREE_H
#define _BIN_TREE_H


#include <iostream>
#include <cstddef>
#include <vector>

#define COUNT 10

std::vector<int> v;



template <class T>
class bin_tree 
{

	private:

		struct Node
		{
		
			T data;
			
			Node *right;
			
			Node *left;
		
			Node *parent;
		
		};

		Node* root;
		
		int numNodes;
		
		//int height;


	public:
	
		bin_tree(T value)
		{
		
			root = new Node;
		
			root->data = value;
			
			root->right = NULL;
		
			root->left = NULL;
			
			root->parent = NULL;
		
			numNodes = 1;
			
			//height = 1;
		
		}
		
		~bin_tree()
		{
		
			//deleteTree(root);
		
		}
		
		void deleteTree(Node * r)
		{
		
			  if (r == NULL)  
			
				return;  
		  
		   
		     
		    deleteTree(r->right);  
		    
		    if (r != root)
		    {
		    	
		    	if (sideNode(r))
		    	
		    
		    		r->parent->left = NULL;
		    		
		    	else
		    	
		    		r->parent->right = NULL;
		    
		    }
		    
		  
		    
		    delete r;
		    
		    deleteTree(r->left);  
		
		}
		
		int getHeight (Node* start, Node *end)	
		{
		
			int h = 1;
			
			if (end == start)
			
				return 0;
			
			Node * temp = end;
			
			while (temp->parent != start)
			{
			
				temp = temp->parent;
				
				h++;
			
			}
			
			return h + 1;
		
		}	
		
		int max (std::vector<int> a)
		{
		
			int i = 0;
			
			int m = a[i];
			
			for (i = 0; i < v.size(); ++i)
			{
			
				if (a[i] > m)
				
					m = a[i];
			
			}
			
			return m;
		
		}
		
		void getDephtUtil(Node * temp)
		{
		
			 if (temp == NULL)  
			
				return;  
		  
		   
		    getDephtUtil(temp->right);  
		  
		    v.push_back(getHeight(root,temp));
		  
		    getDephtUtil(temp->left);  
			
		}
		
		
		int getDepht()
		{
		
			getDephtUtil(root);
		
			return (max(v));
					
		}
		
		
		
		
		
		Node* createNode(T value,Node * left, Node * right ,Node * parent)
		{
		
			Node* newNode = new Node;
		
			newNode->data = value;
			
			newNode->left = left;
			
			newNode->right = right;
			
			newNode->parent = parent;
			
			return newNode;
		
		}
		
		void insert(Node* node, T value)
		{
		
			node->data = value;
		
		}
		
		void insLeft(Node* node,T value)
		{
		
			node->left = createNode(value,NULL,NULL,node);
		
			numNodes ++;
		
		}
	
		
		void insRight(Node* node,T value)
		{
		
			node->right = createNode(value,NULL,NULL,node);
		
			numNodes ++;
		
		}
			
		Node* getRoot()
		{
		
			return root;
		
		}
		
		void insSubTree(Node * ins, Node * dest, bool side)
		{
		
			if (side)
				
				insNodeLeft(ins,dest);
			
			else
			
				insNodeRight(ins,dest);
			

		
		}
		
		
		void insNodeLeft(Node * ins, Node * dest)
		{
		
		
			dest->left = new Node;
			
			dest->left = ins;
		
		
		}
		
		
		void insNodeRight(Node * ins, Node * dest)
		{
		
		
			dest->right = new Node;
			
			dest->right = ins;
		
		
		}
		
		
		void print2DUtil(Node *r,int space)  
		{  
		
		    if (r == NULL)  
			return;  
		  
		   
		     space += COUNT;  
		  
		    print2DUtil(r->right, space);  
		  
		    std::cout<<"\n";
		      
		    for (int i = COUNT; i < space; i++)  
			
			std::cout<<" ";
			  
		    std::cout<<r->data<<"\n";  
		  
		    print2DUtil(r->left, space);  
		}  
		  
		void print()  
		{  
		
		    print2DUtil(root, 0);  
		
		}  
			
		
		bool emptyTree()
		{
		
			return (root == NULL);
		
		}
		
		bool emptyNode(Node* n)
		{
		
			return (n == NULL);
		
		}
		
		bool emptyLeftNode(Node* n)
		{
		
			return (emptyNode(n->left));
		
		}
		
		
		bool emptyRightNode(Node* n)
		{
		
			return (emptyNode(n->right));
		
		}
		
		
		bool sideNode(Node *n)	//true if is left, false if is right
		{
		
		
			return (n->parent->left == n);
		
		}
		
		
		
		void deleteNode(Node *n,bool side)
		{
			
			if (side)
			
				n->parent->left = NULL;
		
			else
			
				n->parent->right = NULL;
			
		
			
		
			delete n;
		
		}
		
		
		void freeSubTree(Node *n)
		{
		
			
			deleteNode(n,sideNode(n));
			
			
		
		}
		
		
		bool isChild(Node * parent, Node * child)
		{
		
			if (parent->left == child || parent->right == child)
				
				return true;
			
			return false;
		
		}
		
		
		
		Node* parent(Node* n)
		{
		
			return n->parent;
		
		}
				
		Node* leftNode(Node *n)
		{
		
			return n->left;
		
		}
		
		
		Node* rightNode(Node *n)
		{
		
			return n->right;
		
		}


};



#endif
