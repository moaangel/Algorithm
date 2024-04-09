#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int a[100002];
int n, m, tt;
ll ret = 1000000000;

bool check(int mid) {
	int sum = 0;
	int i = 0;
	int temp = 0;
	while (i != n && sum <= m) {
		temp += a[i];
		if (temp > mid) {
			temp = 0;
			sum++;
			continue;
		}
		else if (temp == mid) {
			temp = 0;
			sum++;
			i++;
			continue;
		}
		else i++;
		
	}
	if (temp)
		sum++;
	return m >= sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		tt += a[i];
	}
	int l = 1;
	int r = tt;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (check(mid)) {
			ret = min(ret, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ret << '\n';
}