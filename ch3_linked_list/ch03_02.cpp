#include <iostream>
using namespace std;

bool init_arr(int arr[], const int size) {

	if (arr == nullptr) return false;

	if (size <= 0) return false;

	cout << "Initialize all elements in the array.\n";
	
	for(size_t i = 0 ; i < size ; ++i) {
		arr[i] = i + 1;
	}
	
	return true;
}

bool print_arr(int arr[], const int size) {
	
	cout << "Display all elements in a array.\n";
	
	if (arr == nullptr) return false;
	
	if (size <= 0) return false;

	cout << "arr: ";

	// for(auto val : arr) {
	// 	cout << val << ' ';
	// }
	for(size_t i = 0 ; i < size ; ++i) {
		cout << arr[i] << ' ';
	}
	cout << endl;

	return true;
}

int main() {

	cout << "Allocate an array memory through a dynamic method.\n";
	const int size = 5;
	int *arr = new int[size];

	if (init_arr(arr, size) == true) {
		if (print_arr(arr, size) == false) {
			return -1;
		} 
	}

	cout << "After executing delete array.\n";
	delete [] arr;
	if (print_arr(arr, size) == false) {
		return -1;
	}

	return 0;
}