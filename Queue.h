#ifndef __QUEUE_H__
#define __QUEUE_H__

template <class TREEDATA>
struct queue_node
{
	TREEDATA data;
	queue_node *next;
};

template<class TREEDATA>
class Queue
{
private:
	queue_node<TREEDATA> *start;

public:
	 
	Queue<TREEDATA>()
	{
		start = NULL;
	}

	~Queue<TREEDATA>()
	{ }

	void push(TREEDATA new_value)
	{
		queue_node<TREEDATA> *new_node = new queue_node<TREEDATA>;
		new_node->data = new_value;
		new_node->next = NULL;

		if (start != NULL)
		{
			queue_node<TREEDATA> *tmp = start;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new_node;
		}
		else
			start = new_node;
	}

	bool pop(TREEDATA &data_returned)
	{
		if (start != NULL)
		{
			data_returned = start->data;
			queue_node<TREEDATA> *node_to_delete = start;

			if (start->next != NULL)
				start = start->next;
			else
				start = NULL;
			delete node_to_delete;

			return true;
		}
		return false;
	}

	const TREEDATA &peek(unsigned int position) const
	{
		if (start != NULL)
		{
			unsigned int counter = 0;
			queue_node<TREEDATA> *tmp = start;
			while (counter != position)
			{
				tmp = tmp->next;
				counter++;
			}
			return tmp->data;
		}
		return -1;
	}

	unsigned int count() const
	{
		unsigned int num_elements = 0;
		if (start != NULL)
		{
			queue_node<TREEDATA> *tmp = start;
			while (tmp != NULL)
			{
				num_elements++;
				tmp = tmp->next;
			}
		}
		return num_elements;
	}
};

#endif //!__QUEUE_H__

//template <class TREEDATA>
//struct simpleNode {
//	TREEDATA value;
//	simpleNode<TREEDATA>* next;
//	simpleNode<TREEDATA>* previous;
//};
//
//template <class TREEDATA>
//class Queue {
//
//private:
//	simpleNode<TREEDATA>* start;
//
//public:
//
//	Queue() {
//		start = NULL;
//	}
//
//	~Queue() {
//		delAll();
//	}
//
//	unsigned int count() const {
//		unsigned int counter = 0;
//		simpleNode<TREEDATA>* tmp = start;
//		while (tmp != NULL) {
//			tmp = tmp->next;
//			counter++;
//		}
//		return counter;
//	}
//
//	void push(TREEDATA new_value) {
//
//		// A new simpleNode is being created.
//		simpleNode<TREEDATA>* new_node = new simpleNode<TREEDATA>;
//		new_node->value = new_value;
//		new_node->next = NULL;
//
//		// Once done, has to be added to the list.
//		if (start != NULL) {
//			simpleNode<TREEDATA> *tmp = start;
//			while (tmp->next != NULL)
//				tmp = tmp->next;
//			tmp->next = new_node;
//		}
//		else
//			start = new_node;
//	}
//
//	TREEDATA pop()
//	{
//		TREEDATA ret = -1;
//		if (start != NULL)
//		{
//			simpleNode<TREEDATA>* node_to_delete = start;
//			if (start->next != NULL)
//				start = start->next;
//			else
//				start = NULL;
//			ret = node_to_delete->value;
//			delete node_to_delete;
//		}
//		return ret;
//	}
//
//	simpleNode<TREEDATA>* getNodeAtPos(unsigned int position) const
//	{
//		// Node 1 is zero, node 2 is one, etc.
//		if (start != NULL && position < count())
//		{
//			simpleNode<TREEDATA>* tmp = start;
//			int pos_counter = 0;
//			while (pos_counter != position)
//			{
//				tmp = tmp->next;
//				pos_counter++;
//			}
//			return tmp;
//		}
//		else
//			return NULL;
//	}
//
//	const TREEDATA& peek(unsigned int position) const
//	{
//		return getNodeAtPos(position)->value;
//	}
//
//	bool del(simpleNode<TREEDATA>* node_to_erase) {
//
//		// Si el nodo no existe, petará.
//		// Puede mejorarse añadiendo un booleano que indique error o no.
//
//		if (node_to_erase != NULL && start != NULL)
//		{
//			if (node_to_erase != start)
//			{
//				simpleNode<TREEDATA> *tmp = start;
//				while (tmp->next != node_to_erase)
//				{
//					if (tmp->next == NULL)
//						return false;
//					tmp = tmp->next;
//				}
//
//				tmp->next = node_to_erase->next;
//			}
//			else
//				start = start->next;
//			delete node_to_erase;
//			return true;
//		}
//		return false;
//	}
//
//	bool delAll() {
//
//		// Hacerla booleana. Este método lo podría llamar el destructor
//		// de la clase.
//
//		if (start != NULL)
//		{
//			while (start->next != NULL)
//			{
//				simpleNode<TREEDATA>* node_to_delete = start;
//				start = start->next;
//				delete node_to_delete;
//			}
//			delete start;
//			start = NULL;
//			return true;
//		}
//		return false;
//	}
//
//};
//
//#endif __QUEUE_H__