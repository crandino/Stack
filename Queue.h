#ifndef __QUEUE_H__
#define __QUEUE_H__

template <class TYPE>
struct simpleNode {
	TYPE value;
	simpleNode<TYPE>* next;
	simpleNode<TYPE>* previous;
};

template <class TYPE>
class Queue {

private:
	simpleNode<TYPE>* start;

public:

	Queue() {
		start = NULL;
	}

	~Queue() {
		delAll();
	}

	unsigned int count() const {
		unsigned int counter = 0;
		simpleNode<TYPE>* tmp = start;
		while (tmp != NULL) {
			tmp = tmp->next;
			counter++;
		}
		return counter;
	}

	void push(TYPE new_value) {

		// A new simpleNode is being created.
		simpleNode<TYPE>* new_node = new simpleNode<TYPE>;
		new_node->value = new_value;
		new_node->next = NULL;

		// Once done, has to be added to the list.
		if (start != NULL) {
			simpleNode<TYPE> *tmp = start;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new_node;
		}
		else
			start = new_node;
	}

	TYPE pop()
	{
		TYPE ret = -1;
		if (start != NULL)
		{
			simpleNode<TYPE>* node_to_delete = start;
			if (start->next != NULL)
				start = start->next;
			else
				start = NULL;
			ret = node_to_delete->value;
			delete node_to_delete;
		}
		return ret;
	}

	simpleNode<TYPE>* getNodeAtPos(unsigned int position) const
	{
		// Node 1 is zero, node 2 is one, etc.
		if (start != NULL && position < count())
		{
			simpleNode<TYPE>* tmp = start;
			int pos_counter = 0;
			while (pos_counter != position)
			{
				tmp = tmp->next;
				pos_counter++;
			}
			return tmp;
		}
		else
			return NULL;
	}

	const TYPE& peek(unsigned int position) const
	{
		return getNodeAtPos(position)->value;
	}

	bool del(simpleNode<TYPE>* node_to_erase) {

		// Si el nodo no existe, petar�.
		// Puede mejorarse a�adiendo un booleano que indique error o no.

		if (node_to_erase != NULL && start != NULL)
		{
			if (node_to_erase != start)
			{
				simpleNode<TYPE> *tmp = start;
				while (tmp->next != node_to_erase)
				{
					if (tmp->next == NULL)
						return false;
					tmp = tmp->next;
				}

				tmp->next = node_to_erase->next;
			}
			else
				start = start->next;
			delete node_to_erase;
			return true;
		}
		return false;
	}

	bool delAll() {

		// Hacerla booleana. Este m�todo lo podr�a llamar el destructor
		// de la clase.

		if (start != NULL)
		{
			while (start->next != NULL)
			{
				simpleNode<TYPE>* node_to_delete = start;
				start = start->next;
				delete node_to_delete;
			}
			delete start;
			start = NULL;
			return true;
		}
		return false;
	}

};

#endif __QUEUE_H__