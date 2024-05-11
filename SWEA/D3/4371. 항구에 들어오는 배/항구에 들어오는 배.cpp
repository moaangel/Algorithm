#include<iostream>
#include <vector>
#include <queue>

using namespace std;

int a[5002];
int visited[5002];
int n;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		fill(visited, visited + 5002, 0);
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			a[i] = num;
		}
		int ret = 0;
		for (int i = 1; i < n; i++) {
			if (!visited[i])ret++;
			int temp = a[i];
			int gap = a[i] - 1;
			visited[i] = 1;
			for (int j = i+1; j < n; j++) {
				if (a[j] == temp + gap) {
					visited[j] = 1;
					temp = a[j];
				}
				else if (a[j] > temp + gap)break;

			}
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;
}