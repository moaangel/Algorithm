#include<iostream>

using namespace std;

int n,ret;
int visited[10000];
int a[1002];
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		fill(visited, visited + 10000, 0);
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			visited[a[i]] = 1;
		}
		for (int i = 0; i < n - 1; i++) {
			int temp = a[i] * 10 + a[i + 1];
			visited[temp] = 1;
		}
		for (int i = 0; i < n - 2; i++) {
			int temp = a[i] * 100 + a[i + 1] * 10 + a[i + 2];
			visited[temp] = 1;
		}
		for (int i = 0; i < 10000; i++) {
			if (!visited[i]) {
				ret = i;
				break;
			}
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}