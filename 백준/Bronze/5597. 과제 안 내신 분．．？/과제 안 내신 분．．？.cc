#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int A[28];
	int x1 = 0, x2 = 0;
	for (int i = 0; i < 28; ++i)
	{
		cin >> A[i];
	}
	for (int c = 1; c <= 30; ++c)
	{
		int r = 0;
		for (int i = 0; i < 28; ++i)
		{
			if (c == A[i])
				r = 1;
		}
		if (r == 0 && x1 == 0)
			x1 = c;
		else if (r == 0)
			x2 = c;
	}
	if (x1 > x2)
		cout << x2 << "\n" << x1;
	else
		cout << x1 << "\n" << x2;
}