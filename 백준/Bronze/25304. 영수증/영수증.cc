#include <iostream>

using namespace std;


int main()
{
	int X,N,a,b;
	cin >> X >> N;
	int r = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		r += a*b;
	}
	if (X == r)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;


	return 0;
 }