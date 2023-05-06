#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	double A[1000];
	int N, MAX = 0;
	double SUM = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
		if (A[i] > MAX)
			MAX = A[i];
	}
	for (int i = 0; i < N; ++i)
	{
		SUM += A[i] / MAX * 100;
	}
	cout << SUM / N << endl;
}