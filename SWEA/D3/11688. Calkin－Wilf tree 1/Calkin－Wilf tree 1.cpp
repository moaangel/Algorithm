#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int a[22];
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		pair<int, int> node = { 1,1 };
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'L') node.second = node.first + node.second;
			if (s[i] == 'R') node.first = node.first + node.second;
		}
		cout << "#" << test_case << " " << node.first << " " << node.second << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}