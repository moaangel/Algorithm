#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int ret;
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int tmp = s[i] - 'A';
		if (tmp >= 0 && tmp <= 2)
			ret += 3;
		else if (tmp >= 3 && tmp <= 5)
			ret += 4;
		else if (tmp >= 6 && tmp <= 8)
			ret += 5;
		else if (tmp >= 9 && tmp <= 11)
			ret += 6;
		else if (tmp >= 12 && tmp <= 14)
			ret += 7;
		else if (tmp >= 15 && tmp <= 18)
			ret += 8;
		else if (tmp >= 19 && tmp <= 21)
			ret += 9;
		else
			ret += 10;
	}
	cout << ret << endl;
}