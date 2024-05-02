#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<int> v;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ret = 0;
		if (v.size())v.clear();
		cin >> n;
		int rng = pow(2, n);
		for (int i = 0; i < rng; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		while (1) {
			vector<int> temp;
			for (int i = 0; i < v.size(); i += 2) {
				int num = max(v[i], v[i + 1]);
				ret += abs(v[i]-v[i + 1]);
				temp.push_back(num);
			}
			if (temp.size() <= 1)break;
			v = temp;
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}