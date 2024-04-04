#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[104];
int visited[104];
int n, k,ret;
vector<int> v;
int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < k; i++) {
		if (!visited[a[i]]) {
			if (v.size() == n) {
				int last = 0, pos;
				for (int tem : v) {
					int here = 104;
					for (int j = i + 1; j < k; j++) {
						if (a[j] == tem) {
							here = j;
							break;
						}
					}
					if (here > last) {
						last = here;
						pos = tem;
					}
				}
				visited[pos] = 0;
				ret++;
				v.erase(find(v.begin(), v.end(), pos));
			}
			visited[a[i]] = 1;

			v.push_back(a[i]);
		}
	}
	cout << ret << '\n';
}