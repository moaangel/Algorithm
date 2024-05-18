#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


char a[102][102];

int T, n, ret, num, cnt;

int main() {
	T = 10;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		ret = 1;
		for (int i = 0; i < 100; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < 100; j++) {
				a[i][j] = s[j];
			}
		}
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {

				for (int k = 99; k > j; k--) {
					if (a[i][j] == a[i][k] && k - j +1 > ret) {
						string temp, temp2;
						for (int l = j; l <= k; l++) {
							temp += a[i][l];
							temp2 += a[i][k + j - l];
						}
						if (temp2 == temp)ret = k - j + 1;
					}
				}
			}
		}
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {

				for (int k = 99; k > j; k--) {
					if (a[j][i] == a[k][i] && k - j + 1 > ret) {
						string temp, temp2;
						for (int l = j; l <= k; l++) {
							temp += a[l][i];
							temp2 += a[k + j - l][i];
						}
						if (temp2 == temp)ret = k - j + 1;
					}
				}
			}
		}

		cout << "#" << n << " " << ret << '\n';
	}
}