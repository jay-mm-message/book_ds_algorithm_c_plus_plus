#include <iostream>
using namespace std;

int main() {
	int score[5] = {87, 66, 90, 65, 70};
	int total_score = 0;

	cout << "score: ";
	for(int i = 0 ; i < 5 ; ++i) {
		total_score += score[i];
		cout << score[i] << ' ';
	}
	cout << endl;
	cout << "total_score: " << total_score << endl;
	return 0;
}