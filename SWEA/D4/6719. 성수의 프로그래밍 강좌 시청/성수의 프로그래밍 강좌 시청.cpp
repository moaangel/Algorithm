#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, k;
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
		double ret = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		for (int i = n - k; i < n; i++) {
			ret += v[i];
			ret /= 2;
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}