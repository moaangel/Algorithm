#include <iostream>
#include <vector>

using namespace std;

int n, m, num;
int psum[100005];
vector<int> ret;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		psum[i] = psum[i - 1] + num;
	}
	for (int i = 1; i <= m; i++) {
		int numstart, numend;
		cin >> numstart >> numend;
		ret.push_back(psum[numend] - psum[numstart-1]);
	}
	for (int i : ret)
		cout << i << "\n";
	
	return 0;
}