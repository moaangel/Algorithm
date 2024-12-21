#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ret;
vector<int> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		int testNum = v[i];
		int s = 0;
		int e = v.size()-1;
		while (s < e) {
			if (s == i) {
				s++;
				continue;
			}
			if (e == i) {
				e--;
				continue;
			}
			if (v[s] + v[e] == testNum) {
				ret++;
				break;
			}
			if (v[s] + v[e] > testNum)e--;
			else s++;
		}
	}
	cout << ret << '\n';
}