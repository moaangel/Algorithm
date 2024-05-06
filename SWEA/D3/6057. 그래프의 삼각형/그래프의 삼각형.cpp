#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool a[52][52];
bool visited[52][52][52];
int n,m;
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
		fill(&a[0][0], &a[0][0] + 52 * 52, 0);
		fill(&visited[0][0][0], &visited[0][0][0] + 52 * 52 * 52, 0);
		int ret = 0;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int s, e;
			cin >> s >> e;
			a[s][e] = 1;
			a[e][s] = 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				for (int k = j + 1; k <= n; k++) {
					if (a[i][j] && a[j][k] && a[k][i] && !visited[i][j][k]) {
						ret++;
						visited[i][j][k] = 1; visited[i][k][j] = 1;
						visited[j][k][i] = 1; visited[j][i][k] = 1;
						visited[k][i][j] = 1; visited[k][j][i] = 1;
					}
				}
			}
		}

		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}