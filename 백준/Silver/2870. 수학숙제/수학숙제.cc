#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n;
string s;
string ret;
vector<string> v;
void go() {
	while (1) {
		if (ret.size() && ret.front() == '0') ret.erase(ret.begin());
		else break;
	}
	if (ret.size() == 0) ret = "0";
	v.push_back(ret);
	ret = "";
}

bool cmp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		ret = "";
		for (int j = 0; j < s.length(); j++) {
			if (s[j] < 65) ret += s[j];
			else if (ret.size()) go();
		}
		if (ret.size()) go();
	}
	sort(v.begin(), v.end(), cmp);
	for (string s : v)
		cout << s << '\n';
}