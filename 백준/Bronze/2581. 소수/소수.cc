#include <iostream>
#include <algorithm>
using namespace std;

int n, m, sumret=0,minret=10001;
bool flag;
int main() {
	cin >> n >> m;
	for (int i = n; i <= m; i++) {
		if (i == 1)
			continue;
		flag = 0;
		for (int j = 1; j <= i; j++) {
			if (j != 1 && j != i && i % j == 0) {
				flag = 1;
				break;
			}
		}
		if (flag)
			continue;
		else {
			sumret += i;
			minret = min(minret, i);
		}
	}
	if (minret == 10001)
		cout << "-1" << endl;
	else
		cout << sumret << '\n' << minret << endl;
}