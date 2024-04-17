#include <iostream>

using namespace std;

int a[1030][1030];
int psum[1030][1030];
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			psum[i][j] = psum[i][j - 1] + a[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int ret = 0;
		int sy, sx, ey, ex;
		cin >> sx >> sy >> ex >> ey;
		for (int i = sx; i <= ex; i++) {
			ret += psum[i][ey] - psum[i][sy-1];
		}
		cout << ret << '\n';
	}
}