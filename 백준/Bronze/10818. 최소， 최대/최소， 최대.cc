#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int *A = new int[1000001];
	int N, min=1000000, max=-1000000;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i)
	{
		if (A[i] < min)
			min = A[i];
		if (A[i] > max)
			max = A[i];
	}
	cout << min << " " << max << endl;
	delete[] A;
}