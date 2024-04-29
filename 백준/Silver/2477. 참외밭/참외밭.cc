#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> a[7];
int n, mx1, mx2, sm1,sm2;
int main() {
	cin >> n;
	for (int i = 0; i < 6; i++) {
		int way, leng;
		cin >> way >> leng;
		a[i] = { way,leng };
		if (way == 1 || way == 2)mx1 = max(mx1, leng);
		else mx2 = max(mx2, leng);
	}
	int bigsq = mx1 * mx2;

	for (int i = 0; i < 6; i++) {
		if (i == 0) {
			if ((a[i].first == 1 || a[i].first == 2) && a[i].second != mx1) {
				if (a[i + 1].second == mx2 || a[5].second == mx2)continue;
				else sm1 = a[i].second;
			}
			else if ((a[i].first == 3 || a[i].first == 4) && a[i].second != mx2) {
				if (a[i + 1].second == mx1 || a[5].second == mx1)continue;
				else sm2 = a[i].second;
			}
		}
		else if (i == 5) {
			if ((a[i].first == 1 || a[i].first == 2) && a[i].second != mx1) {
				if (a[i - 1].second == mx2 || a[0].second == mx2)continue;
				else sm1 = a[i].second;
			}
			else if ((a[i].first == 3 || a[i].first == 4) && a[i].second != mx2) {
				if (a[i - 1].second == mx1 || a[0].second == mx1)continue;
				else sm2 = a[i].second;
			}
		}
		else {
			if ((a[i].first == 1 || a[i].first == 2) && a[i].second != mx1) {
				if (a[i + 1].second == mx2 || a[i-1].second == mx2)continue;
				else sm1 = a[i].second;
			}
			else if ((a[i].first == 3 || a[i].first == 4) && a[i].second != mx2) {
				if (a[i + 1].second == mx1 || a[i-1].second == mx1)continue;
				else sm2 = a[i].second;
			}
		}
	}
	int smsq = sm1 * sm2;
	cout << (bigsq - smsq) *n << '\n';
}