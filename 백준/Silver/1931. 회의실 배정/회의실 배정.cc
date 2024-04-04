#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,ret = 1;
vector<pair<int, int>> v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ b,a });
	}
	sort(v.begin(), v.end());
	int s = v[0].second;
	int e = v[0].first;
	for (int i = 1; i < n; i++) {
		if (v[i].second >= e) {
			ret++;
			s = v[i].second;
			e = v[i].first;
		}
		else
			continue;
	}
	cout << ret << '\n';
}