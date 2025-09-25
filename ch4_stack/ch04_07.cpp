#include <iostream>
using namespace std;
#include <chrono>
#include <thread>  // 只是用來示範延遲

//#define DEBUG 1
void run_recursive_none(int n) {

#ifdef DEBUG
	for(int i = 0 ; i < n ; ++i) {
		cout << i << ' ';
	} cout << endl;
#endif

	// 開始時間
    auto start = std::chrono::high_resolution_clock::now();

    // 模擬耗時的程式 (例如延遲 2 秒)
    std::this_thread::sleep_for(std::chrono::seconds(2));

	for(int i = 0 ; i < n ; ++i) {
		function<int(int)> backtrace = [&](int i) -> int {
			if (i == 0) return 0;
			else if (i == 1) return 1;
			else
				return backtrace(i - 1) + backtrace(i-2);
		};
//#ifdef DEBUG
		cout << backtrace(i) << ' ';
//#endif
	}

    // 結束時間
    auto end = std::chrono::high_resolution_clock::now();

    // 計算耗時 (轉成毫秒)
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	cout << "\nrun_recursive_none fib(" << n << "): \n";
    std::cout << "\n花費時間: " << duration.count() << " 毫秒\n";
}

int output[100] = {0};
void dump_output(int n) {

	cout << "\n\n output(n): "; 
	for(int i = 0 ; i < n ; ++i) {
		cout << "(" << i << "): " << output[i] << ' ';
	}
	cout << endl;
}

// DPA: Dynamic Programming Algorithm
void run_recursive_DPA(int n) {

#ifdef DEBUG
	for(int i = 0 ; i < n ; ++i) {
		cout << i << ' ';
	} cout << endl;
#endif

	// 開始時間
    auto start = std::chrono::high_resolution_clock::now();

    // 模擬耗時的程式 (例如延遲 2 秒)
    std::this_thread::sleep_for(std::chrono::seconds(2));

	for(int i = 0 ; i < n ; ++i) {
		function<int(int)> backtrace = [&](int i) -> int {
			int result = output[i];
			if (result == 0) {
				if (i == 0) return 0;
				else if (i == 1) return 1;
				else
					return backtrace(i - 1) + backtrace(i-2);
			}
			return result;
		};
		output[i] = backtrace(i);
//#ifdef DEBUG
		cout << output[i] << ' ';
//#endif
	}

    // 結束時間
    auto end = std::chrono::high_resolution_clock::now();

    // 計算耗時 (轉成毫秒)
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	cout << "\nrun_recursive_DPA fib(" << n << "): \n";
    std::cout << "\n花費時間: " << duration.count() << " 毫秒\n";

#ifdef DEBUG
	dump_output(n);
#endif
}
/*
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 
28657 46368 75025 121393 196418 317811 514229 832040 1346269 2178309 3524578 5702887 9227465 14930352 24157817 39088169 63245986

run_recursive_none fib(40):
花費時間: 11052 毫秒

0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 
28657 46368 75025 121393 196418 317811 514229 832040 1346269 2178309 3524578 
5702887 9227465 14930352 24157817 39088169 63245986

run_recursive_DPA fib(40):
花費時間: 2000 毫秒
*/
int main() {
	int n = 40;
	run_recursive_none(n);
	run_recursive_DPA(n);
	return 0;
}