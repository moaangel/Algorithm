#include <iostream>

using namespace std;
typedef long long ll;

ll arr[100001], cnt[100001];
ll n,ret,s,e;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
	}
	while (e<n) {
		if (!cnt[arr[e]]) {
			cnt[arr[e]]++;
			e++;
		}
		else {
			ret += (e - s);
			cnt[arr[s]]--;
			s++;
		}
	}
	ret += (e - s) * (e - s + 1) / 2;
	cout << ret << '\n';
}