#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
priority_queue<int,vector<int>,greater<int>> pq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num = 0;
			cin >> num;
			if (pq.size() >= n) {
				if (pq.top() < num) {
					pq.pop();
					pq.push(num);
				}
			}
			else
				pq.push(num);
		}
	}
	for (int i = 0; i < n; i++) {
		if (pq.size() == n) {
			cout << pq.top() << '\n';
			return 0;
		}
		pq.pop();
	}
}