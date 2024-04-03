#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k,cnt;
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	cin >> k;
	sort(v.begin(), v.end());
	int j = n - 1;
	for (int i = 0; i < n; i++) {
		for (j; j > i; j--) {
			if (v[i] + v[j] == k)
				cnt++;
			else if (v[i] + v[j] > k)
				continue;
			else break;
		}
	}
	cout << cnt << '\n';
}