#include <iostream>
#include <algorithm>

using namespace std;
int a[9];
int n, m;

void go(int idx) {
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << " ";
		}
		cout << '\n';
		return;
	}


	for (int i = 1; i <= n; i++) {
		if (idx != 0 && a[idx - 1] > i)continue;
		a[idx] = i;
		go(idx + 1);
	}
}

int main() {
	cin >> n >> m;
	go(0);
}