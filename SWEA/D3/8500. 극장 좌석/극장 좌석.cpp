#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int a[10004];
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ret = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		ret += 2 * a[0] + 1;
		for (int i = 1; i < n; i++) {
			if (a[i] > a[i - 1])ret += a[i] - a[i - 1];
			ret += a[i] + 1;
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}