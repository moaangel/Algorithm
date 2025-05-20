#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
vector<pair<int, string>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		int num;
		cin >> s >> num;
		v.push_back({ num,s });
	}
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		string ans;
		int l = 0, r = v.size()-1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (num > v[mid].first) {
				ans = v[mid + 1].second;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (ans == "")ans = v[0].second;
		cout << ans << '\n';
	}
}