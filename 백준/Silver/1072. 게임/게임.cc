#include <iostream>

using namespace std;

typedef long long ll;
const ll INF = 1000000001;
ll x, y, winrate, ret= INF;

bool check(ll mid) {
	ll temp = (y + mid) * 100 / (x + mid);
	if (temp == winrate)return false;
	else return true;
}

int main() {
	cin >> x >> y;
	winrate = y * 100 / x;
	ll l = 0, r = 1000000000;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (check(mid)) {
			ret = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	if (ret == INF)
		cout << "-1" << '\n';
	else
		cout << ret << '\n';
}