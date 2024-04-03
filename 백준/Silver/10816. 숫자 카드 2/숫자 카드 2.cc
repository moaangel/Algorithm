#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

map<int, int> mp;
int n,m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		mp[a]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		if (mp[a])cout << mp[a] << " ";
		else cout << "0 ";
	}
}