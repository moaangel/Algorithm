#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> mp;
vector<string> v;
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string n, w;
		cin >> n >> w;
		if (w == "enter")
			mp[n] = 1;
		else
			mp[n] = 0;
	}
	for (pair<string, int> a : mp) {
		if (a.second == 1)
			v.push_back(a.first);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (string s : v) {
		cout << s << '\n';
	}
}