#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
map<string, int> md;
vector<string> dv;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		md[s] = 1;
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (md[s] == 1)
			dv.push_back(s);
	}
	int k = dv.size();
	cout << k << '\n';
	sort(dv.begin(), dv.end());
	for (int i = 0; i < k; i++) {
		cout << dv[i] << '\n';
	}
	return 0;
}