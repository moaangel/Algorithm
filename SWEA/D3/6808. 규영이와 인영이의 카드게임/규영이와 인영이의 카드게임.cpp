#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
vector<int> gyu;
vector<int> in;
int visited[9];
int win, loss;
void go(int idx, int w, int l) {
	if (idx == 9) {
		if (w > l)win++;
		else if (w < l)loss++;
		return;
	}

	for (int i = 0; i < 9; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			if (in[i] > gyu[idx]) go(idx + 1, w, l + in[i] + gyu[idx]);
			else go(idx + 1, w + in[i] + gyu[idx], l);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		gyu.clear();
		in.clear();
		win = 0, loss = 0;
		int a[19] = { 0, };
		for (int i = 0; i < 9; i++) {
			int num;
			cin >> num;
			gyu.push_back(num);
			a[num]++;
		}
		for (int i = 1; i <= 18; i++) {
			if (!a[i]) in.push_back(i);
		}
		go(0, 0, 0);
		cout << "#" << tc << " " << win << " " << loss << '\n';
	}
}