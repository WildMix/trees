#ifndef _TREE_H
#define _TREE_H
#include <iostream>
#include <vector>
template <class T>

#define COUNT 10

class tree
{

	private:
	
		struct Node
		{
		
			T data;
			
			Node *parent;
			
			std::vector<Node*> childs;
		
		};
		
		Node * root;
		
		int numNodes;
		
	public:

		tree()
		{
		
			root = new Node;
		
			root->data = 0;
			
			root->parent = NULL;
			
			numNodes = 1;
		
		}
		
		tree(T value)
		{
		
			root = new Node;
		
			root->data = value;
			
			root->parent = NULL;
			
			numNodes = 1;
			
		
		}
		
		void insRoot (T value)
		{
		
			root->data = value;
		
		}
		
		bool isRoot(Node * node)
		{
		
			return (node == root);
		
		}
		
		bool isLeaf(Node * node)
		{
		
			if (!isRoot(node))
			
				return (node->childs.empty());
		
			return false;
		
		}
		
		Node * getFirstChild(Node * node)
		{
		
			if (!isLeaf(node))
			
				return node->childs[0];
				
			return node;
		
		}
		
		Node * lastBrother(Node * node)
		{
		
			if (!isRoot(node))
			{
			
				typename std::vector<Node*>::iterator it = node->parent->childs.end();
				
				int i = it - node->parent->childs.begin();
				
				return node->parent->childs[i];
			
			}
			
			return NULL;
		
		}
		
		int getPositionNode(Node * node)
		{
		
			if (!isRoot(node))
			{
			
				Node * parent = node->parent;
				
				int i;
				
				for(typename std::vector<Node*>::iterator it = parent->childs.begin(); it != parent->childs.end(); ++it)
				{
				
					i = it - parent->childs.begin();
				
					if (parent->childs[i] == node)
					
						return i;
				
				}
			
			}
			
			return 1;
		
		}
		
		Node * nextBrother(Node * node)
		{
		
			if (!isRoot(node))
			{
			
				if (getPositionNode(node) == node->parent->childs.size())
				
					return NULL;
			
				return node->parent->childs[getPositionNode(node) + 1];
			
			}
			
			return node;
		
		
		}
		
		void insChild (Node * n, T value)
		{
		
			Node * newNode = new Node;
		
			newNode->data = value;
			
			newNode->parent = n;
			
			n->childs.push_back(newNode);
			
			numNodes ++;
		
		}
		
		Node* getChild (Node * parent, std::vector<Node*> it)
		{
		
			return parent->childs.at(it);
		
		}
		
		Node * getParent (Node * child)
		{
		
			return (child->parent);
		
		}

		Node * getRoot()
		{
		
			return root;
		
		}

		void print()
		{
						
			std::cout << "\n" << root->data << "\n";
		
			printUtil(root,0);
		
		}
		
		void printUtil(Node * r,int space)
		{
		
			int i;
			
			space += COUNT;  
		  
		  	
		       for (int j = COUNT; j < space; j++)  
			
			    std::cout<<" ";
			  
		    

			for(typename std::vector<Node*>::iterator it = r->childs.begin(); it != r->childs.end(); ++it)
			{
				
				i = it - r->childs.begin();
			
				std::cout << "\n" << r->childs[i]->data << "\n";
				
				if (!r->childs[i]->childs.empty())
				
					printUtil(r->childs[i],space);
				
				
			}
				
		}

};




#endif
