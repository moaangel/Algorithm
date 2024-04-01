#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string stradd(string a, string b) {
	int temp = 0;
	string ans;
	while (a.size() || b.size() || temp) {
		if (a.size()) {
			temp += a.back() - '0';
			a.pop_back();
		}
		if (b.size()) {
			temp += b.back() - '0';
			b.pop_back();
		}
		ans += (temp % 10) + '0';
		temp /= 10;
	}
	reverse(ans.begin(), ans.end());

	return ans;
}

string a,b;
int main() {
	cin >> a >> b;
	cout << stradd(a, b) << endl;
}