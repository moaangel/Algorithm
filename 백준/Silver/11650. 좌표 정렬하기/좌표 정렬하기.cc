#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>>v;
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	for (pair<int,int> num : v) {
		cout << num.first << " " << num.second << '\n';
	}
}