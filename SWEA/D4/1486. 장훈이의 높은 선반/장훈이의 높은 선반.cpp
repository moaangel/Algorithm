#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;
   
int n, b, ret=2000000;
int a[22];

void go(int idx, int sum) {
	if (idx == n) {
		if (sum >= b)
			ret = min(ret, sum - b);
		return;
	}

	go(idx + 1, sum + a[idx]);
	go(idx + 1, sum);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		ret = 2000000;
		cin >> n >> b;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		go(0, 0);
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;
}
