#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int a[15];
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
		for (int i = 2; i <= 11; i++) {
			a[i] = 4;
			if (i == 10) a[i] = 16;
		}
		cin >> n;
		int ret = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			ret += num;
			a[num]--;
		}
		for (int i = 2; i <= 11; i++) {
			if (ret + i > 21)cnt += a[i];
			else cnt -= a[i];
		}
		if (cnt >= 0) {
			cout << "#" << test_case << " STOP" << '\n';
		}
		else cout << "#" << test_case << " GAZUA" << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}