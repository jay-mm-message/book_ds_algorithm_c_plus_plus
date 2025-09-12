/*
	a = | 5 4 3|
		| 6 7 8|
	b = | 3 4 |
		| 6 7 |
		| 3 6 |

	a * b = 
*/

#include <iostream>
#include <vector>
using namespace std;

void print_matrix(vector<vector<int>> vec) {
	for(auto row : vec) {
		for(auto val : row) {
			cout << val << ' ';
		}
		cout << endl;
	}
}

// template <int R, int C>
// void print_matrix(int (&arr)[R][C]) {
// 	for(int i = 0 ; i < R ; ++i) {
// 		for(int j = 0 ; j < C ; ++j) {
// 			cout << arr[i][j] << ' ';
// 		}
// 		cout << endl;
// 	}
// 	cout << endl;
// }

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
	
	vector<vector<int>> a = {{5, 4, 3}, {6, 7, 8}};
	vector<vector<int>> b = {{3, 4}, {6, 7}, {3, 6}};

	cout << "a matrix: " << endl;
	print_matrix(a);
	cout << endl;

	// for(int i = 0 ; i < 2 ; ++i) {
	// 	for(int j = 0 ; j < 3 ; ++j) {
	// 		cout << a[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	cout << endl;

	cout << "b matrix: " << endl;
	print_matrix(b);
	cout << endl;

	// for(int i = 0 ; i < 3 ; ++i) {
	// 	for(int j = 0 ; j < 2 ; ++j) {
	// 		cout << b[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	// vector<vector<int>> c = {a[0][0] * b[0][0] + a[0][1] * b[1][0] + a[0][2] * b[2][0],
	// 						a[0][0] * b[0][1] + a[0][1] * b[1][1] + a[0][2] * b[2][1],
	// 					 	a[1][0] * b[0][0] + a[1][1] * b[1][0] + a[1][2] * b[2][0],
	// 						a[1][0] * b[0][1] + a[1][1] * b[1][1] + a[1][2] * b[2][1]};

	vector<vector<int>> c(2, vector<int>(2, 0));
	for(int i = 0 ; i < 2 ; ++i) {
		for(int j = 0 ; j < 2 ; ++j) {
			for(int k = 0 ; k < 3 ; ++k) {
				c[i][j] = a[i][k] * b[k][j];
			}
		}
	}

	// c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0] + a[0][2] * b[2][0];
	// c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1] + a[0][2] * b[2][1];
	// c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0] + a[1][2] * b[2][0];
	// c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1] + a[1][2] * b[2][1];

	cout << "a matrix * b matrix: " << endl;
	print_matrix(c);
	cout << endl;

	// for(int i = 0 ; i < 2 ; ++i) {
	// 	for(int j = 0 ; j < 2 ; ++j) {
	// 		cout << c[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	return 0;
}