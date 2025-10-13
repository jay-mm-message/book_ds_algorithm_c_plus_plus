#include <iostream>
using namespace std;

void createT (int d[], const int size, int t[]) {
	for(int i = 1 ; i < size ; ++i) {
		int level = 1;
		for(; t[level] != 0 ; ) {
			if (d[i] > t[level]) {
				level = level * 2 + 1;
			}
			else {
				level = level * 2;
			}
		}
		t[level] = d[i];
	}
}

void dump_arr(int arr[], int size) {
	for(int i = 1 ; i < size ; ++i) {
		cout << arr[i] << ' ';
	} cout << endl;
}

void result() {
	cout << "index: 1  2  3  4  5  6  7 10 11 14" << endl;
	cout << "value: 8  3 10  1  6     14 4  7 13" << endl;

/*
               8
           /       \
         3          10
       /   \           \
      1     6            14
           / \           /
          4   7        13
		  
*/
}

int main() {
	int d[] = {0, 8, 3, 10, 1, 6, 14, 4, 7, 13};
	int size = sizeof(d) / sizeof(int);
	int t[20] = {0};

	createT(d, size, t);

	dump_arr(d, size);
	dump_arr(t, 20);

	result();
	return 0;
}