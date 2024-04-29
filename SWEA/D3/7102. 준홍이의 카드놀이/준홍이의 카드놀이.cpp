#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;

int a[42];
int n,m;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		fill(a, a + 42, 0);
		int ret = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				a[i + j]++;
				ret = max(ret, a[i + j]);
			}
		}
		cout << "#" << test_case << " ";
		for (int i = 1; i <= n + m; i++) {
			if (a[i] == ret) cout << i << " ";
		}
		cout << '\n';
	}
	return 0;
}