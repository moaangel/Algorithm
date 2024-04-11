#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[1001];
int visited[1001];
int rea[1001];
int n,ret,eidx;
vector<int> v;
int main() {
	fill(visited, visited + 1001, 1);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && visited[i] <= visited[j]) {
				visited[i] = visited[j] + 1;
				rea[i] = j;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (ret < visited[i]) {
			ret = visited[i];
			eidx = i;
		}
	}
	while (1) {
		v.push_back(a[eidx]);

		if (visited[eidx] == 1) {
			break;
		}
		eidx = rea[eidx];
	}
	sort(v.begin(), v.end());
	cout << ret << '\n';
	for (int num : v) {
		cout << num << " ";
	}
}