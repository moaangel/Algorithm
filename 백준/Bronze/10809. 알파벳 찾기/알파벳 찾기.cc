#include <iostream>
#include <string>

using namespace std;

int n[26];
string s;
int main() {
	cin >> s;
	fill(n, n + 26, -1);
	for (int i = 0; i < s.size(); i++) {
		if (n[s[i] - 'a'] == -1)
			n[s[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << n[i] << " ";
	}
	cout << endl;
}