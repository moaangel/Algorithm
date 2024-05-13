#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> cloth;
int n, t;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		if (cloth.size())cloth.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			cloth[b] += 1;
		}
		long long ret = 1;
		for (pair<string, int> a : cloth) {
			ret *= (a.second + 1);
		}
		ret--;
		cout << ret << '\n';
	}
	return 0;
}