#include <iostream>
using namespace std;

class Queue {
	public:
		static const int size = 5;
		int front;
		int rear;
		int pool[size];

	public:
		Queue(): front(-1), rear(-1) {}
	public:
		// push
		void push(int val) {
			pool[++rear] = val;
		}
		// pop
		int pop() {
			return pool[++front];
		}
		// isEmpty
		bool isEmpty() {
			if (front == rear) return true;
			return false;
		}
		// isFully
		bool isFully() {
			if (rear == this->size - 1) return true;
			return false;
		}
};

typedef Queue *list;

int main() {

	list queue = new Queue();

	int i = 200, count = 1;
	while(!queue->isFully()) {
		cout << "push(" << count << "): " << i << endl;
		queue->push(i);
		++i;
		++count;
	}

	count = 1;
	cout << "Queue: \n";
	while(!queue->isEmpty()) {
		cout << "pop(" << count << "): " << queue->pop() << endl;
		++count;
	} cout << endl;
	return 0;
}