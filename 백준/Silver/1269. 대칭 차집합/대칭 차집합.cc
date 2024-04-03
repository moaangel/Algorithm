#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m, acnt, bcnt, samecnt;
map<int, int> mp;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		mp[a] = 1;
		acnt++;
	}
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		if (mp[a] == 1)
			samecnt++;
		bcnt++;
	}
	cout << acnt + bcnt - (2 * samecnt) << '\n';
}