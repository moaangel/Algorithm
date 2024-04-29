#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
int a[1002];
int visited[1002];
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		fill(visited, visited + 1002, 1);
		int ret = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			a[i] = num;
		}
		for (int i = 1; i < n; i++) {
			for (int j = i-1; j >= 0; j--) {
				if (a[i] > a[j] && visited[i] <= visited[j]) {
					visited[i] = visited[j] + 1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			ret = max(ret, visited[i]);
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;
}