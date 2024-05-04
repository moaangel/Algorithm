#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

vector<int> v;
vector<int> ret[11];
int n, k;

void go(int start, int end, int d) {
	if (start == end) {
		ret[d].push_back(v[start]);
		return;
	}
	int num = (start + end) / 2;
	ret[d].push_back(v[num]);
	go(start, num - 1, d + 1);
	go(num + 1, end, d + 1);
}

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
		for (int i = 1; i < 11; i++) {
			if (ret[i].size())ret[i].clear();
		}
		if (v.size()) v.clear();
		cin >> n;
		int range = pow(2, n) - 1;
		for (int i = 0; i < range; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		go(0, range-1, 1);
		cout << "#" << test_case << " ";
		for (int i = 1; i <= n; i++) {
			for (int num : ret[i]) {
				cout << num << " ";
			}
			cout << '\n';
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}