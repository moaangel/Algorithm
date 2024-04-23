#include <iostream>

using namespace std;

int n, ret;
int main() {
	cin >> n;
	if (n == 1 || n == 3) {
		cout << -1 << '\n';
		return 0;
	}
	ret += (n / 5);
	n %= 5;
	ret += (n / 2);
	n %= 2;
	if (n)ret += 2;
	cout << ret << '\n';
}