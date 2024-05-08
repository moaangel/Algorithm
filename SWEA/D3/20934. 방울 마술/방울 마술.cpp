#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int k;
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
		int ret = 0;
		string s;
		cin >> s >> k;
		if (s == ".o.") {
			if (k % 2 == 0) ret = 1;
			else ret = 0;
		}
		else if (s == "..o") {
			if (k == 0) ret = 2;
			else if (k % 2 == 0) ret = 0;
			else ret = 1;
		}
		else {
			if (k % 2 == 0) ret = 0;
			else ret = 1;
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}