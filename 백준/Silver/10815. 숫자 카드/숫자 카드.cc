#include <iostream>
#include <map>

using namespace std;

map<int, int> mp;
int n, m;
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		mp[tmp] = 1;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		if (mp[tmp] == 1)cout << "1 ";
		else cout << "0 ";
	}
}