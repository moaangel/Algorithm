#include <iostream>

using namespace std;

int n;
int a[1002];
int main() {
	a[1] = 1;
	a[2] = 2;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		a[i] = (a[i - 1] + a[i - 2]) % 10007;
	}
	cout << a[n] << '\n';
}