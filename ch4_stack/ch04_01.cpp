#include <iostream>
using namespace std;

class Stack {
	private:
		static const int size = 5;
		int pool[size];
		int top;

	public:
		~Stack() {}
		Stack() {
			top = -1;
		}
		bool isEmpty() {
			if (top == -1) return true;
			return false;
		}
		bool isFully() {
			if (top + 1 == size) return true;
			return false;
		}
		void push(int val) {
			pool[++top] = val;
		}
		int pop() {
			return pool[top--];
		}
};

typedef Stack *list;

int main() {
	
	list st = new Stack();
	int val = 100;
	
	while(!st->isFully()) {
		cout << "push: " << val << endl;
		st->push(val);
		++val;
	}
	cout << "The stack pool is fully.\n";

	while(!st->isEmpty()) {
		cout << "pop: " << st->pop() << endl;
	}
	cout << "The stack pool is empty.\n";

	cout << endl;
	return 0;
}