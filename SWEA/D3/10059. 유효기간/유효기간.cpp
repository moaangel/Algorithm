#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s,ret;
		cin >> s;
		int fr, bk;
		fr = (s[0] - '0') * 10 + (s[1] - '0');
		bk = (s[2] - '0') * 10 + (s[3] - '0');
		if (fr >= 1 && fr <= 12) {
			if (bk >= 1 && bk <= 12) ret = "AMBIGUOUS";
			else ret = "MMYY";
		}
		else {
			if (bk >= 1 && bk <= 12) ret = "YYMM";
			else ret = "NA";
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;
}