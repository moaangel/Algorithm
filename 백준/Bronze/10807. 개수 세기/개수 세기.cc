#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int A[100];
	int N, R, Count=0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	cin >> R;

	for (int i = 0; i < N; i++)
	{
		if (R == A[i])
			Count++;
	}
	cout << Count << endl;

}