#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

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
		unsigned long long a, b, n;
        cin >> n;
		a = (n - 1) * (n - 1) * 2 + 1;
		b = n * n * 2 - 1;

		cout << "#" << test_case << " " << a << " " << b << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}