#ifndef STACK_TEMPLATE_H
#define STACK_TEMPLATE_H

#include <vector>
#include <stdexcept>
#include <cstddef>


using std::size_t;

template <typename T, size_t MaxSize>
class Stack
{
	T elems[MaxSize];
	size_t elemCount;

public:
	Stack();
	void push(T const&);
	void pop();
	T top() const;
	bool empty() const { return elemCount == 0; }
	bool full() const { return elemCount == MaxSize; }
};

template <typename T, size_t MaxSize>
Stack<T, MaxSize>::Stack()
	: elemCount(0)
{

}

template <typename T, size_t MaxSize>
void Stack<T, MaxSize>::push(T const& elem)
{
	if (full())
	{
		throw std::out_of_range("Stack<>::push(): stack is full");
	}
	elems[elemCount++] = elem;
}

template <typename T, size_t MaxSize>
void Stack<T, MaxSize>::pop()
{
	if (empty())
	{
		throw std::out_of_range("Stack<>::pop(): empty stack");
	}
	--elemCount;
}

template <typename T, size_t MaxSize>
T Stack<T, MaxSize>::top() const
{
	if (empty())
	{
		throw std::out_of_range("Stack<>::top(): empty stack");
	}
	return elems[elemCount - 1];
}

#endif