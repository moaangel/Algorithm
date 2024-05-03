#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int a[100002];
int n;
vector<string> v;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		fill(a, a + 100002, 0);
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			a[num] = 1;
		}
		bool flag = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) {
				flag = 0;
				break;
			}
		}
		if (flag)
			cout << "#" << test_case << " Yes" << '\n';
		else
			cout << "#" << test_case << " No" << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}