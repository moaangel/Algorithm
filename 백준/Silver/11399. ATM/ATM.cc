#include <iostream>
#include <algorithm>
using namespace std;

int a[1002];
int n,ret;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a,a+n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			ret += a[j];
		}
	}
	cout << ret << endl;
}