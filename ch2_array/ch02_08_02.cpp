/*
	a[i][j] = 0, (i > j)
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
}

void create_lower_vec(vector<vector<int>> &vec, int row, int col) {
	srand(time(0));
	for(int i = 0 ; i < row ; ++i) {
		for(int j = 0 ; j < col ; ++j) {
			if (i >= j) {
				vec[i][j] = rand() % 8 + 1;
			}
		}
	}
	print_vec(vec);
}

void print_one_vec(vector<int> vec) {
	for(auto val : vec) {
		cout << val << ' ';
	}
	cout << endl;
}

void translator_one_matrix(vector<vector<int>> vec, vector<int> &new_vec) {
	for(auto row : vec) {
		for(auto val : row) {
			if (val != 0) {
				new_vec.push_back(val);
			}
		} 
	}
	print_one_vec(new_vec);
}



int main() {
	srand(time(0));
	vector<vector<int>> vec(5, vector<int>(5, 0));

	create_lower_vec(vec, 5, 5);	

	cout << endl;

	vector<int> new_vec;
	
	translator_one_matrix(vec, new_vec);
	
	return 0;
}