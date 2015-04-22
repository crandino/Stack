#include "Stack.h"
#include "Queue.h"
#include "Trees.h"

#include <stdio.h>

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

	Tree<char> t('F');
	TreeNode<char> *b = t.addChild('B');
	t.addChild('A', b);
	TreeNode<char> *d = t.addChild('D', b);
	t.addChild('C', d);
	t.addChild('E', d);
	TreeNode<char> *g = t.addChild('G');
	TreeNode<char> *i = t.addChild('I', g);
	TreeNode<char> *h = t.addChild('H', i);


	// Recursive

	DList<TreeNode<char>*> list_preorder_rec;
	t.preOrderRecursive(&list_preorder_rec);
	printf("%s\n", "");

	DList<TreeNode<char>*> list_postorder_rec;
	t.postOrderRecursive(&list_postorder_rec);
	printf("%s\n", "");

	DList<TreeNode<char>*> list_inorder_rec;
	t.inOrderRecursive(&list_inorder_rec);
	printf("%s\n", "");

	// Iterative

	DList<TreeNode<char>*> list_preorder_ite;
	t.preOrderIterative(&list_preorder_ite);
	printf("%s\n", "");

	//DList<treeNode<char>*> list_postorder_ite;
	//t.postOrderIterative(&list_postorder_ite);
	//printf("%s\n", "");
	
	getchar();

	return 0;
}