#include <iostream>
using namespace std;

class Stack {
	public:
		int stack_top;
		static const int size = 15;
		int stack[size];
	public:
		Stack(): stack_top(-1) {};
	public:
		bool isStackEmpty() {
			if (stack_top == -1) return true;
			return false;
		}
		bool isStackFull() {
			if (stack_top == 15) return true;
			return false;
		}
		void stack_push(int data) {
			stack[++stack_top] = data;
		}
		int stack_pop() {
			return stack[stack_top--];
		}
};
typedef Stack *stack_link;

class Node {
	public:
		int data;
		Node *next;
	public:
		Node(int d) : data(d), next(nullptr) {};
};
typedef Node *list;

class LinkList {
	public:
		list top;
	public:
		LinkList() : top(nullptr) {};
	public:
		bool isLinkListEmpty() {
			if (nullptr == top) return true;
			return false;
		}
		void linklist_push(int data) {
			list new_node = new Node(data);
			if (nullptr == top) {
				top = new_node;
				return;
			}
			new_node->next = top;
			top = new_node;
		}
		int linklist_pop() {
			list current = top;
			top = top->next;
			
			int data = current->data;
			delete current;

			return data;
		}
};
typedef LinkList *link;

int main() {
	stack_link pool = new Stack();

	for(int i = 1 ; i < 11 ; ++i) {
		if (!pool->isStackFull()) {
			cout << i << endl;
 			pool->stack_push(i);
		}
	}

	while(!pool->isStackEmpty()) {
		cout << "堆疊彈出的順序為: " << pool->stack_pop() << endl;
	}
	cout << endl;

	link link_list_pool = new LinkList();
	for(int i = 1 ; i < 11 ; ++i) {
		cout << i << endl;
		link_list_pool->linklist_push(i);
	}

	while(!link_list_pool->isLinkListEmpty()) {
		cout << "堆疊彈出的順序為: " << link_list_pool->linklist_pop() << endl;
	}
	cout << endl;
	return 0;
}