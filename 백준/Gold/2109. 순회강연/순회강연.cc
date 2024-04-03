#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int n,ret;
vector<pair<int, int>> v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p, d;
		cin >> p >> d;
		v.push_back({ d,p });
	}
	sort(v.begin(), v.end());
	
	priority_queue<int,vector<int>,greater<int>> pq;
	for (int i = 0; i < n; i++) {
		pq.push(v[i].second);
		if (pq.size() > v[i].first)
			pq.pop();
	}
	while (pq.size()) {
		ret += pq.top();
		pq.pop();
	}
	cout << ret << '\n';
}