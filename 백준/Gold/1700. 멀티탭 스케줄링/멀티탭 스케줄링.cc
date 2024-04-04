#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k, ret;
int a[104];
int visited[104];
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
				for (int tmp : v) {
					int here = 200;
					for (int j = i + 1; j < k; j++) {
						if (tmp == a[j]) {
							here = j;
							break;
						}
					}
					if (here > last) {
						last = here;
						pos = tmp;
					}
				}
				visited[pos] = 0;
				ret++;
				v.erase(find(v.begin(), v.end(), pos));
			}		
			v.push_back(a[i]);
			visited[a[i]] = 1;
		}
	}
	cout << ret << '\n';
}