#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int a[1002];
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
		string s;
		cin >> s;
		if (s.size() == 1) {
			cout << "..#.." << '\n' << ".#.#." << '\n' << "#." << s << ".#" << '\n' << ".#.#." << '\n' << "..#.." << '\n';
		}
		else {
			for (int i = 0; i < s.size(); i++) {
				if (i == 0) cout << "..#..";
				else cout << ".#..";
			}
			cout << '\n';
			for (int i = 0; i < s.size(); i++) {
				if (i == 0) cout << ".#.#.";
				else cout << "#.#.";
			}
			cout << '\n';
			for (int i = 0; i < s.size(); i++) {
				if (i == 0) cout << "#." << s[i] << ".#";
				else cout << "." << s[i] << ".#";
			}
			cout << '\n';
			for (int i = 0; i < s.size(); i++) {
				if (i == 0) cout << ".#.#.";
				else cout << "#.#.";
			}
			cout << '\n';
			for (int i = 0; i < s.size(); i++) {
				if (i == 0) cout << "..#..";
				else cout << ".#..";
			}
			cout << '\n';
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}