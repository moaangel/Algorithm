#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
int n, k;
ll ret;
vector<pair<ll, ll>> vo;
vector<ll> v;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		ll m, p;
		cin >> m >> p;
		vo.push_back({ m,p });
	}
	for (int i = 0; i < k; i++) {
		ll bag;
		cin >> bag;
		v.push_back(bag);
	}
	sort(vo.begin(), vo.end());
	sort(v.begin(), v.end());
	int j = 0;
	priority_queue<long long> pq;
	for (int i = 0; i < k; i++) {
		while (j < n && vo[j].first <= v[i])pq.push(vo[j++].second);
		if (pq.size()) {
			ret += pq.top();
			pq.pop();
		}
	}
	cout << ret << '\n';
}