#include <iostream>

using namespace std;

int visited[5002];
int T,n,p;
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		fill(visited, visited + 5002, 0);
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			for (int j = a; j <= b; j++) {
				visited[j]++;
			}
		}
		cin >> p;
		cout << "#" << tc << " ";
		for (int i = 0; i < p; i++) {
			int num;
			cin >> num;
			cout << visited[num] << " ";
		}
		cout << '\n';
	}
}