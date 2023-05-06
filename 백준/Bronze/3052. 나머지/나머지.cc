#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int A;
	int B[42]{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
			-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 ,-1};
	int count = 0;
	for (int i = 0; i < 10; ++i)
	{
		cin >> A;
		B[A % 42] = 1;
	}

	for (int i = 0; i < 42; ++i)
	{
		if (B[i] > -1)
			count++;
	}
	cout << count << endl;
}