#include <iostream>

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
		cin >> n;
		int ret = 0;
		for (int i = 1; i <= n; i++) {
			int temp = 0;
			for (int j = i; j <= n; j++) {
				temp += j;
				if (temp == n) {
					ret++;
					break;
				}
				if (temp > n)break;
			}
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}