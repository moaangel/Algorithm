#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
double a[18][18];
double ret;
int sa[18];

void go(int here, double tmp) {
	if (here == n) {
		ret = max(ret, tmp);
		return;
	}
	if (tmp < ret) return;
	if (tmp == 0) return;

	for (int i = 0; i < n; i++) {
		if (!sa[i]) {
			sa[i] = 1;
			go(here + 1, tmp * a[here][i]);
			sa[i] = 0;
		}
	}
}

int main(int argc, char** argv)
{
	cout.precision(6);
	cout << fixed;
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ret = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				double num;
				cin >> num;
				a[i][j] = num/100;
			}
		}
		
		go(0, 1);
		cout << "#" << test_case << " " << ret * 100 << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}