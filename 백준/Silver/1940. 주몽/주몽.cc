#include <iostream>
#include <map>
#include <string>
using namespace std;

int a[15002];
int n, m,ret;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] == m) {
				ret++;
				break;
			}
		}
	}
	cout << ret << '\n';
}