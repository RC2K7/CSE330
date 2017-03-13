#ifndef STACK_H
#define STACK_H

#include "../List/List.h"

using namespace std;

template <class T, template <class> class Container = List>
class Stack {
public:
	bool empty() const;
	unsigned int size() const;
	void push(const T &);
	void pop();
	T & top();

private:
	Container<T> container;
};

template <class T, template <class> class Container>
bool Stack<T, Container>::empty() const {
	return container.empty();
}

template <class T, template <class> class Container>
unsigned int Stack<T, Container>::size() const {
	return container.size();
}

template <class T, template <class> class Container>
void Stack<T, Container>::push(const T & x) {
	container.push_back(x);
}

template <class T, template <class> class Container>
void Stack<T, Container>::pop() {
	container.pop_back();
}

template <class T, template <class> class Container>
T & Stack<T, Container>::top() {
	return container.back();
}

#endif