#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
vector<pair<int, int>> v;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		if (v.size())v.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end());
		int ret = 0;
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				if (v[i].second > v[j].second) ret++;
			}
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;
}