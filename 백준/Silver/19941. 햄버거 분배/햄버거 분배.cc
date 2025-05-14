#include <iostream>
#include <string>

using namespace std;

int n, k, ans;
string s;
bool visited[20002];
int main() {
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'H')continue;
		for (int j = i - k; j <= i + k; j++) {
			if (j < 0 || j >= s.size() || visited[j] || s[j] == 'P')continue;
			visited[j] = true;
			ans++;
			break;
		}
	}
	cout << ans << '\n';
}