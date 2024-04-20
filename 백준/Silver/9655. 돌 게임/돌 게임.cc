#include <iostream>

using namespace std;

int dp[1002];
int n, ret;

void go(int cnt, int win) {
	if (cnt == n) {
		ret = win;
	}
	if (cnt > n) {
		return;
	}

	go(cnt + 1, (1^win));
	go(cnt + 3, (1 ^ win));
}

int main() {
	cin >> n;
	if (n % 2 == 1) cout << "SK" << '\n';
	else cout << "CY" << '\n';
}