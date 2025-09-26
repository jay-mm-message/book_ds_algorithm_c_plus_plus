#include <iostream>
using namespace std;

class N {
	public:
		int id;
		int data;
	public:
		N(int id, int data): id(id), data(data) {}
};
typedef N *list;

class Q {
	public:
		int front;
		int rear;
		static const int MAX = 4;
		list pool[MAX];
	public:
		// push
		void push(int id, int data) {
			pool[rear] = new N(id, data);
		}
		// pop
		list pop() {
			return pool[front];
		}
		// isEmpty
		bool isEmpty() {
			++front;
			front %= MAX;
			if (front == rear) return true;
			return false;
		}
		// isFully
		bool isFully() {
			++rear;
			rear %= MAX;
			if (rear == front) return true;
			return false;
		}
};
typedef Q *link;

int main() {
	int id = 0, data = 10;
	link q = new Q();

	cout << "first in first out\n";

	// while(!q->isFully()) {
	// 	cout << "id:" << ++id << ", d: " << ++data << ' ';
	// 	q->push(id, data);
	// }
	// cout << "\nThe queue pool was fully" << endl;

	// while(!q->isEmpty()) {
	// 	list node = q->pop();
	// 	cout << "id:" << node->id << " ,d: " << node->data << ' ';
	// }
	// cout << "\nThe queue pool was empty" << endl;

	for(int i = 0 ; i < 10 ; ++i) {
		q->push(i, i + 100);
		cout << "->id:" << i << ", d:" << i + 100 << '\n';
		list node = q->pop();
		cout << "<-id:" << node->id << ", data:" << node->data << '\n';
	}
	cout << endl;

	return 0;
}