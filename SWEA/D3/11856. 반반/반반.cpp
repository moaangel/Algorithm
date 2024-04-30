#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<char> v;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		if (v.size())v.clear();
		string s;
		cin >> s;
		for (int i = 0; i < 4; i++) {
			v.push_back(s[i]);
		}
		sort(v.begin(), v.end());
		cout << "#" << test_case << " ";
		if (v[0] == v[1] && v[2] == v[3] && v[1] != v[2])cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}