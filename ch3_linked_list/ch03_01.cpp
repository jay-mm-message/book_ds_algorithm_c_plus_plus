#include <iostream>
using namespace std;

int main() {
	
	cout << "Before executing delete m, the memory location pointed to by the pointer m: ";
	int *m = new int(100);
	cout << *m << endl;

	cout << "After executing delete m, the memory location pointed to by the pointer m: ";
	delete m;
	cout << *m << endl;

	return 0;
}