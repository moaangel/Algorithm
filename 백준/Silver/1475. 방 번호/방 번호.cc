#include <iostream>
#include <string>
using namespace std;


string s;
int a[9];
int ret;

void fill() {
	ret++;
	for (int i = 0; i < 9; i++) {
		a[i]++;
		if (i == 6)a[i]++;
	}
}

int main() {
	cin >> s;
	fill();
	int n = 0;
	while (n != s.size()) {
		int temp = s[n] - '0';
		if (temp == 9) temp = 6;
		if (a[temp]) {
			a[temp]--;
			n++;
			continue;
		}
		else {
			fill();
			a[temp]--;
			n++;
			continue;
		}
	}
	cout << ret << '\n';
}