#include <iostream>
#include <vector>
using namespace std;


vector<int>v;
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
		if (v.size())v.clear();
		int ret = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		int avg = 0;
		for (int a : v) {
			avg += a;
		}
		avg /= n;
		for (int a : v) {
			if (a > avg) ret += a - avg;
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}