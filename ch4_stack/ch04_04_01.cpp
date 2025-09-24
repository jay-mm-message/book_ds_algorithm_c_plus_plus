#include <iostream>
using namespace std;


int main() {
	function<int(int)> fib = [&](int n) -> int {
		if (n <= 1) return n;
		return fib(n - 1) + fib(n - 2); 
	};

	cout << "Please keyin fib: ";
	int val;
	cin >> val;
	cout << "fib(" << val << "): " << fib(val) << endl;
	 
	return 0;
}