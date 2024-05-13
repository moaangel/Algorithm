#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

int a[1002];
int check[1002];
int n, m;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		fill(check, check + 1002, 0);
		int ret = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			int num;
			cin >> num;
			for (int j = 1; j <= n; j++) {
				if (a[j] <= num) {
					check[j]++;
					break;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (ret < check[i]) {
				ret = check[i];
				ans = i;
			}
		}
		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}