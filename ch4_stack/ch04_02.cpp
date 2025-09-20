#include <iostream>
using namespace std;

class Node {
	public:
		int val;
		Node *next;
	public:
		Node(int val) {
			this->val = val;
			this->next = nullptr;
		}
		~Node() {}
};
typedef Node *list;

class Stack {
	private:
		list top;
	public:
		Stack() {
			this->top = nullptr;
		}
		~Stack() {};

		void push(list new_node) {
			if (this->top != nullptr) {
				new_node->next = this->top;
			}
			this->top = new_node;
		}

		int pop() {
			int ret = 0;
			if (this->top != nullptr) {
				list free_node = this->top;
				this->top = this->top->next;
				
				ret = free_node->val;
				delete free_node;
				free_node = nullptr;
			} else {
				ret = this->top->val;
				delete this->top;
				this->top = nullptr;
			}
			return ret;
		}

		bool isEmpty() {
			if (this->top == nullptr) return true;
			return false;
		}
};
typedef Stack *link;

int main() {

	cout << "Last In, First Out." << endl;

	link stack = new Stack;
	int val = 1;

	for(size_t i = 0 ; i < 5 ; i++) {
		cout << "push: " << val << endl;
		stack->push(new Node(val));
		++val;
	}
	cout << "push stop.\n";

	while(!stack->isEmpty()) {
		cout << "pop: " << stack->pop() << endl;
	}
	cout << "pop stop.\n";

	cout << endl;
	return 0;
}