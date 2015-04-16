#include "Stack.h"
#include "Queue.h"
#include "Trees.h"

int main(int argc, char **argv)
{
	/* 
	    TREE

	      F
		 / \
	    B   G
       / \   \
	  A   D   I
	     / \   \
        C   E   H
	*/

	Trees<char> t('F');
	tree_node<char> *b = t.add('B');
	t.add('A', b);
	tree_node<char> *d = t.add('D', b);
	t.add('C', d);
	t.add('E', d);
	tree_node<char> *g = t.add('G');
	tree_node<char> *i = t.add('G', g);
	tree_node<char> *h = t.add('G', i);

	DList<char> list_preorder;
	t.visitAllNodes(&list_preorder);
	
	getchar();

	return 0;
}