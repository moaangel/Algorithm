#include <iostream>
#include <vector>

using namespace std;

int ret = -10000005;
int N, K, temp = 0;
int psum[100005];
int main() 
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		psum[i] = psum[i - 1] + temp;
	}
	for (int i = K; i <= N; i++)
	{
		ret = max(ret, psum[i] - psum[i - K]);
	}
	cout << ret;

	return 0;
}