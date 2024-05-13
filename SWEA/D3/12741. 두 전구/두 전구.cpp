#include<iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int a, b, c, d;
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> a >> b >> c >> d;
		int s = max(a, c);
		int e = min(b, d);
		int ret = e - s;
		if (ret < 0) ret = 0;
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}