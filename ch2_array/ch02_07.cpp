/*
*/

// #include <ctime>
// #include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

void print_vec(vector<vector<int>> vec) {
	for(auto row : vec) {
		for(auto val: row) {
			cout << val << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void init_vec(vector<vector<int>> &vec) {

	srand(time(0));
	for(int i = 0 ; i < 8 ; ++i) {

		int row = rand() % 8;
		int col = rand() % 9;
		int val = rand() % 9 + 1;

		// cout << "row: " << row << ' ';
		// cout << "col: " << col << ' ';
		// cout << "val: " << val << endl;

		vec[row][col] = val;
	}
}

bool compare_vec(vector<vector<int>> a, vector<vector<int>> b) {
	for(int row = 0 ; row < 8 ; ++row) {
		for(int col = 0 ; col < 9 ; ++col) {
			if(a[row][col] != b[row][col]) {
				//cout << "The two matrices do not match correctly" << endl;
				return false;
			}
		}
	}
	//cout << "The two matrices match correctly" << endl;
	return true;
}
void chk_vec(vector<vector<int>> vec_list, vector<vector<int>> vec) {
	vector<vector<int>> new_vec(8, vector<int>(9, 0));
	for(int i = 1 ; i < 9 ; ++i) {
		int row = vec_list[i][0];
		int col = vec_list[i][1];
		int val = vec_list[i][2];
		
		new_vec[row][col] = val;
	}
	//print_vec(new_vec);
	if (compare_vec(new_vec, vec)) {
		cout << "The matrix list is correctly" << endl;
	} else {
		cout << "The matrix list is not correctly" << endl;
	}
}

int main() {

	vector<vector<int>> vec(8, vector<int>(9, 0));
	//print_vec(vec);

	init_vec(vec);

	print_vec(vec);

	vector<vector<int>> vec_list(9, vector<int>(3, 0));
	//print_vec(vec_list);
	vec_list[0][0] = 8;
	vec_list[0][1] = 9;
	vec_list[0][2] = 8;
	
	//print_vec(vec_list);
	int row_position = 1;
	for(int row = 0 ; row < 8 ; ++row) {
		for(int col = 0 ; col < 9 ; ++col) {
			if (vec[row][col] != 0) {
				vec_list[row_position][0] = row;
				vec_list[row_position][1] = col;
				vec_list[row_position][2] = vec[row][col];
				++row_position;
			}
		}
	}
	
	print_vec(vec_list);

	chk_vec(vec_list, vec);


	return 0;
}