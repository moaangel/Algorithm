#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[9];
int temp[9];
int visited[9];

void go(int here) {
	if (here == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << " ";
		}
		cout << '\n';
		return;
	}

	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0 && temp[i] != tmp) {
			visited[i] = 1;
			a[here] = temp[i];
			tmp = a[here];
			go(here + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp[i];
	}
	sort(temp, temp + n);
	go(0);
}