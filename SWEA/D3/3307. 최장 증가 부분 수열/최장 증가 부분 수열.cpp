#include <iostream>
#include <algorithm>
using namespace std;

int visited[1002];
int a[1002];
int T,n;
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		fill(visited, visited + 1002, 1);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i < n; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (a[i] > a[j])
					visited[i] = max(visited[i], visited[j] + 1);
			}
		}
		int ret = 0;
		for (int i = 0; i < n; i++) {
			ret = max(ret, visited[i]);
		}
		cout << "#" << tc << " " << ret << '\n';
	}
}