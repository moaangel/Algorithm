#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int a[8004];
int n,mncnt,mnret = 4001, twomin;
vector<int> v;
int main() {
	cin >> n;
	double aver=0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		aver += num;
		v.push_back(num);
		if (num < 0) {
			a[abs(num)]++;
		}
		else a[num + 4001]++;
	}
	aver = round(aver / n);
	if (aver == -0) aver = 0;
	sort(v.begin(), v.end());
	int here = v[0];
	int cnt=0;

	for (int i = 4000; i > 0; i--) {
		if (a[i] > mncnt) {
			twomin = 1;
			mncnt = a[i];
			mnret = -i;
		}
		else if (a[i] == mncnt) {
			twomin++;
			if (twomin == 2) {
				mnret = -i;
			}
		}
	}
	for (int i = 4001; i < 8004; i++) {
		if (a[i] > mncnt) {
			twomin = 1;
			mncnt = a[i];
			mnret = i - 4001;
		}
		else if (a[i] == mncnt) {
			twomin++;
			if (twomin == 2) {
				mnret = i - 4001;
			}
		}
	}

	cout << aver << '\n' << v[n / 2] << '\n' << mnret << '\n' << v[n - 1] - v[0] << '\n';
}