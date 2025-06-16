#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> v;
map<int, int> mp;
int n, k, ans;
int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		v.push_back(num);
	}
	int l = 0, r = 0;
	while (r < n) {
		if (mp[v[r]] < k) {
			ans = max(r - l + 1, ans);
			mp[v[r]]++;
			r++;
		}
		else {
			mp[v[l]]--;
			l++;
		}
	}
	cout << ans << endl;
}