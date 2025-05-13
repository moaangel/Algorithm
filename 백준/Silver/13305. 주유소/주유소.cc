#include <iostream>

using namespace std;

int n;
int dist[100002], cost[100002];
int main() {
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> dist[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	long long ans = 0;
	int tempCost = cost[0];
	int tempDist = dist[0];
	for (int i = 1; i < n - 1; i++) {
		if (tempCost > cost[i]) {
			ans += tempCost * tempDist;
			tempCost = cost[i];
			tempDist = dist[i];
		}
		else {
			tempDist += dist[i];
		}
	}
	ans += tempDist * tempCost;
	cout << ans << endl;
}