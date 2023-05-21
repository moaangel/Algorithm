#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int a[1001];
map<int, int> ma,mafirst;
vector<pair<int,int>> v;

int n, c;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return mafirst[a.second] < mafirst[b.second];
	return a.first > b.first;
}
int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ma[a[i]] += 1;
		if (mafirst[a[i]] == 0) mafirst[a[i]] = i + 1;
	}
	for (auto num : ma) {
		v.push_back({ num.second, num.first });
	}
	sort(v.begin(), v.end(), cmp);
	for (auto i : v) {
		for (int j = 0; j < i.first; j++) {
			cout << i.second << " ";
		}
	}
}