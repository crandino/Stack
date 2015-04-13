#ifndef __TREES_H__
#define __TREES_H__

#include "DList.h"



template<class TYPE>
struct tree_node
{
	TYPE data;
	tree_node<TYPE> *parent;
	DList<TYPE> *children;

	tree_node(TYPE new_value) : data(new_value)
	{ }
};

template <class TYPE> 
class Trees
{

private:

	tree_node<TYPE> *root_node;

public:

	Trees<TYPE>(TYPE new_value)
	{ 
		root_node->data = new_value;
		root_node->parent = NULL;
	}

	~Trees<TYPE>()
	{ }

	const tree_node<TYPE> &add(TYPE new_value, tree_node<TYPE> &parent = &root_node )
	{
		tree_node<TYPE> *new_node = new tree_node<TYPE> ;
		new_node->data = new_value;

		new_node->parent = parent;
		parent->children->add(new_node);
		
		return new_node;
	}

};
#endif // !__TREES_H__
