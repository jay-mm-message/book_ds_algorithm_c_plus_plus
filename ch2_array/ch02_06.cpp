/*
	a = | 1 2 3 |
		| 4 5 6 |
		| 7 8 9	|
*/

#include <vector>
#include <iostream>
using namespace std;

void print_vec(vector<vector<int>> vec) {
	for(auto row : vec) {
		for(auto val : row) {
			cout << val << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	vector<vector<int>> b (3, vector<int>(3, 0));

	cout << "a: " << endl;
	print_vec(a);
	cout << "b: " << endl;
	print_vec(b);

	int b_col = 0;
	for(auto row : a) {
		int b_row = 0;
		for(auto col : row) {
			b[b_row][b_col] = col;
			++b_row;
		}
		++b_col;
	}

	// for(int i = 0 ; i < 3 ; ++i) {
	// 	for(int j = 0 ; j < 3 ; ++j) {
	// 		b[j][i] = a[i][j];
	// 	}
	// }

	cout << "a: " << endl;
	print_vec(a);
	cout << "b: " << endl;
	print_vec(b);

	return 0;
}