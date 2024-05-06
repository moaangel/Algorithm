#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n;
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
		int ret = -100000000;
		cin >> n;
		int temp = 0;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			temp += num;
			ret = max(temp, ret);
			if (temp < 0)temp = 0;
		}

		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}