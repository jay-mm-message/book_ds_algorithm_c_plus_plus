
// Tower of Hanoi
#include <iostream>
using namespace std;

void run_recursive_tower_of_hanoi() {
	int n = 4;
	int p1 = 1, p2 = 2, p3 = 3;

	int moves_count = 0;
	function<void(int, int, int, int)> hanoi = [&](int n, int p1, int p2, int p3) {
		moves_count++;
		if (n == 1) cout << "The dish moves from " << p1 << " to " << p3 << endl;
		else {
			hanoi(n - 1, p1, p3, p2);
			cout << "The dish moves from " << p1 << " to " << p3 << endl;
			hanoi(n - 1, p2, p1, p3);
		}
	};
	hanoi(n, p1, p2, p3);
	cout << "The dish (" << n << ") moves time: " << moves_count << endl;
}

int main() {
	run_recursive_tower_of_hanoi();
	return 0;
}