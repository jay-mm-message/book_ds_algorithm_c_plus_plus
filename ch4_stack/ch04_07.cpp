#include <iostream>
using namespace std;

void run_recursive(int n) {
	function<int(int)> backtrace = [&](int n) -> int {
		if (n == 0) return 0;
		else if (n == 1) return 1;
		else
			return backtrace(n-1) + backtrace(n-2);
	};
	cout << backtrace(n) << ' ';
}

int main() {
	int n = 9;
	for(int i = 0 ; i < n ; ++i) {
		cout << i << ' ';
	} cout << endl;

	for(int i = 0 ; i < n ; ++i) {
		run_recursive(i);
	} cout << endl;
	return 0;
}