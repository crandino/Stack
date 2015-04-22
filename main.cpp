#include "Stack.h"
#include "Queue.h"
#include "Trees.h"

#include <stdio.h>

int main(int argc, char **argv)
{
	///* 
	//    TREE

	//      F
	//	 / \
	//    B   G
 //      / \   \
	//  A   D   I
	//     / \   \
 //       C   E   H
	//*/

	//Trees<char> t('F');
	//tree_node<char> *b = t.add('B');
	//t.add('A', b);
	//tree_node<char> *d = t.add('D', b);
	//t.add('C', d);
	//t.add('E', d);
	//tree_node<char> *g = t.add('G');
	//tree_node<char> *i = t.add('I', g);
	//tree_node<char> *h = t.add('H', i);


	//DList<tree_node<char>*> list_preorder_rec;
	//t.preOrderRecursive(&list_preorder_rec);
	//printf("%s\n", "");

	//DList<tree_node<char>*> list_postorder_rec;
	//t.postOrderRecursive(&list_postorder_rec);
	//printf("%s\n", "");

	//DList<tree_node<char>*> list_inorder_rec;
	//t.inOrderRecursive(&list_inorder_rec);
	//printf("%s\n", "");

	//DList<tree_node<char>*> list_preorder_ite;
	//t.preOrderIterative(&list_preorder_ite);
	//printf("%s\n", "");

	//DList<tree_node<char>*> list_postorder_ite;
	//t.postOrderIterative(&list_postorder_ite);
	//printf("%s\n", "");

	Stack<int> s(50);

	for (int i = 0; i < 100; i++)
		s.push(i);

	for (int i = 0; i < 100; i++)
		printf("%d\n", *s.peek(i));

	Queue<int> q;

	for (int i = 0; i < 100; i++)
		q.push(i);

	/*int ret;
	for (int i = 0; i < 100; i++)
	{
		q.pop(ret);
		printf("%d", ret);
	}*/

	for (int i = 0; i < 100; i++)
		printf("%d\n", *q.peek(i));
	
	getchar();

	return 0;
}