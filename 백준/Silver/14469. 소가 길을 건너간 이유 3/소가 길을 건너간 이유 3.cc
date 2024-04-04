#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,ret;
vector<pair<int, int>> v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	int s = v[0].first;
	int e = s + v[0].second;
	ret += s;
	for (int i = 1; i < n; i++) {
		if (v[i].first > e) {
			ret += (v[i].first - s);
			s = v[i].first;
			e = s + v[i].second;
		}
		else
			e += v[i].second;
	}
	ret += (e - s);
	cout << ret << '\n';
}