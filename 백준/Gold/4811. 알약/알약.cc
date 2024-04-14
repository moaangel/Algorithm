#include <iostream>

typedef long long ll;
using namespace std;

ll dp[31][31];

ll go(int w, int h) {
	if (w == 0 && h == 0) {
		return 1;
	}
	ll &ret = dp[w][h];
	if (ret) return ret;

	if (w > 0) ret += go(w - 1, h + 1);
	if (h > 0) ret += go(w, h - 1);

	return ret;
}

int main() {
	for (int tc = 0; tc <= 1000; tc++) {
		int n;
		cin >> n;
		if (n == 0)	return 0;
		cout << go(n, 0) << '\n';
	}
}