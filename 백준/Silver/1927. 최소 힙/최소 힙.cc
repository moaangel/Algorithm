#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			if (pq.size()) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else {
				cout << 0 << '\n';
			}
		}
		else {
			pq.push(num);
		}
	}
}