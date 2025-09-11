/*
	cout << "|a1 b1|" << endl;
	cout << "|a2 b2|" << endl;

	result = a1 * b2 - a2 * b1

	|3 4|
	|2 1|
	answer = 5
 */

 #include <iostream>
 using namespace std;

 int main() {
	cout << "|3 2|" << endl;
	cout << "|4 1|" << endl;

	int arr[2][2] = {{3, 2}, {4, 1}};
	int result = (arr[0][0] * arr[1][1]) - (arr[1][0] * arr[0][1]);
	cout << "result = " << result << endl;
	
	return 0;
 }