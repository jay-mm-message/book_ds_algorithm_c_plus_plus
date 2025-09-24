#include <iostream>
using namespace std;

void dump(const vector<int> ret) {
	for(int i = ret.size() - 1 ; i >= 0 ; --i) {
		cout << ret[i] << ' ';
	}
	cout << endl;
}

void store(const stack<int> st, vector<int> &ret) {

	stack<int> tmp = st;
	while(!tmp.empty()) {
		ret.push_back(tmp.top());
		tmp.pop();
	}
}

void create_permutation(int n) {

	stack<int> st;
	vector<bool> used(n, false);
	int total_count = 0;

	function<void()> backtrack = [&] () {
		vector<int> ret;
		if (n == st.size()) {
			total_count++;
			// store & dump
			store(st, ret);
			cout << total_count << ": ";
			dump(ret);
			return;
		}
		for(int i = 1 ; i <= n ; ++i) {
			if(!used[i-1]) {
				used[i-1] = true;
				st.push(i);
				backtrack();
				st.pop();
				used[i-1] = false;
			}
		}
	};
	backtrack();

	cout << "\nPermutation(" << n << "), total_count: " << total_count << endl;
}

int main() {

	create_permutation(3);
	return 0;
}