#include <iostream>
#include "Stack.h"
using namespace std;
template <typename TYPE>
bool Stack<TYPE>::isEmpty() const
{
	return count == 0;
}

template <typename TYPE>
void Stack<TYPE>::DestroyStack()
{
	while (!isEmpty())
		this->Pop(); //Function Pop changes count automatically
}

template<typename TYPE>
void Stack<TYPE>::CopyStack(const Stack<TYPE>& other)
{
	this->count = other.count;
	if (other.IsEmpty())
	{
		return;
	}
	this->head = new (nothrow) Node<TYPE>();
	if (this->head == nullptr)
	{
		cerr << "Out of memory!" << endl;
	}
	this->head->data = other.head->data;

	Node<TYPE>* ptrThis = this->head;

	for (Node<TYPE>* ptrOther = other.head->next; ptrOther != nullptr; ptrOther = ptrOther->next)
	{
		ptrThis->next = new (nothrow) Node<TYPE>();
		if (ptrThis->next == nullptr)
		{
			cerr << "Out of memory!" << endl;
		}
		ptrThis = ptrThis->next;
		ptrThis->data = ptrOther->data;
	}
	ptrThis->next = nullptr;
}

template <typename TYPE>
Stack<TYPE>::Stack() :count(0), head(nullptr) {} //Constructor

template<typename TYPE>
Stack<TYPE>::Stack(const Stack<TYPE>& other)
{
	CopyStack(other);
} //Copy Constructor

template<typename TYPE>
Stack<TYPE> Stack<TYPE>::operator=(const Stack<TYPE>& other) //Operator=
{
	if (this != &other)
	{
		DestroyStack();
		CopyStack(other);
	}
	return *this;
} 

template <typename TYPE>
Stack<TYPE>::~Stack() //Destructor
{
	DestroyStack();
}

template <typename TYPE>
void Stack<TYPE>::Push(const TYPE& element) //Pushing element at the top
{
	Node<TYPE>* newEl = new (nothrow) Node<TYPE>();
	if (newEl == nullptr)
		cerr << "Error allocating memory!" << endl;

	newEl->data = element;
	newEl->next = this->head;
	this->head = newEl;
	this->count++;
}

template <typename TYPE>
void Stack<TYPE>::Pop() //Popping
{
	if (this->isEmpty())
		return;
	Node<TYPE>* tempPtr = this->head;
	
	this->head = this->head->next;
	delete tempPtr;
	--count;
}

template <typename TYPE>
TYPE Stack<TYPE>::Top() const
{
	return this->head->data;
}

template <typename TYPE>
void Stack<TYPE>::Print() const
{
	cout << "{";
	Node<TYPE>* helpPtr = this->head;
	for (; helpPtr != nullptr && helpPtr->next!=nullptr; helpPtr = helpPtr->next)
	{
		cout << helpPtr->data << ", ";
	}
	if (helpPtr != nullptr)
		cout << helpPtr->data<<"}"<<endl;
}

template <typename TYPE>
int Stack<TYPE>::getCount() const
{
	return this->count;
}

template<typename TYPE>
void Stack<TYPE>::Clear()
{
	this->DestroyStack();
}
