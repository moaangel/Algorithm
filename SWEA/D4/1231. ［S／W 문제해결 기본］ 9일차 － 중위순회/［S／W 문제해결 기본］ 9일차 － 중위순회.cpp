#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;
   
vector<int> v[102];
char a[102];
int n;

void inorder(int here) {
	if (v[here].size()) {
		inorder(v[here][0]);
	}
	cout << a[here];
	if (v[here].size() == 2)
		inorder(v[here][1]);
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0; i < 102; i++) { if (v[i].size())v[i].clear(); }
		cin >> n;
		for (int i = 1; i <= n; i++) {
			if (i * 2 > n) {
				int num; char c;
				cin >> num >> c;
				a[num] = c;
			}
			else if (i * 2 == n) {
				int num, l; char c;
				cin >> num >> c >> l;
				a[num] = c;
				v[num].push_back(l);
			}
			else {
				int num, l, r; char c;
				cin >> num >> c >> l >> r;
				a[num] = c;
				v[num].push_back(l);
				v[num].push_back(r);
			}
		}
		cout << "#" << test_case << " ";
		inorder(1);
		cout << '\n';
	}
	return 0;
}
