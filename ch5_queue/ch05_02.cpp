#include <iostream>
using namespace std;

class Node {
	public:
		int id;
		int data;
		Node *next;
	public:
		Node(int id, int data): id(id), data(data), next(nullptr) {}
		~Node() { cout << "free node" << endl; }
};
typedef Node *list;

class Queue {
	public:
		list front;
		list rear;
	public:
		Queue(): front(nullptr), rear(nullptr) {}
		// push
		void push(int id, int data) {
			list new_node = new Node(id, data);
			if (nullptr == rear) {
				rear = new_node;
				if (nullptr == front) {
					front = rear;
				}
			} else {
				rear->next = new_node;
				rear = new_node;
			}
		}
		// pop
		list pop() {
			list cur = front;
			front = front->next;
			return cur;
		}
		// isEmpty
		bool isEmpty() {
			if (nullptr == front) return true;
			return false;
		}
};
typedef Queue *link;

int main() {

	link queue = new Queue();
	cout << "push: " << endl;
	for(int i = 0 ; i < 5 ; ++i) {
		queue->push(i, i + 500);
		cout << "id: " << i << ", data: " << i + 500 << endl;
	}

	cout << "pop: " << endl;
	while(!queue->isEmpty()) {
		list get_node = queue->pop();
		cout << "id: " << get_node->id << ", data: " << get_node->data << endl;
	}
	cout << endl;
	return 0;
}