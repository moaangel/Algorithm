#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int A[9];
	int max = 0, count = 0;
	int mC;
	for (int i = 0; i < 9; ++i)
	{
		cin >> A[i];
	}
	for (int i = 0; i < 9; ++i)
	{
		++count;
		if (A[i] > max)
		{
			max = A[i];
			mC = count;
		}
	}
	cout << max << '\n' << mC << endl;
}