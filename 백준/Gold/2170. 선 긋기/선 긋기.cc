#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> L[1000004];
int n,ret;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> L[i].first >> L[i].second;
	}
	sort(L, L + n);
	int s = L[0].first;
	int e = L[0].second;
	for (int i = 1; i < n; i++) {
		if (L[i].first > e) {
			ret += (e - s);
			s = L[i].first;
			e = L[i].second;
		}
		else if (e >= L[i].first && e <= L[i].second) {
			e = L[i].second;
		}
	}
	ret += (e - s);
	cout << ret << '\n';
}