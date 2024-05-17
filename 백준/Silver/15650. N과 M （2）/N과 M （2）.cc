#include <iostream>

using namespace std;

int n, m;
int a[9];
int visited[9];

void go(int here) {
	if (here == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i])continue;
		if (here != 0 && a[here - 1] > i)continue;
		visited[i] = 1;
		a[here] = i;
		go(here + 1);
		visited[i] = 0;
	}
}

int main() {
	cin >> n >> m;
	go(0);
}