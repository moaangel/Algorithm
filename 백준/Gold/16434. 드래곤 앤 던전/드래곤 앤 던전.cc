#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

struct dungeon
{
	ll ty, atk, hp;
};

vector<dungeon> v;
ll n, hatk, r, ret;

bool check(ll starthp) {
	ll nowhp = starthp;
	ll nowatk = hatk;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].ty == 1) {
			ll cnt = v[i].hp / nowatk + (v[i].hp % nowatk ? 1 : 0);
			nowhp -= (cnt -1) * v[i].atk;
		}
		else {
			if (nowhp + v[i].hp > starthp)
				nowhp = starthp;
			else
				nowhp += v[i].hp;
			nowatk += v[i].atk;
		}
		if (nowhp <= 0)return false;
	}
	return true;
}

int main() {
	cin >> n >> hatk;
	for (int i = 0; i < n; i++) {
		ll t, a, h;
		cin >> t >> a >> h;
		v.push_back({ t,a,h });

	}
	r = 1e18+4;
	ll l = 1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (check(mid)) {
			ret = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ret << '\n';
}