#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,p,mi,mul,di,minret= 1000000000,maxret= -1000000000;
int a[12];
int oper[4];

void brute(int num,int idx,int p,int mi,int mul, int div) {
	if (idx == n-1) {
		minret = min(minret, num);
		maxret = max(maxret, num);
		return;
	}

	if (p) brute(num + a[idx+1], idx + 1, p-1, mi, mul, div);
	if (mi) brute(num - a[idx + 1], idx + 1, p, mi-1, mul, div);
	if (mul) brute(num * a[idx + 1], idx + 1, p, mi, mul-1, div);
	if (div) brute(num / a[idx + 1], idx + 1, p, mi, mul, div-1);

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> p >> mi >> mul >> di;
	brute(a[0],0,p, mi, mul, di);
	cout << maxret << '\n' << minret << '\n';
}