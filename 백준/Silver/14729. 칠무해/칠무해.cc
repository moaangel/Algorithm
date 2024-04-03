#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

priority_queue<double> pq;
vector<double> ret;
int n;
int main() {
	cout<<fixed;
	cout.precision(3);
	cin >> n;
	for (int i = 0; i < n; i++) {
		double a;
		cin >> a;
		pq.push(a);
		if (pq.size() > 7)
			pq.pop();
	}
	for (int i = 0; i < 7; i++) {
		double a = pq.top();
		ret.push_back(a);
		pq.pop();
	}
	sort(ret.begin(), ret.end());
	for (double a : ret) {
		cout << a << '\n';
	}
}