#include "Queue.h"

Queue::Queue()
{
	this->queue = new int[0];
	this->copacity = 0;
}

Queue::Queue(int copacity)
{
	this->queue = new int [copacity];
	for (int i = 0; i < copacity; i++) {
		this->queue[i] = NULL;
	}
	this->copacity = copacity;
}

bool Queue::empty()
{
	return this->size()? true : false;
}

void Queue::push(int element)
{
	try
	{
		int i = 0;
		while (this->queue[i] && i < this->size())
		{
			i++;
		}
		if (this->queue[i] == NULL) {
			this->queue[i] = element;
		}
		else {
			throw string("Queue is full");
		}		
	}
	catch (string exception)
	{
		cout << "Error: " << exception << endl;
	}
}

int* Queue::pop()
{
	try
	{
		int i = 0;
		if (this->queue[0]) {
			while (i + 1 < this->size() - 1)
			{
				this->queue[i] = this->queue[i + 1];
				i++;
			}
			this->queue[i + 1] = NULL;
			return &this->queue[0];
		}
		else {
			throw string("Queue is empty");
		}
	}
	catch (string exception)
	{
		cout << "Error: " << exception << endl;
	}
}

int Queue::size()
{
	return this->copacity;
}

int* Queue::front()
{
	return &(this->queue[0]);
}

int* Queue::back()
{
	int i = 0;
	while ((this->queue[i+1] != NULL) && (i+1 < this->size()))
	{
		i++;
	}
	return &this->queue[i];
}
