#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<char> v;
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		v.push_back(s[i]);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (char a : v) {
		cout << a - '0';
	}
}