#include <iostream>

using namespace std;

int main()
{
	int A,B,C;
	cin >> A >> B >> C;
	if (B+C < 60)
		cout << A << " " << B+C << endl;
	else if (A+((B+C)/60) >= 24)
		cout << (A+(B+C)/60) - 24 << " " << (B+C)%60 << endl;
	else
		cout << A+((B+C)/60) << " " << (B+C)%60 << endl;
}