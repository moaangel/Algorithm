#include<iostream>
#include <string>
#include<algorithm>
using namespace std;

string a, b, ret;

void cal(string a, string b) {
	bool up = false;
	if (a.size() > b.size()) {
		for (int i = 0; i < b.size(); i++) {
			int temp = (a[i] - '0') + (b[i] - '0');
			if (up) {
				temp++;
				up = false;
			}
			if (temp >= 10) {
				up = true;
				temp %= 10;
			}
			ret += temp + '0';
		}
		for (int i = b.size(); i < a.size(); i++) {
			if (up) {
				up = false;
				int temp = a[i] - '0';
				temp++;
				if (temp >= 10) {
					up = true;
					temp %= 10;
				}
				ret += temp + '0';
				continue;
			}
			ret += a[i];
		}
		if (up)ret += '1';
	}
	else if (a.size() == b.size()) {
		for (int i = 0; i < b.size(); i++) {
			int temp = (a[i] - '0') + (b[i] - '0');
			if (up) {
				temp++;
				up = false;
			}
			if (temp >= 10) {
				up = true;
				temp %= 10;
			}
			ret += temp + '0';
		}
		if (up)ret += '1';
	}
	else {
		for (int i = 0; i < a.size(); i++) {
			int temp = (a[i] - '0') + (b[i] - '0');
			if (up) {
				temp++;
				up = false;
			}
			if (temp >= 10) {
				up = true;
				temp %= 10;
			}
			ret += temp + '0';
		}
		for (int i = a.size(); i < b.size(); i++) {
			if (up) {
				up = false;
				int temp = b[i] - '0';
				temp++;
				if (temp >= 10) {
					up = true;
					temp %= 10;
				}
				ret += temp + '0';
				continue;
			}
			ret += b[i];
		}
		if (up)ret += '1';
	}
	reverse(ret.begin(), ret.end());
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
		ret = "";
		cin >> a >> b;
		if (a.size() != 1) {
			reverse(a.begin(), a.end());
		}
		if (b.size() != 1) {
			reverse(b.begin(), b.end());
		}
		cal(a, b);
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}