#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int A,B;
	int count = 0;

	cin >> A;
	int rA = A;
	while (1)
	{
		B = (A % 10) * 10 + ((A / 10 + A % 10) % 10);
		A = B;
		count++;
		if (rA == A)
		{
			break;
		}
	}
	cout << count << endl;
}