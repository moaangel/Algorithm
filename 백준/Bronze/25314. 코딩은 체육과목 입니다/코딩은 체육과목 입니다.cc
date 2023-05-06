#include <iostream>

using namespace std;
int N;
int main()
{
	cin >> N;
	int r = N / 4;
	for (int i = 0; i < r; i++)
		cout << "long ";
	cout << "int";
}