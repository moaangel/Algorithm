#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<pair<string, int>> v;
vector<string> buylist;
int n,m;
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
		if (buylist.size())buylist.clear();
		int ret = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			string s;
			int num;
			cin >> s >> num;
			v.push_back({ s,num });
		}
		for (int i = 0; i < m; i++) {
			string s;
			cin >> s;
			buylist.push_back(s);
		}
		for (auto a : v) {
			for (string buy : buylist) {
				bool flag = 1;
				for (int i = 0; i < 8; i++) {
					if (a.first[i] == '*') continue;
					if (a.first[i] != buy[i]) {
						flag = 0;
						break;
					}
				}
				if (flag) ret += a.second;
			}
		}

		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}