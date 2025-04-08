#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;
char c;
string s;
vector<string> v;
int main() {
	cin >> n;
	cin >> c;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	if (c == 'Y') {
		cout << v.size() << endl;
	}
	else if (c == 'F') {
		cout << v.size() / 2 << endl;
	}
	else {
		cout << v.size() / 3 << endl;
	}
}