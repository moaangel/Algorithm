#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;

int n, m, ret;
vector<string> v;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ret = 0;
		if (v.size())v.clear();
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			v.push_back(s);
		}
		for (int i = 0; i < n; i++) {
			string temp;
			temp = v[i];
			reverse(temp.begin(), temp.end());
			for (int j = i + 1; j < n; j++) {
				if (temp == v[j])ret += (2 * m);
			}
		}
		for (int i = 0; i < n; i++) {
			string temp;
			temp = v[i];
			reverse(temp.begin(), temp.end());
			if (temp == v[i]) {
				ret += m;
				break;
			}
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}