#pragma once
#include <exception>
#include <iostream>
#include <string>
using namespace std;

class Queue
{
private:
	int* queue;
	int copacity;
public:
	Queue();
	Queue(int copacity);

	bool empty();
	void push(int element);
	int* pop();
	int size();

	int* front();
	int* back();
};

