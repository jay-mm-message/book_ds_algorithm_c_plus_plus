#include <iostream>
using namespace std;

void run_factorial(int n) {
	function<int(int)> recursive = [&] (int n) -> int {
		if (n == 0) return 1;
		cout << n;
		(n != 1)? cout << " * ": cout << " = ";

		return n * recursive(n-1);
	};

	cout << "(" << n << "!): " << recursive(n) << endl;
}

int main() {
	for(int i = 0 ; i < 6 ; ++i) {
		run_factorial(i);
	}
	return 0;
}