#ifndef __TREES_H__
#define __TREES_H__

#include "DList.h"

template<class TYPE>
struct tree_node
{
	TYPE data;
	tree_node<TYPE> *parent;
	DList<tree_node*> children;

	tree_node<TYPE>(const TYPE &new_data)
	{
		data = new_data;
		parent = NULL;
	}

	void visitAll(DList<TYPE> *list) const
	{
		list->add(data);
		printf("%c", data);

		doubleNode<TYPE> *tmp = children.getFirst();
		
	}
};

template <class TYPE> 
class Trees
{

private:

	tree_node<TYPE> root_node;

public:

	Trees<TYPE>(const TYPE &new_value) : root_node(new_value)
	{ }

	virtual ~Trees<TYPE>()
	{ }
	
	tree_node<TYPE> *add(const TYPE &new_value)
	{
		tree_node<TYPE> *new_node = new tree_node<TYPE>(new_value);
		
		new_node->parent = &root_node;
		root_node.children.add(new_node);
		
		return new_node;
	}

	tree_node<TYPE> *add(const TYPE &new_value, tree_node<TYPE> *parent)
	{
		tree_node<TYPE> *new_node = new tree_node<TYPE>(new_value);
	
		new_node->parent = parent;
		parent->children.add(new_node);
		
		return new_node;
	}

	void visitAllNodes(DList<TYPE> *list) const
	{
		root_node.visitAll(list);
	}

};
#endif // !__TREES_H__
