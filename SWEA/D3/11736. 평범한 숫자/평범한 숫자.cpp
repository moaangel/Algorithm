#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int a[22];
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ret = 0;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i < n - 1; i++) {
			if (a[i] < a[i - 1] && a[i] > a[i + 1])ret++;
			if (a[i] > a[i - 1] && a[i] < a[i + 1])ret++;

		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}