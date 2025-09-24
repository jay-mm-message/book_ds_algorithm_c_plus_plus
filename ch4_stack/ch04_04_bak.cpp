#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dump_vec(vector<int> &vec) {
	for (int i = vec.size() - 1; i >= 0; i--) 
		cout << vec[i] << " ";
	cout << endl;
}

void store(const stack<int> st, vector<int> &res) {
	stack<int> tmp = st;
	while(!tmp.empty()) {
		res.push_back(tmp.top());
		tmp.pop();
	}
}

void generate_permutations(int n) {
    vector<bool> used(n, false); // 紀錄哪些數字已經用過
    stack<int> st;               // 模擬遞迴的路徑
    int count = 0;

    function<void()> backtrack = [&]() {
        if (st.size() == n) {
            count++;
            cout << count << ": ";
            vector<int> res;

			store(st, res);
            // stack 是倒序的，要反轉一下
			dump_vec(res);
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (!used[i-1]) {
                used[i-1] = true;
                st.push(i);
                backtrack();   // 模擬遞迴
                st.pop();
                used[i-1] = false;
            }
		}
    };

    backtrack();
    cout << "總共有 " << count << " 種排列" << endl;
}

int main() {
    int n = 3;
    //cout << "輸入 n: ";
    //cin >> n;
    generate_permutations(n);
    return 0;
}
