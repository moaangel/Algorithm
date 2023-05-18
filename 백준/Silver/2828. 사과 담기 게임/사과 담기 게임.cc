#include <iostream>

using namespace std;


int n, m, j, goal, ret, l, r;
int main() {
	cin >> n >> m >> j;
	l = 1;
	for (int i = 0; i < j; i++) {
		r = l + m - 1;
		cin >> goal;
		if (goal >= l && goal <= r) continue;
		if (goal > r) {
			ret += goal - r;
			r = goal;
			l = r - m + 1;
		}
		else {
			ret += l - goal;
			l = goal;
			r = l + m - 1;
		}
	}
	cout << ret;
}