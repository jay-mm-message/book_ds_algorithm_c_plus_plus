#include <iostream>
using namespace std;

// create Node
template<class T>
class Node {
	public:
		T data;
		Node<T> *next;
	public:
		Node(const T& value): data(value), next(nullptr) {}
};
typedef Node<int> *list;

// create LinkList
template<class T>
class LinkList {
	public:
		list top;
	public:
		LinkList(): top(nullptr) {}
	public:
		// push
		void push(list new_node) {
			new_node->next = top;
			top = new_node;
		}

		// pop
		T pop() {
			list free_node = top;
			top = top->next;
			
			T data;
			data = free_node->data;
			delete free_node;
			free_node = nullptr;
			return data;
		}
		
		// isEmpty
		bool isEmpty() {
			if (nullptr == top) return true;
			return false;
		}
};
typedef LinkList<int> *link;

int main() {

	link stack = new LinkList<int>();
	int value = 1000;
	
	int num = 5;
	for(size_t i = 0 ; i < num ; ++i) {
		cout << "push: " << value << endl;
		stack->push(new Node<int>(value));
		++value;
	}
	cout << "All elements have already been pushed into the stack.\n";

	while(!stack->isEmpty()) {
		cout << "pop: " << stack->pop() << endl;
	}
	cout << "The pool of stack is empty.\n";

	cout << endl;
	return 0;
}