#ifndef __TREES_H__
#define __TREES_H__

#include "DList.h"
#include "Stack.h"

template <class TREEDATA> 
class TreeNode
{

public:

	TREEDATA data;
	TreeNode<TREEDATA> *parent;
	DList<TreeNode<TREEDATA>*> children;

public:
	
	TreeNode(const TREEDATA &new_data) : parent(NULL), data(new_data)
	{ }

	void clear()
	{
		doubleNode<TreeNode*> *tmp = children.getFirst();
		for (; tmp != NULL; tmp = tmp->next)
			tmp->data->clear();
		delete this;
	}

	void preOrderRecursive(DList<TreeNode<TREEDATA>*> *list)
	{
		list->add(this);
		printf("%c", data);
		
		doubleNode<TreeNode*> *tmp = children.getFirst();
		for (; tmp != NULL; tmp = tmp->next)
			tmp->data->preOrderRecursive(list);
	}

	void postOrderRecursive(DList<TreeNode<TREEDATA>*> *list)
	{
		doubleNode<TreeNode*> *tmp = children.getFirst();
		for (; tmp != NULL; tmp = tmp->next)
			tmp->data->postOrderRecursive(list);

		list->add(this);
		printf("%c", data);
	}

	void inOrderRecursive(DList<TreeNode<TREEDATA>*> *list)
	{
		// Odd number of sons -> (x left) | (x+1 right)
		unsigned int middle = children.count() / 2;

		doubleNode<TreeNode*> *tmp = children.getFirst();

		for (unsigned int i = 0; i < middle; i++, tmp = tmp->next)
		{
			tmp->data->inOrderRecursive(list);
		}
			
		list->add(this);
		printf("%c", data);

		for (; tmp != NULL; tmp = tmp->next)
			tmp->data->inOrderRecursive(list);
	}

};

template <class TREEDATA>
class Tree
{

private:

	TreeNode<TREEDATA> root;

public:

	Tree(const TREEDATA &new_data) : root(new_data)
	{ }

	TreeNode<TREEDATA> *addChild(const TREEDATA &new_data)
	{
		TreeNode<TREEDATA> *new_tree_node = new TreeNode<TREEDATA>(new_data);
		new_tree_node->parent = &root;
		root.children.add(new_tree_node);

		return new_tree_node;
	}

	TreeNode<TREEDATA> *addChild(const TREEDATA &new_data, TreeNode<TREEDATA> *parent)
	{
		TreeNode<TREEDATA> *new_tree_node = new TreeNode<TREEDATA>(new_data);
		new_tree_node->parent = parent;
		parent->children.add(new_tree_node);

		return new_tree_node;
	}

	void clear()
	{
		root.clear();
	}

	void preOrderRecursive(DList<TreeNode<TREEDATA>*> *list)
	{
		root.preOrderRecursive(list);
	}

	void postOrderRecursive(DList<TreeNode<TREEDATA>*> *list)
	{
		root.postOrderRecursive(list);
	}

	void inOrderRecursive(DList<TreeNode<TREEDATA>*> *list)
	{
		root.inOrderRecursive(list);
	}

	void preOrderIterative(DList<TreeNode<TREEDATA>*> *list)
	{
		Stack<TreeNode<TREEDATA>*> stack;
		TreeNode<TREEDATA> *node = &root;

		while ( node != NULL || stack.pop(node) )
		{
			list->add(node);
			printf("%c", node->data);
			doubleNode<TreeNode<TREEDATA>*> *item = node->children.getLast();
			for (; item != NULL; item = item->previous)
				stack.push(item->data);

			node = (item != NULL) ? item->data : NULL;
		}
	}

	void postOrderIterative(DList<TreeNode<TREEDATA>*> *list)
	{
		Stack<TreeNode<TREEDATA>*> stack;
		TreeNode<TREEDATA> *node = &root;
		stack.push(node);

		while ( stack.pop(node) )
		{
			doubleNode<TreeNode<TREEDATA>*> *item = node->children.getLast();

			if (item != NULL && !(list->isOnList(item)) )
			{
				stack.push(node);
				for (; item != NULL; item = item->previous)
					stack.push(item->data);
			}
			else
			{
				list->add(node);
				printf("%c", node->data);
			}
		}
	}

};

#endif //__TREES_H__


//template<class TREEDATA>
//struct treeNode
//{
//	TREEDATA data;
//	treeNode<TREEDATA> *parent;
//	DList<treeNode*> children;
//
//	treeNode<TREEDATA>(const TREEDATA &new_data)
//	{
//		data = new_data;
//		parent = NULL;
//	}
//
//	void preOrderRecursive(DList<treeNode<TREEDATA>*> *list) 
//	{
//		list->addChild(this);
//		printf("%c", data);
//
//		doubleNode<treeNode*> *item = children.getFirst();
//
//		for (; item != NULL; item = item->next)
//		{
//			item->value->preOrderRecursive(list);
//		}		
//	}
//
//	void postOrderRecursive(DList<treeNode<TREEDATA>*> *list) 
//	{
//		doubleNode<treeNode*> *item = children.getFirst();
//
//		for (item ; item != NULL; item = item->next)
//		{
//			item->value->postOrderRecursive(list);
//		}
//
//		list->addChild(this);
//		printf("%c", data);
//	}
//
//	void inOrderRecursive(DList<treeNode<TREEDATA>*> *list) 
//	{
//		unsigned int middle = ceil( (float) children.count() / 2.0f );
//
//		doubleNode<treeNode*> *item = children.getFirst();
//
//		for (unsigned int i = 0; i < middle; i++)
//		{
//			item->value->inOrderRecursive(list);
//			item = item->next;
//		}
//
//		list->addChild(this);
//		printf("%c", data);
//
//		for (; item != NULL; item = item->next)
//		{
//			item->value->inOrderRecursive(list);
//		}
//	}
//};
//
//template <class TREEDATA> 
//class Trees
//{
//
//private:
//
//	treeNode<TREEDATA> root_node;
//
//public:
//
//	Trees<TREEDATA>(const TREEDATA &new_value) : root_node(new_value)
//	{ }
//
//	virtual ~Trees<TREEDATA>()
//	{ }
//	
//	treeNode<TREEDATA> *addChild(const TREEDATA &new_value)
//	{
//		treeNode<TREEDATA> *new_node = new treeNode<TREEDATA>(new_value);
//		
//		new_node->parent = &root_node;
//		root_node.children.addChild(new_node);
//		
//		return new_node;
//	}
//
//	treeNode<TREEDATA> *addChild(const TREEDATA &new_value, treeNode<TREEDATA> *parent)
//	{
//		treeNode<TREEDATA> *new_node = new treeNode<TREEDATA>(new_value);
//	
//		new_node->parent = parent;
//		parent->children.addChild(new_node);
//		
//		return new_node;
//	}
//
//	void preOrderRecursive(DList<treeNode<TREEDATA>*> *list) 
//	{
//		root_node.preOrderRecursive(list);
//	}
//
//	void preOrderIterative(DList<treeNode<TREEDATA>*> *list)
//	{
//		Stack<treeNode<TREEDATA>*> s;
//		treeNode<TREEDATA> *node = &root_node;
//		
//		while (s.pop(node) == true || node != NULL)
//		{
//			list->addChild(node);
//			printf("%c", node->data);
//
//			doubleNode<treeNode<TREEDATA>*> *item = node->children.getLast();
//			while (item != NULL)
//			{
//				s.push(item->value);
//				item = item->previous;
//			}
//
//			node = NULL;
//		}
//	}
//
//	void postOrderIterative(DList<treeNode<TREEDATA>*> *list)
//	{
//		Stack<treeNode<TREEDATA>*> s;
//		treeNode<TREEDATA> *node = &root_node;
//		s.push(node);
//
//		while (node != NULL)
//		{
//			doubleNode<treeNode<TREEDATA>*> *item = node->children.getLast();
//			if (item != NULL)
//			{
//				while (item->previous != NULL)
//				{
//					s.push(item->value);
//					item = item->previous;
//				}
//				s.push(item->value);
//				node = item->value;				
//			}
//			else
//			{
//				list->addChild(node);
//				printf("%c", node->data);
//				s.pop(node);
//			}
//		}
//	}
//
//
//	void postOrderRecursive(DList<treeNode<TREEDATA>*> *list) 
//	{
//		root_node.postOrderRecursive(list);
//	}
//
//	void inOrderRecursive(DList<treeNode<TREEDATA>*> *list)
//	{
//		root_node.inOrderRecursive(list);
//	}
//
//};
//#endif // !__TREES_H__
