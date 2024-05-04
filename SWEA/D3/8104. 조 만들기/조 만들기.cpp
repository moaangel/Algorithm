#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int a[22];
int n, k;
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
		fill(a, a + 22, 0);
		cin >> n >> k;
		int ret = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= k; j++) {
				int num = (i * k) + j;
				if (i % 2 == 0) a[j] += num;
				else a[k - j + 1] += num;
			}
			
		}
		cout << "#" << test_case << " ";
		for (int i = 1; i <= k; i++) {
			cout << a[i] << " ";
		}
		cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}