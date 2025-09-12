/*
	a = | 5 4 3|
		| 6 7 8|
	b = | 3 4 |
		| 6 7 |
		| 3 6 |

	a * b = 
*/

#include <iostream>
using namespace std;

template <int R, int C>
void print_matrix(int (&arr)[R][C]) {
	for(int i = 0 ; i < R ; ++i) {
		for(int j = 0 ; j < C ; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

// void print_matrix(int rows, int cols, int arr[rows][cols]) {
// 	cout << "a matrix: " << endl;
// 	for(int i = 0 ; i < rows ; ++i) {
// 		for(int j = 0 ; j < cols ; ++j) {
// 			cout << arr[i][j] << ' ';
// 		}
// 		cout << endl;
// 	}
// 	cout << endl;
// }

int main() {
	int a[2][3] = {{5, 4, 3}, {6, 7, 8}};
	int b[3][2] = {{3, 4}, {6, 7}, {3, 6}};

	cout << "a matrix: " << endl;
	print_matrix(a);
	// for(int i = 0 ; i < 2 ; ++i) {
	// 	for(int j = 0 ; j < 3 ; ++j) {
	// 		cout << a[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	cout << endl;

	cout << "b matrix: " << endl;
	print_matrix(b);
	// for(int i = 0 ; i < 3 ; ++i) {
	// 	for(int j = 0 ; j < 2 ; ++j) {
	// 		cout << b[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	int c[2][2];
	c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0] + a[0][2] * b[2][0];
	c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1] + a[0][2] * b[2][1];
	c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0] + a[1][2] * b[2][0];
	c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1] + a[1][2] * b[2][1];

	cout << "a matrix * b matrix: " << endl;
	print_matrix(c);
	// for(int i = 0 ; i < 2 ; ++i) {
	// 	for(int j = 0 ; j < 2 ; ++j) {
	// 		cout << c[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	return 0;
}