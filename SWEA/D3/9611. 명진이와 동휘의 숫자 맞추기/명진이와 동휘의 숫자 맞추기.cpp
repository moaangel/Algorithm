#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int num[10];
int n;
vector<string> v;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ret = 0;
		fill(num, num + 10, 1);
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b, c, d;
			string s;
			cin >> a >> b >> c >> d >> s;
			if (s == "YES") {
				num[a]++;
				num[b]++;
				num[c]++;
				num[d]++;
			}
			else {
				num[a]--;
				num[b]--;
				num[c]--;
				num[d]--;
			}
		}
		int mx = 0;
		for (int i = 0; i < 10; i++) {
			if (num[i] > mx) {
				ret = i;
				mx = num[i];
			}
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}