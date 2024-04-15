#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
pair<int, int> a[101], b[101];
int dp[101][100001];
int go(int here, int havetime) {
	if (here == n) {
		return 0;
	}
	int &ret = dp[here][havetime];
	if (ret) return ret;
    ret = -1e6;
	if (havetime - a[here].first >= 0) ret = max(ret, go(here + 1, havetime - a[here].first) + a[here].second);
	if (havetime - b[here].first >= 0) ret = max(ret, go(here + 1, havetime - b[here].first) + b[here].second);
	return ret;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int at, aw, bt, bw;
		cin >> at >> aw >> bt >> bw;
		a[i].first = at;
		a[i].second = aw;
		b[i].first = bt;
		b[i].second = bw;
	}

	cout << go(0, k) << '\n';
}