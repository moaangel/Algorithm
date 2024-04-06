#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> a;
int t, k,ret;
vector<pair<int, int>> v;

void roll(vector<pair<int,int>> &v) {
	for (int i = 0; i < v.size(); i++) {
		int idx = v[i].first;
		string ret;
		if (v[i].second == 1) {
			ret += a[idx][7];
			for (int i = 0; i < 7; i++) {
				ret += a[idx][i];
			}
		}
		else {
			for (int i = 1; i < 8; i++) {
				ret += a[idx][i];
			}
			ret += a[idx][0];
		}
		a[idx] = ret;
	} 
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		a.push_back(s);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		if (v.size())
			v.clear();
		int num, b;
		cin >> num >> b;
		int realb = b;
		v.push_back({ num-1,b });
		for (int j = num; j < t; j++) {
			if (a[j - 1][2] != a[j][6]) {
				b = -b;
				v.push_back({ j,b });
			}
			else break;
		}
		b = realb;
		for (int j = num - 2; j >= 0; j--) {
			if (a[j][2] != a[j + 1][6]) {
				b = -b;
				v.push_back({ j,b });
			}
			else break;
		}
		roll(v);
	}
	for (int i = 0; i < t; i++) {
		if (a[i][0] == '1')
			ret++;
	}
	cout << ret << '\n';
}