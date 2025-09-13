#include <iostream>
using namespace std;

int recursive_fib(int n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 1;
	}
	return recursive_fib(n - 1) + recursive_fib(n - 2);
}

int non_recursive_fib(int n) {
	if (n == 0) return 1;
	if (n == 1) return 1;

	int ret = 0, a = 1, b = 1;
	for(int i = 2 ; i <= n ; ++i) {
		ret = a + b;
		a = b;
		b = ret;
	}
	return ret;
}

int recursive_test(int fn) {
	if (fn == 1) return 1;
	if (fn == 0) return 1;
	return recursive_test(fn - 1) + recursive_test(fn - 2);
}

int non_recursive_test(int n) {
	if (n == 1) return 1;
	if (n == 0) return 1;

	int ret = 0, a = 1, b = 1;
	for(int i = 2 ; i <= n ; ++i) {
		ret = a + b;
		a = b;
		b = ret;
	}
	return ret;
}

void result(int n) {
	cout << "recursive: ";
	cout << "fib(" << n << "): ";
	cout << recursive_fib(n) << endl;

	cout << "non recursive: ";
	cout << "fib(" << n << "): ";
	cout << non_recursive_fib(n) << endl;

	cout << "recursive (test): ";
	cout << "fin(" << n << "): ";
	cout << recursive_test(n) << endl;

	cout << "non_recursive (test): ";
	cout << "fin(" << n << "): ";
	cout << non_recursive_test(n) << endl;
}

int main(void) {
	cout << "fn(?): ";
	int n = 0;
	cin >> n;
	cout << endl;

	result(n);

	return 0;
}