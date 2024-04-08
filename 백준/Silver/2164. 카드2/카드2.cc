#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	while (1) {
		q.pop();
		if (q.size() == 1)
			break;
		int temp = q.front();
		q.pop();
		q.push(temp);
	}
	cout << q.front() << endl;
}