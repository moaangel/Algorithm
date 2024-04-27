#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
int a[10], check[10];
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		fill(a, a + 10, 0);		
		cin >> n;
		string s = to_string(n);
		for (int i = 0; i < s.size(); i++) {
			a[s[i]-'0']++;
		}
		int temp = n;
		bool flag = 0;
		while (1) {
			temp += n;
			string scheck = to_string(temp);
			if (s.size() != scheck.size())break;
			fill(check, check + 10, 0);
			for (int i = 0; i < scheck.size(); i++) {
				check[scheck[i]-'0']++;
			}
			bool baesoo = 1;
			for (int i = 0; i < 10; i++) {
				if (a[i] != check[i]) baesoo = 0;
			}
			if (baesoo) { 
				flag = 1;
				break;
			}
		}
		cout << "#" << test_case << " ";
		if (flag) cout << "possible" << '\n';
		else cout << "impossible" << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}