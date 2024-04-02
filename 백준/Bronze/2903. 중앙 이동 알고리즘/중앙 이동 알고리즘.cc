#include <iostream>

using namespace std;

int ret;
int main() {
	int n;
	cin >> n;
	int a = 2;
	for (int i = 1; i <= n; i++) {
		a += (a - 1);
	}
	cout << a * a << endl;
}