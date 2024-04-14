#include <iostream>

using namespace std;

int dp[21][21][21];

int go(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	if (a > 20 || b > 20 || c > 20)
		return go(20, 20, 20);

	if (dp[a][b][c]) return dp[a][b][c];

	if (a < b && b < c) return dp[a][b][c] = go(a, b, c - 1) + go(a, b - 1, c - 1) - go(a, b - 1, c);

	else return dp[a][b][c] = go(a - 1, b, c) + go(a - 1, b - 1, c) + go(a - 1, b, c - 1) - go(a - 1, b - 1, c - 1);
}

int main() {
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << go(a, b, c) << '\n';
	}
}