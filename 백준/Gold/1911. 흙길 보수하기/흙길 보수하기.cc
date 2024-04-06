#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l, idx, temp ,ret;
vector<pair<int, int>> v;
int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	int s = v[0].first;
	int e = v[0].second;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second <= idx) continue;
		if (idx < v[i].first) {
			temp = (v[i].second - v[i].first) / l;
			if ((v[i].second - v[i].first) % l)temp++;
			idx = v[i].first + (temp * l);
		}
		else {
			temp = (v[i].second - idx) / l;
			if ((v[i].second - idx) % l)temp++;
			idx = idx + (temp * l);
		}
		ret += temp;
	}
	cout << ret << '\n';
}