#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, score, p;
vector<int> v;
int main() {
	cin >> n >> score >> p;
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		v.push_back(num);
	}
	if (n == 0) {
		cout << 1 << endl;
		return 0;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (i + 1 == p) {
			if (v[i] < score)
				cout << i + 1 << endl;
			else
				cout << -1 << endl;
			return 0;
		}
		if (v[i] == score) {
			int temp = i;
			bool flag = true;
			while (temp < v.size()) {
				if (v[temp] == score) {
					temp++;
				}
				else {
					break;
				}
			}
			if (temp+1 > p) {
				flag = false;
			}

			if (flag) {
				cout << i + 1 << endl;
				return 0;
			}
			else {
				cout << -1 << endl;
				return 0;
			}

		}
		if (v[i] < score) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << v.size() + 1 << endl;
}