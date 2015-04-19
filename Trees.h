#ifndef __TREES_H__
#define __TREES_H__

#include "DList.h"
#include "Stack.h"
#include <math.h>

template<class TREEDATA>
struct tree_node
{
	TREEDATA data;
	tree_node<TREEDATA> *parent;
	DList<tree_node*> children;

	tree_node<TREEDATA>(const TREEDATA &new_data)
	{
		data = new_data;
		parent = NULL;
	}

	void preOrderRecursive(DList<tree_node<TREEDATA>*> *list) 
	{
		list->add(this);
		printf("%c", data);

		doubleNode<tree_node*> *item = children.getFirst();

		for (; item != NULL; item = item->next)
		{
			item->value->preOrderRecursive(list);
		}		
	}

	void postOrderRecursive(DList<tree_node<TREEDATA>*> *list) 
	{
		doubleNode<tree_node*> *item = children.getFirst();

		for (item ; item != NULL; item = item->next)
		{
			item->value->postOrderRecursive(list);
		}

		list->add(this);
		printf("%c", data);
	}

	void inOrderRecursive(DList<tree_node<TREEDATA>*> *list) 
	{
		unsigned int middle = ceil( (float) children.count() / 2.0f );

		doubleNode<tree_node*> *item = children.getFirst();

		for (unsigned int i = 0; i < middle; i++)
		{
			item->value->inOrderRecursive(list);
			item = item->next;
		}

		list->add(this);
		printf("%c", data);

		for (; item != NULL; item = item->next)
		{
			item->value->inOrderRecursive(list);
		}
	}
};

template <class TREEDATA> 
class Trees
{

private:

	tree_node<TREEDATA> root_node;

public:

	Trees<TREEDATA>(const TREEDATA &new_value) : root_node(new_value)
	{ }

	virtual ~Trees<TREEDATA>()
	{ }
	
	tree_node<TREEDATA> *add(const TREEDATA &new_value)
	{
		tree_node<TREEDATA> *new_node = new tree_node<TREEDATA>(new_value);
		
		new_node->parent = &root_node;
		root_node.children.add(new_node);
		
		return new_node;
	}

	tree_node<TREEDATA> *add(const TREEDATA &new_value, tree_node<TREEDATA> *parent)
	{
		tree_node<TREEDATA> *new_node = new tree_node<TREEDATA>(new_value);
	
		new_node->parent = parent;
		parent->children.add(new_node);
		
		return new_node;
	}

	void preOrderRecursive(DList<tree_node<TREEDATA>*> *list) 
	{
		root_node.preOrderRecursive(list);
	}

	void preOrderIterative(DList<tree_node<TREEDATA>*> *list)
	{
		Stack<tree_node<TREEDATA>*> s;
		tree_node<TREEDATA> *node = &root_node;
		
		while (s.pop(node) == true || node != NULL)
		{
			list->add(node);
			printf("%c", node->data);

			doubleNode<tree_node<TREEDATA>*> *item = node->children.getLast();
			while (item != NULL)
			{
				s.push(item->value);
				item = item->previous;
			}

			node = NULL;
		}
	}

	void postOrderIterative(DList<tree_node<TREEDATA>*> *list)
	{
		Stack<tree_node<TREEDATA>*> s;
		tree_node<TREEDATA> *node = &root_node;

		while (s.pop(node) == true || node != NULL)
		{
			list->add(node);
			printf("%c", node->data);

			doubleNode<tree_node<TREEDATA>*> *item = node->children.getLast();
			while (item != NULL)
			{
				s.push(item->value);
				item = item->previous;
			}

			node = NULL;
		}
	}


	void postOrderRecursive(DList<tree_node<TREEDATA>*> *list) 
	{
		root_node.postOrderRecursive(list);
	}

	void inOrderRecursive(DList<tree_node<TREEDATA>*> *list)
	{
		root_node.inOrderRecursive(list);
	}

};
#endif // !__TREES_H__
