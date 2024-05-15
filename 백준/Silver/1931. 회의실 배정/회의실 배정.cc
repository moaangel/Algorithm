#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({ e,s });
	}
	sort(v.begin(), v.end());
	int s = v[0].second;
	int e = v[0].first;
	int ret = 1;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].second >= e) {
			ret++;
			s = v[i].second;
			e = v[i].first;
		}
		else continue;
	}
	cout << ret << '\n';
}