#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int A[10000];
	int N, X;
	cin >> N >> X;

	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i)
	{
		if (A[i] < X)
			cout << A[i] << " ";
	}
}