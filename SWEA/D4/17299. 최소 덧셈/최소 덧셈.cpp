#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

string s;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ret = 0;
		cin >> s;
		if (s.size() % 2 == 0) {
			int temp = 0;
			for (int i = 0; i < s.size() / 2; i++) {
				temp *= 10;
				temp += s[i] - '0';
			}
			ret += temp;
			temp = 0;
			for (int i = s.size() / 2; i < s.size(); i++) {
				temp *= 10;
				temp += s[i] - '0';
			}
			ret += temp;
		}
		else {
			string a, b;
			for (int i = 0; i < s.size()/2; i++) {
				a += s[i];
			}
			for (int i = s.size() / 2; i < s.size(); i++) {
				b += s[i];
			}
			ret = (stoi(a) + stoi(b));
			a.clear();
			b.clear();
			for (int i = 0; i < s.size() / 2 +1; i++) {
				a += s[i];
			}
			for (int i = s.size() / 2 +1; i < s.size(); i++) {
				b += s[i];
			}
			int temp = (stoi(a) + stoi(b));
			ret = min(ret, temp);
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}