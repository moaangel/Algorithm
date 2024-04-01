#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, mp, mf, ms, mv, ret = 10000;

int food[16][5];
vector<int> v;
void go(int num) {
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	vector<int> temp;
	for (int i = 0; i < n; i++) {
		if (num & (1 << i)) {
			a += food[i][0];
			b += food[i][1];
			c += food[i][2];
			d += food[i][3];
			e += food[i][4];
			temp.push_back(i + 1);
		}
	}

	if (a >= mp && b >= mf && c >= ms && d >= mv) {
		if (e < ret) {
			ret = e;
			v = temp;
			return;
		}
		else if (e == ret) {
			if (v.size() > temp.size()) {
				for (int l = 0; l < temp.size(); l++) {
					if (v[l] == temp[l])continue;
					else {
						if (v[l] > temp[l]) {
							v = temp;
							break;
						}
						else
							break;
					}
				}
			}
			else {
				for (int l = 0; l < v.size(); l++) {
					if (v[l] == temp[l])continue;
					else {
						if (v[l] > temp[l]) {
							v = temp;
							break;
						}
						else
							break;
					}
				}
			}
			return;
		}
	}
}

int main() {
	cin >> n;
	cin >> mp >> mf >> ms >> mv;

	for (int i = 0; i < n; i++) {
		cin >> food[i][0] >> food[i][1] >> food[i][2] >> food[i][3] >> food[i][4];
	}

	for (int i = 0; i < (1 << n); i++) {
		go(i);
	}

	if (ret == 10000) {
		cout << "-1" << endl;
	}
	else {
		cout << ret << '\n';
		for (int a : v) {
			cout << a << " ";
		}
	}
}