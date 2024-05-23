#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
int n;
int ret = 1000000001;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 0; i < (1 << n); i++) {
		int sin=1, sseun=0, cnt =0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				sin *= v[j].first;
				sseun += v[j].second;
				cnt++;
			}
		}
		if (!cnt) continue;
		else {
			int temp = abs(sin - sseun);
			ret = min(ret, temp);
		}
	}

	cout << ret << '\n';
}