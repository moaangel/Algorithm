#include <iostream>
#include <algorithm>
using namespace std;

int a[1001];
int visited[1001];
int n,ret;
int main() {
	fill(visited, visited + 1001, 1);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && visited[i] <= visited[j] ) visited[i] = visited[j] + 1;
		}
	}
	for (int i = 0; i < n; i++) {
		ret = max(ret, visited[i]);
	}
	cout << ret << '\n';
}