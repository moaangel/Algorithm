#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n,b,e;
int a[10004];
vector<int> v;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		if (v.size())v.clear();
		int ret = 0;
		cin >> n >> b >> e;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		for (int i = 0; i < n; i++) {
			int num = v[i];
			for (int j = num; j <= b + e; j += num) {
				if (j >= b - e && j <= b + e) {
					ret++;
					break;
				}
			}
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}