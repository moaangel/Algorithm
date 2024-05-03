#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

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
		int ret = 0;
		if (v.size()) v.clear();
		cin >> n;
		for (int i = 0; i < 2; i++) {
			string s;
			cin >> s;
			v.push_back(s);
		}
		for (int i = 0; i < n; i++) {
			if (v[0][i] == v[1][i])ret++;
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}