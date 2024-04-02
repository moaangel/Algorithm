#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int n,ret;
int main() {
	string s;
	cin >> s;
	cin >> n;
	for (int i = s.size() - 1; i >= 0; i--) {
		int temp = 0;
		if (s[i] >= 'A')temp += s[i] - 'A' + 10;
		else temp += s[i] - '0';
		ret += temp * pow(n, s.size() - 1 - i);
		temp = 0;
	}
	cout << ret << endl;
}