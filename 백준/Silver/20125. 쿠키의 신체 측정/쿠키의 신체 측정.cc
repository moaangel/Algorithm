#include <iostream>
#include <string>
using namespace std;

int n,hy,hx,la, ra, w, lleg, rl, endY;
string s;
char arr[1002][1002];

void check() {
	for (int i = hx - 1; i >= 0; i--) {
		if (arr[hy][i] == '*')la++;
		else break;
	}

	for (int i = hx + 1; i < n; i++) {
		if (arr[hy][i] == '*')ra++;
		else break;
	}

	for (int i = hy + 1; i < n; i++) {
		if (arr[i][hx] == '*')w++;
		else {
			endY = i-1;
			break;
		}
	}

	for (int i = endY + 1; i < n; i++) {
		if (arr[i][hx - 1] == '*')lleg++;
		else break;
	}

	for (int i = endY + 1; i < n; i++) {
		if (arr[i][hx + 1] == '*')rl++;
		else break;
	}

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j];
			if (!hy && !hx && arr[i][j] == '*') {
				hy = i + 1;
				hx = j;
			}
		}
	}
		check();
		cout << hy + 1 << " " << hx + 1 << '\n' << la << " " << ra << " " << w << " " << lleg << " " << rl;
}