#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int n, m, ret;
vector<int> v;
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cout.precision(6);
	cout << fixed;

	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{	
		if (v.size())v.clear();
		ret = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		if (v.size() % 2 == 0) ret = v[0] * v[v.size() - 1];
		else ret = v[v.size() / 2] * v[v.size() / 2];
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}