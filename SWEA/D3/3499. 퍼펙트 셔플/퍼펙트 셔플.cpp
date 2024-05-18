#include <iostream>
#include <vector>
#include <string>
using namespace std;

int T, n;
vector<string> a;
vector<string> b;
int main() {
	cin >> T;
	for (int test_caes = 1; test_caes <= T; test_caes++) {
		a.clear();
		b.clear();
		cin >> n;
		if (n % 2) {
			for (int i = 0; i <= n/2; i++) {
				string s;
				cin >> s;
				a.push_back(s);
			}
			for (int i = n / 2 + 1; i < n; i++) {
				string s;
				cin >> s;
				b.push_back(s);
			}
		}
		else {
			for (int i = 0; i < n / 2; i++) {
				string s;
				cin >> s;
				a.push_back(s);
			}
			for (int i = n / 2; i < n; i++) {
				string s;
				cin >> s;
				b.push_back(s);
			}
		}
		cout << "#" << test_caes << " ";
		for (int i = 0; i < n / 2; i++) {
			cout << a[i] << " " << b[i] << " ";
		}
		if (n % 2)cout << a[a.size() - 1];
		cout << '\n';
	}
}