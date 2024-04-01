#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int sa[101][101];

int n,ret;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		for (int a = x; a < x + 10; a++) {
			for (int b = y; b < y + 10; b++) {
				if (sa[a][b] == 1)
					continue;
				sa[a][b] = 1;
				ret++;
			}
		}
	}
	cout << ret << endl;
}