#include <iostream>

using namespace std;

bool che[4000001];
int a[2000001];
int n, p, sum,s,e, ret;

int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (che[i]) continue;
		for (int j = i * 2; j <= n; j += i) {
			che[j] = 1;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (!che[i]) a[p++] = i;
	}

	while (1) {
		if (sum >= n)sum -= a[s++];
		else if (e == p)break;
		else sum += a[e++];
		if (sum == n) ret++;
	}
	cout << ret << '\n';
}