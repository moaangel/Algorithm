#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, ret;
vector<int> v;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	int now = k;
	while (now) {
		int best=0;
		for (int i = 0; i < n; i++) {
			if (now >= v[i])best = v[i];
			else break;
		}
		ret += (now / best);
		now -= (now / best * best);
	}
	cout << ret << '\n';
}