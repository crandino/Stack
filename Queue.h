#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include "DynArray.h"

template <class TYPE>
struct QueueItem
{
	TYPE data;
	QueueItem<TYPE> *next;

	inline QueueItem<TYPE>() : next(NULL)
	{ }

	inline QueueItem<TYPE>(TYPE new_data) : data(new_data), next(NULL)
	{ }
};

template <class TYPE>
class Queue
{

private:

	QueueItem<TYPE> *start;
	unsigned int num_elements;
	
public:

	Queue() : start(NULL), num_elements(0)
	{ }

	void push(const TYPE &new_data)
	{
		QueueItem<TYPE> *new_QueueItem = new QueueItem<TYPE>(new_data);

		if (start == NULL)
			start = new_QueueItem;
		else
			getLast()->next = new_QueueItem;	

		num_elements++;
	}

	bool pop(TYPE &pop_data)
	{
		if (start == NULL)
			return false;

		QueueItem<TYPE> *node_to_delete = new QueueItem<TYPE>;
		node_to_delete = start;

		pop_data = start->data;
		start = start->next;
		delete node_to_delete;

		num_elements--;

		return true;
	}

	QueueItem<TYPE> *getLast() const
	{
		if (start == NULL)
			return start;

		QueueItem<TYPE> *tmp = start;
		while (tmp->next != NULL)
			tmp = tmp->next;

		return tmp;
	}

	const TYPE *peek(unsigned int position) const
	{

		TYPE *ret = NULL;

		if (start != NULL && position < num_elements)
		{
			unsigned int counter = 0;
			QueueItem<TYPE> *tmp = start;
			
			for (; counter < position; counter++)
				tmp = tmp->next;

			ret = &(tmp->data);
		}
		return ret;
		
	}

	void clear()
	{
		if (start != NULL)
		{
			QueueItem<TYPE> *tmp = start;
			QueueItem<TYPE> *tmp_next;

			while (tmp->next != NULL)
			{
				tmp_next = tmp->next;
				delete tmp;
				tmp = tmp_next;
			}

			start = NULL;
			num_elements = 0;
		}
	}

	unsigned int count() const
	{
		return num_elements;
	}
};

// Queue on Arrays...
template <class TYPE>
class Queue2
{

private:

	DynArray<TYPE> data;

public:

	Queue2()
	{ }

	~Queue2()
	{ }

	void push(const TYPE &new_data)
	{
		data.pushBack(new_data);
	}

	bool pop(TYPE &result)
	{
		if (data.getNumElements() > 0)
		{
			// Potser el millor es fer un m�tode delete de una posici� determinada.
			// I utilitzar-ho aqu� dintre.
			result = data[0];

			for (unsigned int i = 0; i < data.getNumElements() - 1; i++)
				data[i] = data[i + 1];

			// Sobretot per aix�.
			TYPE trash;
			data.pop(trash);

			return true;
		}
		else
			return false;
	}

	unsigned int count() const
	{
		return data.getNumElements();
	}
	
};

#endif // __QUEUE_H__