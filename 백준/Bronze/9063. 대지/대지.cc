#include <iostream>
#include <algorithm>
using namespace std;

int n, xl = -10001, xs = 10001, yl = -10001, ys = 10001;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		xl = max(xl, x);
		xs = min(xs, x);
		yl = max(yl, y);
		ys = min(ys, y);
	}
	cout << (xl - xs)*(yl - ys) << endl;
}