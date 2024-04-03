#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> mp;
int n,m,cnt;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		mp[s] = 1;
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (mp[s] == 1)cnt++;
	}
	cout << cnt << '\n';
}