#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int a[1000001];
char d;
int s, e;
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	a[0] = a[1] = 1;
	for (int i = 2; i < 1000001; i++) {
		if (a[i] != 0)continue;
		for (int j = i * 2; j < 1000001; j += i) {
			a[j] = 1;
		}
	}

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{	
		int ret = 0;
		cin >> d >> s >> e;
		for (int i = s; i <= e; i++) {
			if (a[i] == 0) {
				string temp;
				temp = to_string(i);
				bool flag = 0;
				for (int j = 0; j < temp.size(); j++) {
					if (temp[j] == d) {
						flag = 1;
						break;
					}
				}
				if (flag) ret++;
			}
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}