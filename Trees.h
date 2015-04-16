#ifndef __TREES_H__
#define __TREES_H__

#include "DList.h"
#include "Stack.h"

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

		for (; item != NULL; item = item->next)
		{
			item->value->postOrderRecursive(list);
		}

		list->add(this);
		printf("%c", data);
	}

	void inOrderRecursive(DList<tree_node<TREEDATA>*> *list) 
	{
		doubleNode<tree_node*> *item = children.getFirst();

		if (item != NULL)
			item->value->inOrderRecursive(list);
		
		list->add(this);
		printf("%c", data);

		if (item != NULL && item->next != NULL)
			item->next->value->inOrderRecursive(list);

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
		Stack<tree_node<TREEDATA>*> tmp_stack(64);
		list->add(&root_node);
		printf("%c", root_node.data);
		Stack.push(root_node);

		doubleNode<tree_node<TREEDATA>*> *node = root_node.children.getFirst();
		while (tmp_stack.count() > 0)
		{
			node = node->value->children.getFirst();
			if (node != NULL)
			{
				list->add(node->&value);
				Stack.push(node);
			}
			else
				Stack.pop();	
		}

		tmp_stack.pop();
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
