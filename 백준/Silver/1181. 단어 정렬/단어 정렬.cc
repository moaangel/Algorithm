#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, string>a, pair<int, string>b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

vector<pair<int, string>>v;
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back({ (int)s.size(), s });
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) {
		if (i >= 1 && v[i].second == v[i - 1].second)
			continue;
		cout << v[i].second << '\n';
	}
}