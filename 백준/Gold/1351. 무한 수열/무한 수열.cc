#include <iostream>

using namespace std;

int dp[1000002];
long long n, p, q, ret;

long long go(long long num) {
	if (num == 0) return 1;

	if (num < 1000002)
		if (dp[num]) return dp[num];
		else return dp[num] = go(num / q) + go(num / p);
	else
		return go(num / q) + go(num / p);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> p >> q;
	dp[0] = 1;
	
	
	cout << go(n) << '\n';
}