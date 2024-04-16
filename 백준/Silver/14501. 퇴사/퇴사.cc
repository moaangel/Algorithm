#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int n;
int dp[16][15002];
int go(int t, int p) {
	if (t == n)	return p;
	if (t > n) return 0;

	int &ret = dp[t][p];
	if (ret) return ret;
	ret += max(go(t + 1, p), go(t + v[t].first, p+ v[t].second));
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t, p;
		cin >> t >> p;
		v.push_back({ t,p });
	}
	cout << go(0, 0)<< '\n';
}