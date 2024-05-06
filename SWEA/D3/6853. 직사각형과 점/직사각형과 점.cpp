#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n,sx,ex,sy,ey;
int main(int argc, char** argv)
{

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int a[3] = { 0, };
		cin >> sx >> sy >> ex >> ey;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;

			if (x == sx || x == ex) {
				if (y >= sy && y <= ey) {
					a[1]++;
					continue;
				}
			}
			if (y == sy || y == ey) {
				if (x >= sx && x <= ex) {
					a[1]++;
					continue;
				}
			}
			if (y > sy && y < ey && x > sx && x < ex) {
				a[0]++;
				continue;
			}
			else a[2]++;
		}
		cout << "#" << test_case << " ";
		for (int i = 0; i <= 2; i++) {
			cout << a[i] << " ";
		}
		cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}