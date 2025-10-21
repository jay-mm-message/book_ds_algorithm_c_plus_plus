#include <iostream>
using namespace std;

void create_bt(int d[], const int sz, int bt[]);
void dump_arr(int arr[], const int sz);

int main() {
	int d[] = {0, 6, 3, 5, 9, 7, 8, 4, 2};
	const int sz = sizeof(d) / sizeof(int);
	const int btsz = sz * 2;
	int bt[btsz] = {0};

	dump_arr(d, sz);
	create_bt(d, sz, bt);
	dump_arr(bt, btsz);
	return 0;
}

void create_bt(int d[], const int sz, int bt[]) {
	for(int i = 1 ; i < sz ; ++i) {
		int level = 1;
		// search right, left on bt
		while(bt[level] != 0) {
			if (d[i] > bt[level]) {
				level = level * 2 + 1;
			} else {
				level = level * 2;
			}
		}
		bt[level] = d[i];
	}
}

void dump_arr(int arr[], const int sz) {
	for(int i = 0 ; i < sz ; ++i) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}