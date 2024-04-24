#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,ret;
vector<int> v;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		ret = 0;
		if (v.size())v.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			int absnum = abs(num);
			v.push_back(absnum);
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < n; i++) {
			if (v[i] == v[0])ret++;
			else break;
		}

		cout << "#" << test_case << " " << v[0] << " " << ret << '\n';
			
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}