#pragma once
template <typename TYPE>
struct Node
{
	TYPE data;
	Node<TYPE>* next;
};

template <typename TYPE>
class Stack
{
private:
	Node<TYPE>* head;
	int count;

	void DestroyStack();
	void CopyStack(const Stack<TYPE>&);

public:
	//Help function (used in Big 4)

	//Big 4
	Stack(); //Default constructor
	Stack(const Stack<TYPE>&); //Copy Constructor
	Stack<TYPE> operator=(const Stack<TYPE>&); //operator =
	~Stack(); //Destructor

	void Push(const TYPE&);
	void Pop();
	TYPE Top() const;

	void Print() const;
	bool isEmpty() const;
	int getCount() const;

	void Clear();

};